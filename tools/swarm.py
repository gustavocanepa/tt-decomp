#!/usr/bin/env python3
"""Work allocation and per-function steps for the matching swarm (one lead, N subagents).

Lead (one process, serial):
    swarm.py status                                   progress, leases, size tiers
    swarm.py areas [--max-bytes 256] [--limit 25]     areas (translation units) with work left
    swarm.py assign WORKER [--count 6] [--max-bytes 256] [--min-bytes 8] [--area NAME | --new-area] [--deferred]
                                                      lease the next functions of one area to WORKER
    swarm.py assign WORKER --certified [--tier T] [--count N]
                                                      first the functions whose closest kept draft the
                                                      oracle certified logic-complete or left within a
                                                      few instructions, closest first, whatever their
                                                      area (tools/retry_brief.py queue); the usual
                                                      queue once none is left
    swarm.py start                                    session start: drop stale leases, warm caches
    swarm.py release WORKER | --all                   drop a worker's leases

Worker (any number in parallel, each in build/swarm/WORKER/; workers also run assign/release
for themselves, so the lead only keeps slots filled):
    swarm.py rules                                    compiler rules + knowledge (read once)
    swarm.py prompt ADDR                              everything known about one function, with the
                                                      retry report when drafts of it are kept: the
                                                      closest one, the oracle's certificate, the
                                                      decisions that differ (tools/retry_brief.py)
    swarm.py try ADDR FILE                            judge FILE; on MATCH it is saved to src/,
                                                      else its text is kept (tools/attempt_store.py).
                                                      A C++ near miss is first judged once more with
                                                      the translation-unit context tools/unit_map.py
                                                      predicts written in (predicted_context).
                                                      A draft off only by branches against their
                                                      branch-likely forms is first searched for the
                                                      callees to declare `throw()` (nothrow_closure)
    swarm.py giveup ADDR ATTEMPTS [--best N] [--note TEXT]
                                                      record a function as deferred

An area is a translation unit from config/units.txt; within it functions go in address order,
so one worker keeps the same class and its neighbours in context. Each exact-copy group is
represented once (tools/dedup_all.py settles the copies). Leases live in build/swarm/leases.json
and only the lead writes them. Results go to build/auto/log.jsonl.
"""
import argparse
import bisect
import csv
import json
import os
import re
import shutil
import subprocess
import sys
import threading
import time

try:
    import fcntl
except ImportError:  # Windows Python: only the lead writes leases, one command at a time.
    fcntl = None

import asm_policy
import attempts
import match
import project
import symbols

ROOT = match.ROOT
AUTO = os.path.join(ROOT, "build", "auto")
LOG = os.path.join(AUTO, "log.jsonl")
SWARM = os.path.join(ROOT, "build", "swarm")
LEASES = os.path.join(SWARM, "leases.json")
M2C = os.path.join(ROOT, "tools", "ext", "m2c", "m2c.py")

SYSTEM = f"""You write C++ that {project.CONFIG["compiler"]["name"]} ({project.compiler_command().split(" -c ", 1)[-1]})
compiles to exactly the instructions of a given function from {project.CONFIG["game"]["name"]}. Each draft is a
complete, self-contained translation unit: declare every struct, global and callee you use (extern), then
define the function with the exact name given. No headers. Matching is judged instruction by instruction;
addresses filled by the linker (call targets, %hi/%lo of globals) only need the right opcode and registers.

Conventions:
- Name globals D_XXXXXXXX (char arrays or typed externs) and callees func_XXXXXXXX.
- Model offsets with explicit char padding fields in structs.
- Write C that is also valid C++ (always the `struct` keyword, no classes, references, templates or
  default arguments) unless the function needs C++ (virtual calls, constructors): it is compiled as C++.
- No assembly posing as C: only single-instruction intrinsics (e.g. sqrt.s) may be inline asm.
- Never use goto unless nothing else works.

{{knowledge}}"""


def rules():
    return SYSTEM.replace("{knowledge}", project.knowledge())




def plain(words, addr=None):
    """Ordinary instructions from a compiler we have: the game's, or the SDK's for listed functions."""
    for x in words:
        op = x >> 26
        if op in (0x10, 0x12, 0x1C, 0x2F, 0x36, 0x3E, 0x1E, 0x1F):
            return False  # COP0, COP2/VU, MMI, cache, lqc2/sqc2, lq/sq
        if op == 0 and (x & 0x3F) in (0x0C, 0x0F):
            return False  # syscall, sync
    return addr in sdk_functions() or not other_compiler(words)


def other_compiler(words):
    """True for code built by another compiler (the Sony SDK libraries): its prologue saves the
    callee-saved registers 16 bytes apart, where the game's ee-gcc 2.96 packs them 8 apart."""
    # Saves can be interleaved with argument setup and occupy the first call's
    # delay slot. A fixed sixteen-instruction prefix can omit a middle save,
    # turning a real sixteen-byte sequence into apparent mixed gaps.
    prefix = words[:64]
    for index, word in enumerate(prefix):
        opcode = word >> 26
        control = (opcode in (1, 2, 3, 4, 5, 6, 7, 20, 21, 22, 23)
                   or (opcode == 0 and word & 63 in (8, 9))
                   or (opcode in (16, 17, 18) and (word >> 21) & 31 == 8))
        if control:
            prefix = prefix[:index + 2]  # Include the transfer's delay slot.
            break
    offsets = []
    for x in prefix:
        if x >> 26 == 0x3F and (x >> 21) & 31 == 29:  # sd $rt, off($sp)
            rt = (x >> 16) & 31
            if 16 <= rt <= 23 or rt in (30, 31):
                offsets.append(x & 0xFFFF)
    offsets.sort()
    gaps = {b - a for a, b in zip(offsets, offsets[1:])}
    # Two saves suffice: no function matched with 2.96 has two saves 16 apart (checked 2026-10-11).
    return len(offsets) >= 2 and gaps == {16}


def link_rejects():
    """Addresses whose source matched the judge and then differed after linking (written by
    tools/integrate.py when it sets one aside): `try` does not save them again and the queues skip
    them, or the same draft comes back every round and costs a full build each time."""
    path = os.path.join(SWARM, "link_rejects.txt")
    if not os.path.exists(path):
        return set()
    return {int(x.split()[0], 16) for x in open(path) if x.strip() and not x.startswith("#")}


def done_addrs():
    """Matched (a source anywhere under src/, project.sources) or hand-written assembly."""
    out = set(project.sources(refresh=True))
    # Functions written in assembly in the original are not decompilation targets.
    asm_list = os.path.join(ROOT, "config", "asm_functions.txt")
    if os.path.exists(asm_list):
        for line in open(asm_list):
            if line.strip() and not line.startswith("#"):
                out.add(int(line.split()[0], 16))
    return out






