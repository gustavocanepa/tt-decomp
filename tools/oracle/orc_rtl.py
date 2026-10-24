"""Readers for what the compiler prints: RTL dumps (`-da`), the assembler listing, MIPS words.

Nothing here is specific to one game; the register numbering is gcc's for MIPS (0-31 integer,
32-63 floating point), the dump formats are those of gcc 2.9x.
"""
import collections
import re

REGS = "zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra".split()
CALLEE_SAVED = set(range(16, 24)) | {30} | set(range(52, 64))


def regname(h):
    if h is None or h < 0:
        return "stack"
    return "$" + REGS[h] if h < 32 else f"$f{h - 32}" if h < 64 else f"hard{h}"


# ---------------------------------------------------------------- machine words

def fields(word):
    """(opcode key, {field: gcc hard register}): immediates and jump targets are left out of the
    key, so relocated words compare equal; FP registers are 32 + n as in gcc."""
    op = word >> 26
    rs, rt, rd, sa, fn = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31, word & 63
    if op == 0:
        return (0, fn), {"rs": rs, "rt": rt, "rd": rd}
    if op == 0x1C:
        return (op, fn, sa), {"rs": rs, "rt": rt, "rd": rd}
    if op == 1:
        return (1, rt), {"rs": rs}
    if op in (2, 3):
        return (op,), {}
    if op == 0x11:
        if rs in (0, 1, 4, 5):      # mfc1 dmfc1 mtc1 dmtc1
            return (op, rs), {"rt": rt, "fs": 32 + rd}
        if rs == 8:                 # bc1f/bc1t(l)
            return (op, rs, rt), {}
        if rs in (16, 17, 20, 21):
            return (op, rs, fn), {"ft": 32 + rt, "fs": 32 + rd, "fd": 32 + sa}
        return (op, rs, rt, rd), {}
    if op in (0x31, 0x39, 0x35, 0x3D):  # lwc1 swc1 ldc1 sdc1
        return (op,), {"rs": rs, "ft": 32 + rt}
    return (op,), {"rs": rs, "rt": rt}


LIKELY = {0x14: 4, 0x15: 5, 0x16: 6, 0x17: 7}  # beql bnel blezl bgtzl -> beq bne blez bgtz


def shape(word):
    """The opcode key with branch-likely folded into the plain branch (for alignment only)."""
    key, _ = fields(word)
    if key[0] in LIKELY:
        return (LIKELY[key[0]],) + key[1:]
    if key[0] == 1 and key[1] in (2, 3):       # bltzl bgezl
        return (1, key[1] - 2)
    if key[0] == 0x11 and len(key) == 3 and key[1] == 8:
        return (0x11, 8, key[2] & 1)
    return key


