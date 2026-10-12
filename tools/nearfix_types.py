#!/usr/bin/env python3
"""Type-shape fixes for m2c near misses, read from the judge's diff. CPU only.

Judging the whole pool of "same length, 1-6 instructions off" drafts (2026-10-11) showed that
most of it is not a near miss at all (an empty stub or a draft that returns early, so the judge
trims the original to the draft's length) and that the genuine rest falls into a few type-level
classes that no register or statement-order recipe can move:

- `sw`/`sh`/`lw` where the draft has `sb`/`lhu`/`lb` at the same offset (a third of the genuine
  pool): m2c typed the access by another function's width. Widening the type alone is not enough:
  the original keeps the loads after the store, so the store's alias set must be 0. In the game's
  C++ a member of class type gets alias set 0 (gcc 2.96 c-common.c lang_get_alias_set: "It's not
  yet safe to use alias sets for classes in C++"); in C the same thing is an access through a
  union member (`M2C_FIELD(p, union AliasAny *, off).w = v`). Both the plain and the union access
  are tried, at the original's width.
- a virtual call through the old-ABI vtable entry `{s16 delta; s16 index; fn}`: m2c folds the
  entry address into the two loads (`lh 0x68($v1); lw 0x6C($v1)`) where the original computes it
  (`addiu $v1, $v1, 0x68; lh 0($v1); lw 4($v1)`): the matched sources' `VEntry *e_` statement
  expression (tools/dtors.py, src/) is written for every m2c call of that shape.
- a literal that is a global's address (`lui/ori` where the original has `lui/addiu` or a store
  through `lui $at`): near_fix's `addresses` and `derefs` rules, re-applied here because the
  drafts were remade after near_fix ran.
- a parameter declared narrower than the original's (`andi $s3, $a1, 0xFFFF` where the original
  copies `$a1`): the parameter becomes s32.

The rules are applied one at a time, the candidates of every function judged in one batch per
round (match.judge_many), the best kept and re-diffed, for up to --rounds rounds. A MATCH is
saved to src/ as regsearch.py does (never over an existing source; dedup; the attempts diary).

    nearfix_types.py [--max-differ 6] [--rounds 4] [--jobs 3] [--limit N] [--addrs FILE]
                     [--include-truncated] [--retry]

Work list: unmatched functions whose kept m2c draft (build/auto/cpu/ADDR.c) differs by at most
--max-differ instructions with the same length, minus stubs and truncated drafts (the draft's
judged length is shorter than the inventory's function). Results: build/auto/nearfix_types/
(results.jsonl, matched.txt, tried.txt, the work directory).
"""
import argparse
import json
import os
import re
import subprocess
import sys

import cpu_solve
import match
import near_fix
import project
import regsearch

ROOT = match.ROOT
OUT = os.path.join(ROOT, "build", "auto", "nearfix_types")
WORK = os.path.join(OUT, "work")
PRELUDES = (cpu_solve.PRELUDE, cpu_solve.LEGACY_PRELUDE)
UNION = "union AliasAny { s8 b; u8 ub; s16 h; u16 uh; s32 w; u32 uw; s64 d; f32 f; };\n"
VENTRY = "typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;\n"
# memory opcode -> (C type, union member)
WIDTH = {"sb": ("s8", "b"), "lb": ("s8", "b"), "lbu": ("u8", "ub"), "sh": ("s16", "h"), "lh": ("s16", "h"),
         "lhu": ("u16", "uh"), "sw": ("s32", "w"), "lw": ("s32", "w"), "lwu": ("u32", "uw"), "sd": ("s64", "d"),
         "ld": ("s64", "d"), "swc1": ("f32", "f"), "lwc1": ("f32", "f")}
SIZE = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4, "s64": 8}
ARG_REGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]
MEM = re.compile(r"^(-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)$")
FIELD = re.compile(r"M2C_FIELD\(([^()]*(?:\([^()]*\)[^()]*)*), (u8|s8|u16|s16|u32|s32|s64|f32|void \*|M2C_UNK\w*) \*, (0x[0-9A-Fa-f]+|\d+)\)")


