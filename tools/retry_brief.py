#!/usr/bin/env python3
"""What a retry starts from: the closest kept draft of a function, whether the compiler oracle
certified its logic, and the compiler decisions that still differ, in the draft's own terms.

Three tools know things about an unmatched function that the worker retrying it was never told:
the attempt store keeps every judged draft (tools/attempt_store.py, drafts/ADDR/), the oracle says
whether a draft's logic is already the original's and which allocation or scheduling decisions
separate the two (tools/oracle.py, build/oracle/ADDR_SHA.json), and the unit map predicts the
translation-unit context (tools/unit_map.py: the first-line marker, the callees to declare
`throw()`). This module turns them into one short text and puts it into `swarm.py prompt ADDR`
(the predicted context for every function it exists for, drafts or not; left out under a certified
draft, whose own context the certificate proves); `swarm.py assign --certified` leases from its
queue.

    retry_brief.py show ADDR [--no-lazy]   the report `swarm.py prompt ADDR` carries
    retry_brief.py refresh [-j3] [--only ADDR,..] [--seconds 240] [--no-summary]
                                           the lead, at integration: measure the kept drafts the
                                           oracle has not seen (oracle.measure_one, cached per
                                           content), try the scheduler on the ones whose residual is
                                           a pure permutation, tie the decisions to source lines,
                                           rebuild the queue (build/oracle/briefs.json)
    retry_brief.py index                   rebuild the queue only (drops what was matched since)
    retry_brief.py queue [--within 3]      what `assign --certified` offers, closest first
    retry_brief.py stats                   the certified functions by how specific their report is

The report names, for the closest draft: its path, distance and compiler profile; whether its logic
is certified; each differing decision with the variables and source lines it belongs to (which of
two values must be allocated first and by how much, which instruction the scheduler issued ahead of
which); the two or three source edits the project's rules (knowledge/gt4.md, ee-gcc-2.96.md,
gcc296-codegen-map.md) give for that kind of decision; the mechanical passes that already ran on
that text; and the unit map's predicted context.

Distance. The judge counts row by row, so one inserted nop makes every later row differ ("469 of
811" for a draft three instructions off). Drafts are compared by finish_near.aligned_distance (the
two listings aligned, branch targets as one token); the row count is shown beside it when the two
differ. Neither the oracle's rows nor the attempt store keep the judge's diff: `swarm.py try` notes
the aligned count of a draft more than 20 rows off while it has the diff in hand (keep_distance,
into the draft's brief), and `refresh` judges again every kept draft that has none.

Cost. `prompt` reads a few small files (the function's oracle rows, its store log, the draft):
0.05 s measured, nothing compiled. Measuring inside `prompt` was tried and is off: with the swarm
running, the oracle on one draft took 4 to 8 s and a judge call for the aligned count over a
second (SWARM_ORACLE_SECONDS=N turns it on for a function with no certified draft: at most
LAZY_JUDGES stored drafts judged again, and the closest stored draft measured within N seconds,
once per content). The lead's `refresh` keeps the results current instead.

Per draft, beside the oracle's own JSON: build/oracle/ADDR_SHA.brief.json (the scheduler's verdict,
the displaced instructions with their source lines, the allocation decisions of a draft that also
needs registers forced, the aligned distance). A certificate says the logic is complete; it is never a match.
"""
import argparse
import collections
import hashlib
import json
import math
import multiprocessing
import os
import re
import signal
import subprocess
import sys
import time

TOOLS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(TOOLS)
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)

ORACLE = os.path.join(ROOT, "build", "oracle")
INDEX = os.path.join(ORACLE, "briefs.json")
ROW = re.compile(r"^([0-9a-f]{8})_([0-9a-f]{16})\.json$")
VERSION = 1
LAZY_SECONDS = float(os.environ.get("SWARM_ORACLE_SECONDS", "0"))
LAZY_DIFFER = 25      # a stored draft further off than this is not measured inside `prompt`
LAZY_JUDGES = 2       # stored drafts judged again inside `prompt` for their aligned distance
SHIFTED = 20          # a row count above this may be a shift: worth the aligned count (swarm.CONTEXT_DISTANCE)
NEAR = 3              # instructions left once the registers are forced: "within a few decisions"
STUCK = 6             # rank of a certified draft whose decisions could not be counted
SHOWN = 3             # decisions spelled out
UNIT_CONTEXT = True   # append tools/unit_map.py's predicted context (the hook for workstream 1b)
SAVED = re.compile(r"^\$(s[0-7]|fp|f2[0-9]|f3[01])$")


def rel(path):
    return os.path.relpath(os.path.abspath(path), ROOT).replace(os.sep, "/")


def digest(path):
    try:
        with open(path, "rb") as f:
            return hashlib.sha1(f.read()).hexdigest()[:16]
    except OSError:
        return None


def load(path, default=None):
    try:
        with open(path, encoding="utf-8") as f:
            return json.load(f)
    except (OSError, ValueError):
        return default


def dump(path, data):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    tmp = f"{path}.{os.getpid()}.tmp"
    with open(tmp, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=1)
    os.replace(tmp, path)


def brief_path(addr, sha):
    return os.path.join(ORACLE, f"{addr:08x}_{sha}.brief.json")


def merge(addr, sha, fields):
    """Add fields to a draft's brief cache (one writer per draft at a time)."""
    data = load(brief_path(addr, sha), {}) or {}
    data.update(version=VERSION, addr=f"{addr:08x}", sha=sha)
    data.update(fields)
    dump(brief_path(addr, sha), data)
    return data


# ---------------------------------------------------------------- what is known about a function

def oracle_rows(addr):
    """The oracle's reports on drafts of addr (one per draft content)."""
    prefix = f"{addr:08x}_"
    try:
        names = [n for n in os.listdir(ORACLE) if n.startswith(prefix) and ROW.match(n)]
    except OSError:
        return []
    return [r for r in (load(os.path.join(ORACLE, n)) for n in sorted(names)) if r and r.get("sha")]


def text_of(addr, row):
    """A file that still holds the text the oracle measured: the draft where it was, else the
    attempt store's copy of that content; None when the text is gone."""
    path = os.path.join(ROOT, row.get("draft", ""))
    if os.path.isfile(path) and digest(path) == row["sha"]:
        return path
    import attempt_store
    for ext in attempt_store.EXTS:
        path = attempt_store.source_path(addr, row["sha"], ext)
        if os.path.isfile(path):
            return path
    return None


