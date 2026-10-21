"""The translation-unit map: what the rest of a function's unit told the original compiler.

One function per file discards three things the original compiler knew, and each changes code:

  nothrow   a callee compiled earlier in the same translation unit cannot throw (with
            -fno-exceptions every finished function is marked so), nor can a C library function
            the compiler knows by name, nor a function declared `throw()` (operator delete);
            reorg then scans past the call: `beq` against `beql`, what fills a delay slot;
  const     a callee compiled earlier in the unit and found free of side effects is const for the
            callers after it, which keep values cached across the call;
  aliasing  the unit's -fstrict-aliasing or -fno-strict-aliasing.

tools/unit_harvest.py measures all three on every matched source. This module solves the
measurements into unit boundaries and predicts the context of any function, matched or not:

  hard boundaries    after every static-initialiser wrapper (`_GLOBAL_.I.`/`.D.`, emitted last in
                     its unit: tools/gthd_units.py);
  same-unit spans    a callee that MUST be nothrow, below its caller with no hard boundary between:
                     no unit starts in (callee, caller]. Class-run boundaries of config/units.txt
                     and file-run guesses of config/units_gthd.txt inside a span are refuted;
  cuts               a callee that MUST NOT be nothrow, below its caller with no hard boundary
                     between: a unit starts somewhere in (callee, caller] outside the spans.
                     Overlapping cuts share one boundary; a candidate start inside the range
                     places it, else the range is kept and the map says `maybe` there;
  declared nothrow   a callee that must be nothrow from another unit or from below: the C library
                     names (config/libc_nothrow_names.txt at the addresses tools/libc_names.py
                     found) and whatever the callers vote for (operator delete);
  flag               per unit, the flag its sensitive functions need; where they disagree, the
                     nearest one.

    unit_map.py build [--check]     harvest -> config/unit_map.json, build/units/units_proposed.txt,
                                    the counts against config/units.txt; --check predicts every
                                    measured pair and flag from the other functions' measurements
    unit_map.py predict ADDR        the predicted context of one function
    unit_map.py context ADDR        the same as text for a worker prompt
    unit_map.py apply ADDR FILE     the draft with the predicted context written in (stdout)
    unit_map.py prove [-jN] [--save]  the open near-miss drafts judged with the predicted context
                                    only, against what finish_near.py's search found
    unit_map.py open                how many unmatched functions get a predicted context

As a module: predict(addr) -> dict, context_for(addr) -> text, apply(addr, text) -> (text, info).
They read config/unit_map.json; nothing here compiles except `prove`.
"""
import bisect
import collections
import csv
import json
import os
import re
import sys
import time

import project
import symbols

ROOT = project.ROOT
NSA = "ee-gcc2.96-no-strict-aliasing"
LIBRARY = 0x5547E8  # the library region starts here (config/libs/newlib.toml, the skill's notes)
DIFFER = re.compile(r"(\d+) of (\d+) instructions differ")

KEYWORDS = re.compile(r"\b(return|else|do|case|goto|delete|new|throw|sizeof|if|while|for|switch)\b")
PROTO = re.compile(r"^(?P<head>[^=;{}()]*?[\w\*&>\s])(?P<name>[A-Za-z_]\w*)\s*"
                   r"(?P<args>\((?:[^;{}()]|\([^()]*\))*\))\s*(?P<cv>const)?\s*;", re.S)
THROW = re.compile(r"\s*\bthrow\s*\(\s*\)")
ATTR_CONST = re.compile(r"\s*__attribute__\s*\(\(\s*(?:__)?const(?:__)?\s*\)\)")


def strip_marker(text):
    """(text without its `/* compiler: NAME */` first line, NAME or None)."""
    first, _, rest = text.partition("\n")
    m = project.COMPILER_MARKER.match(first)
    return (rest, m.group(1)) if m else (text, None)


def split_statements(text):
    """(start, end, in extern "C") of each `...;` chunk outside function bodies (file scope,
    extern "C" blocks and class bodies)."""
    kinds = []  # of the open braces: lang | type | body
    i, n, start = 0, len(text), 0
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
            continue
        if text.startswith("/*", i):
            j = text.find("*/", i)
            i = n if j < 0 else j + 2
            continue
        if c == '"':
            j = i + 1
            while j < n and text[j] != '"':
                j += 2 if text[j] == "\\" else 1
            i = j + 1
            continue
        if c == "'":
            j = i + 1
            while j < n and text[j] != "'":
                j += 2 if text[j] == "\\" else 1
            i = j + 1
            continue
        if c == "{":
            head = text[start:i]
            if re.search(r'extern\s+"C"\s*$', head):
                kinds.append("lang")
            elif re.search(r"\b(struct|class|union|enum|namespace)\b[^;{}()=]*$", head) or \
                    re.search(r'extern\s+"C\+\+"\s*$', head):
                kinds.append("type")
            else:
                kinds.append("body")
            start = i + 1
        elif c == "}":
            if kinds:
                kinds.pop()
            start = i + 1
        elif c == ";":
            if "body" not in kinds:
                yield start, i + 1, "lang" in kinds
            start = i + 1
        i += 1


def _proto(chunk):
    """(match on the chunk without its leading space, that space's length) for a function
    prototype, else (None, 0)."""
    lead = len(chunk) - len(chunk.lstrip())
    m = PROTO.match(chunk.lstrip())
    if not m or KEYWORDS.search(m.group("head")) or "typedef" in m.group("head"):
        return None, 0
    if "(*" in chunk[:lead + m.start("name")]:
        return None, 0
    return m, lead


def _address(name):
    try:
        return symbols.address_of(name)
    except Exception:
        return None


class Protos:
    """The callee prototypes of a C++ source, and the source with any chosen sets of them declared
    `throw()` and `__attribute__((const))`.

    callees     addresses, in order of first declaration (the function itself left out)
    have        the callees the text declares `throw()` already
    have_const  the callees it declares `__attribute__((const))`
    c_names     {name: address or None} of prototypes with C linkage (extern "C"): a C library
                name there is nothrow by name, whatever the text says
    render(nothrow, const) the text with exactly those annotations (const: as the text has it)
    """

    def __init__(self, text, own=None):
        # the text without the annotations of its prototypes, remembering who had which
        out, last, have, have_const = [], 0, set(), set()
        for s, e, _ in split_statements(text):
            chunk = text[s:e]
            if "throw" not in chunk and "__attribute__" not in chunk:
                continue
            bare = THROW.sub("", ATTR_CONST.sub("", chunk))
            m, _ = _proto(bare)
            addr = _address(m.group("name")) if m else None
            if addr is None or "throw" in bare:
                continue
            if THROW.search(chunk):
                have.add(addr)
            if ATTR_CONST.search(chunk):
                have_const.add(addr)
            out.append(text[last:s] + bare)
            last = e
        out.append(text[last:])
        self.bare = "".join(out)
        self.cuts, self.c_names, self.names = [], {}, {}
        for s, e, c_linkage in split_statements(self.bare):
            chunk = self.bare[s:e]
            m, lead = _proto(chunk)
            if not m or "throw" in chunk:
                continue
            name = m.group("name")
            addr = _address(name)
            if c_linkage or re.search(r'extern\s+"C"', m.group("head")):
                self.c_names[name] = addr
            if addr is None or addr == own:
                continue
            self.names.setdefault(addr, name)
            self.cuts.append((s + lead + (m.end("cv") if m.group("cv") else m.end("args")), addr))
        self.callees = list(dict.fromkeys(a for _, a in self.cuts))
        self.have = frozenset(have & set(self.callees))
        self.have_const = frozenset(have_const & set(self.callees))

    def render(self, nothrow, const=None):
        const = self.have_const if const is None else const
        out, last = [], 0
        for cut, addr in self.cuts:
            extra = (" throw()" if addr in nothrow else "") + (" __attribute__((const))" if addr in const else "")
            if extra:
                out.append(self.bare[last:cut] + extra)
                last = cut
        out.append(self.bare[last:])
        return "".join(out)


