"""The passes before register allocation cannot be forced, only read.

For a draft whose length differs from the original by a few instructions, the question is which
early pass made or removed the instruction: common-subexpression elimination reusing a value the
original computes twice, GCSE moving a load, jump optimisation merging two tails, combine fusing
two insns. The compiler writes the function after every pass (`-da`); every insn keeps its uid
through the passes, so the dumps side by side are a ledger: per pass, the insns it deleted, the
ones it made and the ones whose pattern it changed, each with its source line.

ledger   that table for one compile
explain  for the instructions only the draft has: the pass and line each came from; for the ones
         only the original has: the insns of the same kind that a pass deleted or rewrote on the
         lines around the place where the original has one more
"""
import collections
import glob
import os
import re

import orc_core as C
import orc_rtl as R

EARLY = ("rtl", "sibling", "jump", "cse", "addressof", "gcse", "loop", "cse2", "cfg", "bp", "flow", "life", "combine", "ce",
         "regmove", "sched", "lreg", "greg", "flow2", "ce2", "peephole2", "sched2", "jump2", "mach", "dbr")
_UIDS = re.compile(r"^\((insn|jump_insn|call_insn)(?:/\w)* (\d+) (\d+) (\d+) ", re.M)


def dumps(s, tag="n"):
    """[(pass name, path)] of the dumps of one compile, in the compiler's order: by their
    number where the compiler numbers them (2.96), else by the known order of passes (2.9)."""
    found = []
    for path in glob.glob(os.path.join(s.work, glob.escape(tag) + ".*")):
        parts = os.path.basename(path)[len(tag) + 1:].split(".")
        if len(parts) == 2 and parts[0].isdigit():
            found.append((int(parts[0]), parts[1], path))
        elif len(parts) == 1 and parts[0] in EARLY:
            found.append((EARLY.index(parts[0]), parts[0], path))
    return [(name, path) for _, name, path in sorted(found)]


def flat(node):
    if isinstance(node, list):
        return "(" + " ".join(flat(x) for x in node) + ")"
    return node


def patterns(s, tag, name, path):
    """{uid: (kind, pattern as text)} and the order of uids, for one pass of one function."""
    text = open(path, errors="replace").read()
    parts = R.split_functions(text)
    body = None
    plain = re.split(r"__(?=[FQ\d])", s.fname)[0]
    for head, b in parts:
        if re.search(rf"\b{re.escape(plain)}\b", head):
            body = b
    if body is None:
        return None, None
    insns, _ = R.parse_insns(body)
    out, order = {}, []
    for ins in insns:
        form = R.sexp(ins.text)
        pat = flat(form[4]) if len(form) > 4 else ""
        out[ins.uid] = (ins.kind, re.sub(r"\s+", " ", pat))
        order.append(ins.uid)
    return out, order


def split_set(pat):
    """(destination, source) of a single `(set DEST SRC)` as text, or (None, None)."""
    if not re.match(r"\(set \(", pat):
        return None, None
    depth, i = 0, pat.find("(", 5)
    for j in range(i, len(pat)):
        depth += pat[j] == "("
        depth -= pat[j] == ")"
        if depth == 0:
            return pat[i:j + 1], pat[j + 1:].strip()[:-1].strip()
    return None, None


def kind_of_rtl(kind, pat):
    if kind == "call_insn":
        return "call"
    if kind == "jump_insn":
        return "branch"
    m = re.match(r"\(set \((\w+)", pat)
    if not m:
        return "other"
    if m.group(1).startswith("mem"):
        return "store"
    src = split_set(pat)[1] or ""
    if "(mem" in src:
        return "load"
    if re.match(r"\((reg|subreg|const_int|const|symbol_ref|high|const_double|label_ref)\b", src):
        return "move"
    return "arith"


def kind_of_word(w):
    op, fn, rs, rt = w >> 26, w & 63, (w >> 21) & 31, (w >> 16) & 31
    if op == 3 or (op == 0 and fn == 9):
        return "call"
    if R.transfers(w):
        return "branch"
    if op in (0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x31, 0x35, 0x37, 0x1A, 0x1B, 0x1E):
        return "load"
    if op in (0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x39, 0x3D, 0x3F, 0x1F):
        return "store"
    if op == 0x0F or (op in (9, 0x19, 0x0D) and rs == 0) or (op == 0 and fn in (0x21, 0x2D, 0x25) and (rt == 0 or rs == 0)) or \
            (op == 0x11 and (rs in (0, 4, 1, 5) or (rs in (16, 17) and fn == 6))):
        return "move"
    return "arith"


def ledger(s, tag="n"):
    """[{pass, deleted, created, changed}]: what each pass before allocation did to the insn
    list. `deleted` and `created` are [uid, kind, line, pattern]; `changed` is [uid, kind, line,
    before, after, kind before]."""
    out, prev = [], None
    states = {}
    for name, path in dumps(s, tag):
        if name == "greg":
            break       # from here on the registers are hard ones and every pattern changes
        cur, order = patterns(s, tag, name, path)
        if cur is None:
            continue
        states[name] = cur
        if prev is not None:
            row = {"pass": name, "deleted": [], "created": [], "changed": []}
            for u, (k, p) in prev.items():
                if u not in cur:
                    row["deleted"].append([u, kind_of_rtl(k, p), s.line_of(u), p[:200]])
                elif cur[u][1] != p:
                    row["changed"].append([u, kind_of_rtl(*cur[u]), s.line_of(u), p[:200], cur[u][1][:200], kind_of_rtl(k, p)])
            for u, (k, p) in cur.items():
                if u not in prev:
                    row["created"].append([u, kind_of_rtl(k, p), near_line(s, order, u), p[:200]])
            if row["deleted"] or row["created"] or row["changed"]:
                out.append(row)
        prev = cur
    return out, states