def status(row, ex):
    """(level, decisions, label): level 0 for a draft whose logic is certified (label says by
    what), with the number of decisions left; level 1 otherwise, with the instructions left once
    the registers are forced."""
    if row.get("kind") == "match":
        return 0, 0, "match"
    if row.get("certified"):
        d = row.get("distance")
        return 0, (STUCK if d is None else d) + (row.get("operand_swaps") or 0), "allocation"
    sched = ex.get("sched") or {}
    if sched.get("result") == "reproduced":
        n = len(ex["moves"]) if ex.get("moves") else sched.get("picks_changed") or 1
        if sched.get("registers_forced"):
            return 0, n + (len((ex.get("causal") or {}).get("decisions", [])) or sched["registers_forced"]), "allocation+schedule"
        return 0, n, "schedule"
    left = (row.get("reload") or {}).get("differ_forced")
    left = row.get("differ") if left is None else left
    return 1, 999 if left is None else left, None


def off_by(row):
    """(row count, instructions missing) of an oracle row, as the attempt store counts them: a
    draft that stops early is judged over its own span only."""
    d = row.get("differ")
    short = (row.get("original") or 0) - (row.get("instructions") or row.get("original") or 0)
    return (999 if d is None else d), (short if short > 1 else 0)


def reach(rows, short, ex):
    """A draft's distance: the aligned count when it is known and smaller than the judge's row
    count (finish_near.aligned_distance, cached by `refresh`), plus the instructions missing."""
    aligned = (ex or {}).get("aligned")
    return min(rows, aligned) + short if aligned is not None else rows + short


def candidates(addr):
    """Every kept draft of addr, closest first: certified ones by decisions left, the others by
    distance. Each: path, sha, row (the oracle's, None if never measured), ex (the brief cache),
    attempt (the store's, if any), level, decisions, label, differ (the distance: aligned when
    known, see reach) and rows (the judge's row-by-row count)."""
    import attempt_store
    out, seen = [], set()
    stored = attempt_store.attempts(f"{addr:08x}") if os.path.isdir(attempt_store.folder(addr)) else {}
    for row in oracle_rows(addr):
        path = text_of(addr, row)
        if not path or row["sha"] in seen:
            continue
        seen.add(row["sha"])
        ex = load(brief_path(addr, row["sha"]), {}) or {}
        level, n, label = status(row, ex)
        rows, short = off_by(row)
        out.append({"path": rel(path), "sha": row["sha"], "row": row, "ex": ex, "attempt": stored.get(row["sha"]),
                    "level": level, "decisions": n, "label": label, "rows": rows + short, "differ": reach(rows, short, ex)})
    length = None
    for sha, a in stored.items():
        if sha in seen or not a.get("path") or a.get("verdict") != "differs":
            continue
        if length is None:
            length = attempt_store.true_length(addr) or 0
        ex = load(brief_path(addr, sha), {}) or {}
        rows, short = a.get("differ", 999), attempt_store.missing(a, length)
        out.append({"path": rel(a["path"]), "sha": sha, "row": None, "ex": ex, "attempt": a, "level": 2,
                    "decisions": None, "label": None, "rows": rows + short, "differ": reach(rows, short, ex)})
    out.sort(key=lambda c: (0, c["decisions"], c["differ"]) if c["level"] == 0 else (1, c["differ"], c["level"]))
    return out


# ---------------------------------------------------------------- the project's rules, by decision

EDITS = {
    "saved-swap": [
        "give {first} one more real use, or assign it later (after the early-return checks) so its life is shorter; "
        "or give {second} one use fewer or a longer life (keep it to the end). Declaration order does not decide",
        "a variable first set from a constant has its life counted double: one more set of the right one in its own arm "
        "(`case N: x = K; break;`, 00116e20); writing the first field through the pointer (`p->x = v`) raises that "
        "pointer's rank (0048C5E8)",
        "split or merge values: a parameter tested and then replaced (`n ? n : D`) is a short-lived parameter plus a new "
        "value; one variable reused for two roles is one value; a `goto` into the bottom of a do-while has fixed s0/s1",
    ],
    "v0-taken": [
        "the callee called just before returns a value in the original: declare it returning `void *` (constructors "
        "return `this`) or `s32`, even with the result unused (001fa3f0)",
        "a call result kept but not returned at once (`r = f(); ...; return r;`) keeps $v0 busy and pushes later "
        "temporaries to $v1",
        "where the return value is set decides: `$v0 = K` of a `return K;` placed before this line, or a result variable "
        "returned right after it, keeps $v0 busy over the temporary (00447828, 004588c0)",
    ],
    "v0-free": [
        "the callee called just before is `void` in the original: declare it `void` (its unused result keeps $v0 busy here)",
        "`if (!x) return 0; ... return 1;` instead of `int res = 0; ... res = 1; return res;` frees $v0 (004588c0); "
        "`return f(...);` directly instead of through a local",
        "a value computed only at the call site (`f(a, c ? -1 : g(o))`) goes straight into the argument register; a "
        "local assigned before it holds a register for longer",
    ],
    "local-order": [
        "inside a block the value with more uses per instruction of life is placed first, equal ones in the order they "
        "are first set: compute {first} before {second} (exchange the two statements)",
        "name a sub-expression in its own local, or fold a single-use local back into its use: one reference more or "
        "fewer changes the rank; a second use of a value extends its life",
        "locals declared in reverse order of last use change the temporaries of an add chain (00472110); float locals "
        "take FP registers in declaration order once $v0 is right (004588c0)",
    ],
    "copy": [
        "the value is copied to or from that register (argument, call result, return value): use a new variable for "
        "this call's result instead of reusing one, or reuse one where the original has a single home",
        "pass the expression itself instead of a local holding it, or the reverse; an inline wrapper around the call "
        "changes the register the value is built in",
        "check the callee's prototype: an argument register set again after a call belongs to the next call (fewer "
        "arguments, 004468F8); a parameter passed through must be in the prototype (001cc430)",
    ],
    "hard-live": [
        "an argument, call result or return value is set inside this value's life: load the arguments into locals "
        "first, in the original's order (`f(h0.p, b.p, g(c.p))`), or compute this value before the argument setup",
        "arguments are evaluated right to left: move a load or `*p++` out of the argument list into a statement before "
        "the call to change what overlaps",
        "declare the callee with the arguments it really takes and its real return type",
    ],
    "tie": [
        "exchange the operands of the commutative operator on that line (the operand that dies there shares the "
        "result's register)",
        "use the dying value once more after that statement, or compute the result into a new local",
    ],
    "operand": [
        "exchange the two operands of that `+`, `|`, `&`, `*` or `==` in the source",
        "`e = &tbl[i]; e->a` and `tbl[i].a` give opposite `addu` orders, as do `*(p + i)` and `p[i]`; a `u8 b[]` member "
        "indexed `p->b[i]` puts the index first",
    ],
    "life": [
        "one variable reused for two unrelated roles is one value, two locals are two: merge or split to match the "
        "original's register homes",
        "a pointer or field cached across a call that the original reloads after it (or the reverse): write the field "
        "access again, or hoist it into a local before the call",
    ],
}
SCHED_EDITS = {
    "load-store": [
        "a load moves above a store only when their types cannot alias: give both the data's real types (`f32` against "
        "`s32` field, `T *` against `s32`) to let it move, the same type or a `union` member to hold it below",
        "first line `/* compiler: ee-gcc2.96-no-strict-aliasing */` keeps loads and stores in source order (try with "
        "and without, 001d5258); `volatile` pins a single access",
        "read the field into a local before the unrelated store, or after it: the statement order then decides",
    ],
    "stores": [
        "a run of stores comes out rotated, the last store of the source first: for the original's A,B,C,D write "
        "B,C,D,A (0057A628)",
        "among equal stores the one that is the last use of its register goes first: move that statement, or keep its "
        "value alive with a later use",
        "fields all of one type keep source order, mixed types are reordered (0048fb58); a store fed by a `lui/ori` "
        "constant is issued early wherever it is written",
    ],
    "prologue": [
        "against the prologue's register saves an instruction is ranked by the chain of instructions waiting for it, "
        "then by position: change what waits for it (move the statement that first uses this value across the next "
        "call, or split it with a local)",
        "a later store in the block that may alias what it reads also waits for it: give both their real types "
        "(`const` for read-only tables), or try `/* compiler: ee-gcc2.96-no-strict-aliasing */` with and without",
    ],
    "frame": [
        "only register saves or restores are out of order, and no source line owns them: they are ordered with the "
        "body instructions beside them. Change what is computed before the first call, or how the last statement "
        "produces the return value (`return f(...);`, a local, a ternary)",
    ],
    "args": [
        "argument moves of one call are equal down to source position, and statement order does not change them "
        "(0032B798): change how each value reaches its register (a local loaded before the call in the original's "
        "order, or the expression written inline)",
        "arguments are evaluated right to left; a load or `*p++` written as an argument comes before the ones on its left",
    ],
    "other": [
        "instructions of equal rank keep the order they arrive in: exchange the two statements on the lines named",
        "the one that is the last use of a register goes first; a hoisted `lui` constant is ready first: hold it in a "
        "local assigned where the original loads it (003BB9A0)",
        "if a load and a store are involved their declared types decide (real types to let them cross, one type or a "
        "`union` to pin them)",
    ],
}
TITLES = {"saved-swap": "saved registers exchanged", "v0-taken": "a temporary one register too early",
          "v0-free": "a temporary one register too late", "local-order": "temporaries of one block exchanged",
          "copy": "a register tied by a copy", "hard-live": "an argument or result register in the way",
          "tie": "two values sharing a register", "operand": "operand order", "life": "a value's life differs",
          "load-store": "a load against a store", "stores": "store order", "prologue": "against the register saves",
          "frame": "register saves among themselves",
          "args": "argument setup order", "other": "instruction order"}