# ------------------------------------------------------------------------------------------
# what the original's machine code says about a callee: can gcc have found it free of side effects

_STORES = {0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x3F, 0x39, 0x3D, 0x1F, 0x38, 0x3C, 0x3A, 0x3E}
_LOADS = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x1A, 0x1B, 0x37, 0x31, 0x35, 0x1E, 0x30, 0x34, 0x32, 0x36}
_FP_LOADS = {0x31, 0x35}
PURITY = ("const", "reads", "impure")  # ordered: a function is as bad as the worst thing it does
_purity = {}


def _own_purity(addr):
    """(class, call targets) from the function's own instructions. const: it touches no memory but
    its own frame and float constants (absolute lwc1: the constant pool); reads: it also loads
    through pointers or from globals; impure: it stores outside its frame, jumps through a
    register, or traps into the kernel."""
    import match
    try:
        size = match.function_span(addr)
        text_addr, text = match.load_text()
        words = match.trim_padding(match.words_at(text_addr, text, addr, size))
    except (SystemExit, Exception):
        return "impure", []
    worst, calls, lui = 0, [], {}
    for i, w in enumerate(words):
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op in _STORES:
            if rs != 29:
                return "impure", []
        elif op in _LOADS:
            if rs != 29 and not (op in _FP_LOADS and rs in lui):
                worst = max(worst, 1)
            if op not in _FP_LOADS and op not in (0x32, 0x36):
                lui.pop(rt, None)
        elif op == 0x0F:
            lui[rt] = w & 0xFFFF
        elif op in (2, 3):
            target = ((addr + 4 * i) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            if op == 3 or not addr <= target < addr + 4 * len(words):
                calls.append(target)
            lui.clear()  # a call clobbers the temporaries
        elif op == 0:
            funct = w & 63
            if funct == 9 or funct == 0x0C or (funct == 8 and rs != 31):
                return "impure", []  # jalr, syscall, a jump table or computed jump
            lui.pop((w >> 11) & 31, None)
        elif 8 <= op <= 14 or op in (0x18, 0x19):
            if not (op in (9, 0x0D) and rs == rt):  # lui + addiu/ori of one register: still an address
                lui.pop(rt, None)
    return PURITY[worst], calls


def returns_value(addr):
    """Does the function's own code set $v0 or $f0, or end in a call whose value it can pass on:
    gcc never marks a void function const (and a const call whose value is unused is deleted)."""
    import match
    try:
        text_addr, text = match.load_text()
        words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    except (SystemExit, Exception):
        return False
    for w in words:
        op, rs, rt, rd = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        if op in (2, 3):
            return True
        if op == 0 and rd == 2 and (w & 63) not in (8, 9) and w != 0:
            return True
        if (8 <= op <= 15 or op in (0x18, 0x19) or (op in _LOADS and op not in _FP_LOADS)) and rt == 2:
            return True
        if op in _FP_LOADS and rt == 0:
            return True
        if op == 0x11:
            if rs == 0 and rt == 2:                       # mfc1 $v0
                return True
            if rs == 4 and rd == 0:                       # mtc1 to $f0
                return True
            if rs in (16, 20) and (w >> 6) & 31 == 0 and (w & 63) < 0x30 and (w & 63) not in (0x18, 0x1C, 0x1D, 0x1E, 0x1F):
                return True                               # an arithmetic result in $f0 (not adda/madd to ACC)
            if rs in (16, 20) and (w & 63) in (0x1C, 0x1D) and (w >> 6) & 31 == 0:
                return True                               # madd.s/msub.s into $f0
    return False


def purity(addr):
    """'const', 'reads' or 'impure' for the function at addr, its callees included (a call cycle
    counts as impure)."""
    if addr in _purity:
        return _purity[addr]
    _purity[addr] = "impure"  # while it is being worked out: a cycle
    cls, calls = _own_purity(addr)
    worst = PURITY.index(cls)
    for c in calls:
        if worst == 2:
            break
        if c != addr:
            worst = max(worst, PURITY.index(purity(c)))
    _purity[addr] = PURITY[worst]
    return _purity[addr]


# ------------------------------------------------------------------------------------------
# the harvest (tools/unit_harvest.py)

HARVEST = os.path.join(ROOT, "build", "units", "harvest.jsonl")


def harvest_rows(path=HARVEST):
    """{address: row} of the harvest, the rows of one source content merged (a later aspect adds
    its fields), a newer content replacing an older one."""
    out = {}
    if not os.path.exists(path):
        return out
    for line in open(path):
        try:
            r = json.loads(line)
        except ValueError:
            continue  # cut short by a kill
        a = int(r["addr"], 16)
        old = out.get(a)
        if old and old["sha"] == r["sha"]:
            base = old["base"] if r["base"] is None else r["base"]
            old.update(r)
            old["base"] = base
        else:
            out[a] = r
    return out


# ------------------------------------------------------------------------------------------
# the image and what the project already knows about its units

DATA = os.path.join(ROOT, "config", "unit_map.json")
OUT = os.path.join(ROOT, "build", "units")
PROPOSED = os.path.join(OUT, "units_proposed.txt")
LIBC = os.path.join(OUT, "libc_names.json")
TABLE = os.path.join(ROOT, "config", "libc_nothrow_names.txt")
# the profile that differs from each one in the aliasing flag only
FLIP = {None: NSA, NSA: None,
        "ee-gcc2.96-nosib": "ee-gcc2.96-nsa-nosib", "ee-gcc2.96-nsa-nosib": "ee-gcc2.96-nosib",
        "ee-gcc2.96-nosched1": "ee-gcc2.96-nsa-nosched1", "ee-gcc2.96-nsa-nosched1": "ee-gcc2.96-nosched1"}
_image = {}


def aliasing(profile):
    """'nsa' or 'strict' for a profile of FLIP (None: the project's compiler)."""
    return "nsa" if profile and ("no-strict-aliasing" in profile or "nsa" in profile) else "strict"


def functions():
    """Sorted [(address, size)] of the inventory (build/functions.csv)."""
    if "funcs" not in _image:
        with open(os.path.join(ROOT, "build", "functions.csv")) as f:
            _image["funcs"] = sorted((int(r["address"], 16), int(r["max_size"])) for r in csv.DictReader(f))
    return _image["funcs"]


def _words(addr, size):
    import match
    text_addr, text = match.load_text()
    return match.words_at(text_addr, text, addr, size)


def calls(addr):
    """The addresses the function at addr calls (jal, and j out of the function), each once."""
    if "sizes" not in _image:
        _image["sizes"] = dict(functions())
    size = _image["sizes"].get(addr)
    if not size:
        return []
    out = []
    for i, w in enumerate(_words(addr, size)):
        if w >> 26 in (2, 3):
            t = ((addr + 4 * i) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            if (w >> 26 == 3 or not addr <= t < addr + size) and t != addr and t not in out:
                out.append(t)
    return out


def callers():
    """{callee: {callers}} over the whole inventory."""
    if "callers" not in _image:
        out = collections.defaultdict(set)
        for a, _ in functions():
            for t in calls(a):
                out[t].add(a)
        _image["callers"] = out
    return _image["callers"]


def hard_starts():
    """The first function, and every function that follows a static-initialiser wrapper (the D
    after its I when both): g++ 2.96 emits the wrappers last in their unit."""
    if "hard" not in _image:
        import gthd_units
        funcs = functions()
        w = gthd_units.init_wrappers(funcs, gthd_units.here_reader())
        addrs = [a for a, _ in funcs]
        out = [addrs[0]]
        for k, a in enumerate(addrs[:-1]):
            if a in w and not (w[a] == "I" and w.get(addrs[k + 1]) == "D"):
                out.append(addrs[k + 1])
        _image["hard"] = out
        # what the wrappers call: __static_initialization_and_destruction_0, generated at the end of
        # the unit together with the inline constructors and destructors it calls
        _image["ssdf"] = {c for a in w for c in calls(a)[:1]}
    return _image["hard"]


def static_init_functions():
    hard_starts()
    return _image["ssdf"]


def known_units():
    """({start: kind}, {start: name}) of the unit starts the project already proposes that are
    not hard boundaries. Kinds: `class run` (config/units.txt: where a class's functions begin),
    `file change` (config/units_gthd.txt: two adjacent functions paired with two GT HD files),
    `file change nearby` (the same with unpaired functions between the two)."""
    if "known" in _image:
        return _image["known"]
    hard = set(hard_starts())
    kinds, names = {}, {}
    path = os.path.join(ROOT, "config", "units.txt")
    for line in open(path):
        p = line.split()
        if len(p) >= 2 and not line.startswith("#"):
            a = int(p[0], 16)
            names[a] = p[1]
            if a not in hard:
                kinds[a] = "class run"
    path = os.path.join(ROOT, "config", "units_gthd.txt")
    if os.path.exists(path):
        for line in open(path):
            if line.startswith("#") or not line.strip():
                continue
            p = line.rstrip("\n").split("\t")
            a, name = p[0].split()
            a = int(a, 16)
            if not name.startswith("unit_") or a not in names:
                names[a] = name
            if a not in hard and len(p) > 3:
                kinds[a] = "file change" if p[3].startswith("adjacent") else "file change nearby"
    _image["known"] = (kinds, names)
    return kinds, names


DELETE = ("__builtin_delete", "__builtin_vec_delete")  # g++ 2.96's names of operator delete, delete[]


def libc_nothrow():
    """{address: name} of the functions the compiler knows by name cannot throw: the C library
    names of its table at the addresses tools/libc_names.py placed or the symbol table has, and
    operator delete."""
    if "libc" in _image:
        return _image["libc"]
    table = {l.strip() for l in open(TABLE) if l.strip() and not l.startswith("#")}
    out = {}
    t = symbols._load()
    for name in table | set(DELETE):  # operator delete is declared throw() by the language
        if name in t.names and t.names[name][1] == "func":
            out[t.names[name][0]] = name
    if os.path.exists(LIBC):
        for r in json.load(open(LIBC))["names"]:
            if r["nothrow"]:
                out[r["addr"]] = r["name"]
    _image["libc"] = out
    return out


# ------------------------------------------------------------------------------------------
# solving the harvest into a map

def solve(rows, exclude=None):
    """The map as plain data (what config/unit_map.json holds) from harvest rows; `exclude`
    leaves one function's own measurements out, to predict it from the others."""
    funcs = [a for a, _ in functions()]
    index = {a: i for i, a in enumerate(funcs)}
    hard = hard_starts()
    kinds, _ = known_units()
    libc = libc_nothrow()

    def hard_between(c, g):
        return bisect.bisect_right(hard, g) > bisect.bisect_right(hard, c)

    must, must_not, flags, const_yes, const_no = [], [], {}, [], []
    for g, r in rows.items():
        if g == exclude or r.get("base") != "match" or g not in index:
            continue
        must += [(int(c, 16), g) for c in r.get("must", [])]
        must_not += [(int(c, 16), g) for c in r.get("must_not", [])]
        const_yes += [(int(c, 16), g) for c in r.get("must_const", [])]
        const_no += [(int(c, 16), g) for c in r.get("must_not_const", [])]
        if r.get("flag") not in (None, "match", "error") and r["profile"].replace("default", "") in ("", *filter(None, FLIP)):
            flags[g] = aliasing(r["profile"])
    # declared nothrow: needed from another unit or from below, by name or by vote
    yes, no = collections.Counter(), collections.Counter()
    for c, g in must:
        if c > g or hard_between(c, g) or c not in index:
            yes[c] += 1
    for c, g in must_not:
        no[c] += 1
    declared = {c: {"name": n, "why": "known by name", "yes": yes[c], "no": no[c]} for c, n in libc.items()}
    for c in yes:
        if c not in declared:
            declared[c] = {"name": symbols.name_of(c), "why": "callers need it", "yes": yes[c], "no": no[c]}
    clashes = {c: d for c, d in declared.items() if d["no"]}
    declared = {c: d for c, d in declared.items() if d["no"] <= d["yes"] and (d["yes"] or not d["no"])}
    # spans: no unit starts at the functions after the callee up to the caller
    n = len(funcs)
    diff = [0] * (n + 2)
    same = [(c, g) for c, g in must if c < g and c in index and c not in declared and not hard_between(c, g)]
    for c, g in same:
        diff[index[c] + 1] += 1
        diff[index[g] + 1] -= 1
    glued, run = bytearray(n), 0
    for i in range(n):
        run += diff[i]
        glued[i] = run > 0
    glue, i = [], 0
    while i < n:
        if glued[i]:
            j = i
            while j + 1 < n and glued[j + 1]:
                j += 1
            glue.append((funcs[i - 1], funcs[j]))
            i = j + 1
        else:
            i += 1
    # cuts: a unit starts in (callee, caller], outside the spans
    groups, conflicts = [], []
    # (not from a static-initialisation function: the inline destructors it calls sit below it
    # and are compiled after it)
    ssdf = static_init_functions()
    cuts = sorted(((c, g) for c, g in must_not if c < g and c in index and g not in ssdf and not hard_between(c, g)),
                  key=lambda p: (index[p[1]], index[p[0]]))
    for c, g in cuts:
        allowed = {i for i in range(index[c] + 1, index[g] + 1) if not glued[i]}
        if not allowed:
            conflicts.append((c, g))
        elif groups and groups[-1][0] & allowed:
            groups[-1][0] &= allowed
            groups[-1][1].append((c, g))
        else:
            groups.append([allowed, [(c, g)]])
    rank = {"file change": 0, "file change nearby": 1, "class run": 2}
    splits = []
    for allowed, pairs in groups:
        cands = sorted((rank[kinds[funcs[i]]], -i) for i in allowed if funcs[i] in kinds)
        at = -cands[0][1] if cands else max(allowed)
        splits.append({"start": funcs[at], "lo": funcs[min(allowed)], "hi": funcs[max(allowed)],
                       "exact": len(allowed) == 1, "placed": kinds.get(funcs[at]) if cands else None,
                       "pairs": [[g, c] for c, g in pairs]})
    refuted = {a: k for a, k in kinds.items() if a in index and glued[index[a]]}
    # functions gcc can have marked const: free of side effects, returning a value, and (it never
    # marks a public function) possibly static: every caller inside their own unit
    sure = sorted(set(hard) | {s["start"] for s in splits})
    unit_of = lambda a: bisect.bisect_right(sure, a)
    if "const_code" not in _image:
        _image["const_code"] = [a for a in funcs if purity(a) == "const" and returns_value(a)]
    who = callers()
    # ... and no caller after it in its unit is measured to need it plain: that settles it for all
    refused = {c for c, g in const_no if c < g and unit_of(c) == unit_of(g)}
    const_cands = [a for a in _image["const_code"] if a not in refused and who.get(a)
                   and all(unit_of(x) == unit_of(a) for x in who[a])]
    return {"functions": n, "hard": hard, "glue": glue, "splits": splits,
            "soft": {a: k for a, k in kinds.items() if a in index and not glued[index[a]]},
            "refuted": refuted, "conflicts": conflicts, "declared": declared, "clashes": clashes,
            "flags": flags, "const": const_yes, "not_const": const_no, "const_candidates": const_cands,
            "static_init": sorted(ssdf),
            "pairs": {"must": len(must), "must_not": len(must_not), "same": len(same), "cuts": len(cuts)}}


def _dump(data):
    h = lambda a: f"{a:08x}"
    out = dict(data)
    out["hard"] = [h(a) for a in data["hard"]]
    out["const_candidates"] = [h(a) for a in data["const_candidates"]]
    out["static_init"] = [h(a) for a in data["static_init"]]
    out["glue"] = [[h(a), h(b)] for a, b in data["glue"]]
    out["splits"] = [dict(s, start=h(s["start"]), lo=h(s["lo"]), hi=h(s["hi"]),
                          pairs=[[h(g), h(c)] for g, c in s["pairs"]]) for s in data["splits"]]
    for key in ("soft", "refuted", "declared", "clashes", "flags"):
        out[key] = {h(a): v for a, v in sorted(data[key].items())}
    for key in ("conflicts", "const", "not_const"):
        out[key] = [[h(a), h(b)] for a, b in data[key]]
    return out


def _load(raw):
    x = lambda s: int(s, 16)
    out = dict(raw)
    out["hard"] = [x(a) for a in raw["hard"]]
    out["const_candidates"] = [x(a) for a in raw["const_candidates"]]
    out["static_init"] = [x(a) for a in raw["static_init"]]
    out["glue"] = [(x(a), x(b)) for a, b in raw["glue"]]
    out["splits"] = [dict(s, start=x(s["start"]), lo=x(s["lo"]), hi=x(s["hi"]),
                          pairs=[[x(g), x(c)] for g, c in s["pairs"]]) for s in raw["splits"]]
    for key in ("soft", "refuted", "declared", "clashes", "flags"):
        out[key] = {x(a): v for a, v in raw[key].items()}
    for key in ("conflicts", "const", "not_const"):
        out[key] = [(x(a), x(b)) for a, b in raw[key]]
    return out


class Map:
    """Predictions from the solved data."""

    def __init__(self, data=None):
        if data is None:
            if not os.path.exists(DATA):
                raise SystemExit("config/unit_map.json is missing: python3 tools/unit_map.py build")
            data = _load(json.load(open(DATA)))
        self.d = data
        self.hard = data["hard"]
        self.glue = sorted(data["glue"])
        self.glue_lo = [a for a, _ in self.glue]
        self.splits = sorted(data["splits"], key=lambda s: s["lo"])
        self.soft = sorted(data["soft"])
        self.sure = sorted(set(self.hard) | {s["start"] for s in self.splits})
        self.votes = sorted(data["flags"])
        self.const_cands = set(data["const_candidates"])
        self.static_init = set(data["static_init"])

    def unit(self, addr):
        """(start, end or None, evidence of the start) of the unit holding addr, by the boundaries
        the map is sure of (static initialisers and the cuts the pairs demand)."""
        i = bisect.bisect_right(self.sure, addr) - 1
        start = self.sure[max(i, 0)]
        end = self.sure[i + 1] if i + 1 < len(self.sure) else None
        why = "static initialiser" if start in set(self.hard) else "a callee below must not be nothrow"
        return start, end, why

    def relation(self, c, g):
        """Is the callee c (below g) in g's unit: `same` (a measured span covers both), `cut` (a
        boundary lies between for sure), `maybe` (a cut whose place is not settled reaches
        between them), `cut?` (a file change of GT HD's lies between), `same?` (nothing known
        between them but class runs, or nothing at all)."""
        if bisect.bisect_right(self.hard, g) > bisect.bisect_right(self.hard, c):
            return "cut"
        partial = False
        for s in self.splits:
            if s["lo"] > g:
                break
            if c < s["lo"] and s["hi"] <= g:
                return "cut"
            if s["hi"] > c and s["lo"] <= g:
                partial = True
        k = bisect.bisect_right(self.glue_lo, c) - 1
        if k >= 0 and self.glue[k][1] >= g:
            return "same"
        if partial:
            return "maybe"
        between = self.soft[bisect.bisect_right(self.soft, c):bisect.bisect_right(self.soft, g)]
        if any(self.d["soft"][a] == "file change" for a in between):
            return "cut?"
        return "same?"

    def flag(self, addr):
        """('nsa' | 'strict' | None, why): what the sensitive functions of addr's unit need."""
        start, end, _ = self.unit(addr)
        lo = bisect.bisect_left(self.votes, start)
        hi = bisect.bisect_left(self.votes, end) if end else len(self.votes)
        mine = [a for a in self.votes[lo:hi] if a != addr]
        kinds = collections.Counter(self.d["flags"][a] for a in mine)
        if not kinds:
            return None, "no function of the unit depends on the flag"
        if len(kinds) == 1:
            k = next(iter(kinds))
            return k, f"{kinds[k]} function(s) of the unit need it, none the other"
        near = min(mine, key=lambda a: abs(a - addr))
        return self.d["flags"][near], (f"the unit's functions disagree ({kinds['nsa']} nsa, {kinds['strict']} strict); "
                                       f"the nearest is {near:08x}")

    def is_const(self, c, g, rel):
        """Would the compiler have marked callee c const when it reached g: c is free of side
        effects by its machine code, returns a value, has no caller outside its unit (gcc marks
        static functions only), and was compiled above g in g's unit."""
        return rel in NOTHROW_RELATIONS and c in self.const_cands

    def predict(self, addr, callees=None):
        """The predicted context of the function at addr. callees: the ones to decide (default:
        what the original calls)."""
        callees = calls(addr) if callees is None else callees
        start, end, why = self.unit(addr)
        flag, flag_why = self.flag(addr)
        out = {"addr": addr, "unit": [start, end], "unit_evidence": why, "flag": flag, "flag_why": flag_why,
               "nothrow": {}, "const": [], "maybe": [], "plain": []}
        for c in callees:
            d = self.d["declared"].get(c)
            rel = self.relation(c, addr) if c < addr else "above"
            if rel == "same?" and addr in self.static_init:
                rel = "maybe"  # the inline constructors and destructors it calls are compiled after it
            if d:
                out["nothrow"][c] = f"known by name: {d['name']}" if d["why"] == "known by name" else \
                    f"declared nothrow ({d['yes']} matched caller(s) in other units need it)"
            elif rel in NOTHROW_RELATIONS:
                out["nothrow"][c] = "defined above it in its unit" + ("" if rel == "same" else " (no boundary known between)")
            elif rel == "maybe":
                out["maybe"].append(c)
            else:
                out["plain"].append(c)
            if c < addr and self.is_const(c, addr, rel):
                out["const"].append(c)
        return out


NOTHROW_RELATIONS = ("same", "same?")
_map = None


def the_map():
    global _map
    if _map is None:
        _map = Map()
    return _map


def predict(addr):
    """The predicted translation-unit context of the function at addr (see Map.predict)."""
    return the_map().predict(addr)


def context_for(addr, m=None):
    """The predicted context as text for a worker prompt; '' when there is nothing to say."""
    p = (m or the_map()).predict(addr)
    name = lambda c: f"func_{c:08X}"
    lines = []
    if p["flag"] == "nsa":
        lines.append(f"- First line of the source: `/* compiler: {NSA} */` ({p['flag_why']}).")
    elif p["flag"] == "strict":
        lines.append(f"- Start without a compiler marker: {p['flag_why']} (strict aliasing, the default).")
    else:
        lines.append(f"- First line of the source: `/* compiler: {NSA} */`. No matched function of this unit shows its "
                     "aliasing flag; about 3 in 4 flag-sensitive functions of the game need this one and the others "
                     "compile the same either way. Drop it if a diff shows a load forwarded across a store.")
    unit = [c for c, why in p["nothrow"].items() if why.startswith("defined")]
    lib = [(c, why) for c, why in p["nothrow"].items() if not why.startswith("defined")]
    if unit:
        lines.append("- Declare these callees `throw()`: they are defined above this function in its translation unit, "
                     "so the compiler knew they cannot throw: " + ", ".join(name(c) for c in unit) + ".")
    if lib:
        lines.append("- Declare these `throw()` too: " + ", ".join(
            f"{name(c)} ({why.split(': ')[1]})" if why.startswith("known by name") else f"{name(c)} (declared nothrow)"
            for c, why in lib) + ".")
    if p["const"]:
        lines.append("- Add `__attribute__((const))` after the `throw()` of: " + ", ".join(name(c) for c in p["const"])
                     + " (free of side effects and compiled above this function: the caller keeps values cached across the call).")
    if p["maybe"]:
        lines.append("- Not settled (a unit boundary lies somewhere near): " + ", ".join(name(c) for c in p["maybe"])
                     + ". Try them with and without `throw()`.")
    if lines and p["plain"]:
        lines.append("- Leave the other callees plain: a `throw()` on a callee from another unit changes the code "
                     "(`beq` for `beql`, another delay-slot fill).")
    if not lines:
        return ""
    end = f"0x{p['unit'][1]:08X}" if p["unit"][1] else "the end"
    return (f"Translation-unit context (predicted by tools/unit_map.py from the matched functions around it; "
            f"unit 0x{p['unit'][0]:08X} to {end}):\n" + "\n".join(lines))


# Where no matched function of the unit shows its flag: of the 303 flag-sensitive functions of the
# 2026-10-12 harvest, 230 need -fno-strict-aliasing, and 99.7% of the others compile the same under
# both. A worker in such a unit (RaceDisplay) needed the marker on three of its functions.
PRIOR = "nsa"


def flagged(own, flag, impose_strict=False):
    """The profile a draft marked `own` gets under the predicted flag. Only -fno-strict-aliasing
    is ever added: strict aliasing is where every draft starts, a draft that asks for the other
    flag does so because it was judged closer with it, and the functions that need strict aliasing
    inside units that need the other flag cannot be told from their neighbours (first proof run:
    three drafts 3, 5 and 11 instructions off went to 27, 19 and 13 when a lone strict vote nearby
    took their marker away). impose_strict=True is that first rule, kept to measure against."""
    if flag and own in FLIP and aliasing(own) != flag and (flag == "nsa" or impose_strict):
        return FLIP[own]
    return own


def apply(addr, text, m=None, impose_strict=False):
    """(the C++ draft with the predicted context written in, the prediction). Callees the map
    cannot decide keep what the draft says; the flag as flagged() says."""
    m = m or the_map()
    body, own = strip_marker(text)
    p = Protos(body, addr)
    pred = m.predict(addr, p.callees)
    undecided = set(pred["maybe"])
    nothrow = set(pred["nothrow"]) | (p.have & undecided)
    const = set(pred["const"]) | (p.have_const & undecided)
    pred["flag_prior"] = not pred["flag"]
    profile = pred["profile"] = flagged(own, pred["flag"] or PRIOR, impose_strict)
    return (f"/* compiler: {profile} */\n" if profile else "") + p.render(nothrow, const), pred


# ------------------------------------------------------------------------------------------
# judging (for the harvest and the proof; everything else here only reads)

def verdict(ok, report):
    """'match', ('differs', n) or 'error' (did not compile, refused, not in the inventory)."""
    first = report.split("\n")[0] if report else ""
    if ok or "matches alone" in first:
        return "match"
    m = DIFFER.search(first)
    return ("differs", int(m.group(1))) if m else "error"


def judge_all(pairs, jobs, sources=None):
    """{path: verdict} for [(addr, path)]: match.judge_many without its rescan of src/ per call."""
    import shutil
    import match
    sources = project.sources() if sources is None else sources
    out = {}
    for k in range(0, len(pairs), 300):
        part = pairs[k:k + 300]
        objs = match.compile_many([p for _, p in part], jobs)
        batch = next((os.path.dirname(o) for o in objs.values() if o), None)
        for addr, path in part:
            obj = objs.get(path)
            if not obj:
                out[path] = "error"
                continue
            try:
                out[path] = verdict(*match.judge(addr, path, obj, sources))
            except (SystemExit, Exception):  # an address the inventory does not know
                out[path] = "error"
        if batch:
            shutil.rmtree(batch, ignore_errors=True)
    return out


# ------------------------------------------------------------------------------------------
# commands

def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def proposed_units(data):
    """[(start, name, evidence)] of the units the map proposes: every boundary it is sure of, and
    the project's own guesses it could not refute."""
    _, names = known_units()
    hard = set(data["hard"])
    rows = {a: "static initialiser" for a in hard}
    for a, k in data["soft"].items():
        rows[a] = f"{k} (untested)"
    for s in data["splits"]:
        where = "here exactly" if s["exact"] else f"between {s['lo']:08x} and {s['hi']:08x}"
        placed = f", placed at the {s['placed']}" if s["placed"] else ""
        rows[s["start"]] = f"cut: {len(s['pairs'])} caller(s) need a boundary {where}{placed}"
    return [(a, names.get(a, f"unit_{a:08X}"), why) for a, why in sorted(rows.items())]


def cmd_build(a):
    rows = harvest_rows()
    data = solve(rows)
    os.makedirs(OUT, exist_ok=True)
    with open(DATA, "w", newline="\n") as f:
        json.dump(_dump(data), f, indent=0, sort_keys=True)
        f.write("\n")
    m = Map(data)
    units = proposed_units(data)
    starts = [u[0] for u in units]
    votes = sorted(data["flags"])
    with open(PROPOSED, "w", newline="\n") as f:
        f.write("# Translation units proposed by tools/unit_map.py build. PROPOSAL: the same format as config/units.txt\n"
                "# (START NAME), then tab separated: evidence of the boundary, the aliasing flag its sensitive functions\n"
                "# need (nsa:N strict:N). Installing it as config/units.txt changes the swarm's areas (tools/swarm.py\n"
                "# area_of: leases, paused areas and `swarm.py areas` go by these names), tools/layout.py's paths for\n"
                "# functions without a class, and the per-unit tables of knowledge/coverage-map.md: do it between swarm\n"
                "# sessions, then run tools/organize.py. Boundaries marked `untested` are the old files' guesses.\n")
        for k, (start, name, why) in enumerate(units):
            end = starts[k + 1] if k + 1 < len(starts) else 1 << 32
            mine = collections.Counter(data["flags"][v] for v in votes[bisect.bisect_left(votes, start):bisect.bisect_left(votes, end)])
            flag = " ".join(f"{x}:{n}" for x, n in sorted(mine.items())) or "-"
            f.write(f"{start:08x} {name}\t{why}\t{flag}\n")
    old = {int(l.split()[0], 16) for l in open(os.path.join(ROOT, "config", "units.txt")) if l.strip() and not l.startswith("#")}
    hard = set(data["hard"])
    new_cuts = [s for s in data["splits"] if not any(s["lo"] <= u <= s["hi"] for u in old)]
    old_cuts = [s for s in data["splits"] if any(s["lo"] <= u <= s["hi"] for u in old)]
    sens = [r for r in rows.values() if r.get("base") == "match"]
    print(f"harvest: {len(rows)} functions; pairs {data['pairs']}; {len(data['flags'])} functions need their flag")
    print(f"same-unit spans: {len(data['glue'])} (after merging); cuts: {len(data['splits'])} "
          f"({sum(1 for s in data['splits'] if s['exact'])} placed exactly); pairs no boundary can satisfy: {len(data['conflicts'])}")
    print(f"against config/units.txt ({len(old)} starts):")
    print(f"  merged: {sum(1 for u in data['refuted'] if u in old)} of its starts lie inside a same-unit span (not boundaries)")
    print(f"  split by the pairs: {len(new_cuts)} cuts fall where it has no start; {len(old_cuts)} cuts confirm one of its starts "
          f"(or have one in their range)")
    print(f"  split by static initialisers: {len(hard - old)} hard boundaries it lacks ({len(hard & old)} it has)")
    print(f"  untested: {sum(1 for u in data['soft'] if u in old)} of its starts")
    print(f"units_gthd.txt guesses: {sum(1 for u, k in data['refuted'].items() if k != 'class run')} refuted, "
          f"{sum(1 for u, k in data['soft'].items() if k != 'class run')} untested")
    d = data["declared"]
    print(f"declared nothrow: {sum(1 for x in d.values() if x['why'] == 'known by name')} known by name "
          f"({sum(1 for x in d.values() if x['why'] == 'known by name' and x['yes'])} confirmed by a caller), "
          f"{sum(1 for x in d.values() if x['why'] != 'known by name')} more by callers' votes; "
          f"{len(data['clashes'])} with votes both ways or against")
    for c, x in sorted(data["clashes"].items()):
        print(f"    {c:08x} {x['name'] or ''}: {x['yes']} need it nothrow, {x['no']} need it plain ({x['why']})")
    per = collections.defaultdict(collections.Counter)
    for v in votes:
        per[m.unit(v)[0]][data["flags"][v]] += 1
    print(f"flags: {len(per)} units have a sensitive function: {sum(1 for c in per.values() if set(c) == {'nsa'})} nsa only, "
          f"{sum(1 for c in per.values() if set(c) == {'strict'})} strict only, {sum(1 for c in per.values() if len(c) == 2)} mixed")
    print(f"const: {len(data['const'])} pairs must be const, {len(data['not_const'])} must not")
    print(f"wrote {os.path.relpath(DATA, ROOT)} and {os.path.relpath(PROPOSED, ROOT)} ({len(units)} units)")
    if a.check:
        check(rows)


def check(rows):
    """Predict every measured pair and flag from the other functions' measurements."""
    log("check: each sensitive function predicted with its own measurements left out")
    pairs, flags, consts, imposed = collections.Counter(), collections.Counter(), collections.Counter(), collections.Counter()
    wrong = collections.defaultdict(list)
    todo = [g for g, r in rows.items() if r.get("base") == "match" and
            (r.get("must") or r.get("must_not") or r.get("must_const") or r.get("must_not_const")
             or r.get("flag") not in (None, "match", "error"))]
    every = solve(rows)
    for n, g in enumerate(sorted(todo), 1):
        r = rows[g]
        m = Map(solve(rows, exclude=g))
        truth = {int(c, 16): True for c in r.get("must", [])}
        truth.update({int(c, 16): False for c in r.get("must_not", [])})
        if truth:
            pred = m.predict(g, list(truth))
            for c, want in truth.items():
                if c in pred["maybe"]:
                    got, kind = None, "maybe"
                else:
                    got = c in pred["nothrow"]
                    kind = ("declared" if c in m.d["declared"] else m.relation(c, g) if c < g else "above")
                pairs[(kind, "must" if want else "must not", "undecided" if got is None else "right" if got == want else "WRONG")] += 1
                if got is not None and got != want:
                    wrong[kind].append(f"{g:08x}<-{c:08x}")
        truth = {int(c, 16): True for c in r.get("must_const", [])}
        truth.update({int(c, 16): False for c in r.get("must_not_const", [])})
        for c, want in truth.items():
            rel = m.relation(c, g) if c < g else "above"
            got = c < g and m.is_const(c, g, rel)
            kind = purity(c) + ("" if returns_value(c) else ", void") + (", local callers" if c in m.const_cands else "")
            consts[(kind, rel, "must" if want else "must not", "right" if got == want else "WRONG")] += 1
        want = every["flags"].get(g)
        if want:
            got, why = m.flag(g)
            how = "none" if got is None else "nearest" if why.startswith("the unit's functions disagree") else "unit"
            flags[(how, "right" if got == want else "undecided" if got is None else "WRONG")] += 1
            # what apply() does to a draft that starts without a marker
            imposed[(f"needs {want}", "nsa added" if got == "nsa" else "left alone",
                     "right" if (got == "nsa") == (want == "nsa") else "WRONG" if got == "nsa" else "not found")] += 1
        if n % 300 == 0:
            log(f"  {n} of {len(todo)}")
    for title, c in (("nothrow pairs", pairs), ("const pairs (purity, relation)", consts), ("flags (the unit's vote against the function's need)", flags),
                     ("flags as applied to an unmarked draft (nsa is added, strict never imposed)", imposed)):
        print(title + ":")
        for k, v in sorted(c.items()):
            print(f"  {v:5}  {' / '.join(k)}")
    for kind, ex in wrong.items():
        print(f"wrong, {kind}: {' '.join(ex[:12])}")


def cmd_predict(a):
    p = the_map().predict(a.addr)
    show = lambda c: f"{c:08x}" + (f" {symbols.name_of(c)}" if symbols.name_of(c) else "")
    end = f"{p['unit'][1]:08x}" if p["unit"][1] else "end"
    print(f"{a.addr:08x}: unit {p['unit'][0]:08x}-{end} (starts after: {p['unit_evidence']})")
    print(f"  flag: {p['flag'] or 'unknown'} ({p['flag_why']})")
    for c, why in p["nothrow"].items():
        print(f"  nothrow {show(c)}: {why}")
    for c in p["const"]:
        print(f"  const   {show(c)}")
    for c in p["maybe"]:
        print(f"  maybe   {show(c)}")
    for c in p["plain"]:
        print(f"  plain   {show(c)}")


def cmd_context(a):
    print(context_for(a.addr) or "(no context to add)")


def cmd_apply(a):
    text, _ = apply(a.addr, open(a.file, encoding="utf-8", errors="replace").read())
    sys.stdout.write(text)


def open_functions():
    """Inventory functions without a source that are decompilation targets."""
    done = set(project.sources(refresh=True))
    skip = set()
    path = os.path.join(ROOT, "config", "asm_functions.txt")
    if os.path.exists(path):
        skip = {int(l.split()[0], 16) for l in open(path) if l.strip() and not l.startswith("#")}
    return [(a, size) for a, size in functions() if a not in done and a not in skip]


def cmd_open(a):
    m = the_map()
    c = collections.Counter()
    for addr, size in open_functions():
        c["open"] += 1
        p = m.predict(addr)
        if not (p["nothrow"] or p["plain"] or p["maybe"]):
            c["without a call"] += 1
        game = addr < LIBRARY
        c["game code" if game else "library region"] += 1
        unit = [x for x, why in p["nothrow"].items() if why.startswith("defined")]
        sure = [x for x in unit if "no boundary known" not in p["nothrow"][x]]
        lib = [x for x in p["nothrow"] if x not in unit]
        ctx = bool(p["nothrow"] or p["const"] or p["flag"])
        c["with a predicted context (a nothrow callee, a const callee or a flag)"] += ctx
        c["  ... in game code"] += ctx and game
        c["a callee above it in its unit is nothrow"] += bool(unit)
        c["  ... on a measured span"] += bool(sure)
        c["a C library or declared-nothrow callee"] += bool(lib)
        c["a const callee"] += bool(p["const"])
        c["flag predicted nsa"] += p["flag"] == "nsa"
        c["flag predicted strict"] += p["flag"] == "strict"
        c["a callee near an unsettled boundary"] += bool(p["maybe"])
    for k, v in c.items():
        print(f"{v:6}  {k}")


def cmd_prove(a):
    """Judge the near-miss drafts with the predicted context only, no search."""
    import hashlib
    import finish_near
    rows = harvest_rows()
    base_map = Map(solve(rows))
    done = project.sources(refresh=True)
    corpus = collections.defaultdict(set)
    searched = collections.defaultdict(list)
    for r in finish_near.rows():
        if r["step"] not in finish_near.STEPS:
            continue
        addr = int(r["addr"], 16)
        if r["step"] == "context":
            searched[addr].append(r)
        for key in ("draft", "best_draft"):
            if r.get(key) and os.path.exists(os.path.join(ROOT, r[key])):
                corpus[addr].add(r[key].replace("\\", "/"))
    for addr, paths in finish_near.drafts().items():
        corpus[addr].update(p.replace("\\", "/") for p in paths)
    for path in a.corpus or []:   # rows with addr and draft: an earlier corpus, matched since or not
        for r in json.load(open(path)):
            if os.path.exists(os.path.join(ROOT, r["draft"])):
                corpus[int(r["addr"], 16)].add(r["draft"].replace("\\", "/"))
    for path in a.found or []:    # what an earlier search matched: rows with addr, best [0, 0], throws
        for r in json.load(open(path)):
            if list(r.get("best") or []) == [0, 0]:
                searched[int(r["addr"], 16)].append({"matched": "search", "throws": r.get("throws"), "profile": None})
    only = {int(x, 16) for x in a.only.split(",")} if a.only else None
    work = os.path.join(OUT, "prove")
    os.makedirs(work, exist_ok=True)
    pairs, items = [], []
    for addr, paths in sorted(corpus.items()):
        if only and addr not in only:
            continue
        m = Map(solve(rows, exclude=addr)) if addr in rows else base_map
        for path in sorted(paths):
            text = open(os.path.join(ROOT, path), encoding="utf-8", errors="replace").read()
            if path.endswith(".cpp"):
                new, pred = apply(addr, text, m, a.rule == "1")
            else:  # C: no throw(), the flag only
                body, own = strip_marker(text)
                profile = flagged(own, m.flag(addr)[0], a.rule == "1")
                new, pred = (f"/* compiler: {profile} */\n" if profile else "") + body, {"profile": profile, "nothrow": {}, "const": [], "maybe": []}
            item = {"addr": addr, "draft": path, "changed": new.strip() != text.strip(), "pred": pred}
            if item["changed"]:
                sha = hashlib.sha1(new.encode("utf-8", "replace")).hexdigest()[:10]
                item["file"] = os.path.join(work, f"p{addr:08x}_{sha}{os.path.splitext(path)[1]}")
                with open(item["file"], "w", encoding="utf-8", newline="\n") as f:
                    f.write(new)
                pairs.append((addr, item["file"]))
            pairs.append((addr, os.path.join(ROOT, path)))
            items.append(item)
    log(f"prove: {len(items)} drafts of {len({i['addr'] for i in items})} functions, "
        f"{sum(1 for i in items if i['changed'])} changed by the predicted context; {len(pairs)} judge calls, {a.jobs} jobs")
    v = judge_all(list(dict.fromkeys(pairs)), a.jobs, done)
    score = lambda x: 0 if x == "match" else x[1] if isinstance(x, tuple) else None
    best = {}  # per function: its closest draft as it is, and what the prediction made of each draft
    out = open(os.path.join(OUT, "prove.jsonl"), "a")
    for i in items:
        i["base"] = score(v.get(os.path.join(ROOT, i["draft"])))
        i["predicted"] = score(v.get(i["file"])) if i["changed"] else i["base"]
        b = best.setdefault(i["addr"], {"base": None, "predicted": None, "item": None})
        if i["base"] is not None and (b["base"] is None or i["base"] < b["base"]):
            b["base"] = i["base"]
        if i["predicted"] is not None and (b["predicted"] is None or i["predicted"] < b["predicted"]):
            b["predicted"], b["item"] = i["predicted"], i
    c = collections.Counter()
    new_matches, saved = [], []
    for addr, b in sorted(best.items()):
        srch = searched.get(addr, [])
        found = any(r.get("matched") and r["matched"] != "as is" for r in srch)
        row = {"addr": f"{addr:08x}", "base": b["base"], "predicted": b["predicted"], "open": addr not in done,
               "search_matched": found, "searched": bool(srch), "rule": a.rule}
        if b["item"]:
            p = b["item"]["pred"]
            row.update(draft=b["item"]["draft"], profile=p.get("profile"), nothrow=[f"{x:08x}" for x in p["nothrow"]],
                       const=[f"{x:08x}" for x in p["const"]], maybe=[f"{x:08x}" for x in p["maybe"]])
        if b["base"] is None or b["base"] > a.max_distance:
            c["drafts out of reach (or not compiling)"] += 1
            continue
        c["functions with a draft within reach"] += 1
        c["  searched by finish_near context"] += bool(srch)
        if b["base"] == 0:
            c["draft matches as it is"] += 1
        elif b["predicted"] == 0:
            c["MATCH with the predicted context only"] += 1
            c["  of them: search matched too"] += found
            c["  of them: search ran and did not match"] += bool(srch) and not found
            c["  of them: not searched yet"] += not srch
            if addr not in done:
                new_matches.append(addr)
                if a.save:
                    rel = os.path.relpath(b["item"]["file"], ROOT)
                    row["saved"] = finish_near.save(addr, rel)
                    saved.append((addr, row["saved"]))
        else:
            if b["predicted"] is not None and b["predicted"] < b["base"]:
                c["closer with the predicted context"] += 1
            elif b["predicted"] is not None and b["predicted"] > b["base"]:
                c["worse with the predicted context"] += 1
            if found:
                c["search matched, prediction did not"] += 1
                r = next(r for r in srch if r.get("matched") and r["matched"] != "as is")
                row["search"] = {"throws": r.get("throws"), "profile": r.get("profile")}
        out.write(json.dumps(row) + "\n")
    out.close()
    for k, n in c.items():
        print(f"{n:5}  {k}")
    s_all = {addr for addr, rs in searched.items() if any(r.get("matched") and r["matched"] != "as is" for r in rs)}
    print(f"search (finish_near context) has matched {len(s_all)} functions in all; "
          f"{sum(1 for x in s_all if x in best)} of them still have their draft here")
    print("open functions matched by the prediction:", " ".join(f"{x:08x}" for x in new_matches) or "none")
    for addr, msg in saved:
        print(f"  {addr:08x}: {msg}")
    for line in open(os.path.join(OUT, "prove.jsonl")).read().splitlines()[-len(best):]:
        r = json.loads(line)
        if r.get("search") and r["rule"] == a.rule:
            print(f"  miss {r['addr']}: search throw() on {r['search']['throws']} {r['search']['profile']}; "
                  f"predicted {r.get('nothrow')} {r.get('profile') or 'default'}, maybe {r.get('maybe')}; {r['base']} -> {r['predicted']}")


def main():
    import argparse
    sys.setrecursionlimit(20000)  # purity() follows call chains
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("build")
    p.add_argument("--check", action="store_true")
    for name in ("predict", "context"):
        p = sub.add_parser(name)
        p.add_argument("addr", type=lambda x: int(x, 16))
    p = sub.add_parser("apply")
    p.add_argument("addr", type=lambda x: int(x, 16))
    p.add_argument("file")
    p = sub.add_parser("prove")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--save", action="store_true", help="save the matches of open functions (finish_near.save)")
    p.add_argument("--max-distance", type=int, default=20)
    p.add_argument("--only")
    p.add_argument("--rule", default="2", help="a label for this run in build/units/prove.jsonl; 1: the first flag "
                   "rule (a predicted strict flag removes a draft's marker)")
    p.add_argument("--corpus", action="append", help="JSON rows (addr, draft) of more drafts, matched since or not")
    p.add_argument("--found", action="append", help="JSON rows (addr, best, throws) of what a search matched")
    sub.add_parser("open")
    a = ap.parse_args()
    {"build": cmd_build, "predict": cmd_predict, "context": cmd_context, "apply": cmd_apply,
     "prove": cmd_prove, "open": cmd_open}[a.cmd](a)


if __name__ == "__main__":
    main()