def split_prelude(text):
    for p in PRELUDES:
        if text.startswith(p):
            return text[len(p):]
    return text


def assemble(body, decls=()):
    """The compilable file: a compiler marker (a decl starting with `/* compiler:`) first, then
    the prelude, the helper declarations and the body."""
    markers = [d for d in decls if d.startswith("/* compiler:")]
    return "".join(markers[-1:]) + cpu_solve.PRELUDE + "".join(d for d in decls if not d.startswith("/* compiler:")) + body


def profile_fixes(addr, body, rows, decls):
    """The same body under the compiler profile the diff points at (near_fix.profiles_for: a
    sibling `j` on one side only -> no sibling calls; loads and stores reordered -> no strict
    aliasing; the SDK range -> ee-gcc 2.9), unless the draft already carries a marker."""
    if any(d.startswith("/* compiler:") for d in decls):
        return []
    return [(f"profile {name}", body, (f"/* compiler: {name} */\n",)) for name in near_fix.profiles_for(addr, rows)]


def parse_rows(report):
    """[(left tokens, right tokens)] of the differing rows, operands without their commas."""
    strip = lambda toks: [t.rstrip(",") for t in toks if not t.startswith("<")]
    return [(strip(l), strip(r)) for l, r in near_fix.diff_lines(report)]


def columns(report):
    """The two instruction columns of the judge's listing (symbol tags dropped)."""
    left, right = [], []
    for line in report.splitlines():
        if line[:2] in ("! ", "  ") and "|" in line:
            l, r = line[2:].split("|", 1)
            left.append(" ".join(l.split()))
            right.append(" ".join(r.split("<")[0].split()))
    return left, right


def distance(report):
    """Instructions outside the longest common alignment of the two columns: one inserted
    instruction counts 1 here where the judge's positional count sees every row after it as
    different. None when the source did not compile; 0 on MATCH."""
    import difflib
    s = score(report)
    if s is None or s == 0:
        return s
    left, right = columns(report)
    matched = sum(b.size for b in difflib.SequenceMatcher(None, left, right, autojunk=False).get_matching_blocks())
    return max(len(left), len(right)) - matched


def mem_operand(tok):
    m = MEM.match(tok[-1]) if len(tok) == 3 else None
    return (int(m.group(1), 0), m.group(2)) if m else None


# --- rule 1: access width / alias set --------------------------------------------------------

def width_fixes(body, rows):
    """Candidates where one access of the draft gets the original's width: a plain one and a
    union (alias set 0) one per differing (offset, width) pair."""
    wanted = {}
    for left, right in rows:
        if not left or not right or left[0] not in WIDTH or right[0] not in WIDTH:
            continue
        lm, rm = mem_operand(left), mem_operand(right)
        if not lm or not rm or lm != rm or left[1] != right[1]:
            continue
        lt, rt = WIDTH[left[0]][0], WIDTH[right[0]][0]
        if lt == rt:
            continue
        wanted[(lm[0], rt)] = lt
    out = []
    for (off, mine_t), orig_t in wanted.items():
        # an offset above 0x7FFF reaches memory through `lui $at, 1; addu $at, base`: compare mod 0x10000
        hits = [m for m in FIELD.finditer(body) if int(m.group(3), 0) & 0xFFFF == off & 0xFFFF and SIZE.get(m.group(2)) == SIZE[mine_t]]
        if not hits:
            continue
        for union in (False, True):
            new, pos = [], 0
            for m in hits:
                new.append(body[pos:m.start()])
                if union:
                    new.append(f"M2C_FIELD({m.group(1)}, union AliasAny *, {m.group(3)}).{WIDTH_MEMBER[orig_t]}")
                else:
                    new.append(f"M2C_FIELD({m.group(1)}, {orig_t} *, {m.group(3)})")
                pos = m.end()
            new.append(body[pos:])
            out.append((f"width {off:#x} {mine_t}->{orig_t}{' union' if union else ''}", "".join(new), (UNION,) if union else ()))
    return out