def priority(refs, length):
    """The allocators' rank (global.c, local-alloc.c), as the oracle scales it."""
    if not refs or not length or length <= 0:
        return 0
    return int((refs.bit_length() - 1) * refs / length * 10000)


def flip_hint(first, f_refs, f_len, second, s_refs, s_len):
    """The smallest change in references that puts `first` ahead of `second`, when one exists."""
    target = priority(s_refs, s_len)
    if not f_refs or not f_len or not s_refs or not s_len or priority(f_refs, f_len) > target:
        return ""
    for k in range(1, 9):
        if priority(f_refs + k, f_len) > target:
            more = f"{k} more use{'s' if k > 1 else ''} of {first} ({priority(f_refs + k, f_len)})"
            break
    else:
        more = ""
    fewer = ""
    for k in range(1, s_refs):
        if priority(s_refs - k, s_len) < priority(f_refs, f_len):
            fewer = f"{k} fewer of {second} ({priority(s_refs - k, s_len)})"
            break
    shorter = next((f"{first} living {f_len - n} less" for n in range(f_len - 1, 0, -1)
                    if priority(f_refs, n) > target), "")
    parts = [p for p in (more, fewer, shorter) if p]
    return ("; flips, if nothing else moves, with " + ", or ".join(parts[:3])) if parts else ""


def who(e):
    """A value as the worker knows it: the variable, or the temporary and where it is first set."""
    if e.get("var"):
        kind = "parameter" if e.get("kind") == "param" else "local"
        return f"`{e['var']}`", f"{kind} `{e['var']}`" + (f" (declared line {e['declared']})" if e.get("declared") else "")
    line = e.get("line")
    return (f"the temporary of line {line}" if line else "a temporary"), (f"a temporary first set on line {line}" if line else "a temporary")


def spot(e):
    """The source line worth quoting for a value: where it is first set; none for a parameter."""
    return None if e.get("kind") == "param" else e.get("line")


CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")
NOT_CALLS = {"if", "while", "for", "switch", "return", "sizeof", "defined", "else", "do", "case"}


def calls_before(source, line, span=6):
    """[(callee, line, declared return type)] of the calls on the `span` lines up to `line`: what
    decides whether $v0 is held there. Text only: the first prototype of each name in the draft."""
    text, out, seen = "\n".join(source), [], set()

    def declared(name, where):
        m = re.search(r'^[ \t]*(?:extern\s+"C"\s+|extern\s+|static\s+|inline\s+|virtual\s+)*([A-Za-z_][\w \t]*?[\s\*&]+)'
                      + re.escape(name) + r"\s*\(", where, re.M)
        return m and not re.match(r"(return|else|new|delete|case|goto|throw)\b", m.group(1).strip()) and " ".join(m.group(1).split())

    for n in range(max(1, line - span), min(line, len(source)) + 1):
        for name in CALL.findall(source[n - 1]):
            if name in NOT_CALLS or name in seen or declared(name, source[n - 1]):   # a prototype is not a call
                continue
            kind = declared(name, text)
            if kind:
                seen.add(name)
                out.append((name, n, kind))
    return out[-4:]


def decision_class(d):
    if d.get("decision") == "tie":
        return "tie"
    why = d.get("why", "")
    saved = bool(SAVED.match(d.get("got", "")) and SAVED.match(d.get("want", "")))
    if d.get("rivals"):
        return "saved-swap" if saved or d.get("phase") == "global" and d.get("calls_crossed") else "local-order"
    if "suggested by a copy" in why:
        return "copy"
    if "itself is live or set" in why:
        return "hard-live"
    if d.get("blocked"):
        return "v0-free"
    return "v0-taken"