def strings_used(addr, sections):
    """Printable strings at addresses the function builds with lui + addiu/ori/load."""
    asm = match.gnu_asm(addr)
    hi = {}
    found = {}
    for line in asm.splitlines():
        m = re.search(r"\*/\s+(\w+)\s+\$(\w+),\s*(.*)", line)
        if not m:
            continue
        op, reg, rest = m.groups()
        if op == "lui":
            hi[reg] = int(rest, 16) << 16
            continue
        m2 = re.match(r"\$(\w+),\s*(-?0x[0-9A-Fa-f]+)$", rest) or re.match(r"(-?0x[0-9A-Fa-f]+)\(\$(\w+)\)$", rest)
        if not m2:
            continue
        if op in ("addiu", "ori") and m2.re.pattern.startswith(r"\$"):
            base, imm = m2.group(1), int(m2.group(2), 16)
        elif m2.re.pattern.startswith("(-"):
            imm, base = int(m2.group(1), 16), m2.group(2)
        else:
            continue
        if base not in hi:
            continue
        target = hi[base] + imm
        for a, blob in sections:
            if a <= target < a + len(blob):
                end = blob.find(b"\0", target - a, target - a + 200)
                s = blob[target - a:end] if end > 0 else b""
                if len(s) >= 2 and all(32 <= c < 127 or c in (9, 10) for c in s):
                    found[target] = s.decode("ascii")
    return found


def m2c_draft(addr):
    directory = os.path.join(SWARM, "m2c")
    os.makedirs(directory, exist_ok=True)
    path = os.path.join(directory, f"{addr:08x}.s")
    with open(path, "w") as f:
        f.write(match.gnu_asm(addr))
    res = subprocess.run([sys.executable, M2C, "-t", project.CONFIG["cpu"]["m2c_target"], path], capture_output=True, text=True)
    return (res.stdout or res.stderr).strip()[:6000]


def check(addr, path):
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:x}", path],
                         capture_output=True, text=True)
    out = (res.stdout + res.stderr).strip()
    return res.returncode == 0, out


def mnemonics(addr):
    out = []
    for line in match.gnu_asm(addr).splitlines():
        m = re.search(r"\*/\s+(\S+)", line)
        if m:
            out.append(m.group(1))
    return out


MNEMONICS = os.path.join(SWARM, "mnemonics.json")


def solved_mnemonics():
    """{addr: mnemonics} of every solved function. The original instructions never change, so
    the cache only grows: disassembling all of src/ takes over a minute, a cached load a moment."""
    try:
        with open(MNEMONICS) as f:
            cache = json.load(f)
    except (OSError, ValueError):
        cache = {}
    out, missing = {}, False
    for addr_, name in sorted(project.sources().items()):
        key = f"{addr_:08X}"
        if key not in cache:
            missing = True
            try:
                cache[key] = mnemonics(int(key, 16))
            except SystemExit:
                # Sources can include pointer-only functions absent from functions.csv.
                cache[key] = []
        out[int(key, 16)] = (cache[key], name)
    if missing:
        os.makedirs(SWARM, exist_ok=True)
        tmp = f"{MNEMONICS}.{os.getpid()}.{threading.get_ident()}"
        with open(tmp, "w") as f:
            json.dump(cache, f)
        os.replace(tmp, MNEMONICS)  # parallel writers (processes and threads): last complete file wins
    return out


def similar_examples(addr, count=4):
    """The solved functions whose instruction sequences look most like this one."""
    target = mnemonics(addr)
    grams = set(zip(target, target[1:]))
    scored = []
    for other_addr, (other, name) in solved_mnemonics().items():
        if other_addr == addr:
            continue
        og = set(zip(other, other[1:]))
        if not og:
            continue
        score = len(grams & og) / len(grams | og) - abs(len(other) - len(target)) / (4 * max(len(target), 1))
        scored.append((score, other_addr, name))
    scored.sort(reverse=True)
    picked, seen = [], set()
    for score, a, name in scored:
        source = open(name, encoding="utf-8").read()
        body = re.sub(r"func_[0-9A-F]{8}|D_[0-9A-F]{8}", "", source)
        if body in seen:  # copies of one function teach nothing new
            continue
        seen.add(body)
        picked.append((a, source))
        if len(picked) == count:
            break
    return picked


_names = {}


def rtti_name(addr):
    """Name tools/rtti.py gave the function (class and vtable slot), if any."""
    if not _names:
        path = os.path.join(ROOT, "config", "symbol_addrs.txt")
        if os.path.exists(path):
            for line in open(path):
                parts = line.split("=")
                if len(parts) == 2 and "type:func" in line:
                    _names[int(parts[1].split(";")[0].strip(), 16)] = parts[0].strip()
        _names.setdefault(-1, "")
    return _names.get(addr)


def callee_context(addr):
    """For each function this one calls: its RTTI name and, if solved, its declaration."""
    out = []
    targets = sorted(set(int(t[5:], 16) for t in re.findall(r"func_[0-9A-F]{8}", match.gnu_asm(addr))))
    for target in targets:
        if target == addr:
            continue
        line = f"func_{target:08X}"
        name = rtti_name(target)
        if name:
            line += f" ({name})"
        src = project.source_for(target)
        if src:
            text = open(src, encoding="utf-8").read()
            real = symbols.name_of(target)
            names = f"func_{target:08X}" + (f"|{re.escape(real)}" if real else "")
            m = re.search(r"^[^;{}\n]*\b(?:%s)\b[^;{]*\)" % names, text, re.M)
            if m:
                line += f": solved, defined as `{m.group(0).strip()}`"
        out.append(line)
    return out


def hints(addr):
    """Facts read straight off the assembly, stated per function (models skip general rules)."""
    text_addr, text = match.load_text()
    words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
    out = []
    if len(words) >= 2:
        tail = [w for w in words if w != 0][-2:]
        if tail and tail[0] >> 26 == 2:  # j target, then the delay slot: a tail call
            target = ((addr & 0xF0000000) | ((tail[0] & 0x03FFFFFF) << 2))
            out.append(f"It ends with a tail call (`j func_{target:08X}`): write "
                       f"`return func_{target:08X}(...);` and give both functions a non-void return type.")
    if any(w >> 26 == 0x11 and ((w >> 21) & 31) in (0x10, 0x11) for w in words):
        out.append("It does floating-point arithmetic: float parameters arrive in $f12, $f13, ... "
                   "and a float result is returned in $f0.")
    return out


def sdk_facts(addr):
    """For a function the SDK compiler builds: which compiler. Its habits come from its knowledge
    file, when there is one."""
    if addr not in sdk_functions():
        return []
    out = [f"Built by Sony ee-gcc 2.9 (the SDK libraries' compiler), not the game's: write plain C, "
           f"save the draft as .c, and make its FIRST line `{SDK_MARKER}` (the judge and the build "
           f"compile it with that compiler only then)."]
    knowledge = project.path("knowledge/ee-gcc-2.9.md")
    if os.path.exists(knowledge):
        out.append("Compiler habits:\n" + open(knowledge, encoding="utf-8").read().strip())
    return out


SDK_MARKER = "/* compiler: ee-gcc2.9-991111 */"


def sdk_functions():
    """Addresses built by the SDK compiler (config/compiler_sdk.txt, one address per line; none
    when the file is absent): their prompts ask for the SDK_MARKER first line."""
    if "sdk" not in _cache:
        path = project.path("config/compiler_sdk.txt")
        _cache["sdk"] = {int(l.split()[0], 16) for l in open(path) if l.strip() and not l.startswith("#")} \
            if os.path.exists(path) else set()
    return _cache["sdk"]