WIDTH_MEMBER = {t: mem for t, mem in WIDTH.values()}


# --- rule 2: virtual call entries ------------------------------------------------------------

def balanced(text, start):
    """Index just past the parenthesis group opening at text[start] == '('."""
    depth = 0
    for i in range(start, len(text)):
        if text[i] == "(":
            depth += 1
        elif text[i] == ")":
            depth -= 1
            if depth == 0:
                return i + 1
    return None


VCALL_HEAD = re.compile(r"M2C_FIELD\(\((\w+) \+ (0x[0-9A-Fa-f]+)\), ")


def vcall_fix(body, adjust_local=False, void_unused=False):
    """Every `M2C_FIELD((V + OFF), RT (**)(...), 4)(OBJ + M2C_FIELD(V, s16 *, OFF), args)` as the
    VEntry statement expression; None when the draft has no such call. adjust_local: the adjusted
    object (`OBJ + delta`) is computed into a local before the call, which g++ does before the
    other arguments (the inline form evaluates it last, right to left); void_unused: a call whose
    result is dropped gets a void function type (the call then leaves `$v0` free for the entry)."""
    out, pos, n = [], 0, 0
    while True:
        m = VCALL_HEAD.search(body, pos)
        if not m:
            break
        v, off = m.group(1), m.group(2)
        # the function type runs to ", 4)(" at depth 0
        i, depth = m.end(), 0
        while i < len(body):
            c = body[i]
            if c == "(":
                depth += 1
            elif c == ")":
                if depth == 0:
                    break
                depth -= 1
            elif c == "," and depth == 0 and body.startswith(", 4)(", i):
                break
            i += 1
        if not body.startswith(", 4)(", i) or "(**)" not in body[m.end():i]:
            pos = m.end()
            continue
        ftype = body[m.end():i].replace("(**)", "(*)", 1)
        args_start = i + 4
        args_end = balanced(body, args_start)
        if args_end is None:
            pos = m.end()
            continue
        args = body[args_start + 1:args_end - 1]
        am = re.match(r"(\w+) \+ M2C_FIELD\(" + re.escape(v) + r", s(?:16|32) \*, " + re.escape(off) + r"\)(, |$)", args)
        if not am:
            pos = m.end()
            continue
        n += 1
        rest = args[am.end():]
        e = f"e{n}_"
        unused = re.search(r"[;{}]\s*$", body[:m.start()]) is not None  # the call is a statement by itself
        if void_unused and unused:
            ftype = re.sub(r"^\w+ \**(?=\(\*\))", "void ", ftype)
        this = f"(char *){am.group(1)} + {e}->delta"
        out.append(body[pos:m.start()])
        if adjust_local:
            out.append(f"({{ VEntry *{e} = (VEntry *)((char *){v} + {off}); void *o{n}_ = {this}; (({ftype}){e}->fn)(o{n}_"
                       + (", " + rest if rest else "") + "); })")
        else:
            out.append(f"({{ VEntry *{e} = (VEntry *)((char *){v} + {off}); (({ftype}){e}->fn)({this}"
                       + (", " + rest if rest else "") + "); })")
        pos = args_end
    if not n:
        return None
    out.append(body[pos:])
    return "".join(out)


# --- rule 3: parameter width -----------------------------------------------------------------