def decision_lines(k, n, d):
    """One allocation decision in plain terms: [text], the source lines it points to, the class,
    and the names the edit rules are filled with."""
    cls = decision_class(d)
    short, long_ = who(d)
    lines = [spot(d)]
    phase = "saved registers and values that span blocks" if d.get("phase") == "global" else "temporaries of one block"
    head = f"- Decision {k} of {n} ({phase}): "
    names = {"first": short, "second": "the other value"}
    if cls == "tie":
        other = d.get("tied_to", {})
        text = (f"{long_} shares one register with {who(other)[1]} (the instruction that sets it is the last use of the "
                f"other); the original has them apart, in {d.get('want')} and another register")
    elif d.get("rivals"):
        r = d["rivals"][0]
        r_short, r_long = who(r)
        lines.append(spot(r))
        mine, his = (d.get("n_refs") or d.get("refs"), d.get("live_length")), (r.get("refs"), r.get("live_length"))
        if d.get("phase") == "local":
            mine = (d.get("n_refs"), (d.get("death") or 0) - (d.get("birth") or 0))
            his = (r.get("refs"), (r.get("death") or 0) - (r.get("birth") or 0)) if "birth" in r else (None, None)
        nums = ""
        if d.get("priority") is not None and r.get("priority") is not None:
            unit = "insns" if d.get("phase") == "global" else "half-insns"
            nums = (f" Rank floor(log2(refs))*refs/life ({unit}): {short} {mine[0]}/{mine[1]} = {d['priority']}, "
                    f"{r_short} {his[0]}/{his[1]} = {r['priority']}")
        if d.get("blocked"):            # the rival holds the register this one should have
            names = {"first": short, "second": r_short}
            text = (f"{long_} is in {d['got']} because {r_long} took {d['want']} before it; the original gives {d['want']} "
                    f"to {short}: {short} must be allocated first.{nums}")
            hint = flip_hint(short, mine[0], mine[1], r_short, his[0], his[1]) if his[0] else ""
        else:                           # this one took the register the rival has in the original
            names = {"first": r_short, "second": short}
            each = " (they are in each other's registers)" if r.get("reg") == d.get("want") else ""
            text = (f"{long_} is in {d['got']} and {r_long} in {r.get('reg')}; the original has {r_short} in {d['got']} and "
                    f"{short} in {d['want']}{each}: {r_short} must be allocated first.{nums}")
            hint = flip_hint(r_short, his[0], his[1], short, mine[0], mine[1]) if his[0] else ""
            if not hint and nums and d["priority"] == r["priority"]:
                hint = f"; equal rank: the one set first wins, so set {r_short} first"
        text += hint
    elif cls == "copy":
        text = (f"{long_} is in {d['got']} because it is copied to or from {d['got']} (an argument, a call result or the "
                f"return value); the original has it in {d['want']}")
    elif cls == "hard-live":
        text = (f"{long_} is in {d['got']}; the original has it in {d['want']}, which here is set or live inside this "
                f"value's life (an argument being set up, a call result, the return value)")
    elif cls == "v0-free":
        text = (f"{long_} is in {d['got']}; the original has it in {d['want']}, which is busy over this value's life here "
                f"and free there")
    else:
        text = (f"{long_} took {d['got']}, the first free register; the original has it in {d['want']}, so there "
                f"{d['got']} is still held over this value's life (a call result, a longer-lived value)")
    return [head + text], [x for x in lines if x], cls, names


INSN_KINDS = (("store", {"sb", "sh", "sw", "sd", "swc1", "sdl", "sdr", "swl", "swr", "sq", "sdc1"}),
              ("load", {"lb", "lbu", "lh", "lhu", "lw", "lwu", "ld", "lwc1", "ldl", "ldr", "lwl", "lwr", "lq", "ldc1"}))


def insn_kind(text):
    m = text.split()[0] if text else ""
    return next((k for k, names in INSN_KINDS if m in names), "other")


def move_class(m):
    body = [c for c in m.get("across", []) if not c.get("frame")]      # a register save aliases nothing
    if m.get("frame") and not body:
        return "frame"
    if m.get("frame") or not body:
        return "prologue"
    mine = insn_kind(m["insn"])
    others = {insn_kind(c["insn"]) for c in body}
    if {mine} | others == {"store"}:
        return "stores"
    if "store" in {mine} | others and "load" in {mine} | others:
        return "load-store"
    if re.match(r"\S+\s+\$(a[0-3]|t[0-3]|f1[2-9]),", m["insn"]) and all(
            re.match(r"\S+\s+\$(a[0-3]|t[0-3]|f1[2-9]),", c["insn"]) for c in body):
        return "args"
    return "prologue" if len(body) < len(m["across"]) else "other"


def move_lines(k, n, m):
    """One displaced instruction in plain terms."""
    across = m.get("across", [])
    frame = lambda c: " (register save)" if insn_kind(c["insn"]) == "store" else " (register restore)"
    where = f" (line {m['line']})" if m.get("line") else frame(m) if m.get("frame") else ""
    names = ", ".join(f"`{c['insn']}`" + (f" (line {c['line']})" if c.get("line") else frame(c) if c.get("frame") else "")
                      for c in across[:3])
    names += f" and {len(across) - 3} more" if len(across) > 3 else ""
    if len(across) == 1:
        a, b = (f"`{m['insn']}`{where}", names) if m["early"] else (names, f"`{m['insn']}`{where}")
        text = f"the draft issues {a} before {b}; the original has them the other way round"
    else:
        side = "earlier" if m["early"] else "later"
        rest = "come first" if m["early"] else "come after it"
        text = (f"`{m['insn']}`{where} is issued {len(across)} instructions {side} than in the original, where "
                f"{names} {rest}")
    lines = [m.get("line")] + [c.get("line") for c in across[:2]]
    return [f"- Order {k} of {n} (the scheduler after register allocation): {text}"], [x for x in lines if x], move_class(m)


# ---------------------------------------------------------------- the report

def clip(text, n=120):
    text = " ".join(text.split())
    return text if len(text) <= n else text[:n - 3] + "..."


def tried(addr, sha):
    """The mechanical passes that already ran on this text without a match."""
    out = []
    try:
        steps = collections.OrderedDict()
        with open(os.path.join(ROOT, "build", "finish", "results.jsonl"), encoding="utf-8") as f:
            for line in f:
                if f'"{addr:08x}"' in line:
                    r = json.loads(line)
                    if r.get("sha") == sha and not r.get("matched"):
                        steps[r["step"]] = r
        names = {"sweep": "every compiler profile", "context": "the `throw()` subsets of its callees",
                 "rewrite": "{n} single-step rewrites (order of declarations, one operand exchange, two adjacent "
                            "statements exchanged, a statement in a block)", "permute": "decomp-permuter"}
        out += [names[s].format(n=r.get("variants", "the")) for s, r in steps.items() if s in names]
    except (OSError, ValueError):
        pass
    aim = (load(os.path.join(ORACLE, "aim.json"), {}).get("per_draft") or {}).get(f"{addr:08x}_{sha}")
    n = sum(r.get("n", {}).get("aimed", 0) for r in (aim or {}).get("rounds", []))
    if n:
        out.append(f"{n} rewrites aimed at these decisions (a declaration moved, a temporary named or folded, a "
                   "callee's return type, operands exchanged)")
    return out