_cache = {}


LIBRARY_START = 0x5547E8  # Sony's libraries and third-party code from here on


def upstream_facts(addr):
    """What the CPU tools know: the queue's suggested approach, the family, the closest automatic
    draft (cpu_solve / near_fix / region), and the compiler profile to try for library code."""
    out = []
    it = queue_items().get(addr)
    if it and it.get("approach"):
        out.append(f"Work queue suggests: {it['approach']}")
    try:
        fams, index = attempts.families_index()
        fam = index.get(f"{addr:08x}")
        if fam is not None:
            out.append(f"Family {fam}: functions of the same shape (`python3 tools/families.py show {fam}`); "
                       "once this one matches, `python3 tools/siblings.py scan -j4` derives members that "
                       "differ only in constants, addresses and callees")
    except Exception:
        pass
    drafts = sorted(attempts.best_results().get(f"{addr:08x}", []))
    if drafts:
        differ, of, tool, path = drafts[0]
        out.append(f"Closest automatic draft: {differ} of {of} instructions differ ({tool}), {path}: "
                   "start from it (it compiles; M2C_* macros come from include/m2c_macros.h)")
    if addr >= LIBRARY_START and addr not in sdk_functions():
        out.append("Library code: if a near miss resists, try the profile the game's libraries use: first "
                   "line `/* compiler: ee-gcc2.96-no-strict-aliasing */`")
    return out


def types_context(addr):
    """Declarations the type database knows for the callees and globals the original references
    (tools/types_db.py: prototypes with the real argument order and types, globals, layouts)."""
    try:
        import types_db
        return types_db.context_for(match.gnu_asm(addr), addr) or ""
    except Exception:
        return ""


def earlier_attempts(addr):
    """What earlier tiers learned about addr (escalation): one line per give-up, newest last."""
    out = []
    for r in log_rows():
        if r.get("matched") is False and int(r["addr"], 16) == addr and (r.get("note") or r.get("best") is not None):
            out.append(f"Earlier attempt ({row_tier(r)}, best {r.get('best', '?')} differing): {r.get('note', '')}")
    diary = [r for r in attempts.load() if r.get("addr") == f"{addr:08x}" and r.get("result") != "match"]
    out += [f"Diary ({r.get('who', '?')}, {r.get('result')}): {r.get('hypothesis', '')[:300]}" for r in diary[-3:]]
    return out[-5:]


def retry_report(addr):
    """What a retry starts from (tools/retry_brief.py): the closest kept draft, whether the oracle
    certified its logic, the compiler decisions that differ in the draft's own terms with the edits
    the rules give for them, and the unit map's predicted context. [] when there is nothing to say;
    SWARM_NO_BRIEF=1 turns it off; nothing that goes wrong there reaches the prompt."""
    if os.environ.get("SWARM_NO_BRIEF"):
        return []
    try:
        import retry_brief
        text = retry_brief.report(addr)
    except (Exception, SystemExit):
        return []
    return [text + "\n"] if text else []


def first_prompt(addr, sections):
    strings = strings_used(addr, sections)
    parts = []
    for a, source in similar_examples(addr):
        parts.append(f"Solved example (func_{a:08X}, matches exactly):\n```\n" + match.gnu_asm(a) +
                     "```\n```cpp\n" + source.strip() + "\n```\n")
    facts = hints(addr)
    name = rtti_name(addr)
    if name:
        facts.insert(0, f"RTTI names this function {name} (class and vtable slot from the game's own type info)")
    callees = callee_context(addr)
    if callees:
        facts.append("Functions it calls: " + "; ".join(callees))
    facts = sdk_facts(addr) + facts + upstream_facts(addr) + earlier_attempts(addr)
    parts += [f"Now the function to write: func_{addr:08X}\n" + "".join(f"- {h}\n" for h in facts),
              *retry_report(addr),
              "Original assembly:\n```\n" + match.gnu_asm(addr) + "```\n",
              "m2c draft (types and names are guesses):\n```c\n" + m2c_draft(addr) + "\n```\n"]
    context = types_context(addr)
    if context:
        parts.append("Known declarations from the type database (real prototypes, globals and struct "
                     "layouts; prefer them to guessed ones, or #include the class header "
                     "include/gt4/<Class>.h):\n```c\n" + context[:6000] + "\n```\n")
    if strings:
        parts.append("Strings at addresses the code builds (use them as literals if they fit):\n" +
                     "\n".join(f"  0x{a:08X}: {json.dumps(s)}" for a, s in sorted(strings.items())) + "\n")
    parts.append(f"Write func_{addr:08X} so that it matches.")
    return "\n".join(parts)




# ---------------------------------------------------------------- allocation

class Lock:
    def __enter__(self):
        os.makedirs(SWARM, exist_ok=True)
        self.f = open(os.path.join(SWARM, "lock"), "w")
        if fcntl:
            fcntl.flock(self.f, fcntl.LOCK_EX)
        return self

    def __exit__(self, *a):
        self.f.close()


def load_leases():
    if os.path.exists(LEASES):
        with open(LEASES) as f:
            return json.load(f)
    return {"leases": {}, "last_area": {}}


def save_leases(state):
    os.makedirs(SWARM, exist_ok=True)
    tmp = LEASES + ".tmp"
    with open(tmp, "w") as f:
        json.dump(state, f, indent=1, sort_keys=True)
    os.replace(tmp, LEASES)


def log_rows():
    if not os.path.exists(LOG):
        return []
    rows = []
    with open(LOG) as f:
        for line in f:
            if line.strip():
                try:
                    rows.append(json.loads(line))
                except ValueError:
                    continue
    return rows


def upstream_matched():
    """Addresses another copy of the project has matched, one per line in
    build/upstream/matched.txt; empty when absent."""
    path = os.path.join(ROOT, "build", "upstream", "matched.txt")
    if not os.path.exists(path):
        return set()
    return {int(line, 16) for line in open(path) if line.strip()}


def deferred_addrs(done):
    return {int(r["addr"], 16) for r in log_rows() if r.get("matched") is False} - done


_units = []


def area_of(addr):
    if not _units:
        with open(os.path.join(ROOT, "config", "units.txt")) as f:
            for line in f:
                if line.strip() and not line.startswith("#"):
                    start, name = line.split()[:2]
                    _units.append((int(start, 16), name))
        _units.sort()
    i = bisect.bisect_right([u[0] for u in _units], addr) - 1
    return _units[i][1] if i >= 0 else "unit_start"


def fragment_addrs():
    """Inventory entries that are pieces of a larger routine, not functions (config/fragments.txt,
    written by `tools/inventory.py --check --write`): no source can match one alone."""
    if "fragments" not in _cache:
        path = project.path("config/fragments.txt")
        _cache["fragments"] = set()
        if os.path.exists(path):
            with open(path) as f:
                _cache["fragments"] = {int(l.split()[0], 16) for l in f if l.split("#")[0].strip()}
    return _cache["fragments"]