def transfers(word):
    """Does the instruction have a delay slot?"""
    op, fn = word >> 26, word & 63
    return op in (1, 2, 3, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or (op == 0 and fn in (8, 9)) or \
        (op == 0x11 and (word >> 21) & 31 == 8)


def is_likely(word):
    """A branch-likely form (the delay slot is annulled when the branch is not taken)."""
    op, rt = word >> 26, (word >> 16) & 31
    return op in LIKELY or (op == 1 and rt in (2, 3, 18, 19)) or (op == 0x11 and (word >> 21) & 31 == 8 and bool(rt & 2))


def nodisp(word):
    """A word without its branch displacement (the likely bit stays)."""
    op = word >> 26
    if op in (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or (op == 0x11 and (word >> 21) & 31 == 8):
        return word & 0xFFFF0000
    return word


def bag_distance(mine, target):
    """How many instructions one side has that the other has not, whatever their order."""
    a, b = collections.Counter(map(nodisp, mine)), collections.Counter(map(nodisp, target))
    return max(sum((a - b).values()), sum((b - a).values()))


def canon(word):
    """A word as it compares across positions and delay-slot decisions: a branch without its
    displacement and without its likely bit."""
    op, rt = word >> 26, (word >> 16) & 31
    if op in (4, 5, 6, 7):
        return word & 0xFFFF0000
    if op in LIKELY:
        return (LIKELY[op] << 26) | (word & 0x03FF0000)
    if op == 1 and rt in (0, 1, 2, 3, 16, 17, 18, 19):
        return (word & 0xFFE00000) | ((rt & ~2) << 16)
    if op == 0x11 and (word >> 21) & 31 == 8:
        return word & 0xFFFD0000
    return word


_FIELD_AT = {"rs": 21, "rt": 16, "rd": 11, "fs": 11, "ft": 16, "fd": 6}


def skeleton(word):
    """canon() with every register field reduced to "is it $zero": two instructions with one
    skeleton differ only in which registers they name."""
    w = canon(word)
    _, f = fields(word)
    for name, reg in f.items():
        at = _FIELD_AT[name]
        w = (w & ~(31 << at)) | ((31 if reg else 0) << at)
    return w


def written(word):
    """The hard register the instruction writes (gcc's number), or None."""
    _, f = fields(word)
    name = dest_field(word)
    reg = f.get(name) if name else None
    return reg if reg else None


def align_words(mine, target):
    """[(i, j)] pairing my instructions with the original's when order may differ too: runs
    equal up to branch form first, then inside each gap the instructions that are equal but
    for their registers, the k-th with the k-th."""
    import difflib
    cm, ct = [canon(w) for w in mine], [canon(w) for w in target]
    pairs, a0, b0 = [], 0, 0
    for blk in difflib.SequenceMatcher(None, cm, ct, autojunk=False).get_matching_blocks():
        where = collections.defaultdict(list)
        for j in range(b0, blk.b):
            where[skeleton(target[j])].append(j)
        for i in range(a0, blk.a):
            js = where.get(skeleton(mine[i]))
            if js:
                pairs.append((i, js.pop(0)))
        pairs += [(blk.a + k, blk.b + k) for k in range(blk.size)]
        a0, b0 = blk.a + blk.size, blk.b + blk.size
    return sorted(pairs)


def unmatched(mine, target):
    """(indices only in mine, indices only in the original) by skeleton, nops aside: the
    instructions no choice of register, order or branch form accounts for."""
    def key(w):
        # a stack slot's offset and the frame size follow from the registers saved
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if rs == 29 and (op >= 0x20 or op in (0x1A, 0x1B) or (op in (9, 0x19) and rt == 29)):
            w &= 0xFFFF0000
        return skeleton(w)

    left = collections.defaultdict(list)
    for j, w in enumerate(target):
        if w:
            left[key(w)].append(j)
    only_mine = []
    for i, w in enumerate(mine):
        if not w:
            continue
        js = left.get(key(w))
        if js:
            js.pop(0)
        else:
            only_mine.append(i)
    return only_mine, sorted(j for js in left.values() for j in js)


def source_pair(word):
    """The two source fields of a commutative instruction, or None."""
    op, rs, fn = word >> 26, (word >> 21) & 31, word & 63
    if op == 0 and fn in (0x18, 0x19, 0x20, 0x21, 0x24, 0x25, 0x26, 0x27, 0x2C, 0x2D):
        return ("rs", "rt")
    if op == 0x1C and fn in (0x00, 0x01, 0x18, 0x19, 0x20, 0x21):
        return ("rs", "rt")
    if op in (4, 5, 0x14, 0x15):
        return ("rs", "rt")
    if op == 0x11 and rs == 16 and fn in (0, 2, 0x18, 0x1A, 0x1C, 0x32):
        return ("fs", "ft")
    return None


def dest_field(word):
    """Name of the field the instruction writes, or None."""
    op = word >> 26
    rs, fn = (word >> 21) & 31, word & 63
    if op == 0:
        if fn in (8, 0x11, 0x13, 0x0C, 0x0D, 0x1A, 0x1B) or 0x30 <= fn <= 0x36:
            return None
        return "rd"
    if op == 0x1C:
        return None if fn in (0x11, 0x13, 0x1A, 0x1B) else "rd"
    if op in (1, 2, 3, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17):
        return None
    if op == 0x11:
        if rs in (0, 1, 2):
            return "rt"
        if rs in (4, 5):
            return "fs"
        if rs in (16, 17, 20, 21):
            return None if fn >= 48 or fn in (24, 25, 26, 30, 31) else "fd"
        return None
    if op in (0x31, 0x35):
        return "ft"
    if op in (0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x3F, 0x1F, 0x39, 0x3D):
        return None
    return "rt"


# ---------------------------------------------------------------- assembler listing

_LIST = re.compile(r"\s*\d+\s+([0-9a-f]{4,8})\s+((?:[0-9A-F]{8}[ ]?)+)(?:\s+(.*))?$")
_UID = re.compile(r"#\s*(\d+)\t\S+(?:\t\[length = \d+\])?\s*$")


def listing_uids(path):
    """{object offset: insn uid or None} from an assembler listing of `-dp` output."""
    uid_at, uid = {}, None
    for line in open(path, errors="replace"):
        m = _LIST.match(line.rstrip("\n"))
        if not m:
            continue
        text = m.group(3) or ""
        if text.strip():
            u = _UID.search(text)
            uid = int(u.group(1)) if u else None
        off = int(m.group(1), 16)
        for k in range(len(m.group(2).split())):
            uid_at[off + 4 * k] = uid
    return uid_at


def asm_functions(path):
    """Names in `.ent` order from compiler output."""
    return re.findall(r"^\s*\.ent\s+(\S+)", open(path, errors="replace").read(), re.M)


# ---------------------------------------------------------------- RTL dumps

_FORM = re.compile(r"^\((insn|jump_insn|call_insn|note|code_label|barrier)\b|^;; Start of basic block (\d+), registers live:(.*)$", re.M)
_TOKEN = re.compile(r'"(?:[^"\\]|\\.)*"|[()\[\]]|[^\s()\[\]"]+')


def sexp(text):
    """One printed RTL form as nested lists of strings."""
    stack, cur = [], []
    for tok in _TOKEN.findall(text):
        if tok in "([":
            stack.append(cur)
            cur = []
        elif tok in ")]":
            if not stack:
                break
            done, cur = cur, stack.pop()
            cur.append(done)
        else:
            cur.append(tok)
    while stack:
        done, cur = cur, stack.pop()
        cur.append(done)
    return cur[0] if cur and isinstance(cur[0], list) else cur


def _is_reg(node):
    return isinstance(node, list) and node and isinstance(node[0], str) and re.match(r"reg(/\w)*(:\w+)?$", node[0]) \
        and len(node) > 1 and isinstance(node[1], str) and node[1].isdigit()


def _regs(node, out):
    if _is_reg(node):
        out.add(int(node[1]))
    elif isinstance(node, list):
        for child in node:
            _regs(child, out)


def _pattern(node, sets, uses, clobbers):
    if not isinstance(node, list) or not node:
        return
    head = node[0] if isinstance(node[0], str) else ""
    if head.startswith("set") and len(node) >= 3 and head.split(":")[0].split("/")[0] == "set":
        dest = node[1]
        partial = False
        while isinstance(dest, list) and dest and isinstance(dest[0], str) and \
                dest[0].split(":")[0].split("/")[0] in ("subreg", "strict_low_part", "zero_extract", "sign_extract"):
            partial = partial or dest[0].startswith(("strict_low_part", "zero_extract", "sign_extract"))
            for extra in dest[2:]:
                _regs(extra, uses)
            dest = dest[1]
        if _is_reg(dest):
            sets.add(int(dest[1]))
            if partial:
                uses.add(int(dest[1]))
        else:
            _regs(dest, uses)
        _regs(node[2], uses)
    elif head.startswith("clobber"):
        if len(node) > 1 and _is_reg(node[1]):
            clobbers.add(int(node[1][1]))
        elif len(node) > 1:
            _regs(node[1], uses)
    elif head.startswith("parallel") or head.startswith("sequence") or not head:
        for child in node[1:] if head else node:
            _pattern(child, sets, uses, clobbers)
    else:
        _regs(node, uses)


def _notes(node, dead, unused):
    while isinstance(node, list) and len(node) >= 2 and isinstance(node[0], str):
        kind = node[0]
        if kind.endswith(":REG_DEAD") and _is_reg(node[1]):
            dead.add(int(node[1][1]))
        elif kind.endswith(":REG_UNUSED") and _is_reg(node[1]):
            unused.add(int(node[1][1]))
        node = node[2] if len(node) > 2 else None


Insn = collections.namedtuple("Insn", "uid kind block sets uses clobbers dead unused line text")


def split_functions(text):
    """[(header, body)] of a dump, one per `;; Function` section."""
    parts = re.split(r"^;; Function (.*)$", text, flags=re.M)
    return [(parts[i].strip(), parts[i + 1]) for i in range(1, len(parts) - 1, 2)]


def parse_insns(body):
    """(insns in dump order, {block: live at start}) of one function's section of a dump."""
    marks = list(_FORM.finditer(body))
    insns, live_in = [], {}
    block, line = None, None
    for i, m in enumerate(marks):
        end = marks[i + 1].start() if i + 1 < len(marks) else len(body)
        if m.group(2) is not None:
            block = int(m.group(2))
            live_in[block] = {int(x) for x in re.sub(r"\[[^\]]*\]", " ", m.group(3)).split() if x.isdigit()}
            continue
        kind = m.group(1)
        chunk = body[m.start():end]
        cut = chunk.find("\n;;")
        if cut >= 0:
            chunk = chunk[:cut]
        if kind == "note":
            ln = re.match(r'\(note \d+ \d+ \d+ \("[^"]*"\) (\d+)(?: \d+)?\)', chunk)
            if ln:
                line = int(ln.group(1))
            continue
        if kind in ("code_label", "barrier"):
            continue
        form = sexp(chunk)
        try:
            uid = int(form[1])
        except (ValueError, IndexError, TypeError):
            continue
        sets, uses, clobbers, dead, unused = set(), set(), set(), set(), set()
        pattern = form[4] if len(form) > 4 else None
        _pattern(pattern, sets, uses, clobbers)
        for extra in form[5:]:
            if isinstance(extra, list) and extra and isinstance(extra[0], str):
                if extra[0].startswith("expr_list:REG_") or extra[0].startswith("insn_list:REG_"):
                    _notes(extra, dead, unused)
                elif extra[0] == "expr_list":      # CALL_INSN_FUNCTION_USAGE
                    _regs(extra, uses)
        insns.append(Insn(uid, kind, block, sets, uses, clobbers, dead, unused, line, chunk))
    return insns, live_in


def conflict_graph(insns, live_in):
    """{reg: set of regs live when it is set}, as global.c's global_conflicts builds it: inputs
    that die in an insn do not conflict with its outputs, clobbers do."""
    graph = collections.defaultdict(set)
    live, block = set(), None
    for ins in insns:
        if ins.block != block:
            block = ins.block
            live = set(live_in.get(block, ()))
        for c in ins.clobbers:
            for other in live:
                if other != c:
                    graph[c].add(other)
                    graph[other].add(c)
        live -= ins.dead
        for s in ins.sets | ins.clobbers:
            for other in live:
                if other != s:
                    graph[s].add(other)
                    graph[other].add(s)
        live |= ins.sets
        live -= ins.unused
        live -= {c for c in ins.clobbers if c in ins.unused}
    return graph


# `; set N times` is absent for a register never set (gcc 2.9 prints it only when N is not zero)
_STAT = re.compile(r"^Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?(?:; set (\d+) times?)?(.*)$", re.M)


def pseudo_stats(body):
    """{pseudo: {refs, length, block, sets, user, calls}} from the lreg dump's register table."""
    out = {}
    for m in _STAT.finditer(body):
        rest = m.group(6)
        calls = re.search(r"crosses (\d+) calls?", rest)
        out[int(m.group(1))] = {"refs": int(m.group(2)), "length": int(m.group(3)),
                                "block": int(m.group(4)) if m.group(4) else None, "sets": int(m.group(5) or 0),
                                "user": "user var" in rest, "calls": int(calls.group(1)) if calls else 0,
                                "pointer": "pointer" in rest}
    return out


def dispositions(body):
    """{pseudo: hard register} from a greg dump's `;; Register dispositions:` (the final homes)."""
    if ";; Register dispositions:" not in body:
        return {}
    part = body.split(";; Register dispositions:", 1)[1].split("\n\n", 1)[0]
    return {int(p): int(h) for p, h in re.findall(r"(\d+) in (\d+)", part)}


def global_order(body):
    """The pseudos in global's order. An entry may carry the pseudos sharing its allocno
    (`100+103`) and its size in words when that is not one (`100 (2)`)."""
    m = re.search(r";; \d+ regs to allocate:([^\n]*)", body)
    return [int(x) for x in re.findall(r"(?<![+(\d])(\d+)", m.group(1))] if m else []


def barriers(body):
    """{insn uid: note kind} for the insns that follow a note the scheduler treats as a barrier
    (a loop's beginning or end, an exception region): nothing is moved across them."""
    out, pending = {}, None
    for m in re.finditer(r"^\((insn|jump_insn|call_insn|note|code_label|barrier)(?:/\w)* (\d+) \d+ \d+(?: (NOTE_INSN_\w+))?", body, re.M):
        if m.group(1) == "note":
            if m.group(3) in ("NOTE_INSN_LOOP_BEG", "NOTE_INSN_LOOP_END", "NOTE_INSN_EH_REGION_BEG", "NOTE_INSN_EH_REGION_END",
                              "NOTE_INSN_SETJMP", "NOTE_INSN_RANGE_START", "NOTE_INSN_RANGE_END"):
                pending = m.group(3)
        elif m.group(1) in ("insn", "jump_insn", "call_insn"):
            if pending:
                out[int(m.group(2))] = pending
            pending = None
    return out


def line_notes(body, keep_order=False):
    """{uid: source line} from a dump in emission order (the .rtl dump: nothing moved yet); with
    keep_order the list [(uid, line)] of the real insns in order. Lines exist only under -g."""
    out, line = [], None
    for m in re.finditer(r'^\((insn|jump_insn|call_insn|note)(?:/\w)* (\d+) \d+ \d+(?: \("[^"]*"\) (\d+)(?: \d+)?\))?', body, re.M):
        if m.group(1) == "note":
            if m.group(3):
                line = int(m.group(3))
        else:
            out.append((int(m.group(2)), line))
    return out if keep_order else dict(out)