def unit_context(addr):
    """tools/unit_map.py's predicted translation-unit context, as what to write into the draft:
    the first-line marker and the prototypes to annotate. '' when it predicts nothing."""
    if not UNIT_CONTEXT or not os.path.exists(os.path.join(TOOLS, "unit_map.py")):
        return ""
    try:
        import unit_map
        text = unit_map.context_for(addr) or ""
    except (Exception, SystemExit):
        return ""
    head, _, body = text.partition("\n")
    if not body:
        return ""
    unit = re.search(r"unit 0x[0-9A-Fa-f]+ to [^)]+", head)
    return ("Translation-unit context to write into the draft (" + (unit.group(0) + "; " if unit else "") +
            "a prediction by tools/unit_map.py from the matched functions around it, right about 19 times in 20; a "
            "prototype is annotated as `extern \"C\" void func_X(int) throw();`. If the diff then shows `beq` against "
            "`beql` or another delay-slot fill after a call, toggle that callee's `throw()`. `try` also judges a draft "
            "within 20 instructions once more with this context and says so in a `note:` line):\n" + body)


def classify(c):
    """How much a certified draft's report says: `specific` (every shown decision names a variable
    or a source line, and its kind has rules of its own), `located` (named, but only the general
    rule applies), `bare` (nothing to point at: "allocation differs")."""
    row, ex = c.get("row") or {}, c.get("ex") or {}
    if c["level"] != 0:
        return None
    if c["label"] == "match":
        return "specific"
    tied, classes = [], []
    for d in ((row.get("causal") or ex.get("causal") or {}).get("decisions") or []):
        tied.append(bool(d.get("var") or d.get("line")))
        classes.append(decision_class(d))
    for sw in (row.get("reload") or {}).get("swaps", []):
        tied.append(bool(sw.get("line")))
        classes.append("operand")
    for m in ex.get("moves") or []:
        tied.append(bool(m.get("line") or any(x.get("line") for x in m.get("across", []))))
        classes.append(move_class(m))
    if not tied or not any(tied):
        return "bare"
    return "located" if all(k in ("other", "life", "frame") for k in classes) else "specific"


def report(addr, lazy=True):
    """The text for `swarm.py prompt ADDR` ('' when nothing is kept and no context is predicted)."""
    found = candidates(addr)
    if lazy and LAZY_SECONDS > 0 and found and not any(c["level"] == 0 for c in found):
        if align_lazily(addr, found):
            found = candidates(addr)
        new = next((c for c in found if c["level"] == 2 and c["differ"] <= LAZY_DIFFER), None)
        if new and "lazy" not in new["ex"] and measure_lazily(addr, os.path.join(ROOT, new["path"])):
            found = candidates(addr)
    out = []
    if found:
        out = draft_report(addr, found)
    # a certified draft's profile and throw() declarations are proven by its certificate
    context = "" if found and found[0]["level"] == 0 else unit_context(addr)
    if context:
        out += context.split("\n")[:7]
    return "\n".join(out)


def how_far(c, of, short=False):
    """A draft's distance in words: the aligned count, with the judge's row count beside it when
    the two differ."""
    if c["differ"] < c["rows"]:
        text = (f"{c['differ']} instruction{'s differ' if c['differ'] != 1 else ' differs'} once the listings are aligned (the judge's row-by-row count says "
                f"{c['rows']} of {of or '?'}: it counts every row an inserted or moved instruction shifts)")
        return f"{c['differ']} aligned, {c['rows']} by rows" if short else text
    unknown = "" if "aligned" in (c.get("ex") or {}) or c["rows"] <= SHIFTED or short else \
        " by the judge's row count (aligned count not computed yet: a shift would make it far smaller)"
    return f"{c['differ']}" if short else f"{c['differ']} of {of or '?'} instructions differ{unknown}"