def candidates(max_bytes, min_bytes=8, deferred=False):
    """{addr: bytes} of functions a worker can take: unmatched, ordinary instructions, the game's
    compiler, one per exact-copy group, no fragment of a larger routine (fragment_addrs). With
    deferred=True, only functions given up on before."""
    text_addr, text = match.load_text()
    done = done_addrs()
    fragments = fragment_addrs()
    retry = deferred_addrs(done)
    done = done | upstream_matched()  # nobody redoes what the upstream project already matched
    done = done | link_rejects()
    group_of, seen = {}, set()
    path = os.path.join(ROOT, "build", "groups.json")
    if os.path.exists(path):
        for i, g in enumerate(json.load(open(path))["groups"]):
            for a in g:
                group_of[int(a, 16)] = i
            if any(int(a, 16) in done for a in g):
                seen.add(i)
    out = {}
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            addr, span = int(row["address"], 16), int(row["max_size"])
            if addr in done or addr in fragments or (addr in retry) != deferred or span > max_bytes + 64:
                continue
            g = group_of.get(addr)
            if g is not None:
                if g in seen:
                    continue
                seen.add(g)
            words = match.trim_padding(match.words_at(text_addr, text, addr, span))
            if min_bytes <= len(words) * 4 <= max_bytes and plain(words, addr):
                out[addr] = len(words) * 4
    return out


WORK_QUEUE = os.path.join(ROOT, "build", "work_queue.json")


def refresh_queue():
    """Rank all work with tools/work_queue.py (expected bytes recovered / expected cost)."""
    subprocess.run([sys.executable, os.path.join(ROOT, "tools", "work_queue.py"), "--top", "0",
                    "--json", WORK_QUEUE], capture_output=True, text=True)
    _cache.pop("queue", None)


def queue_items():
    """{addr: work_queue item} (functions, and families by their representative); {} if never ranked."""
    if "queue" not in _cache:
        items = {}
        if os.path.exists(WORK_QUEUE):
            for it in json.load(open(WORK_QUEUE)):
                items[int(it["addr"], 16)] = it
        _cache["queue"] = items
    return _cache["queue"]


def score(addr):
    it = queue_items().get(addr)
    return it["score"] if it else 0.0


def tiers():
    """project.toml [swarm.tiers]: name -> settings (fresh band, retries, count, model...)."""
    return project.CONFIG.get("swarm", {}).get("tiers", {})


def row_tier(row):
    """The tier that wrote a log row; rows from before tiers were Haiku workers or the local model."""
    return row.get("tier") or ("local" if row.get("worker") == "local" else "haiku")


def last_giveup_tier():
    """{addr: tier of its latest give-up}: escalation sends it to the tier that retries that one."""
    out = {}
    for r in log_rows():
        if r.get("matched") is False:
            out[int(r["addr"], 16)] = row_tier(r)
    return out


def tier_rank(name, seen=()):
    """Where a tier sits in the escalation order: 0 for one that retries nobody (or is not in
    project.toml), else one above the highest tier it retries."""
    t = tiers().get(name) or {}
    below = [x for x in t.get("retries", []) if x != name and x not in seen]
    return 1 + max((tier_rank(x, tuple(seen) + (name,)) for x in below), default=-1)


def tier_candidates(name, fresh_only=False):
    """{addr: bytes} a tier may take: never-tried functions in its fresh band, plus functions whose
    latest give-up came from a tier it retries (up to retry_max_bytes)."""
    t = tiers()[name]
    low, high = t["fresh"]
    out = dict(candidates(high, low))
    if t.get("retries") and not fresh_only:
        last = last_giveup_tier()
        for addr, n in candidates(t.get("retry_max_bytes", high), 8, deferred=True).items():
            if last.get(addr) in t["retries"]:
                out[addr] = n
    return out


def lease_tier(addr):
    """The tier of the worker holding addr, so try/giveup records it without the worker saying so."""
    lease = load_leases()["leases"].get(f"{addr:08x}")
    return lease.get("tier") if lease else None


def by_area(pool):
    areas = {}
    for addr in sorted(pool):
        areas.setdefault(area_of(addr), []).append(addr)
    return areas


def cmd_areas(a):
    pool = candidates(a.max_bytes, a.min_bytes, a.deferred)
    state = load_leases()
    holders = {}
    for addr, lease in state["leases"].items():
        holders.setdefault(lease["area"], set()).add(lease["worker"])
    rows = sorted(by_area(pool).items(), key=lambda kv: -len(kv[1]))
    print(f"{len(pool)} candidates <= {a.max_bytes} bytes in {len(rows)} areas")
    for name, addrs in rows[:a.limit]:
        who = ",".join(sorted(holders.get(name, ()))) or "-"
        print(f"  {name:48s} {len(addrs):5d} functions {sum(pool[x] for x in addrs):7d} bytes  workers: {who}")


def paused_areas():
    path = os.path.join(ROOT, "config", "paused_areas.txt")
    if not os.path.exists(path):
        return set()
    with open(path) as f:
        return {line.split("#")[0].strip() for line in f} - {""}


def certified_queue(tier, worker=""):
    """[(addr, bytes, index row)] for `assign --certified`, closest first: the unmatched functions
    whose closest kept draft the oracle certified or left within a few instructions
    (tools/retry_brief.py queue, written by its `refresh`). The certificate is the reason to retry,
    so the tier's bands and escalation order do not apply, only its largest size; a function the
    tier (or this worker) gave up on after that report stood is left to the others, and so is one
    whose latest give-up came from this tier or a higher one, whenever its report was written (a
    give-up leaves a new closest draft, so the report is always newer): it escalates."""
    try:
        import retry_brief
        order = retry_brief.queue()
    except (Exception, SystemExit):
        return []
    if not order:
        return []
    limit = 10 ** 9
    if tier:
        limit = max(tiers()[tier]["fresh"][1], tiers()[tier].get("retry_max_bytes", 0))
    sizes = takable_sizes([addr for addr, _ in order])
    gave_up = {int(r["addr"], 16): r.get("time", "") for r in log_rows()
               if r.get("matched") is False and (row_tier(r) == tier or r.get("worker") == worker)}
    last = last_giveup_tier() if tier else {}
    return [(addr, sizes[addr], e) for addr, e in order
            if 8 <= sizes.get(addr, 0) <= limit and gave_up.get(addr, "") <= e.get("time", "")
            and not (addr in last and tier_rank(last[addr]) >= tier_rank(tier))]


def takable_sizes(addrs):
    """{addr: bytes} of those among addrs a worker can take, by the rules of candidates(): no
    source here or upstream, no fragment, ordinary instructions, no solved exact copy."""
    text_addr, text = match.load_text()
    done = done_addrs() | upstream_matched()
    fragments = fragment_addrs()
    copies = {}
    path = os.path.join(ROOT, "build", "groups.json")
    if os.path.exists(path):
        for g in json.load(open(path))["groups"]:
            members = {int(x, 16) for x in g}
            for m in members:
                copies[m] = members
    out = {}
    for addr in addrs:
        if addr in done or addr in fragments or copies.get(addr, set()) & done:
            continue
        try:
            words = match.trim_padding(match.words_at(text_addr, text, addr, match.function_span(addr)))
        except SystemExit:  # not in the inventory
            continue
        if plain(words, addr):
            out[addr] = len(words) * 4
    return out