def near_line(s, order, uid):
    """Line of an insn a later pass made: that of the nearest insn before it that has one."""
    i = order.index(uid)
    for u in reversed(order[:i]):
        line = s.lines.get(u) if hasattr(s, "lines") else None
        if line:
            return line
    return s.line_of(uid)


def explain(s, lst, report, tag="n"):
    """What the dumps say about the instructions one side has and the other has not."""
    mine, target = lst.linked, s.padded(len(lst.linked))
    only_mine, only_orig = R.unmatched(mine, target)
    led, states = ledger(s, tag)
    cols = C.columns(report)
    text = lambda side, i: cols[side][i] if i < len(cols[side]) else "?"
    last = states[list(states)[-1]] if states else {}
    born = {}
    for row in led:
        for u, k, line, p in row["created"]:
            born.setdefault(u, (row["pass"], line))
    out = {"length": [len(mine), len(target)], "extra": [], "missing": [],
           "ledger": {row["pass"]: {k: len(row[k]) for k in ("deleted", "created", "changed")} for row in led}}
    for i in only_mine[:6]:
        uid = lst.words[i][2]
        e = {"instruction": text(1, i), "uid": uid, "line": s.line_of(uid) if uid is not None else None}
        if uid in born:
            e["made_by"], e["line"] = born[uid][0], born[uid][1] or e["line"]
        elif uid is not None:
            e["made_by"] = "expansion of the source line"
        e["history"] = [{"pass": row["pass"], "before": c[3], "after": c[4]} for row in led for c in row["changed"] if c[0] == uid][:4]
        # the same value computed elsewhere too: the original has one of the two, so what lies
        # between them (a store, a call, a label) makes this compile compute it again
        if uid in last:
            src = split_set(last[uid][1])[1]
            if src and not re.match(r"\((reg|const_int|subreg)\b", src):
                e["same_value_at"] = [{"uid": u, "line": s.line_of(u)} for u, (k, p) in last.items()
                                      if u != uid and split_set(p)[1] == src][:3]
        out["extra"].append(e)
    pair = sorted(R.align_words(mine, target), key=lambda x: x[1])
    for j in only_orig[:6]:
        before = [i for i, jj in pair if jj < j]
        near = lst.words[before[-1]][2] if before else None
        k = 1
        while near is None and before and k < len(before):      # a nop or an assembler-made word has no uid
            k += 1
            near = lst.words[before[-k]][2]
        line = s.line_of(near) if near is not None else None
        want = kind_of_word(target[j])
        cands = []
        for row in led:
            for u, kind, ln, p in row["deleted"]:
                if kind == want and line and ln and abs(ln - line) <= 3:
                    cands.append({"pass": row["pass"], "what": "deleted", "uid": u, "line": ln, "rtl": p})
            for u, kind, ln, p, q, was in row["changed"]:
                if was == want and kind != want and line and ln and abs(ln - line) <= 3:
                    cands.append({"pass": row["pass"], "what": f"turned from a {want} into a {kind}", "uid": u, "line": ln,
                                  "rtl": p, "now": q})
        cands.sort(key=lambda c: (abs(c["line"] - line), EARLY.index(c["pass"]) if c["pass"] in EARLY else 99))
        out["missing"].append({"instruction": text(0, j), "kind": want, "after_insn": near, "line": line, "candidates": cands[:5]})
    out["accounted"] = bool(out["extra"] or out["missing"]) and all(e.get("made_by") for e in out["extra"]) and \
        all(m["candidates"] for m in out["missing"])
    return out


def sentences(e):
    """explain()'s result as lines of text."""
    out = []
    for x in e["extra"]:
        out.append(f"only the draft has `{x['instruction']}`: insn {x['uid']}"
                   + (f", line {x['line']}" if x.get("line") else "") + (f", made by {x['made_by']}" if x.get("made_by") else ""))
        for h in x.get("history", []):
            out.append(f"    {h['pass']} rewrote it: {h['before'][:90]}  ->  {h['after'][:90]}")
        for t in x.get("same_value_at", []):
            out.append(f"    the same value is computed by insn {t['uid']}" + (f" (line {t['line']})" if t["line"] else "")
                       + " too: the original has only one of the two")
    for m in e["missing"]:
        out.append(f"only the original has `{m['instruction']}` (a {m['kind']}), after insn {m['after_insn']}"
                   + (f", line {m['line']}" if m.get("line") else ""))
        for c in m["candidates"]:
            out.append(f"    {c['pass']} {c['what']} insn {c['uid']} (line {c['line']}): {c['rtl'][:100]}"
                       + (f"  ->  {c['now'][:80]}" if c.get("now") else ""))
        if not m["candidates"]:
            out.append("    no pass removed an instruction of that kind near that line: the source does not compute it")
    return out