def draft_report(addr, found):
    best = found[0]
    row, ex, att = best["row"] or {}, best["ex"], best["attempt"] or {}
    try:
        source = open(os.path.join(ROOT, best["path"]), encoding="utf-8", errors="replace").read().split("\n")
    except OSError:
        source = []
    marker = re.match(r"/\* compiler: ([\w.+-]+) \*/", source[0] if source else "")
    profile = marker.group(1) if marker else "the project's default"
    of = row.get("original") or att.get("of")
    kept = f", kept from {att['worker']}" + (f" ({att['tier']})" if att.get("tier") else "") if att.get("worker") else ""
    out = ["Retry report (the kept drafts and the compiler oracle; tools/retry_brief.py):",
           f"- Start from {best['path']}: {how_far(best, of)}; compiler profile "
           f"{profile}" + (" (keep its first line)" if marker else "") + kept + "."]
    spots, classes, names = [], [], {}
    if best["label"] == "match":
        out.append("- The oracle judged this text a MATCH as it is: run `try` on it unchanged. If `try` says the source "
                   "already exists, the function is defined inside another function's file: give up with that note.")
    elif best["level"] == 0:
        ca = row.get("causal") or ex.get("causal") or {}
        decisions = ca.get("decisions") or []
        swaps = (row.get("reload") or {}).get("swaps") or []
        moves = ex.get("moves") or []
        total = len(decisions) + len(swaps) + len(moves)
        what = {"allocation": "register", "schedule": "instruction order", "allocation+schedule": "register and order"}[best["label"]]
        if swaps:
            what = "operand order" if not decisions else what + " and operand order"
        out.append(f"- Its logic is CERTIFIED complete: made to take the original's {what} choice at "
                   f"{total or 'a few'} point{'s' if total != 1 else ''}, Sony's compiler turns this text into the original "
                   "exactly. Do not change what it computes, its compiler line or its `throw()` declarations (the "
                   "certificate proves them too); change only the shape that moves each choice below. A certificate is "
                   "not a match: only `try` printing MATCH counts.")
        shown = 0
        for k, d in enumerate(decisions, 1):
            if shown == SHOWN:
                break
            text, lines, cls, nm = decision_lines(k, len(decisions), d)
            out += text
            if cls in ("v0-taken", "v0-free") and d.get("line"):
                near = calls_before(source, d["line"])
                if near:
                    out.append("    calls up to that line: " + ", ".join(f"{c} (line {n}, declared `{t}`)" for c, n, t in near))
            spots += lines
            classes.append(cls)
            names.setdefault(cls, nm)
            shown += 1
        for sw in swaps[:max(0, SHOWN - shown)]:
            out.append(f"- Operand order, line {sw.get('line')}: the original has `{sw['original']}`, the draft `{sw['mine']}`.")
            spots.append(sw.get("line"))
            classes.append("operand")
            shown += 1
        for k, m in enumerate(moves, 1):
            if shown >= SHOWN + (1 if not decisions else 0):
                break
            text, lines, cls = move_lines(k, len(moves), m)
            out += text
            spots += lines
            classes.append(cls)
            shown += 1
        if total > shown:
            out.append(f"  (+{total - shown} more: python3 tools/oracle.py report {addr:08x} {best['path']})")
        if ca.get("result") == "stuck" or (best["label"] == "allocation" and row.get("distance") is None and not decisions):
            out.append("- The registers alone give the original, but this text cannot be allocated that way: a value "
                       "lives longer or shorter in the original.")
            classes.append("life")
        if moves and not any(m.get("line") or any(x.get("line") for x in m.get("across", [])) for m in moves[:SHOWN]):
            out.append("  (these instructions come from the prologue or from reload: no source line of their own)")
    elif best["row"]:
        left = (row.get("reload") or {}).get("differ_forced")
        sched = (ex.get("sched") or {}).get("result")
        if row.get("kind") == "error":
            out.append("- The oracle could not read it (it may not compile as it is).")
        elif sched in ("not reproduced", "closer"):
            out.append("- Not certified: its instructions are the original's in another order, but steering the scheduler "
                       "alone does not reproduce the original (a delay-slot or earlier decision): read the diff.")
        elif left is not None and row.get("kind") == "allocation+other":
            out.append(f"- Not certified: with {len(row['reload'].get('force', {}))} values moved to the original's registers, "
                       f"{left} instruction{'s' if left != 1 else ''} still differ ({row.get('residual_class')}): something "
                       "besides register choice differs; read the diff for the lines that are not a register rename.")
        else:
            out.append(f"- Not certified: the difference is not register allocation alone ({row.get('residual_class') or row.get('natural_class')}).")
    else:
        cls = f" ({att['class']})" if att.get("class") else ""
        out.append(f"- Not measured by the oracle yet{cls}; the lead's `tools/retry_brief.py refresh` does it.")
    seen = set()
    for n in spots:
        if n and n not in seen and 0 < n <= len(source) and len(seen) < 4:
            seen.add(n)
            out.append(f"    line {n}: {clip(source[n - 1])}")
    order = [c for i, c in enumerate(classes) if c not in classes[:i]][:2]
    table = dict(EDITS, **SCHED_EDITS)
    for cls in order:
        fill = names.get(cls, {"first": "the one the original places first", "second": "the other"})
        rules = table[cls][:3 if len(order) == 1 else 2]
        out.append(f"- Edits the project's rules give for this ({TITLES[cls]}):")
        out += [f"    {chr(97 + i)}. " + r.replace("{first}", fill["first"]).replace("{second}", fill["second"])
                for i, r in enumerate(rules)]
    done = tried(addr, best["sha"])
    if done:
        out.append("- Already run on this text without a match (do not repeat single steps of these): " + "; ".join(done) + ".")
    others = [c for c in found[1:] if c["differ"] < best["differ"]]
    if others:
        o = min(others, key=lambda c: c["differ"])
        out.append(f"- Fewer instructions differ in {o['path']} ({how_far(o, of, short=True)}), but its logic is not certified.")
    if len(found) > 1:
        out.append(f"- {len(found)} drafts are kept: python3 tools/attempt_store.py show {addr:08x}")
    return out


# ---------------------------------------------------------------- measuring (refresh, and lazily)

class Timeout(Exception):
    pass


def _alarm(*_):
    raise Timeout()