def cmd_assign(a):
    queue = certified_queue(a.tier, a.worker) if getattr(a, "certified", False) else []  # before the lock: it reads no lease
    with Lock():
        state = load_leases()
        leased = {int(x, 16) for x in state["leases"]}
        queue = [q for q in queue if q[0] not in leased]
        if queue:
            picked = queue[:a.count or (tiers()[a.tier]["count"] if a.tier else 6)]
            now = time.strftime("%Y-%m-%d %H:%M:%S")
            for addr, _, _ in picked:
                state["leases"][f"{addr:08x}"] = {"worker": a.worker, "area": area_of(addr), "time": now, "tier": a.tier}
            save_leases(state)  # last_area stays: the worker returns to its area afterwards
            os.makedirs(os.path.join(SWARM, a.worker), exist_ok=True)
            print(json.dumps({"worker": a.worker, "tier": a.tier, "area": "certified", "certified": True,
                              "remaining_in_area": len(queue) - len(picked),
                              "draft_dir": f"build/swarm/{a.worker}",
                              "functions": [{"addr": f"{x:08x}", "bytes": n, "name": rtti_name(x) or "",
                                             "area": area_of(x), "draft": e["draft"], "certified": e["certified"],
                                             "decisions": e["decisions"] if e["level"] == 0 else None,
                                             "differ": e["differ"]} for x, n, e in picked]}, indent=1))
            return
        source = tier_candidates(a.tier, a.fresh) if a.tier else candidates(a.max_bytes, a.min_bytes, a.deferred)
        pool = {k: v for k, v in source.items() if k not in leased}
        count = a.count or (tiers()[a.tier]["count"] if a.tier else 6)
        if getattr(a, "priority", None):
            # An explicit order (a JSON list of {"addr": "00573360", ...}, hottest first), e.g. what the
            # native port executes most: take the first open ones, ignoring areas.
            order = [int(r["addr"], 16) for r in json.load(open(a.priority))]
            picked = [x for x in order if x in pool][:count]
            now = time.strftime("%Y-%m-%d %H:%M:%S")
            for addr in picked:
                state["leases"][f"{addr:08x}"] = {"worker": a.worker, "area": area_of(addr), "time": now, "tier": a.tier}
            save_leases(state)
            os.makedirs(os.path.join(SWARM, a.worker), exist_ok=True)
            print(json.dumps({"worker": a.worker, "tier": a.tier, "area": "priority",
                              "remaining_in_area": sum(1 for x in order if x in pool) - len(picked),
                              "draft_dir": f"build/swarm/{a.worker}",
                              "functions": [{"addr": f"{x:08x}", "bytes": pool[x], "name": rtti_name(x) or ""}
                                            for x in picked]}, indent=1))
            return
        areas = by_area(pool)
        if not areas:
            print(json.dumps({"worker": a.worker, "area": None, "functions": []}))
            return
        busy = {l["area"] for l in state["leases"].values() if l["worker"] != a.worker}
        last = state["last_area"].get(a.worker)
        if a.area:
            if a.area not in areas:
                sys.exit(f"no candidates left in area {a.area}")
            area = a.area
        elif last in areas and not a.new_area:
            area = last  # stay with the same class while it has work
        else:
            # The biggest area nobody else is in; shared big areas only when nothing else is left.
            # Areas in config/paused_areas.txt (known blockers) are only taken with --area.
            choices = [n for n in areas if n not in paused_areas()] or list(areas)
            # work_queue's expected return decides, size only breaks ties
            area = max(choices, key=lambda n: (n not in busy, n != last,
                                              sum(score(x) for x in areas[n]), len(areas[n])))
        ranked = sorted(areas[area], key=lambda x: -score(x)) if queue_items() else areas[area]
        picked = ranked[:count]
        home = {x: area for x in picked}
        if len(picked) < count and not a.area:
            # A thin area: top the batch up from the nearest areas nobody else is in, so a worker
            # session is not spent on one or two functions.
            others = {x: n for n, xs in areas.items() if n != area and n not in busy and n not in paused_areas()
                      for x in xs}
            for x in sorted(others, key=lambda x: abs(x - picked[0]))[:count - len(picked)]:
                picked.append(x)
                home[x] = others[x]
        now = time.strftime("%Y-%m-%d %H:%M:%S")
        for addr in picked:
            state["leases"][f"{addr:08x}"] = {"worker": a.worker, "area": home[addr], "time": now, "tier": a.tier}
        state["last_area"][a.worker] = area
        save_leases(state)
    os.makedirs(os.path.join(SWARM, a.worker), exist_ok=True)
    print(json.dumps({"worker": a.worker, "tier": a.tier, "area": area,
                      "remaining_in_area": len(areas[area]) - sum(1 for x in picked if home[x] == area),
                      "draft_dir": f"build/swarm/{a.worker}",
                      "functions": [{"addr": f"{x:08x}", "bytes": pool[x], "name": rtti_name(x) or ""}
                                    for x in picked]}, indent=1))


def cmd_release(a):
    with Lock():
        state = load_leases()
        if a.all:
            dropped = len(state["leases"])
            state = {"leases": {}, "last_area": state["last_area"]}
        else:
            keep = {k: v for k, v in state["leases"].items() if v["worker"] != a.worker}
            dropped = len(state["leases"]) - len(keep)
            state["leases"] = keep
        save_leases(state)
    print(f"released {dropped} leases")


def cmd_start(a):
    """Leases from an earlier session are stale (subagents end with the lead's session). Warm the
    solved-function cache once here rather than in N workers at the same time."""
    a.all = True
    cmd_release(a)
    t = time.time()
    print(f"{len(solved_mnemonics())} solved functions indexed in {time.time() - t:.1f}s")
    refresh_queue()
    print(f"work queue: {len(queue_items())} items ranked (tools/work_queue.py)")
    cmd_status(a)


def cmd_status(a):
    n = len(project.sources(refresh=True))
    done = done_addrs()
    state = load_leases()
    per_worker = {}
    for addr, lease in state["leases"].items():
        per_worker.setdefault(lease["worker"], []).append(addr)
    pool = candidates(100000)
    tiers = {}
    for size in pool.values():
        tier = next(t for t in (128, 256, 384, 512, 1024, 10 ** 9) if size <= t)
        tiers[tier] = tiers.get(tier, 0) + 1
    rows = log_rows()
    today = time.strftime("%Y-%m-%d")
    matched_today = [r for r in rows if r.get("matched") and r.get("time", "").startswith(today)]
    print(f"sources: {n}; deferred: {len(deferred_addrs(done))}; "
          f"matched today: {len(matched_today)} functions, {sum(r.get('bytes', 0) for r in matched_today)} bytes")
    print("candidates by size: " + ", ".join(f"<={'max' if t == 10 ** 9 else t}: {c}" for t, c in sorted(tiers.items())))
    for worker, addrs in sorted(per_worker.items()):
        area = state["leases"][addrs[0]]["area"]
        print(f"  {worker}: {len(addrs)} leased in {area}")
    if not per_worker:
        print("  no leases")