def param_fixes(body, rows):
    """The parameter that the draft masks or sign-extends where the original copies it, as s32."""
    narrow = set()
    for left, right in rows:
        if not right or len(right) != 4 or right[2] not in ARG_REGS:
            continue
        if right[0] == "andi" and right[3] in ("0xFF", "0xFFFF") or right[0] == "sll" and right[3] in ("16", "24"):
            if not left or left[:1] != right[:1] or left[2:] != right[2:]:
                narrow.add(ARG_REGS.index(right[2]))
    if not narrow:
        return []
    sig = re.search(r"(?m)^[\w \*]+\b(func_[0-9A-F]{8})\s*\(([^)]*)\)\s*\{", body)
    if not sig:
        return []
    params = [p.strip() for p in sig.group(2).split(",")]
    changed = False
    for k in sorted(narrow):
        if k < len(params):
            m = re.match(r"(u8|s8|u16|s16)\s+(\w+)$", params[k])
            if m:
                params[k] = f"s32 {m.group(2)}"
                changed = True
    if not changed:
        return []
    new = body[:sig.start(2)] + ", ".join(params) + body[sig.end(2):]
    return [("param width s32", new, ())]


# --- rule 4: literal addresses (near_fix's rules on the current draft) -----------------------

def literal_fixes(body, rows):
    out = []
    a = near_fix.addresses(body, rows)
    if a:
        out.append(("literal address (lui/addiu)", a, ()))
    d = near_fix.derefs(body)
    if d:
        out.append(("literal deref -> D_ADDR", d, ()))
    return out


def nearfix_variants(body, rows):
    """near_fix's structural rules, only when the diff points at them: a `$a0` set where the
    original sets another argument register (the caller's `this` passed on untouched), or a
    `$v0`/`$v1` swap (an unused result's callee declared void)."""
    out = []
    a0_wrong = any(l and r and len(l) == len(r) and r[1] == "$a0" and l[1] in ARG_REGS[1:] and l[0] == r[0] for l, r in rows)
    v_swap = any(l and r and len(l) == len(r) and l != r and
                 [x.replace("$v0", "$v1") if x == "$v0" else x.replace("$v1", "$v0") for x in l] == r for l, r in rows)
    if a0_wrong:
        out += [(f"this passed through (k{k})", v, ()) for k, v in enumerate(near_fix.this_passthrough(body))]
    if v_swap:
        out += [(f"void callee ({k})", v, ()) for k, v in enumerate(near_fix.void_returns(body))]
    return out


PURE = re.compile(r"^[\w\s\*\(\),\+\-&\.]*$")  # field reads, casts, arithmetic: no calls, no side effects


def inline_temp(body, name):
    """The body with the single-assignment temporary `name = EXPR;` (EXPR a pure field read)
    replaced by EXPR at every use and its declaration removed. The object of a virtual call is
    such a temporary in m2c's drafts; the original reads the field once into the argument
    register and cse makes the vptr fetch and the `this` adjustment read that register, where a
    named temporary is a pseudo that sched1's early copy to the argument register splits
    (func_002F1098, alloc_table: `r89 sugg $a2` lost to `$a3`). None when it does not apply."""
    sets = re.findall(r"(?m)^\s*" + re.escape(name) + r" = ([^;]+);\s*$", body)
    if len(sets) != 1 or not PURE.match(sets[0]) or "M2C_FIELD" not in sets[0]:
        return None
    expr = sets[0].strip()
    decl = re.search(r"(?m)^\s*[\w \*]+?\*?\s*\**" + re.escape(name) + r";\s*\n", body)
    if not decl:
        return None
    new = body[:decl.start()] + body[decl.end():]
    new = re.sub(r"(?m)^\s*" + re.escape(name) + r" = [^;]+;\s*\n", "", new, count=1)
    new, n = re.subn(r"\b" + re.escape(name) + r"\b", f"({expr})", new)
    return new if n else None


def candidates(body, rows):
    out = width_fixes(body, rows) + literal_fixes(body, rows) + param_fixes(body, rows)
    objects = set(re.findall(r", 4\)\((\w+) \+ M2C_FIELD\(\w+, s(?:16|32) \*, 0x[0-9A-Fa-f]+\)", body))
    for local in (False, True):
        for void in (False, True):
            v = vcall_fix(body, adjust_local=local, void_unused=void)
            if v and (not void or v != vcall_fix(body, adjust_local=local)):
                tag = f"vcall entry{' (this local)' if local else ''}{' (void)' if void else ''}"
                out.append((tag, v, (VENTRY,)))
                if not local:
                    for obj in sorted(objects):
                        w = inline_temp(v, obj)
                        if w:
                            out.append((f"{tag} + {obj} inlined", w, (VENTRY,)))
    out += nearfix_variants(body, rows)
    return out