def _same(word):
    """A word as it compares across positions: a branch without its displacement."""
    op = word >> 26
    if op in (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or (op == 0x11 and (word >> 21) & 31 == 8):
        return word & 0xFFFF0000
    return word


def heaviest_increasing(seq, weight):
    """Indices of the heaviest increasing subsequence of seq: the instructions that stay."""
    n = len(seq)
    best, prev = list(weight), [-1] * n
    for i in range(n):
        for j in range(i):
            if seq[j] < seq[i] and best[j] + weight[i] > best[i]:
                best[i], prev[i] = best[j] + weight[i], j
    i = max(range(n), key=best.__getitem__) if n else -1
    keep = set()
    while i >= 0:
        keep.add(i)
        i = prev[i]
    return keep


def displaced(session, lst):
    """The instructions of a draft that is a permutation of the original which sit elsewhere: for
    each, its text, source line, whether the draft has it early, and the instructions it crossed.
    None when the listing is not a permutation. Frame instructions (saves and restores, which
    have no source line) are kept in place where there is a choice."""
    import match
    mine = [_same(w) for w in lst.linked]
    raw = session.padded(len(mine))
    target = [_same(w) for w in raw]
    if len(mine) != len(target) or collections.Counter(mine) != collections.Counter(target):
        return None
    where = collections.defaultdict(list)
    for j, w in enumerate(target):
        where[w].append(j)
    to = [where[w].pop(0) for w in mine]

    def describe(i):
        uid = lst.words[i][2]
        text = " ".join(match.disasm(lst.linked[i], session.addr + 4 * i).split())
        frame = uid not in session.by_uid and bool(re.search(r"\(\$sp\)$", text)) and insn_kind(text) != "other"
        return {"insn": text, "line": session.line_of(uid) if uid in session.by_uid else None, "frame": frame, "at": i, "to": to[i]}

    info = [describe(i) for i in range(len(mine))]
    keep = heaviest_increasing(to, [1.01 if x["frame"] or not x["line"] else 1.0 for x in info])
    out = []
    for i in range(len(mine)):
        if i in keep:
            continue
        early = [k for k in sorted(keep) if k > i and to[k] < to[i]]
        late = [k for k in sorted(keep) if k < i and to[k] > to[i]]
        across = early or late
        out.append(dict(info[i], early=bool(early), across=[info[k] for k in across[:6]], crossed=len(across)))
    return out


def brief_one(item):
    """The scheduler's verdict on one draft whose residual is a permutation, and what it takes to
    say it in source terms. Writes build/oracle/ADDR_SHA.brief.json and returns it."""
    addr, path, row, seeded, seconds = item
    started = time.time()
    out = {"version": VERSION, "addr": f"{addr:08x}", "sha": row["sha"], "draft": rel(path)}
    signal.signal(signal.SIGALRM, _alarm)
    signal.alarm(int(seconds))
    try:
        sys.path.insert(0, os.path.join(TOOLS, "oracle"))
        import orc_aim
        import orc_core as C
        fp = row.get("reload") or {}
        force = {p: v[1] for p, v in fp.get("force", {}).items()} if row.get("kind") == "allocation+other" else {}
        sched = seeded or orc_aim.sched_one((addr, path, force))
        out["sched"] = {k: sched.get(k) for k in ("result", "passes", "slots", "picks_changed", "registers_forced",
                                                  "differ", "best", "steps", "error") if k in sched}
        if sched.get("result") == "reproduced":
            with C.Session(addr, path) as s:
                s.natural()
                lst = s.lst
                if force:
                    f = {int(p): h for p, h in force.items()}
                    lst = s.forced("p", f)[2]
                    want = {int(p): h for p, h in s.forced("t", {}, at="alloc", trace="light")[4].get("renumber", {}).items()}
                    want.update(f)
                    out["causal"] = s.causal(want)
                out["moves"] = displaced(s, lst)
    except Timeout:
        out["error"] = f"over {seconds}s"
    except Exception as e:  # one bad draft must not stop the run
        out["error"] = f"{type(e).__name__}: {e}"[:300]
    finally:
        signal.alarm(0)
    out["seconds"] = round(time.time() - started, 1)
    return merge(addr, row["sha"], out)


def align_one(item):
    """The aligned distance of one kept draft (finish_near.judge: the judge again, then
    finish_near.aligned_distance on its diff), cached in the draft's brief."""
    addr, path, sha = item
    try:
        import finish_near
        v = finish_near.judge(addr, rel(path))
    except (Exception, SystemExit) as e:
        v = {"status": "error", "error": str(e)}
    if v.get("status") == "different":
        fields = {"aligned": v["distance"], "positional": v.get("positional", v["distance"])}
    else:
        fields = {"aligned": 0 if v.get("status") == "match" else None, "judge": v.get("status")}
    merge(addr, sha, fields)
    return addr, sha, fields


def align_lazily(addr, found):
    """Inside `prompt`, when no draft is certified: the aligned count of at most LAZY_JUDGES drafts
    whose row count is high enough to be a shift, the lowest row counts first. True when one moved."""
    todo = [c for c in found if "aligned" not in c["ex"] and c["rows"] > SHIFTED and c["level"] != 0]
    todo.sort(key=lambda c: (c["rows"], c["path"]))
    moved = False
    for c in todo[:LAZY_JUDGES]:
        fields = align_one((addr, os.path.join(ROOT, c["path"]), c["sha"]))[2]
        moved |= fields.get("aligned") is not None
    return moved


def wants_schedule(row):
    return row.get("natural_class") == "order" or (row.get("kind") == "allocation+other" and row.get("residual_class") == "order")


def measure_lazily(addr, path):
    """Inside `prompt`: the oracle's report on one stored draft nobody measured, within
    LAZY_SECONDS, once per content (a draft that runs over is left to `refresh`). True when a
    report was written."""
    sha = digest(path)
    started = time.time()
    note = {"draft": rel(path), "lazy": "started"}
    merge(addr, sha, note)                   # whatever happens, `prompt` does not pay for this text twice
    old = signal.signal(signal.SIGALRM, _alarm)
    signal.setitimer(signal.ITIMER_REAL, LAZY_SECONDS)
    row = None
    try:
        import oracle
        row = oracle.one_report(addr, path)
        note["lazy"] = "measured"
    except Timeout:
        note["lazy"] = f"over {LAZY_SECONDS}s"
    except (Exception, SystemExit) as e:
        note["lazy"] = f"{type(e).__name__}: {e}"[:200]
    finally:
        signal.setitimer(signal.ITIMER_REAL, 0)
        signal.signal(signal.SIGALRM, old)
    note["lazy_seconds"] = round(time.time() - started, 1)
    merge(addr, sha, note)
    if row:
        update_index([addr])
    return bool(row)


# ---------------------------------------------------------------- the queue

def entry(addr, old=None):
    """The index row of one function: its closest draft and where it stands."""
    found = candidates(addr)
    if not found:
        return None
    b = found[0]
    row = b["row"] or {}
    left = (row.get("reload") or {}).get("differ_forced")
    e = {"draft": b["path"], "sha": b["sha"], "level": b["level"], "certified": b["label"], "decisions": b["decisions"],
         "differ": b["differ"], "rows": b["rows"], "left": min(b["differ"], left if left is not None else b["differ"]),
         "report": classify(b),
         "time": time.strftime("%Y-%m-%d %H:%M:%S")}
    if old and old.get("sha") == e["sha"] and old.get("certified") == e["certified"]:
        e["time"] = old.get("time", e["time"])     # since when this draft has stood as the function's report
    return e


def update_index(addrs=None):
    """Rewrite build/oracle/briefs.json: for `addrs`, or for every unmatched function with a
    measured or stored draft. One writer at a time."""
    import attempt_store
    import project
    os.makedirs(ORACLE, exist_ok=True)
    with open(os.path.join(ORACLE, "briefs.lock"), "w") as lock:
        try:
            import fcntl
            fcntl.flock(lock, fcntl.LOCK_EX)
        except ImportError:
            pass
        index = load(INDEX, {}) or {}
        functions = index.get("functions", {})
        if addrs is None:
            done = set(project.sources(refresh=True))
            names = {m.group(1) for m in map(ROW.match, os.listdir(ORACLE)) if m} | set(attempt_store.functions())
            addrs = [int(n, 16) for n in sorted(names) if int(n, 16) not in done]
            functions = {k: v for k, v in functions.items() if int(k, 16) in set(addrs)}
        for addr in addrs:
            key = f"{addr:08x}"
            e = entry(addr, functions.get(key))
            if e:
                functions[key] = e
            else:
                functions.pop(key, None)
        dump(INDEX, {"version": VERSION, "time": time.strftime("%Y-%m-%d %H:%M:%S"), "functions": functions})
    return functions


def queue(within=NEAR):
    """[(addr, index row)] of the functions worth a retry on the oracle's word, closest first:
    certified drafts by decisions left (then by aligned distance), then drafts with at most
    `within` instructions left, aligned or once the registers are forced. Reads the index only;
    the caller drops matched and leased ones."""
    functions = (load(INDEX, {}) or {}).get("functions", {})
    out = [(int(k, 16), e) for k, e in functions.items()
           if e["level"] == 0 or (e.get("left") is not None and e["left"] <= within)]
    out.sort(key=lambda x: (min(x[1]["level"], 1), x[1]["decisions"] if x[1]["level"] == 0 else x[1]["left"], x[1]["differ"], x[0]))
    return out


# ---------------------------------------------------------------- commands

def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def cmd_show(a):
    addr = int(re.sub(r"^(func_|0x)", "", a.addr, flags=re.I), 16)
    text = report(addr, lazy=not a.no_lazy)
    print(text or "nothing kept for this function, and no predicted context")


def cmd_refresh(a):
    import oracle
    import project
    started = time.time()
    done = set(project.sources(refresh=True))
    only = {int(x, 16) for x in a.only.split(",")} if a.only else None
    items = [(addr, path) for addr, path in oracle.corpus() if only is None or addr in only]
    lost_before = oracle.lost_drafts() if not a.fresh else set()
    new = [(addr, path) for addr, path in items if not os.path.exists(oracle.out_path(addr, path))
           and os.path.relpath(path, ROOT) not in lost_before]
    log(f"refresh: {len(items)} kept drafts of {len({i[0] for i in items})} unmatched functions; {len(new)} not measured yet")
    with multiprocessing.Pool(a.jobs) as pool:
        work = [(addr, path, a.seconds, False) for addr, path in new]
        # One result at a time with a time limit: a worker that dies under gdb never returns its
        # task, and imap would wait for it for ever (the pool replaces the worker, the rest goes on).
        pending = [(w, pool.apply_async(oracle.measure_one, (w,))) for w in work]
        lost = []
        for n, (w, res) in enumerate(pending, 1):
            try:
                res.get(timeout=(a.seconds or 240) + 60)
            except multiprocessing.TimeoutError:
                lost.append(w)
            except Exception as e:
                lost.append(w)
                log(f"  {w[0]:08x} {os.path.relpath(w[1], ROOT)}: {type(e).__name__}: {str(e)[:100]}")
            if n % 10 == 0 or n == len(work):
                log(f"  measured {n} of {len(work)}; {time.time() - started:.0f}s")
        for w in lost:
            log(f"  not measured (no result): {w[0]:08x} {os.path.relpath(w[1], ROOT)}")
            oracle.mark_lost(w[0], w[1])
        # the scheduler, for drafts whose residual is a permutation and that have no verdict yet
        seeds = {}
        for r in (load(os.path.join(ORACLE, "sched.json"), {}) or {}).get("rows", []):
            seeds[(r["addr"], r["draft"])] = r
        todo = []
        for name in sorted(os.listdir(ORACLE)):
            m = ROW.match(name)
            if not m or int(m.group(1), 16) in done or (only is not None and int(m.group(1), 16) not in only):
                continue
            row = load(os.path.join(ORACLE, name))
            if not row or not wants_schedule(row):
                continue
            addr = int(m.group(1), 16)
            old = load(brief_path(addr, row["sha"]), {})
            if old.get("version") == VERSION and "sched" in old and not a.fresh:
                continue
            path = text_of(addr, row)
            if path:
                seed = seeds.get((row["addr"], row.get("draft"))) if rel(path) == row.get("draft") and not a.fresh else None
                todo.append((addr, path, row, seed if seed and seed.get("result") in ("reproduced", "not reproduced", "closer") else None,
                             a.seconds))
        log(f"scheduler: {len(todo)} permutation drafts without a verdict ({sum(1 for t in todo if t[3])} taken from oracle.py sched)")
        counts = collections.Counter()
        for n, out in enumerate(pool.imap_unordered(brief_one, todo), 1):
            counts[(out.get("sched") or {}).get("result") or out.get("error", "error")] += 1
            if n % 10 == 0 or n == len(todo):
                log(f"  {n} of {len(todo)}: {dict(counts)}; {time.time() - started:.0f}s")
        # the aligned distance of every kept draft that has none (the judge again: nothing keeps its diff)
        import attempt_store
        kept = {(addr, digest(path)): path for addr, path in items}
        for name in attempt_store.functions():
            addr = int(name, 16)
            if addr in done or (only is not None and addr not in only):
                continue
            for sha, att in attempt_store.attempts(name).items():
                if att.get("path") and att.get("verdict") == "differs":
                    kept.setdefault((addr, sha), att["path"])
        todo = [(addr, path, sha) for (addr, sha), path in sorted(kept.items())
                if sha and (a.fresh or "aligned" not in (load(brief_path(addr, sha), {}) or {}))]
        log(f"distance: {len(todo)} of {len(kept)} kept drafts without an aligned count")
        moved = 0
        for n, (addr, sha, fields) in enumerate(pool.imap_unordered(align_one, todo), 1):
            moved += fields.get("aligned") is not None and fields["aligned"] < fields.get("positional", 0)
            if n % 50 == 0 or n == len(todo):
                log(f"  {n} of {len(todo)}; {moved} closer aligned than by rows; {time.time() - started:.0f}s")
    if not a.no_summary and new:
        # the oracle's own summary and index (everything is cached by now)
        res = subprocess.run([sys.executable, os.path.join(TOOLS, "oracle.py"), "measure", "-j", str(a.jobs)],
                             capture_output=True, text=True, timeout=3600)
        print("\n".join((res.stdout + res.stderr).strip().splitlines()[-12:]))
    functions = update_index(None if only is None else sorted(only))
    log(f"index: {len(functions)} functions; build/oracle/briefs.json; {time.time() - started:.0f}s in all")
    print_stats(functions)


def print_stats(functions=None):
    functions = functions if functions is not None else (load(INDEX, {}) or {}).get("functions", {})
    cert = {k: e for k, e in functions.items() if e["level"] == 0}
    by = collections.Counter(e["certified"] for e in cert.values())
    kinds = collections.Counter(e["report"] for e in cert.values())
    near = sum(1 for e in functions.values() if e["level"] != 0 and e.get("left") is not None and e["left"] <= NEAR)
    n = max(len(cert), 1)
    print(f"{len(functions)} unmatched functions with a kept draft; {len(cert)} certified "
          f"({', '.join(f'{k}: {v}' for k, v in sorted(by.items()))}); {near} more within {NEAR} instructions, aligned or "
          "once registers are forced")
    print("report of the certified ones: " + ", ".join(
        f"{k} {kinds.get(k, 0)} ({100 * kinds.get(k, 0) // n}%)" for k in ("specific", "located", "bare")))


def cmd_queue(a):
    import project
    done = set(project.sources(refresh=True))
    rows = [(addr, e) for addr, e in queue(a.within) if addr not in done]
    for addr, e in rows:
        what = f"certified ({e['certified']}), {e['decisions']} decision(s)" if e["level"] == 0 else f"{e['left']} left"
        by_rows = f" ({e['rows']} by rows)" if e.get("rows", e["differ"]) != e["differ"] else ""
        print(f"{addr:08x}  {what:44s} {e['differ']:4d} differ{by_rows:16s} {e['report'] or '-':9s} {e['draft']}")
    print(f"{len(rows)} functions")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("show"); p.add_argument("addr"); p.add_argument("--no-lazy", action="store_true")
    p = sub.add_parser("refresh")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--only")
    p.add_argument("--seconds", type=int, default=240, help="time limit per draft")
    p.add_argument("--fresh", action="store_true", help="run the scheduler again on drafts that have a verdict")
    p.add_argument("--no-summary", action="store_true", help="do not rewrite oracle.py's summary.json")
    p = sub.add_parser("queue"); p.add_argument("--within", type=int, default=NEAR)
    sub.add_parser("stats")
    sub.add_parser("index")
    a = ap.parse_args()
    {"show": cmd_show, "refresh": cmd_refresh, "queue": cmd_queue, "stats": lambda a: print_stats(),
     "index": lambda a: print_stats(update_index())}[a.cmd](a)


if __name__ == "__main__":
    main()