# ---------------------------------------------------------------- worker steps

def record(entry):
    entry["time"] = time.strftime("%Y-%m-%d %H:%M:%S")
    os.makedirs(AUTO, exist_ok=True)
    with open(LOG, "a") as f:  # one short line per write: safe with parallel appends
        f.write(json.dumps(entry) + "\n")


def size(addr):
    t_addr, text = match.load_text()
    return len(match.trim_padding(match.words_at(t_addr, text, addr, match.function_span(addr)))) * 4


def cmd_prompt(a):
    _, sections = project.load_image()
    print(first_prompt(a.addr, sections))
    ext = "c" if a.addr in sdk_functions() else "cpp"
    print(f"\nDraft: build/swarm/WORKER/{a.addr:08x}.{ext}, then: python3 tools/swarm.py try {a.addr:08x} FILE")


def cmd_try(a):
    addr, path = a.addr, a.file
    src = open(path, encoding="utf-8").read()
    bad = asm_policy.violations(src)
    if bad:
        print("REJECTED: " + "; ".join(bad) + ". Write C, not assembly: only single-instruction "
              "intrinsics (e.g. sqrt.s) may be inline asm.")
        sys.exit(2)
    if not re.search(rf"\bfunc_{addr:08X}\b", src):
        print(f"REJECTED: the source must define func_{addr:08X} (uppercase hex, as the linker expects).")
        sys.exit(2)
    if re.match(r"/\* compiler: [^*]*nosched1", src) and not os.environ.get("SWARM_ALLOW_NOSCHED1"):
        print("REJECTED: the nosched1 compiler profiles are not for workers. Find the source form, or give up "
              "with a note saying the function matches only without the first scheduling pass.")
        sys.exit(2)
    if addr in sdk_functions() and not src.startswith(SDK_MARKER):
        print(f"REJECTED: func_{addr:08X} is SDK code: the first line must be `{SDK_MARKER}`.")
        sys.exit(2)
    ok, out = check(addr, path)
    # the prediction first (one compile); the search only for the pure branch-likely case it leaves open
    closure = None if ok else (predicted_context(addr, path, src, out, a.worker)
                               or nothrow_closure(addr, path, src, out, a.worker))
    if closure:
        # The draft was right, its callees' prototypes were not: go on as a match of the variant.
        keep_attempt("try", addr, a.worker, text=src, ext="cpp", report=out, done="context")
        ok, path, src, out = True, closure["path"], closure["text"], closure["report"]
    if ok:
        checked = re.search(r": MATCH \((\d+) instructions\)", out)
        if not checked:
            raise RuntimeError("Successful check omitted its instruction count")
        if addr in link_rejects():
            print("MATCH, but not saved: an earlier source of this function matched the judge and differed after "
                  "linking (tools/integrate.py set it aside in build/swarm/rejected/). It probably names a wrong "
                  "global or callee; the lead clears its line in build/swarm/link_rejects.txt once that is fixed.")
            return
        existing = project.source_for(addr)
        if existing:
            print(f"MATCH, but {os.path.relpath(existing, ROOT)} already exists: not saved")
            if closure:
                print(closure["note"])
            return
        # Atomic: a full build may be reading src/ at this moment.
        tmp = os.path.join(SWARM, f"save_{addr:08x}_{os.getpid()}.tmp")
        shutil.copy(path, tmp)
        ext = "c" if path.endswith(".c") else "cpp"  # the language it was judged as
        os.replace(tmp, os.path.join(ROOT, "src", f"func_{addr:08X}.{ext}"))
        record({"addr": f"{addr:08x}", "bytes": int(checked.group(1)) * 4, "matched": True,
                "effort": "agent", "worker": a.worker, "tier": lease_tier(addr),
                "fakematch": asm_policy.fakematch(src),
                **({"nothrow": closure["callees"], **closure.get("log", {})} if closure else {})})
        print(f"MATCH: saved src/func_{addr:08X}.{ext}")
        if closure:
            print(closure["note"])
        keep_attempt("match", addr, a.worker, text=src)
        return
    record_partial(addr, out)
    lines = out.splitlines()
    if len(lines) <= 100:
        print("\n".join(lines))
    else:
        # Long functions: the header, then every differing line with one line of context.
        head = [l for l in lines if not l.startswith(("!", " "))]
        body = [l for l in lines if l.startswith(("!", " "))]
        keep = sorted({j for i, l in enumerate(body) if l.startswith("!") for j in (i - 1, i, i + 1)
                       if 0 <= j < len(body)})
        shown, prev = [], -2
        for j in keep:
            if j != prev + 1:
                shown.append(f"  ... (line {j + 1})")
            shown.append(body[j])
            prev = j
        print("\n".join(head + shown))
    keep_attempt("try", addr, a.worker, text=src, ext="c" if path.endswith(".c") else "cpp", report=out,
                 done="context" if closure is False else None)
    keep_distance(addr, src, out)
    sys.exit(1)


CONTEXT_DISTANCE = 20  # aligned instructions: a draft further off is not judged with the predicted context
CONTEXT_LOG = os.path.join(SWARM, "context.jsonl")


_aligned = {}


def keep_distance(addr, src, out):
    """For a judged draft more than CONTEXT_DISTANCE rows off: note its aligned distance beside the
    oracle's files (tools/retry_brief.py picks a function's closest draft by it; the attempt store
    keeps the row count only, and nobody keeps the diff). After the verdict is printed; nothing
    that goes wrong here reaches the worker."""
    try:
        m = re.search(r"(\d+) of (\d+) instructions differ", out.split("\n")[0])
        if not m or int(m.group(1)) <= CONTEXT_DISTANCE or int(m.group(2)) > 4000:
            return
        import attempt_store
        import retry_brief
        retry_brief.merge(addr, attempt_store.digest(src), {"aligned": aligned_differ(out), "positional": int(m.group(1))})
    except (Exception, SystemExit):
        pass


def aligned_differ(out):
    """Differing instructions of a judge report once the two listings are aligned
    (finish_near.aligned_distance: the judge counts row by row, so one inserted instruction makes
    every later row differ); never more than the judge's own count. None without a listing."""
    m = re.search(r"(\d+) of (\d+) instructions differ", out.split("\n")[0])
    if not m:
        return None
    rows = int(m.group(1))
    if rows <= CONTEXT_DISTANCE or int(m.group(2)) > 4000:  # close already, or too long to align inside a try
        return rows
    if out not in _aligned:
        try:
            import finish_near
            aligned = finish_near.aligned_distance(out)
        except (Exception, SystemExit):
            aligned = None
        _aligned[out] = rows if aligned is None else min(rows, aligned)
    return _aligned[out]