# --- driver --------------------------------------------------------------------------------

def score(report):
    return regsearch.score(report)


def judged_length(report):
    m = re.search(r"instructions differ \(original (\d+), mine (\d+)\)", report)
    return int(m.group(1)) if m else None


def work_list(a):
    done = set(project.sources(refresh=True))
    tried = set()
    if not a.retry and os.path.exists(os.path.join(OUT, "tried.txt")):
        tried = {l.strip() for l in open(os.path.join(OUT, "tried.txt")) if l.strip()}
    items = {}
    if a.addrs:
        for l in open(a.addrs):
            if l.strip():
                addr = int(l.split()[0], 16)
                items[addr] = 0
    else:
        for l in open(os.path.join(ROOT, "build", "auto", "cpu", "results.jsonl")):
            try:
                r = json.loads(l)
            except ValueError:
                continue
            if r.get("result") == "differs" and r.get("same_length") and r.get("differ", 99) <= a.max_differ:
                addr = int(r["addr"], 16)
                items[addr] = min(items.get(addr, 99), r["differ"])
    out = {}
    for addr in sorted(items, key=lambda x: (items[x], x)):
        path = os.path.join(ROOT, "build", "auto", "cpu", f"{addr:08x}.c")
        if addr in done or f"{addr:08x}" in tried or not os.path.exists(path):
            continue
        text = open(path, encoding="utf-8", errors="replace").read()
        span = regsearch.body_span(text)
        if not span or len(re.sub(r"\s", "", text[span[0]:span[1]])) < 40:
            continue  # stub: m2c gave up on the body
        out[addr] = path
    return out