def predicted_context(addr, path, src, out, worker=""):
    """For a C++ draft that compiles and is within CONTEXT_DISTANCE aligned instructions of the
    original: judge it once more with the translation-unit context tools/unit_map.py predicts
    written in (unit_map.apply: the unit's aliasing flag when the draft names no compiler,
    `throw()` and `__attribute__((const))` on exactly the predicted callees). Returns what
    nothrow_closure returns on a match (the variant is build/swarm/WORKER/ADDR_context.cpp); False
    when the variant was judged and differs; None when nothing was judged (not that kind of draft,
    or the draft already says what is predicted). One compile. SWARM_NO_CONTEXT=1 turns it off.
    Each judged variant leaves a row in build/swarm/context.jsonl."""
    if os.environ.get("SWARM_NO_CONTEXT") or not path.endswith(".cpp") or addr in sdk_functions():
        return None
    started, row = time.time(), None
    try:
        distance = aligned_differ(out)
        if distance is None or distance > CONTEXT_DISTANCE:
            return None
        import unit_map
        text, pred = unit_map.apply(addr, src)
        own = unit_map.strip_marker(src)[1]
        before = unit_map.Protos(unit_map.strip_marker(src)[0], addr)
        after = unit_map.Protos(unit_map.strip_marker(text)[0], addr)
        names = lambda cs: ", ".join(sorted(symbols.symbol(c) for c in cs))
        changes = []
        if pred.get("profile") != own:
            changes.append(f"first line `/* compiler: {pred['profile']} */`" if pred.get("profile") else "no compiler line")
        for what, new, old in (("`throw()`", after.have, before.have),
                               ("`__attribute__((const))`", after.have_const, before.have_const)):
            if new - old:
                changes.append(f"{what} on {names(new - old)}")
            if old - new:
                changes.append(f"no {what} on {names(old - new)}")
        if not changes:
            return None
        row = {"addr": f"{addr:08x}", "worker": worker, "differ": distance, "applied": changes}
        stem = os.path.join(SWARM, worker if re.fullmatch(r"[\w.-]+", worker or "") else "", f"{addr:08x}_context")
        os.makedirs(os.path.dirname(stem), exist_ok=True)
        variant = f"{stem}.{os.getpid()}.cpp"
        try:
            with open(variant, "w", encoding="utf-8", newline="\n") as f:
                f.write(text)
            ok, report = check(addr, variant)  # match.py check itself: its MATCH is the verdict
        finally:
            if os.path.exists(variant):
                os.remove(variant)
        row.update(matched=ok, differ_with=0 if ok else aligned_differ(report))
        if not ok:
            return False
        final = stem + ".cpp"
        with open(final, "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
        return {"path": final, "text": text, "report": report, "callees": sorted(symbols.symbol(c) for c in after.have),
                "log": {"context": "predicted"},
                "note": "note: the draft matched once the translation-unit context predicted by tools/unit_map.py was "
                        f"written in ({'; '.join(changes)}); the saved source says so, and "
                        f"{os.path.relpath(final, ROOT)} is that text"}
    except (Exception, SystemExit):
        return None if row is None else False
    finally:
        if row is not None:
            try:
                row.update(seconds=round(time.time() - started, 1), time=time.strftime("%Y-%m-%d %H:%M:%S"))
                with open(CONTEXT_LOG, "a") as f:
                    f.write(json.dumps(row) + "\n")
            except OSError:
                pass


CLOSURE_SECONDS = 30  # after this long a nothrow search inside `try` starts no further round
CLOSURE_JOBS = 3      # variants judged at a time
CLOSURE_LOG = os.path.join(SWARM, "closure.jsonl")


def nothrow_closure(addr, path, src, out, worker=""):
    """For a C++ draft whose every differing instruction is a branch against its branch-likely
    form (the signature of a callee the original unit knew could not throw): search the draft's
    callee prototypes for the ones to declare `throw()` (tools/tu_context.py: none, all, the
    lower addresses, then single toggles), reduce a matching set to the smallest, and write that
    variant to build/swarm/WORKER/ADDR_nothrow.cpp. Returns {"path", "text", "report" (of
    match.py check: a MATCH), "callees", "note"}; False when the search ran and found nothing;
    None when the draft is not of that kind (the usual case: nothing is compiled for it).
    SWARM_NO_CLOSURE=1 turns it off. Each search leaves a row in build/swarm/closure.jsonl."""
    if os.environ.get("SWARM_NO_CLOSURE") or not path.endswith(".cpp"):
        return None
    started, calls, row = time.time(), 0, None
    try:
        import attempt_store
        verdict = attempt_store.classify(out)
        if verdict.get("class") != "branch-form":
            return None
        import concurrent.futures
        import tu_context
        search = tu_context.Search(addr, src, profiles=())  # the draft's own compiler only
        if not search.callees:
            return None
        row = {"addr": f"{addr:08x}", "worker": worker, "differ": verdict["differ"], "callees": len(search.callees)}
        stem = os.path.join(SWARM, worker if re.fullmatch(r"[\w.-]+", worker or "") else "", f"{addr:08x}_nothrow")
        os.makedirs(os.path.dirname(stem), exist_ok=True)

        reports, count = {}, iter(range(1 << 30))

        def judge(chosen):
            variant = f"{stem}.{os.getpid()}.{next(count)}.cpp"
            try:
                with open(variant, "w", encoding="utf-8", newline="\n") as f:
                    f.write(search.render(chosen, search.own))
                ok, report = check(addr, variant)  # match.py check itself: its MATCH is the verdict
            finally:
                if os.path.exists(variant):
                    os.remove(variant)
            if ok:
                reports[chosen] = report
                return tu_context.MATCH
            m = re.search(r"(\d+) of \d+ instructions differ", report.split("\n")[0])
            return (int(m.group(1)), 0) if m else None

        def matches(subset):
            nonlocal calls
            calls += bool(subset)
            return bool(subset) and judge(subset) == tu_context.MATCH

        with concurrent.futures.ThreadPoolExecutor(CLOSURE_JOBS) as pool:
            while time.time() - started < CLOSURE_SECONDS:
                frontier = search.frontier()
                if not frontier:
                    break
                # the empty set is the draft as it was just judged
                todo = [(chosen, profile) for chosen, profile in frontier if chosen]
                results = [(chosen, profile, (verdict["differ"], 0)) for chosen, profile in frontier if not chosen]
                scores = list(pool.map(judge, [chosen for chosen, _ in todo]))
                calls += len(todo)
                search.feed(results + [(chosen, profile, sc) for (chosen, profile), sc in zip(todo, scores)])
            if not search.best or search.best[0] != tu_context.MATCH:
                row["matched"] = None
                return False
            # The smallest set: one callee was enough for every function the research matched this
            # way, so the single callees go first, together; else drop them one by one.
            chosen = search.best[1]
            if len(chosen) > 1:
                singles = [frozenset([c]) for c in sorted(chosen)]
                calls += len(singles)
                alone = [one for one, sc in zip(singles, pool.map(judge, singles)) if sc == tu_context.MATCH]
                chosen = alone[0] if alone else tu_context.minimise(chosen, matches)
        text, final = search.render(chosen, search.own), stem + ".cpp"
        with open(final, "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
        names = sorted(symbols.symbol(c) for c in chosen)
        row["matched"] = names
        return {"path": final, "text": text, "report": reports[chosen], "callees": names,
                "note": f"note: the draft matched once {', '.join(names)} "
                        f"{'was' if len(names) == 1 else 'were'} declared `throw()` (nothrow closure, "
                        f"tools/tu_context.py); the saved source says so, and {os.path.relpath(final, ROOT)} is that text"}
    except (Exception, SystemExit):
        return None if row is None else False
    finally:
        if row is not None:
            try:
                row.update(judged=calls, seconds=round(time.time() - started, 1), time=time.strftime("%Y-%m-%d %H:%M:%S"))
                with open(CLOSURE_LOG, "a") as f:
                    f.write(json.dumps(row) + "\n")
            except OSError:
                pass


def keep_attempt(event, addr, worker, **kw):
    """Hand a judged draft, a match or a give-up to the attempt store (tools/attempt_store.py:
    the text and how it was judged, for the tools that go on from near misses). File writes only,
    after the verdict is printed; nothing that goes wrong in the store reaches the worker."""
    try:
        sys.stdout.flush()
        import attempt_store
        tier = lease_tier(addr)
        if event == "try":
            attempt_store.put(addr, kw["text"], kw["ext"], kw["report"], worker, tier)
            if kw.get("done"):  # a mechanical step `try` already ran on this text
                attempt_store.mark_pass(addr, attempt_store.digest(kw["text"]), kw["done"], "swarm.py try")
        elif event == "match":
            attempt_store.matched(addr, kw["text"], worker, tier)
        else:
            attempt_store.giveup(addr, worker, tier, kw["attempts"], kw["best"], kw["note"],
                                 os.path.join(SWARM, worker) if re.fullmatch(r"[\w.-]+", worker or "") else None)
    except Exception:
        pass


def record_partial(addr, out):
    """Keep the best partial score per function (share of instructions that match) for the
    progress report, so near misses show up instead of counting as 0%."""
    m = re.search(r"(\d+) of (\d+) instructions differ", out)
    if not m:
        return
    score = round(100.0 * (1 - int(m.group(1)) / int(m.group(2))), 1)
    path = os.path.join(AUTO, "partial.json")
    with Lock():
        best = json.load(open(path)) if os.path.exists(path) else {}
        if score > best.get(f"{addr:08x}", -1):
            best[f"{addr:08x}"] = score
            json.dump(best, open(path, "w"))


def cmd_giveup(a):
    attempts.append({"addr": f"{a.addr:08x}", "time": time.strftime("%Y-%m-%d %H:%M"),
                     "who": a.worker or "swarm", "result": "abandoned",
                     "hypothesis": f"{lease_tier(a.addr) or 'haiku'} tier gave up after {a.attempts} tries: {a.note}",
                     **({"diff": a.best} if a.best is not None else {})})
    record({"addr": f"{a.addr:08x}", "bytes": size(a.addr), "matched": False, "effort": "auto",
            "attempts": a.attempts, "worker": a.worker, "tier": lease_tier(a.addr) or "haiku",
            "best": a.best, "note": a.note})
    print("recorded as deferred")
    keep_attempt("giveup", a.addr, a.worker, attempts=a.attempts, best=a.best, note=a.note)


def local_running():
    """True when tools/local_worker.py runs (its pid file names a live process)."""
    path = os.path.join(ROOT, "build", "local", "worker.pid")
    try:
        os.kill(int(open(path).read().strip()), 0)
        return True
    except (OSError, ValueError):
        return False


def plan(n, queues):
    """Split n Claude slots over the Claude tiers by queue size: each tier with work gets at least
    one slot (within its `slots` cap), the rest go to the longest queues."""
    claude = {name: t for name, t in tiers().items() if t.get("model")}
    want = {name: q for name, q in queues.items()
            if name in claude and q > 0 and claude[name].get("slots", n) > 0}
    slots = {name: 0 for name in claude}
    for name in sorted(want, key=lambda x: -want[x]):
        if sum(slots.values()) < n:
            slots[name] = 1
    while sum(slots.values()) < n:
        open_ = [x for x in want if slots[x] < claude[x].get("slots", n)]
        if not open_:
            break
        best = max(open_, key=lambda x: want[x] / (slots[x] + 1))
        slots[best] += 1
    return slots


def cmd_plan(a):
    """Queue per tier and the slot split for N Claude workers (the lead's default session)."""
    refresh_queue()
    queues = {name: len(tier_candidates(name)) for name in tiers()}
    slots = plan(a.n, queues)
    out = {"slots": a.n, "local_worker_running": local_running(), "tiers": {}}
    for name, t in tiers().items():
        out["tiers"][name] = {"queue": queues[name], "model": t.get("model", "local"),
                              "slots": slots.get(name, 0) if t.get("model") else None,
                              "count": t["count"], "tries": t.get("tries")}
    print(json.dumps(out, indent=1))


def main():
    hexaddr = lambda s: int(s, 16)
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("status")
    sub.add_parser("start")
    for name in ("areas", "assign"):
        p = sub.add_parser(name)
        if name == "assign":
            p.add_argument("worker")
            p.add_argument("--count", type=int, help="default: the tier's count, else 6")
            p.add_argument("--tier", choices=sorted(tiers()), help="take the tier's queue (project.toml [swarm.tiers])")
            p.add_argument("--fresh", action="store_true", help="with --tier: only never-tried functions")
            p.add_argument("--area")
            p.add_argument("--new-area", action="store_true", help="leave the worker's previous area")
            p.add_argument("--certified", action="store_true",
                           help="first the functions the oracle certified or left within a few instructions "
                                "(tools/retry_brief.py), closest first; then the usual queue")
        else:
            p.add_argument("--limit", type=int, default=25)
        p.add_argument("--max-bytes", type=int, default=256)
        p.add_argument("--min-bytes", type=int, default=8)
        p.add_argument("--deferred", action="store_true", help="functions given up on before")
        p.add_argument("--priority", help="JSON list of {addr} in the order to take them (assign only)")
    p = sub.add_parser("plan"); p.add_argument("n", type=int, nargs="?", default=3, help="Claude worker slots")
    p = sub.add_parser("release"); p.add_argument("worker", nargs="?"); p.add_argument("--all", action="store_true")
    sub.add_parser("rules")
    p = sub.add_parser("prompt"); p.add_argument("addr", type=hexaddr)
    p = sub.add_parser("try"); p.add_argument("addr", type=hexaddr); p.add_argument("file")
    p.add_argument("--worker", default=os.environ.get("SWARM_WORKER", ""))
    p = sub.add_parser("giveup"); p.add_argument("addr", type=hexaddr); p.add_argument("attempts", type=int)
    p.add_argument("--best", type=int, help="fewest differing instructions reached")
    p.add_argument("--note", default="", help="one line: what blocks the match")
    p.add_argument("--worker", default=os.environ.get("SWARM_WORKER", ""))
    a = ap.parse_args()
    if a.cmd == "release" and not (a.worker or a.all):
        ap.error("release needs WORKER or --all")
    if a.cmd == "rules":
        print(rules())
    else:
        globals()["cmd_" + a.cmd](a)


if __name__ == "__main__":
    main()