def save(addr, text, rules):
    if project.source_for(addr):
        return None
    path = os.path.join(ROOT, "src", f"func_{addr:08X}.c")
    open(path, "w", encoding="utf-8", newline="\n").write(text)
    ok, _ = match.judge(addr, path)
    if not ok:
        os.remove(path)
        return None
    subprocess.run([sys.executable, os.path.join(ROOT, "tools", "dedup.py"), "apply", f"{addr:x}"], capture_output=True, cwd=ROOT)
    subprocess.run([sys.executable, os.path.join(ROOT, "tools", "attempts.py"), "log", f"{addr:x}", "--hypothesis",
                    "nearfix_types: " + "; ".join(rules), "--result", "match", "--file", os.path.relpath(path, ROOT),
                    "--who", "nearfix_types"], capture_output=True, cwd=ROOT)
    return path


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--max-differ", type=int, default=6)
    ap.add_argument("--rounds", type=int, default=4)
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--addrs")
    ap.add_argument("--include-truncated", action="store_true", help="also drafts shorter than the function")
    ap.add_argument("--retry", action="store_true", help="ignore tried.txt")
    a = ap.parse_args()
    a.jobs = max(1, min(a.jobs, 3))
    os.makedirs(WORK, exist_ok=True)
    items = list(work_list(a).items())
    if a.limit:
        items = items[:a.limit]
    print(f"{len(items)} drafts to judge", flush=True)
    results = open(os.path.join(OUT, "results.jsonl"), "a", encoding="utf-8")
    tried = open(os.path.join(OUT, "tried.txt"), "a")
    # round 0: the drafts as they are (the recorded verdicts predate the last re-draft)
    state = {}  # addr -> dict(body, best, rows, rules, start)
    pairs = []
    for addr, path in items:
        body = split_prelude(open(path, encoding="utf-8", errors="replace").read())
        p = os.path.join(WORK, f"{addr:08x}_0.c")
        open(p, "w", encoding="utf-8", newline="\n").write(assemble(body))
        state[addr] = {"body": body, "decls": (), "rules": []}
        pairs.append((addr, p))
    truncated, stubs = 0, 0
    for addr, p, ok, report in match.judge_many(pairs, a.jobs):
        s = distance(report)
        st = state[addr]
        if s is None:
            st["best"] = None
            continue
        st["positional"] = score(report)
        n = judged_length(report)
        span = match.function_span(addr) // 4
        if n is not None and n < span - 2 and not a.include_truncated:
            truncated += 1
            st["best"] = None  # the draft is shorter than the function: no type fix recovers code
            results.write(json.dumps({"addr": f"{addr:08x}", "result": "truncated", "judged": n, "span": span}) + "\n")
            continue
        st["best"], st["start"], st["rows"] = s, s, parse_rows(report)
    live = [addr for addr in state if state[addr].get("best")]
    print(f"{len(live)} genuine near misses ({truncated} truncated drafts skipped)", flush=True)
    for rnd in range(1, a.rounds + 1):
        pairs, meta = [], {}
        for addr in live:
            st = state[addr]
            cands = candidates(st["body"], st["rows"]) + profile_fixes(addr, st["body"], st["rows"], st["decls"])
            for k, (rule, body, decls) in enumerate(cands):
                decls = tuple(dict.fromkeys(st["decls"] + decls))
                p = os.path.join(WORK, f"{addr:08x}_{rnd}_{k}.c")
                open(p, "w", encoding="utf-8", newline="\n").write(assemble(body, decls))
                pairs.append((addr, p))
                meta[p] = (rule, body, decls)
        if not pairs:
            break
        print(f"round {rnd}: {len(pairs)} candidates for {len({x for x, _ in pairs})} functions", flush=True)
        improved = {}
        for addr, p, ok, report in match.judge_many(pairs, a.jobs):
            s = distance(report)
            if s is not None and s < state[addr]["best"] and (addr not in improved or s < improved[addr][0]):
                improved[addr] = (s, p, report)
        for addr, (s, p, report) in improved.items():
            rule, body, decls = meta[p]
            st = state[addr]
            st.update(best=s, body=body, decls=decls, rows=parse_rows(report))
            st["rules"].append(rule)
        for _, p in pairs:
            if not (p in {v[1] for v in improved.values()}):
                os.remove(p)
        live = [addr for addr in improved if improved[addr][0] > 0]
        for addr in improved:
            if improved[addr][0] == 0:
                st = state[addr]
                saved = save(addr, assemble(st["body"], st["decls"]), st["rules"])
                print(f"{addr:08x}: MATCH ({st['start']} -> 0) {'; '.join(st['rules'])}" + ("" if saved else " (not saved: source exists)"), flush=True)
                if saved:
                    open(os.path.join(OUT, "matched.txt"), "a").write(f"{addr:08x} {'; '.join(st['rules'])}\n")
        if not live:
            break
    matched = 0
    for addr, st in state.items():
        if st.get("best") is None:
            continue
        tried.write(f"{addr:08x}\n")
        row = {"addr": f"{addr:08x}", "judge": st.get("positional"), "start": st["start"], "best": st["best"], "rules": st["rules"]}
        if st["best"] == 0:
            matched += 1
            row["result"] = "match"
        elif st["rules"]:
            row["result"] = "closer"
            open(os.path.join(WORK, f"{addr:08x}_best.c"), "w", encoding="utf-8", newline="\n").write(assemble(st["body"], st["decls"]))
        else:
            row["result"] = "no rule"
        results.write(json.dumps(row) + "\n")
    closer = sum(1 for st in state.values() if st.get("best") and st["rules"])
    print(f"done: {matched} matched, {closer} closer, of {len([1 for st in state.values() if st.get('best') is not None])} genuine near misses")


if __name__ == "__main__":
    main()
