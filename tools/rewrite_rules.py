#!/usr/bin/env python3
"""Source rewrites mined from the edits that closed real near misses.

The two rewriters (finish_near.py rewrite: regsearch.variants; oracle.py aim: orc_rewrite.variants)
know which decision of the compiler is wrong and have few edits to try. Their tables hold: order
of the leading declarations, one declaration before another, a statement exchanged with a
neighbour or moved two places, operands of a commutative operator, a statement in a block or in
`do { } while (0)`, a declaration split from / joined with its first assignment at the top of its
block, an alias used or dropped, a temporary folded, a variable split at its second assignment, a
parenthesised subexpression or a call argument given a name right before its statement, a callee's
return type, the function's own return value from its last call.

This module adds the edit classes the mined pairs show and neither table had. One function per
rule; each works on the text of C++ (and C) drafts through a small statement parser, and none
needs types from the compiler. The judge is always the last word: a variant counts only when
`match.py check` says MATCH on it (finish_near.save() judges again).

    variants(text, aim=None, cap=None, seed=0, cplusplus=True, rules=None) -> [(rule, site, text)]

the same shape as orc_rewrite.variants, so both rewriters can append it to what they generate.
aim = {"vars": names, "lines": 1-based lines, ...} (orc_aim.sites(row)) keeps the sites the
oracle's report points to; None uses every site. RULES holds, per rule: the classes of difference
it answers, whether it preserves behaviour by construction ("exact") or can change it ("judge":
the rule checks what text can show, and only a MATCH proves the variant), and the mined evidence.

    rules_for(*classes) -> [names]  the rules that answer a class of difference
    review(text) -> [reasons]       spellings a person should tidy before the source is kept
                                    (`__typeof__` temporaries, a `do { } while (0)` wrapper)

How the two rewriters call it (neither is edited here)
    finish_near.py rewrite, where it builds `texts` for a draft:
        texts = [text] + regsearch.variants(text, rng, cap=a.variants) + [new for _, _, new in
                 rewrite_rules.variants(text, cap=a.variants, seed=int(key, 16), cplusplus=draft.endswith(".cpp"))]
    oracle.py aim, in orc_aim.write_variants, next to W.variants (same tuples, same aim dict):
        aimed += rewrite_rules.variants(text, aim=sites(row), cap=a.cap, cplusplus=cpp,
                                        rules=rewrite_rules.rules_for(row.get("residual_class") or row["natural_class"]))
    Both should hold back a MATCH whose text has review(text) reasons, as `measure` does here.
    Which decision each rule answers (RULES[name]["answers"]):
        registers (allocation: birth order, references, life)   move_far, name_base, name_load, stack_pointer, sink_init,
                                                                swap_arms, early_exit, ternary_if, return_param ($v0), local_sign,
                                                                loop_first_use, index_walk, drop_base, return_store, name_call, split_op
        order (scheduler: stores, loads, calls' arguments)      move_far, rotate_run, swap_arms, early_exit, sink_init, loop_form,
                                                                name_base, name_load, stack_pointer, loop_first_use (values set
                                                                up before a loop), return_store (the epilogue's restores),
                                                                drop_base (operands of an address), index_walk, name_call
                                                                (argument set-up), split_op
        branch-form (plain against likely, fall-through)        swap_arms, early_exit, ternary_if, loop_form, sink_init
        length                                                  early_exit, ternary_if, loop_form, name_base, local_sign,
                                                                index_walk, drop_base, split_op
    The judge's class tells little by itself (most mined edits closed a draft classed "other"), so
    "other" and an unknown class get every rule.

What was mined (2026-10-12, tools/mine_edits.py; edits of at most 8 code lines)
    876 pairs (failed draft, matched source) of 142 functions, 90 with a small edit; 393 steps
    (draft, next draft the judge counted closer), 105 small. Functions per edit class, closing / steps:
        compiler marker 27 / 6                      (finish_near sweep)
        callee throw() added 11 / 2                 (finish_near context)
        cast added, removed or changed 10 / 7       (mostly a side effect of another edit)
        statement order 10 / 13                     (neighbours 9 / 7: both tables; further 1 / 8: move_far, rotate_run)
        temporary added 10 / 12                     (name_base, name_load, stack_pointer; orc name_subexpr)
        access form 8 / 14                          (no rule: p[i] against *(p + n), offset casts)
        declaration order 7 / 11                    (both tables)
        struct layout or global declaration 7 / 11  (not a rewrite: the draft's types were wrong)
        callee returns void <-> a value 6 / 1       (orc callee_returns)
        own return type 4 / 1                       (orc self_returns, return_param)
        ternary <-> if 3 / 4, return shape 3 / 4, operand order 3 / 5, temporary removed 4 / 5,
        typedef signedness 3 / 4, do { } while (0) 3 / 0, if/else shape 1 / 7, loop form 1 / 1
    Against the 1041 written rules of knowledge/: every mined class has written rules except the
    `do { } while (0)` wrapper (it came from the blind rewriter, not from a person). Written and
    never seen in a small mined edit: real C++ constructs (130), union / alias set (49), switch
    form (26), bit-field (8), goto (5).

Measured (build/rewrite_rules/measure_r1.json, _r2.json): each rule alone, one step, at most 10
variants a draft, on the 335 kept near-miss drafts within 20 instructions:
        rule           drafts  variants  match  closer
        swap_arms          83       136      1      16    0033d810
        early_exit        125       178      2       8    00557f90 005752b0
        ternary_if         41        58      1       2    (0033d810 again)
        loop_form          86       232      0       3
        move_far          249      1909      3      54    00354ce8 004383b0 (00115f58: matched by a worker meanwhile)
        rotate_run         95       671      2      14    00194ad0 00362e58
        sink_init          74       128      1      13    (00115f58 again)
        stack_pointer      64       219      0       8
        name_base          33        81      0       4
        name_load         214      1173      0      23
        return_param      137       137      0       1
        local_sign        229       617      0       8    (239 variants did not compile)
    8 functions matched (7 saved), 5,874 judge calls, eleven minutes at 3 jobs. Second pass on the
    322 drafts left: move_far over three to six places, nearest first, 30 variants a draft: 1 more
    match (001e1528) and 65 closer in 4,197 variants; all four move_far matches are moves of
    exactly three places, the longer ones only came closer. local_sign writing the built-in type
    where the file has no typedef for the other signedness: 634 of 652 variants compile (was 378 of
    617), 1 match (002a6b88), 13 closer. None of the nine saved sources trips review().

Third iteration (2026-10-12): the edits a Sonnet worker closed four certified functions with, as
rules, each checked on the kept draft it closed (the rule's variant is a MATCH there):
        loop_first_use   003d5920   an assignment above a loop moved to its first use inside (and back)
        index_walk       003e3748   a pointer stepped beside the counter written as an index
        return_store     00556d80   a void function returning the value its last statement stores
                                    (own return type: the judge is the proof, the symbol keeps its name)
        drop_base        00566f90   a pointer temporary written out at its uses (reverse of name_base)
and the next closing edits without a rule from a second mining (tools/mine_edits.py pairs + table:
1,440 pairs of 224 functions, 148 with a small edit, 58 of them of functions matched since the first):
        name_call        0039d218   a nested call's result, or a comparison passed as an argument, named
                                    before the statement with the type the text's prototype gives
        split_op         005b7bb8   `x = a | b | c;` <-> `x = a | b; x |= c;` (MATCH on its draft)
        early_exit       0036ae20   also `if (c) { A } return x;` -> `if (!c) return x; A return x;` (MATCH)
        ternary_if       00365e80   also `x = c ? a : x;` -> `if (c) x = a;` (MATCH)
and the causes an Opus worker read in the sched dumps while matching the six certified functions a
Sonnet worker had given up on (each on its first judged try), as cause-to-edit rules:
        callee_return    001d1598 001d42e0 00493918   a scheduler pick decided by dependents N+1 against N
                                    around a call: the callee's declared return, void against a value,
                                    every prototype in turn (also swept blindly: no body edit)
        falls_off_end    00555088   restores or `$v0` stores of the last block out of source order: the
                                    function declared `int` with no `return` (and a `do { } while (0)`
                                    barrier unwrapped)
        count_up_for     0047ec98 0047f4c8   two copies before a loop ordered by the first scheduler's
                                    weight: a count-down over a walking pointer as an indexed `for`
        barrier_last     the fallback for a restore order: the last store in `do { } while (0)`;
                                    review() flags it, a MATCH with it is held back
    Not a rule: a real constructor with initialisers in offset order (002ccaa8).
    Still without a rule, by closing edits in the second mining: struct layout or a callee's
    parameter types (the draft's declarations were wrong: 12 + 3), a float constant one ulp off
    (0036ef28), an inverted test that is a logic fix (005b17d0), a counter stepped in the `for`
    header against the body with `i + 1` after it (00365bc0), a real constructor (002ccaa8).
    Measured inside the search they were built for (oracle.py climb, tools/oracle/orc_climb.py: 20
    functions matched and saved, with every rule of both tables in reach) and each alone, blind,
    on the 328 kept near-miss drafts within 20 instructions (measure_r3.json, measure_r4.json),
    matches in the search / matches and closer alone:
        callee_return   8 (one as the last of three edits) / 0 and 11 of 271 drafts, 1,578 variants
        falls_off_end   2 (00555088; 00472de8 after a swap)  / 0 and 7 of 155
        early_exit, a returned value   1 (004482f0)
        return_store    1 (0048fed0, after a swap)           / 0 and 0 of 41
        split_op        1 (00559a18)                         / the same 1 of 21
        drop_base       0 (00429e10 matches, but another file defines it) / 35 closer of 164
        barrier_last    0 / 4 closer of 69 (held back anyway)
        loop_first_use, index_walk, name_call, count_up_for   0 / 0 (36, 3, 84 and 0 drafts): each
                        matches the draft it was written from and no other kept draft yet
    The two prototype-level toggles are the table's strongest edits where the oracle has
    certified the draft (10 of the 20 matches) and find nothing swept over the other drafts.

    rewrite_rules.py list                              the rule table
    rewrite_rules.py show FILE [--rule R]              the variants of one draft, as diffs
    rewrite_rules.py measure [-jN] [--max-distance 20] [--cap 12] [--rules R,R] [--tag T] [--dry]
        every rule on every kept near-miss draft (finish_near.closest()), judged; per rule: drafts
        it applied to, matches, drafts closer. A natural match is saved by finish_near.save(); one
        that trips review() is kept under build/rewrite_rules/review/ and reported, not saved.
"""
import argparse
import collections
import difflib
import json
import os
import random
import re
import sys
import time

IDENT = re.compile(r"[A-Za-z_]\w*")
KEYWORDS = {"return", "goto", "delete", "new", "case", "else", "break", "continue", "throw", "sizeof", "if", "for",
            "while", "do", "switch", "default", "typedef", "using", "namespace"}
JUMPS = ("return", "goto", "break", "continue")
TYPEWORD = r"(?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+|class\s+|union\s+|enum\s+|register\s+|static\s+|long\s+|short\s+)*"
DECL = re.compile(
    rf"^\s*({TYPEWORD}[A-Za-z_]\w*(?:\s*::\s*\w+)*(?:\s*<[^;=(){{}}]*>)?(?:\s+(?:const|long|int|char|short))*[\s*&]*(?:const\s+)?[\s*&]*)"
    r"\b([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*(?:=\s*(?!=)(.*?))?;\s*$", re.S)
CHAIN = re.compile(r"(?<![\w.>])([A-Za-z_]\w*)((?:\s*(?:->|\.)\s*[A-Za-z_]\w*|\s*\[(?:[^\[\]]|\[[^\[\]]*\])*\])+)")
CHAIN_OP = re.compile(r"\s*(->|\.)\s*([A-Za-z_]\w*)|\s*(\[(?:[^\[\]]|\[[^\[\]]*\])*\])")
IMPURE = re.compile(r"[A-Za-z_]\w*\s*\(|\+\+|--|(?<![=!<>+\-*/%&|^])=(?!=)|[+\-*/%&|^]=|<<=|>>=")
FLOATS = re.compile(r"\b(?:float|double|f32|f64)\b|\d\.\d|\d\.?[fF]\b")
SIGN = {"int": "unsigned int", "unsigned int": "int", "unsigned": "int", "s32": "u32", "u32": "s32", "s16": "u16",
        "u16": "s16", "s8": "u8", "u8": "s8", "short": "unsigned short", "unsigned short": "short", "char": "unsigned char",
        "unsigned char": "char", "signed char": "unsigned char", "long": "unsigned long", "unsigned long": "long",
        "s64": "u64", "u64": "s64"}


# ---------------------------------------------------------------- text

def skip(text, i):
    """Index of the next character at or after i that is code: jumps comments and literals."""
    n = len(text)
    while i < n:
        c = text[i]
        if c == "/" and text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
        elif c == "/" and text.startswith("/*", i):
            j = text.find("*/", i + 2)
            i = n if j < 0 else j + 2
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            i = j + 1
        else:
            return i
    return n


def body_span(text, lo=0, hi=None):
    """(start, end) of the function body: the last top-level `{ ... }` of the file, looked for
    inside an `extern "C" { }` or `namespace N { }` wrapper when that is what the last block is."""
    depth, start, last = 0, None, None
    i, n = lo, len(text) if hi is None else hi
    while i < n:
        i = skip(text, i)
        if i >= n:
            break
        c = text[i]
        if c == "{":
            if depth == 0:
                start = i
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and start is not None:
                last = (start, i + 1)
        i += 1
    if last and re.search(r'(?:extern\s*"C"|namespace(?:\s+\w+)?)\s*$', text[lo:last[0]]):
        return body_span(text, last[0] + 1, last[1] - 1) or last
    return last


def word(text, i):
    m = IDENT.match(text, i)
    return m.group(0) if m else ""


def indent_of(text, pos):
    start = text.rfind("\n", 0, pos) + 1
    m = re.match(r"[ \t]*", text[start:pos])
    return m.group(0) if m else ""


def reindent(src, old, new):
    """src (its first line already placed) with the indentation `old` of its other lines made `new`."""
    lines = src.split("\n")
    return "\n".join([lines[0]] + [new + l[len(old):] if l.startswith(old) else l for l in lines[1:]])


def top_ops(e):
    """[(position, operator)] of the operators at depth 0 of an expression that decide how it can
    be negated or split: || && == != <= >= < > ? : = and the comma."""
    out, depth, i, n = [], 0, 0, len(e)
    while i < n:
        j = skip(e, i)
        if j != i:
            i = j
            continue
        c, two = e[i], e[i:i + 2]
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
        elif depth == 0:
            if two in ("->", "::", "++", "--") or two in ("<<", ">>"):
                i += 3 if e[i:i + 3] in ("<<=", ">>=") else 2
                if e[i - 1] == "=" and two in ("<<", ">>"):
                    out.append((i - 3, "="))
                continue
            if two in ("||", "&&", "==", "!=", "<=", ">="):
                out.append((i, two))
                i += 2
                continue
            if two in ("+=", "-=", "*=", "/=", "%=", "&=", "|=", "^="):
                out.append((i, "="))
                i += 2
                continue
            if c in "<>?:=,":
                out.append((i, c))
        i += 1
    return out


def is_primary(e):
    """An operand that `!` can be put in front of without parentheses."""
    e = e.strip()
    depth, i, n = 0, 0, len(e)
    lead = re.match(r"[*&!~\-\s]*", e).end()
    while i < n:
        c = e[i]
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= 1
        elif depth == 0 and i >= lead and not (c.isalnum() or c in "_. \t\n" or e[i:i + 2] == "->" or e[i - 1:i + 1] == "->"):
            return False
        i += 1
    return bool(e)


def strip_parens(e):
    e = e.strip()
    while e.startswith("(") and e.endswith(")"):
        depth = 0
        for k, c in enumerate(e):
            depth += c == "("
            depth -= c == ")"
            if depth == 0 and k < len(e) - 1:
                return e
        e = e[1:-1].strip()
    return e


def negate(cond, exact):
    """The condition negated, as a person would write it where that is exact: `==`/`!=` exchanged,
    a `!` added or dropped; a relational operator is flipped only when `exact` (the file has no
    floating point: `!(a < b)` is not `a >= b` for a NaN), else the whole is wrapped in `!( )`."""
    e = strip_parens(cond)
    ops = top_ops(e)
    kinds = {op for _, op in ops}
    if not ops:
        m = re.match(r"^!\s*(.+)$", e, re.S)
        if m and is_primary(m.group(1)) and not m.group(1).lstrip().startswith("!"):
            return strip_parens(m.group(1))
        return "!" + e if is_primary(e) else f"!({e})"
    if len(ops) == 1 and not kinds & {"||", "&&", "?", ":", "=", ","}:
        pos, op = ops[0]
        if op in ("==", "!="):
            return e[:pos] + ("!=" if op == "==" else "==") + e[pos + 2:]
        if exact:
            return e[:pos] + {"<": ">=", ">": "<=", "<=": ">", ">=": "<"}[op] + e[pos + len(op):]
    return f"!({e})"


def split_ternary(e):
    """(condition, value if true, value if false) when the whole expression is one `c ? a : b`."""
    e = strip_parens(e)
    ops = top_ops(e)
    if not ops or ops[0][1] != "?" or any(op in ("=", ",") for _, op in ops):
        return None
    depth = 0
    for pos, op in ops:
        if op == "?":
            depth += 1
        elif op == ":":
            depth -= 1
            if depth == 0:
                c, a, b = e[:ops[0][0]].strip(), e[ops[0][0] + 1:pos].strip(), e[pos + 1:].strip()
                return (c, a, b) if c and a and b else None
    return None


def pure(e):
    """No call, assignment, increment or decrement in the text of the expression."""
    return not IMPURE.search(re.sub(r"\bsizeof\s*\(", "(", e))


def declare(head, name):
    """`T x` / `T *x` from a declaration's type text and a name."""
    head = head.strip()
    return head + ("" if head.endswith(("*", "&")) else " ") + name


def uses(name, src):
    return re.findall(rf"(?<![\w.>])(?<!->){re.escape(name)}\b", src)


# ---------------------------------------------------------------- statements

class Node:
    __slots__ = ("kind", "start", "end", "parent", "index", "kids", "cond", "then", "els", "body", "word")

    def __init__(self, start, parent):
        self.kind, self.start, self.end, self.parent, self.index = None, start, None, parent, 0
        self.kids, self.cond, self.then, self.els, self.body, self.word = [], None, None, None, None, ""


class Tree:
    """The statements of the function body as a tree: block (kids), if (cond, then, els), for /
    while / switch (cond: the text inside the parentheses, body), do (body, cond), simple, label, pp."""

    def __init__(self, text):
        self.text, self.span, self.nodes, self.root = text, body_span(text), [], None
        if self.span:
            try:
                self.root = self._stmt(self.span[0], None)
            except (IndexError, RecursionError, ValueError):
                self.root, self.nodes = None, []

    def _ws(self, i):
        t, n = self.text, len(self.text)
        while i < n:
            if t[i].isspace():
                i += 1
            elif t.startswith("//", i) or t.startswith("/*", i):
                i = skip(t, i)
            else:
                return i
        raise IndexError

    def _close(self, i):
        """i at an opening bracket: the index after its closing one."""
        t, depth = self.text, 0
        while True:
            i = skip(t, i)
            if t[i] in "([{":
                depth += 1
            elif t[i] in ")]}":
                depth -= 1
                if depth == 0:
                    return i + 1
            i += 1

    def _stmt(self, i, parent):
        t = self.text
        n = Node(i, parent)
        self.nodes.append(n)
        if t[i] == "{":
            n.kind = "block"
            j = self._ws(i + 1)
            while t[j] != "}":
                kid = self._stmt(j, n)
                kid.index = len(n.kids)
                n.kids.append(kid)
                j = self._ws(kid.end)
            n.end = j + 1
            return n
        if t[i] == "#":
            n.kind = "pp"
            j = t.find("\n", i)
            while j > 0 and t[j - 1] == "\\":
                j = t.find("\n", j + 1)
            n.end = len(t) if j < 0 else j
            return n
        w = n.word = word(t, i)
        if w == "if":
            p = self._ws(i + 2)
            q = self._close(p)
            n.kind, n.cond = "if", (p + 1, q - 1)
            n.then = self._stmt(self._ws(q), n)
            n.end = n.then.end
            try:
                j = self._ws(n.then.end)
            except IndexError:
                return n
            if word(t, j) == "else":
                n.els = self._stmt(self._ws(j + 4), n)
                n.end = n.els.end
            return n
        if w in ("for", "while", "switch"):
            p = self._ws(i + len(w))
            q = self._close(p)
            n.kind, n.cond = w, (p + 1, q - 1)
            n.body = self._stmt(self._ws(q), n)
            n.end = n.body.end
            return n
        if w == "do":
            n.kind = "do"
            n.body = self._stmt(self._ws(i + 2), n)
            j = self._ws(n.body.end)
            if word(t, j) != "while":
                raise ValueError
            p = self._ws(j + 5)
            q = self._close(p)
            n.cond = (p + 1, q - 1)
            j = self._ws(q)
            if t[j] != ";":
                raise ValueError
            n.end = j + 1
            return n
        if w in ("case", "default"):
            depth = 0
            while not (t[i] == ":" and depth == 0 and t[i + 1] != ":" and t[i - 1] != ":"):
                i = skip(t, i)
                depth += t[i] in "(["
                depth -= t[i] in ")]"
                i += 1
            n.kind, n.end = "label", i + 1
            return n
        m = re.match(r"[A-Za-z_]\w*\s*:(?!:)", t[i:i + 80])
        if m and w not in KEYWORDS:
            n.kind, n.end = "label", i + m.end()
            return n
        depth = 0
        while True:
            i = skip(t, i)
            c = t[i]
            if c in "([{":
                depth += 1
            elif c in ")]}":
                depth -= 1
                if depth < 0:
                    raise ValueError
            elif c == ";" and depth == 0:
                n.kind, n.end = "simple", i + 1
                return n
            i += 1

    # ---- queries

    def src(self, n):
        return self.text[n.start:n.end]

    def cond(self, n):
        return self.text[n.cond[0]:n.cond[1]]

    def line(self, pos):
        return self.text.count("\n", 0, pos) + 1

    def decl(self, n):
        """(type text, name, array suffix, initialiser or None) if the statement declares one local."""
        if n.kind != "simple" or n.word in KEYWORDS:
            return None
        m = DECL.match(self.src(n))
        if not m:
            return None
        head = m.group(1).strip()
        if not head or head in KEYWORDS or not re.search(r"[A-Za-z_]", head) or "(" in head:
            return None
        return head, m.group(2), m.group(3), m.group(4)

    def jump(self, n):
        return n.kind == "simple" and n.word in JUMPS

    def stmts(self, kids, ind):
        """The statements as text at indentation ind, one per line."""
        return "\n".join(ind + reindent(self.src(k), indent_of(self.text, k.start), ind) for k in kids)

    def as_block(self, n, ind):
        kids = n.kids if n.kind == "block" else [n]
        return "{\n" + self.stmts(kids, ind + "    ") + "\n" + ind + "}"

    def unwrapped(self, n):
        return n.kids if n.kind == "block" else [n]


class Ctx:
    """One draft being rewritten: its text, statement tree and the sites an aim allows."""

    def __init__(self, text, aim=None, cplusplus=True):
        self.text, self.tree, self.cplusplus = text, Tree(text), cplusplus
        self.aim = aim
        self.lines = set(aim["lines"]) if aim else set()
        self.vars = set(aim["vars"]) if aim else set()
        self.exact = not FLOATS.search(text)
        self._types = None

    def on(self, start, end=None, names=()):
        """Is the text from start to end a site the report points to (a line of it, give or take
        one, or one of the variables)?"""
        if self.aim is None:
            return True
        if self.vars & set(names):
            return True
        a, b = self.tree.line(start), self.tree.line(start if end is None else max(start, end - 1))
        return any(l in self.lines for l in range(a - 1, b + 2))

    def on_node(self, n, names=()):
        if n.kind in ("if", "for", "while", "switch"):
            return self.on(n.start, n.cond[1], names)
        return self.on(n.start, n.end, names or IDENT.findall(self.tree.src(n))[:40])

    def replace(self, a, b, new):
        return self.text[:a] + new + self.text[b:]

    def fresh(self, base):
        name, k = base, 2
        while re.search(rf"\b{re.escape(name)}\b", self.text):
            name, k = f"{base}{k}", k + 1
        return name

    @property
    def types(self):
        if self._types is None:
            self._types = Types(self)
        return self._types

    def void_function(self):
        """The function returns nothing: its header says void and no return carries a value."""
        t, (a, b) = self.text, self.tree.span
        start = max(t.rfind(";", 0, a), t.rfind("}", 0, a)) + 1
        return bool(re.search(r"\bvoid\s+(?:[A-Za-z_]\w*\s*::\s*)*~?[A-Za-z_]\w*\s*\(", t[start:a])) and \
            not re.search(r"\breturn\s*[^;\s]", t[a:b])


class Types:
    """The types the text itself declares: members of its structs, the function's parameters and
    one-name local declarations. Enough to spell the type of `a->b[i]` in most drafts; None when
    the text does not say (the rule then falls back to `__typeof__`, which review() reports)."""

    def __init__(self, ctx):
        text, tree = ctx.text, ctx.tree
        self.structs, self.vars = {}, {}
        for m in re.finditer(r"\b(?:struct|class|union)\s+([A-Za-z_]\w*)\s*(?::[^{;]*)?\{", text):
            try:
                end = tree._close(m.end() - 1)
            except IndexError:
                continue
            fields, depth, piece = {}, 0, ""
            for c in text[m.end():end - 1]:
                depth += c in "({["
                depth -= c in ")}]"
                if c == ";" and depth == 0:
                    self._members(piece, fields)
                    piece = ""
                else:
                    piece += c
            self.structs[m.group(1)] = fields
        a = tree.span[0]
        close = text.rfind(")", 0, a)
        depth, i = 0, close
        while i >= 0:
            depth += text[i] == ")"
            depth -= text[i] == "("
            if depth == 0:
                break
            i -= 1
        if i > 0:
            for piece in self._split(text[i + 1:close]):
                self._members(piece, self.vars)
        for n in tree.nodes:
            d = tree.decl(n)
            if d:
                base = re.sub(r"[\s*&]+$", "", d[0])
                self.vars[d[1]] = (self._base(base), d[0].count("*") + d[2].count("["))

    @staticmethod
    def _split(s):
        out, depth, piece = [], 0, ""
        for c in s:
            depth += c in "({[<"
            depth -= c in ")}]>"
            if c == "," and depth == 0:
                out.append(piece)
                piece = ""
            else:
                piece += c
        return out + [piece]

    @staticmethod
    def _base(s):
        return " ".join(w for w in s.split() if w not in ("const", "volatile", "struct", "class", "union", "register", "static"))

    def _members(self, piece, into):
        piece = re.sub(r"/\*.*?\*/|//[^\n]*", " ", piece, flags=re.S).strip()
        if not piece or "(" in piece or "{" in piece:
            return
        m = re.match(rf"^({TYPEWORD}[A-Za-z_]\w*(?:\s+(?:int|char|short|long))*)\s*(.*)$", piece, re.S)
        if not m:
            return
        for d in self._split(m.group(2)):
            dm = re.match(r"^\s*((?:\*\s*|const\s+)*)([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*(?::\s*\d+)?\s*$", d)
            if dm:
                into[dm.group(2)] = (self._base(m.group(1)), dm.group(1).count("*") + dm.group(3).count("["))

    def chain(self, head, ops):
        """The type of head followed by the access operations ops, as (base, pointer depth)."""
        cur = self.vars.get(head)
        for op, name in ops:
            if cur is None:
                return None
            base, depth = cur
            if op == "[":
                cur = (base, depth - 1) if depth >= 1 else None
            elif (op == "->" and depth == 1) or (op == "." and depth == 0):
                cur = self.structs.get(base, {}).get(name)
            else:
                cur = None
        return cur

    @staticmethod
    def spell(t, name):
        return f"{t[0]} {'*' * t[1]}{name}"


# ---------------------------------------------------------------- the rules

RULES = collections.OrderedDict()


def rule(name, answers, proof, evidence, example, ordered=False):
    """Register a rule. answers: the classes of difference it is an edit for (attempt_store's
    registers / order / branch-form / length, and the oracle's allocation phases); proof: "exact"
    (same behaviour by construction) or "judge" (it can change behaviour: only a MATCH proves it);
    ordered: the rule yields its likeliest variants first, so a cap keeps the head of its list
    instead of a random sample."""
    def deco(fn):
        RULES[name] = {"fn": fn, "answers": answers, "proof": proof, "evidence": evidence, "example": example,
                       "ordered": ordered, "doc": " ".join((fn.__doc__ or "").split())}
        return fn
    return deco


@rule("swap_arms", ("branch-form", "order", "registers"), "exact",
      "mined: if/else shape 4 steps, inverted comparison 1 closing + 4 steps (00337fb8, 00190b50); "
      "regsearch.py's header names `a mirrored if/else` and never implemented it",
      "00337fb8")
def swap_arms(c):
    """`if (c) A else B` -> `if (!c) B else A`. The arms are laid out in source order, so this
    moves which one falls through, which block a delay slot is filled from, and the birth order of
    the values of the two arms."""
    t = c.tree
    for n in t.nodes:
        if n.kind != "if" or n.els is None or not c.on_node(n):
            continue
        ind = indent_of(c.text, n.start)
        then = t.src(n.then) if n.then.kind == "block" else t.as_block(n.then, ind)
        yield f"line {t.line(n.start)}", c.replace(n.start, n.end, f"if ({negate(t.cond(n), c.exact)}) {t.as_block(n.els, ind)} else {then}")


@rule("early_exit", ("branch-form", "order", "length", "registers"), "exact",
      "mined: return shape 3 closing + 4 steps (00443fb8: `r = -1; if (v) return f(); return r;` -> "
      "`if (!v) return -1; return f();`); knowledge: 14 written rules on early return against wrapped body",
      "00443fb8")
def early_exit(c):
    """An `if` without `else`, both ways: `if (c) { A; return; } REST` <-> `if (!c) { REST } A;
    return;` (the arm that leaves and the rest of the block exchanged), and a wrapped tail
    `if (c) { A }` at the end of a void function or of a loop body -> `if (!c) return;` (or
    `continue;`) then `A`. Decides branch-likely against plain branches and which path falls through."""
    t = c.tree
    for n in t.nodes:
        if n.kind != "if" or n.els is not None or n.parent is None or n.parent.kind != "block" or not c.on_node(n):
            continue
        sib, ind = n.parent.kids, indent_of(c.text, n.start)
        rest, then = sib[n.index + 1:], t.unwrapped(n.then)
        if any(k.kind in ("label", "pp") for k in rest + then):
            continue
        neg, site = negate(t.cond(n), c.exact), f"line {t.line(n.start)}"
        owner = n.parent.parent
        in_loop = owner is not None and owner.kind in ("for", "while", "do")
        at_top = owner is None
        if then and t.jump(then[-1]) and rest:
            tail = then
            # a bare `return;` / `continue;` that would end the function or the loop body says nothing
            if (then[-1].word == "return" and at_top and re.match(r"return\s*;", t.src(then[-1]))) or \
                    (then[-1].word == "continue" and in_loop):
                tail = then[:-1]
            if tail and not t.jump(rest[-1]):
                continue        # the rest falls off its end: it would run into the arm placed after it
            new = f"if ({neg}) {{\n{t.stmts(rest, ind + '    ')}\n{ind}}}" + ("\n" + t.stmts(tail, ind) if tail else "")
            yield site + ": the rest of the block wrapped", c.replace(n.start, rest[-1].end, new)
        if not rest and then and not t.jump(then[-1]) and n.then.kind == "block":
            leave = "continue;" if in_loop else "return;" if at_top and c.void_function() else None
            if leave:
                yield site + f": `{leave}` first", c.replace(n.start, n.end, f"if ({neg}) {leave}\n{t.stmts(then, ind)}")
        # `if (c) { A } return x;` closing the function -> `if (!c) return x; A return x;` (mined: 0036ae20, twice in it)
        if len(rest) == 1 and at_top and then and not t.jump(then[-1]) and n.then.kind == "block" and rest[0].word == "return":
            value = re.match(r"return\b\s*(\S.*?)\s*;\s*$", t.src(rest[0]), re.S)
            if value and re.fullmatch(r"-?\s*[\w.]+", value.group(1)) and \
                    not any(t.decl(k) and uses(t.decl(k)[1], value.group(1)) for k in then):
                yield site + f": `return {value.group(1)};` first", \
                    c.replace(n.start, n.end, f"if ({neg}) return {value.group(1)};\n{t.stmts(then, ind)}")


@rule("ternary_if", ("branch-form", "registers", "length"), "judge",
      "mined: ternary <-> if 3 closing + 4 steps, 26 written rules (001f6b28: `src = b; if (a) src = a; f(src)` -> `f(a ? a : b)`; "
      "0056db78 the reverse; 0035f090); knowledge: `x = 1; if (a) x = a` gives movn, `a ? a : 1` a branch",
      "001f6b28")
def ternary_if(c):
    """A conditional value written as `c ? a : b` or as an assignment under `if`, both ways:
    `T x = c ? a : b;` <-> `T x = b; if (c) x = a;` (and `T x = a; if (!c) x = b;`),
    `x = c ? a : b;` <-> `if (c) x = a; else x = b;`, `return c ? a : b;` <-> `if (c) return a;
    return b;`, and `T x = b; if (c) x = a;` with one later use folded into that use. Decides
    movn/movz against a branch, and which value is born first. The forms that evaluate an arm
    unconditionally are made only when that arm has no call or assignment; it may still read
    memory the original read only under the condition, so the judge is the proof."""
    t = c.tree
    for n in t.nodes:
        if n.kind == "simple" and c.on_node(n):
            src, ind, site = t.src(n), indent_of(c.text, n.start), f"line {t.line(n.start)}"
            d = t.decl(n)
            if d and d[3] and not d[2]:
                tern = split_ternary(d[3])
                if tern and "&" not in d[0]:
                    cond, a, b = tern
                    if pure(b):
                        yield site + ": declaration, false arm first", c.replace(n.start, n.end, f"{declare(d[0], d[1])} = {b};\n{ind}if ({strip_parens(cond)}) {d[1]} = {a};")
                    if pure(a):
                        yield site + ": declaration, true arm first", c.replace(n.start, n.end, f"{declare(d[0], d[1])} = {a};\n{ind}if ({negate(cond, c.exact)}) {d[1]} = {b};")
                continue
            m = re.match(r"return\b\s*(.*);\s*$", src, re.S)
            if m:
                tern = split_ternary(m.group(1))
                if tern and n.parent.kind == "block":
                    yield site + ": return", c.replace(n.start, n.end, f"if ({strip_parens(tern[0])}) return {tern[1]};\n{ind}return {tern[2]};")
                continue
            ops = top_ops(src[:-1])
            if ops and ops[0][1] == "=" and src[ops[0][0]] == "=":
                lhs, rhs = src[:ops[0][0]].strip(), src[ops[0][0] + 1:-1]
                tern = split_ternary(rhs) if not top_ops(rhs)[:1] or top_ops(rhs)[0][1] == "?" else None
                if tern and pure(lhs) and " ".join(lhs.split()) in (" ".join(tern[1].split()), " ".join(tern[2].split())):
                    # `x = c ? a : x;` is `if (c) x = a;` (mined: 00365e80, in an else arm)
                    keep_true = " ".join(lhs.split()) == " ".join(tern[2].split())
                    cond = strip_parens(tern[0]) if keep_true else negate(tern[0], c.exact)
                    yield site + ": assignment kept under the condition", \
                        c.replace(n.start, n.end, f"if ({cond}) {lhs} = {tern[1] if keep_true else tern[2]};")
                elif tern and pure(lhs) and n.parent.kind == "block":
                    yield site + ": assignment", c.replace(n.start, n.end, f"if ({strip_parens(tern[0])}) {lhs} = {tern[1]};\n{ind}else {lhs} = {tern[2]};")
        # the reverse forms: an `if` whose arms only assign or return
        if n.kind != "if" or n.parent is None or n.parent.kind != "block" or not c.on_node(n):
            continue
        ind, site = indent_of(c.text, n.start), f"line {t.line(n.start)}"
        then, cond = t.unwrapped(n.then), strip_parens(t.cond(n))
        if len(then) != 1 or then[0].kind != "simple":
            continue
        cond_in = cond if not {op for _, op in top_ops(cond)} & {"?", "=", ","} else f"({cond})"
        ret = re.match(r"return\b\s*(\S.*);\s*$", t.src(then[0]), re.S)
        sib = n.parent.kids
        nxt = sib[n.index + 1] if n.index + 1 < len(sib) else None
        if ret and n.els is None and nxt is not None and nxt.kind == "simple":
            ret2 = re.match(r"return\b\s*(\S.*);\s*$", t.src(nxt), re.S)
            if ret2:
                yield site + ": two returns as one", c.replace(n.start, nxt.end, f"return {cond_in} ? {ret.group(1)} : {ret2.group(1)};")
            continue
        m = re.match(r"(.+?)\s*(?<![=!<>+\-*/%&|^])=(?!=)\s*(.*);\s*$", t.src(then[0]), re.S)
        if not m or not pure(m.group(1)) or top_ops(m.group(1)):
            continue
        lhs, a = m.group(1).strip(), m.group(2)
        if n.els is not None:
            els = t.unwrapped(n.els)
            m2 = re.match(r"(.+?)\s*(?<![=!<>+\-*/%&|^])=(?!=)\s*(.*);\s*$", t.src(els[0]), re.S) if len(els) == 1 and els[0].kind == "simple" else None
            if m2 and m2.group(1).strip() == lhs:
                yield site + ": if/else assignment as a ternary", c.replace(n.start, n.end, f"{lhs} = {cond_in} ? {a} : {m2.group(2)};")
            continue
        prev = sib[n.index - 1] if n.index > 0 else None
        d = t.decl(prev) if prev is not None else None
        if d and d[1] == lhs and d[3] and not d[2] and pure(d[3]) and not uses(lhs, cond) and not uses(lhs, a):
            yield site + ": declaration and if as a ternary", c.replace(prev.start, n.end, f"{declare(d[0], lhs)} = {cond_in} ? {a} : {d[3].strip()};")
            rest = c.text[n.end:n.parent.end]
            if len(uses(lhs, rest)) == 1 and not re.search(rf"&\s*{re.escape(lhs)}\b", rest):
                u = re.search(rf"(?<![\w.>])(?<!->){re.escape(lhs)}\b", rest)
                before, after = rest[:u.start()].rstrip()[-1:], rest[u.end():].lstrip()[:1]
                value = f"{cond_in} ? {a} : {d[3].strip()}"
                value = value if before in "(,=" and after in "),;" else f"({value})"
                line_start = c.text.rfind("\n", 0, prev.start) + 1
                yield site + ": folded into its one use", c.text[:line_start] + c.text[n.end:n.end + u.start()].lstrip("\n") + \
                    value + c.text[n.end + u.end():]


@rule("loop_form", ("branch-form", "length", "order"), "judge",
      "mined: loop form 1 closing + 1 step (00458e08: `if (e != end) do { ... if (e == end) break; } while (1)` -> `for`); "
      "knowledge: 19 written rules (`do { } while (i < N)` gives bnel + delay-slot load, a `for` adds the entry test)",
      "00458e08")
def loop_form(c):
    """One loop written the other ways: `for (I; C; N) B` -> `I; while (C) { B N; }` and
    `I; if (C) { do { B N; } while (C); }`; `while (C) B` -> `if (C) { do B while (C); }`; the
    reverse `if (C) { do B while (C); }` -> `while (C) B`: all exact (a `for` whose body has
    `continue` is left alone). Without the entry test, `do { B N; } while (C);` for a `for` or
    `while`, and `while (C) B` for a `do`: these change the first iteration, so only a MATCH (the
    original has, or has not, the test) proves them."""
    t = c.tree
    for n in t.nodes:
        if n.kind not in ("for", "while", "do", "if") or n.parent is None or n.parent.kind != "block" or not c.on_node(n):
            continue
        ind, site = indent_of(c.text, n.start), f"line {t.line(n.start)}"
        in4 = ind + "    "
        if n.kind == "for":
            parts = [p.strip() for p in _semis(t.cond(n))]
            if len(parts) != 3 or not parts[1]:
                continue
            init, cond, step = parts
            body = t.unwrapped(n.body)
            if re.search(r"\bcontinue\b", t.src(n.body)) and step:
                continue
            dm = DECL.match(init + ";") if init else None
            if dm and dm.group(1).strip() and uses(dm.group(2), c.text[n.end:n.parent.end]) and not uses(dm.group(2), c.text[n.parent.start:n.start]):
                continue        # the loop variable's name is used again after the loop: scope would change
            pre = f"{init};\n{ind}" if init else ""
            inner = t.stmts(body, in4) + (f"\n{in4}{step};" if step else "")
            inner8 = t.stmts(body, in4 + "    ") + (f"\n{in4}    {step};" if step else "")
            yield site + ": for as while", c.replace(n.start, n.end, f"{pre}while ({cond}) {{\n{inner}\n{ind}}}")
            yield site + ": for as if + do-while", c.replace(n.start, n.end, f"{pre}if ({cond}) {{\n{in4}do {{\n{inner8}\n{in4}}} while ({cond});\n{ind}}}")
            yield site + ": for as do-while, no entry test", c.replace(n.start, n.end, f"{pre}do {{\n{inner}\n{ind}}} while ({cond});")
        elif n.kind == "while":
            cond = t.cond(n).strip()
            if cond in ("1", "true"):
                continue
            body = t.as_block(n.body, in4)
            yield site + ": while as if + do-while", c.replace(n.start, n.end, f"if ({cond}) {{\n{in4}do {body} while ({cond});\n{ind}}}")
            yield site + ": while as do-while, no entry test", c.replace(n.start, n.end, f"do {t.as_block(n.body, ind)} while ({cond});")
        elif n.kind == "do":
            cond = t.cond(n).strip()
            if cond not in ("0", "1", "true", "false"):
                yield site + ": do-while as while, entry test added", c.replace(n.start, n.end, f"while ({cond}) {t.as_block(n.body, ind)}")
        elif n.kind == "if" and n.els is None:
            then = t.unwrapped(n.then)
            if len(then) == 1 and then[0].kind == "do" and " ".join(t.cond(then[0]).split()) == " ".join(t.cond(n).split()):
                yield site + ": if + do-while as while", c.replace(n.start, n.end, f"while ({t.cond(n).strip()}) {t.as_block(then[0].body, ind)}")


def _semis(s):
    out, depth, piece = [], 0, ""
    for ch in s:
        depth += ch in "([{"
        depth -= ch in ")]}"
        if ch == ";" and depth == 0:
            out.append(piece)
            piece = ""
        else:
            piece += ch
    return out + [piece]


def _target(t, n):
    """What a simple statement writes, as text: the declared name, or the left side of its
    assignment; None for anything else (a call, a jump)."""
    d = t.decl(n)
    if d:
        return d[1]
    src = t.src(n)
    ops = top_ops(src[:-1])
    if ops and ops[0][1] == "=" and n.word not in KEYWORDS:
        return src[:ops[0][0]].rstrip("+-*/%&|^<> \t\n").strip()
    return None


def _rhs(t, n):
    """The text a declaration or assignment computes its value from ("" for a bare declaration)."""
    d = t.decl(n)
    if d:
        return d[3] or ""
    src = t.src(n)
    ops = top_ops(src[:-1])
    return src[ops[0][0] + 1:-1].lstrip("=") if ops and ops[0][1] == "=" else src


def _independent(t, a, b):
    """Nothing in the text says the two statements depend on each other: neither writes what the
    other names. (Two stores through different pointers can still alias: the judge decides.)"""
    for x, y in ((a, b), (b, a)):
        target = _target(t, x)
        if target is None:
            if x.kind != "simple" or t.jump(x):
                return False
            continue
        root = IDENT.match(target.lstrip("*&( "))
        whole = t.src(y)
        if uses(target, whole) if IDENT.fullmatch(target) else " ".join(target.split()) in " ".join(whole.split()):
            return False
        if root and re.search(rf"(?<![\w.>])(?<!->){re.escape(root.group(0))}\s*(?:=(?!=)|\+\+|--|[-+*/|&^]=)", whole):
            return False
    return True


@rule("move_far", ("order", "registers"), "judge",
      "mined: a statement moved 2 or more places 1 closing + 13 steps of 8 functions (005706f0: `rq.a = (s32)q;` two "
      "stores down; 004383b0); both tables stop at two places. First measurement: 3 matches, all at three places",
      "005706f0", ordered=True)
def move_far(c):
    """A simple statement moved three to six places up or down inside its block, past statements
    that neither write what it reads nor read what it writes as far as the text shows. Moves where
    a value is born (local-alloc numbers quantities by birth) and the order of independent stores
    and calls' arguments. It can change behaviour through memory the text does not show: only a
    MATCH proves it. Yielded nearest first, stores and declarations before calls."""
    t = c.tree
    found = []
    for n in t.nodes:
        if n.kind != "simple" or n.parent is None or n.parent.kind != "block" or t.jump(n) or not c.on_node(n):
            continue
        sib, ind = n.parent.kids, indent_of(c.text, n.start)
        target = _target(t, n)
        names = set(IDENT.findall(t.src(n)))
        for k in (3, -3, 4, -4, 5, -5, 6, -6):
            j = n.index + k
            if not 0 <= j < len(sib):
                continue
            crossed = sib[n.index + 1:j + 1] if k > 0 else sib[j:n.index]
            if any(x.kind in ("label", "pp") or t.jump(x) for x in crossed) or not all(_independent(t, n, x) for x in crossed if x.kind == "simple"):
                continue
            if any(x.kind != "simple" for x in crossed) and (target is None or not pure(_rhs(t, n))):
                continue        # only a plain value or store goes past a branch or a loop
            if k > 0:
                d = t.decl(n)
                if d and any(uses(d[1], t.src(x)) for x in crossed):
                    continue
                new = c.text[:n.start] + c.text[crossed[0].start:crossed[-1].end] + "\n" + ind + t.src(n) + c.text[crossed[-1].end:]
            else:
                if any(t.decl(x) and t.decl(x)[1] in names for x in crossed):
                    continue
                gap = c.text[crossed[-1].end:n.start]
                new = c.text[:crossed[0].start] + t.src(n) + "\n" + indent_of(c.text, crossed[0].start) + \
                    c.text[crossed[0].start:crossed[-1].end] + (c.text[n.end:] if gap.strip() == "" else gap + c.text[n.end:])
            found.append(((abs(k), target is None or not pure(_rhs(t, n)), n.start, k < 0),
                          f"line {t.line(n.start)} {'down' if k > 0 else 'up'} {abs(k)}", new))
    for _, site, new in sorted(found, key=lambda f: f[0]):
        yield site, new


@rule("rotate_run", ("order",), "judge",
      "mined: 0042fb20 (three zero stores a,b,c -> b,c,a), 0046ffe8 (d[1],d[0],d[2] -> [2],[1],[0]), 0048bb88, 001d60a0; "
      "knowledge: `three adjacent independent zero stores come out rotated: write them rotated left by one`",
      "0042fb20")
def rotate_run(c):
    """Three adjacent independent stores (assignments with no call, none reading what another
    writes) rotated left, rotated right, or reversed: the orders one exchange of neighbours does
    not reach. The scheduler emits such stores in an order of its own, so the source order that
    gives the original's is a permutation of it. Stores through different pointers may alias, so
    only a MATCH proves the order."""
    t = c.tree
    for b in t.nodes:
        if b.kind != "block":
            continue
        for i in range(len(b.kids) - 2):
            run = b.kids[i:i + 3]
            if not all(x.kind == "simple" and not t.decl(x) and _target(t, x) and pure(_rhs(t, x)) for x in run):
                continue
            if not all(_independent(t, x, y) for x in run for y in run if x is not y) or not any(c.on_node(x) for x in run):
                continue
            gaps = [c.text[run[0].end:run[1].start], c.text[run[1].end:run[2].start]]
            for name, order in (("rotated left", (1, 2, 0)), ("rotated right", (2, 0, 1)), ("reversed", (2, 1, 0))):
                yield f"lines {t.line(run[0].start)}-{t.line(run[2].start)} {name}", \
                    c.replace(run[0].start, run[2].end, t.src(run[order[0]]) + gaps[0] + t.src(run[order[1]]) + gaps[1] + t.src(run[order[2]]))


@rule("sink_init", ("order", "branch-form", "registers"), "judge",
      "mined: declaration split from its first assignment 1 closing + 4 steps (0019aa80: `char *d = (char *)(r + 1);` "
      "-> `char *d;` and `d = ...;` first in the else arm; 00190b50); knowledge: `d = (char *)(r + 1) inside the else "
      "branch keeps the addiu in that branch; initialising d at its declaration hoists it above the branch`",
      "0019aa80")
def sink_init(c):
    """`T x = e;` above an `if` -> `T x;` there and `x = e;` as the first statement of the arm (or
    arms) that use x. The value is then computed inside the branch instead of above it. Made only
    when e has no call or assignment and nothing between the declaration and the `if` names x; a
    path that reads x without passing the assignment would read garbage, so only a MATCH proves it."""
    t = c.tree
    for n in t.nodes:
        d = t.decl(n)
        if not d or d[3] is None or d[2] or "&" in d[0] or d[0].startswith("const") or not pure(d[3]) or n.parent.kind != "block":
            continue
        head, name, _, init = d
        if not c.on_node(n, (name,)):
            continue
        later = n.parent.kids[n.index + 1:]
        target = next((x for x in later if uses(name, t.src(x))), None)
        if target is None or target.kind != "if" or uses(name, t.cond(target)):
            continue
        arms = [a for a in (target.then, target.els) if a is not None and a.kind == "block" and a.kids and uses(name, t.src(a))]
        bare = declare(head, name) + ";"
        choices = [arms] + ([[a] for a in arms] if len(arms) == 2 else [])
        for chosen in choices:
            if not chosen:
                continue
            new, shift = c.text, 0
            for a in sorted(chosen, key=lambda a: a.start):
                first = a.kids[0]
                ins = f"{name} = {init.strip()};\n{indent_of(c.text, first.start)}"
                new = new[:first.start + shift] + ins + new[first.start + shift:]
                shift += len(ins)
            new = new[:n.start] + bare + new[n.end:]
            which = "both arms" if len(chosen) == 2 else ("then" if chosen[0] is target.then else "else") + " arm"
            yield f"{name} (line {t.line(n.start)}) into the {which} of line {t.line(target.start)}", new


@rule("stack_pointer", ("registers", "order"), "exact",
      "mined: pointer variable for a stack object 001e8000 (`Str *pc = &ctx;` then `pc->p`), 00111498, and the reverse "
      "001e2a30 (`ph` -> `&h`); knowledge: among the 51 written rules on naming a value or a pointer (`pt = &t;` before the call and go "
      "through pt; a 0x10-slot result buffer needs its own pointer variable)",
      "001e8000")
def stack_pointer(c):
    """A local object's address given a name, and the reverse. `T obj; ... f(&obj) ... obj.m` ->
    `T *p_obj = &obj;` before the first statement that takes the address, every later `&obj`
    written `p_obj` (one variant also writes `obj.m` as `p_obj->m`). The address then lives in a
    saved register (`addiu sN, sp, off` once) instead of being formed at each use. The reverse
    drops a pointer that is set once to `&obj` and never changed."""
    if not c.cplusplus:
        return
    t = c.tree
    for n in t.nodes:
        d = t.decl(n)
        if not d or n.parent.kind != "block":
            continue
        head, name, arr, init = d
        # the reverse: `T *p = &obj;`, p never assigned again and its own address never taken
        m = re.match(r"^&\s*([A-Za-z_]\w*)$", (init or "").strip())
        if m and head.rstrip().endswith("*") and c.on_node(n, (name, m.group(1))):
            rest = c.text[n.end:n.parent.end]
            if not re.search(rf"(?<![\w.>])(?<!->){re.escape(name)}\s*(?:=(?!=)|\+\+|--|[-+*/|&^]=)|&\s*{re.escape(name)}\b|(?:\+\+|--)\s*{re.escape(name)}\b", rest) \
                    and uses(name, rest):
                obj = m.group(1)
                out = re.sub(rf"(?<![\w.>])(?<!->){re.escape(name)}\s*->\s*", obj + ".", rest)
                out = re.sub(rf"\*\s*{re.escape(name)}\b(?!\s*[\[(])", obj, out)
                out = re.sub(rf"(?<![\w.>])(?<!->){re.escape(name)}\b", "&" + obj, out)
                line_start = c.text.rfind("\n", 0, n.start) + 1
                yield f"{name} dropped for &{obj}", c.text[:line_start] + out.lstrip("\n") + c.text[n.parent.end:]
            continue
        if init is not None or "*" in head or "&" in head or not c.on_node(n, (name,)):
            continue
        rest_start = n.end
        rest = c.text[rest_start:n.parent.end]
        addr = re.compile(rf"&\s*{re.escape(name)}\b(?!\s*[\[.]|\s*->)") if not arr else None
        if addr is None or len(addr.findall(rest)) < 1:
            continue
        first = next((x for x in n.parent.kids[n.index + 1:] if addr.search(t.src(x))), None)
        if first is None:
            continue            # the address is first taken inside a nested block of a later statement only
        ptr = c.fresh("p_" + name)
        ind = indent_of(c.text, first.start)
        decl = f"{head} *{ptr} = &{name};\n{ind}"
        tail = c.text[first.start:n.parent.end]
        only_addr = addr.sub(ptr, tail)
        if len(addr.findall(tail)) >= 2 or re.search(rf"(?<![\w.>])(?<!->){re.escape(name)}\s*\.", tail):
            yield f"&{name} as {ptr}", c.text[:first.start] + decl + only_addr + c.text[n.parent.end:]
        both = re.sub(rf"(?<![\w.>])(?<!->){re.escape(name)}\s*\.\s*", ptr + "->", only_addr)
        if both != only_addr:
            yield f"&{name} and {name}.m through {ptr}", c.text[:first.start] + decl + both + c.text[n.parent.end:]


def _chains(src):
    """[(start, end, head, [(op, member or index text)])] of the access chains in src."""
    out = []
    for m in CHAIN.finditer(src):
        if m.group(1) in KEYWORDS or m.group(1) == "this":
            continue
        ops = [(o.group(1) or "[", o.group(2) or o.group(3)) for o in CHAIN_OP.finditer(m.group(2))]
        out.append((m.start(), m.end(), m.group(1), ops))
    return out


def _host(t, n):
    """(start, end) of the text of a statement a temporary can be taken out of: a simple
    statement whole, the condition of an `if`."""
    if n.kind == "simple" and not t.jump(n) or n.kind == "simple" and n.word == "return":
        return n.start, n.end
    if n.kind == "if":
        return n.cond
    return None


@rule("name_base", ("registers", "order", "length"), "judge",
      "mined: temporary added 11 closing + 12 steps; the base of a member access named in 001060f8 "
      "(`El *t = k->e + k->idx; t->u30 = 0;`), 00119918 (`Car *c2 = course->p60->p8[i];`), 00195488, 0035a0c0; "
      "orc_rewrite names only parenthesised groups and call arguments",
      "00119918")
def name_base(c):
    """The object a member is reached through, given a name: `a->b[i]->f = v;` -> `T *p = a->b[i];
    p->f = v;`, and `a->e[i].f` -> `T *p = &a->e[i]; p->f`. One variant replaces it in its own
    statement, another in every later statement of the block that spells the same base. The base
    becomes a pseudo of its own, born before the statement: other register, other order of the
    loads. The later statements may run after the base changed, so the judge is the proof. The
    type is read from the text's own struct declarations; where it does not say, the temporary is
    declared with `__typeof__` (review() reports it)."""
    if not c.cplusplus:
        return
    t = c.tree
    for n in t.nodes:
        if n.parent is None or n.parent.kind != "block":
            continue
        host = _host(t, n)
        if host is None or not c.on_node(n):
            continue
        if t.decl(n):
            if t.decl(n)[3] is None:
                continue
            host = (n.start + c.text[n.start:n.end].index("=") + 1, n.end)
        src, seen = c.text[host[0]:host[1]], set()
        for a, b, head, ops in _chains(src):
            if len(ops) < 2 or ops[-1][0] == "[":
                continue
            base_ops = ops[:-1]
            if not any(op in ("->", "[") for op, _ in base_ops):
                continue
            end_base = a + len(head) + sum(m.end() - m.start() for m in list(CHAIN_OP.finditer(src[a + len(head):b]))[:len(base_ops)])
            base = src[a:end_base]
            if base in seen or IMPURE.search(base):
                continue
            seen.add(base)
            arrow = ops[-1][0] == "->"
            ty = c.types.chain(head, base_ops)
            if ty is not None and not arrow:
                ty = (ty[0], ty[1] + 1)
            name = c.fresh("p_" + re.sub(r"\W", "", base_ops[-1][1] if base_ops[-1][0] != "[" else (base_ops[-2][1] if len(base_ops) > 1 else head)))
            value = base if arrow else "&" + base
            decl = (Types.spell(ty, name) if ty and ty[1] >= 1 else f"__typeof__({value}) {name}") + f" = {value};"
            pat = re.compile(rf"(?<![\w.>])(?<!->){re.escape(base)}\s*{re.escape(ops[-1][0])}\s*")
            ind = indent_of(c.text, n.start)
            site = f"line {t.line(n.start)}: {base}"
            one = c.text[:n.start] + decl + "\n" + ind + c.text[n.start:host[0]] + pat.sub(name + "->", src) + c.text[host[1]:]
            yield site, one
            tail = c.text[host[1]:n.parent.end]
            if pat.search(tail):
                yield site + ", to the end of the block", c.text[:n.start] + decl + "\n" + ind + c.text[n.start:host[0]] + \
                    pat.sub(name + "->", src) + pat.sub(name + "->", tail) + c.text[n.parent.end:]


@rule("name_load", ("registers", "order"), "judge",
      "mined: a value read into a local ahead of its use: 005704a8 (`s32 q20 = q->n20;` one store earlier), 003b1248 "
      "(`off = (*pp)->idx;` before the call, `off << 6` after), 001d0698, 00489300 (`p->x` read once into `u`); "
      "knowledge: 51 written rules on naming a value or a pointer (arguments loaded into locals first, in the original's order)",
      "005704a8")
def name_load(c):
    """A member or element read through a pointer, given a name before its statement, or one
    statement earlier: `g(); rq.b = q->n20;` -> `s32 v = q->n20; g(); rq.b = v;`. The load is then
    its own pseudo and is scheduled where the declaration sits (before the call: in a saved
    register). A variant uses the name for every later reading of the same expression in the
    block. A statement in between may write that memory, so only a MATCH proves it. Type as in
    name_base."""
    if not c.cplusplus:
        return
    t = c.tree
    for n in t.nodes:
        if n.parent is None or n.parent.kind != "block":
            continue
        host = _host(t, n)
        if host is None or not c.on_node(n):
            continue
        d = t.decl(n)
        if d:
            if d[3] is None:
                continue
            host = (n.start + c.text[n.start:n.end].index("=") + 1, n.end)
        src, seen = c.text[host[0]:host[1]], set()
        for a, b, head, ops in _chains(src):
            expr = src[a:b]
            after, before = src[b:].lstrip(), src[:a].rstrip()
            if expr in seen or not any(op in ("->", "[") for op, _ in ops) or IMPURE.search(expr):
                continue
            if after[:1] in ("(", "[", ".") or after[:2] in ("->", "++", "--") or re.match(r"(?:[-+*/%&|^]|<<|>>)?=(?!=)", after):
                continue        # called, reached further, or written
            if before.endswith(("++", "--")) or (before.endswith("&") and not re.search(r"[\w)\]]\s*&$", before)):
                continue
            if d and d[3] is not None and " ".join(d[3].split()) == " ".join(expr.split()):
                continue        # it is a named load already
            seen.add(expr)
            ty = c.types.chain(head, ops)
            name = c.fresh("v_" + re.sub(r"\W", "", ops[-1][1] if ops[-1][0] != "[" else head))
            decl = (Types.spell(ty, name) if ty else f"__typeof__({expr}) {name}") + f" = {expr};"
            pat = re.compile(rf"(?<![\w.>&])(?<!->){re.escape(expr)}(?!\s*(?:\(|\[|\.|->|\+\+|--|(?:[-+*/%&|^]|<<|>>)?=(?!=)))")
            ind = indent_of(c.text, n.start)
            site = f"line {t.line(n.start)}: {expr}"
            here = c.text[n.start:host[0]] + pat.sub(name, src)
            sib = n.parent.kids
            prev = sib[n.index - 1] if n.index > 0 else None
            if not (d and d[3] is not None and strip_parens(d[3]) == expr):
                yield site, c.text[:n.start] + decl + "\n" + ind + here + c.text[host[1]:]
            if prev is not None and prev.kind in ("simple", "if", "for", "while", "do") and not t.jump(prev) and \
                    not (t.decl(prev) and uses(t.decl(prev)[1], expr)):
                yield site + ", read one statement earlier", c.text[:prev.start] + decl + "\n" + indent_of(c.text, prev.start) + \
                    c.text[prev.start:n.start] + here + c.text[host[1]:]
            tail = c.text[host[1]:n.parent.end]
            if pat.search(tail):
                yield site + ", to the end of the block", c.text[:n.start] + decl + "\n" + ind + here + pat.sub(name, tail) + c.text[n.parent.end:]


@rule("return_param", ("registers",), "judge",
      "mined: own return type 4 closing + 1 step; 00559548 (`void f(void *arg0)` -> `void *f(void *arg0)` with "
      "`return arg0;`); orc_rewrite covers `returns its last call's result` and `declared int`, not `returns this`; "
      "knowledge: `calls that return this are declared returning a pointer`",
      "00559548")
def return_param(c):
    """A void function made to return its first parameter (a constructor or setter returning
    `this`): the header's `void` becomes the parameter's type, every `return;` and the end of the
    body `return p;`. `$v0` is then set from the parameter at the exits. Callers that ignore the
    result are unaffected; that the original does set `$v0` is what the MATCH proves."""
    t = c.tree
    if not c.void_function() or (c.aim is not None and not c.aim.get("v0")):
        return
    text, (a, b) = c.text, t.span
    start = max(text.rfind(";", 0, a), text.rfind("}", 0, a)) + 1
    header = text[start:a]
    m = re.search(r"\bvoid(\s+)((?:[A-Za-z_]\w*\s*::\s*)*[A-Za-z_]\w*)\s*\(\s*([^,()]*?[\s*&]+)([A-Za-z_]\w*)\s*[,)]", header)
    if not m or "::" in m.group(2):
        return
    ptype, pname = m.group(3).strip(), m.group(4)
    if not ptype.endswith("*") or re.search(rf"(?<![\w.>])(?<!->){re.escape(pname)}\s*(?:=(?!=)|\+\+|--)", text[a:b]):
        return
    body = re.sub(r"\breturn\s*;", f"return {pname};", text[a:b - 1]).rstrip()
    ind = indent_of(text, t.root.kids[0].start) if t.root.kids else "    "
    # the header, and the function's own prototype above if the text has one
    retype = lambda s: re.sub(rf"\bvoid\s+(?={re.escape(m.group(2))}\s*\()", lambda _: ptype, s)
    last = t.root.kids[-1] if t.root.kids else None
    end = "" if last is not None and last.word == "return" else f"\n{ind}return {pname};"
    yield f"returns {pname}", retype(text[:start]) + retype(header) + body + end + "\n}" + text[b:]


BUILTIN = {"u32": "unsigned int", "s32": "int", "u16": "unsigned short", "s16": "short", "u8": "unsigned char",
           "s8": "signed char", "u64": "unsigned long", "s64": "long"}


@rule("local_sign", ("registers", "length", "other"), "judge",
      "mined: local's declared type 4 steps (0035a0c0, 00570900 `s32 k` -> `u32 k`), typedef signedness 3 closing + 4 "
      "steps (001cf628 `typedef unsigned char u8` -> `char`); knowledge: 92 written rules on a cast, a width or signedness",
      "001cf628")
def local_sign(c):
    """One integer local declared with the other signedness (`s32 n` <-> `u32 n`, `char` <->
    `unsigned char`, ...), and a `char` typedef of the file given the other signedness. Decides lb
    against lbu, sra against srl, slt against sltu, and whether a widening needs an extension. It
    changes what the code computes for values with the top bit set: only a MATCH proves it. A
    typedef name the file does not declare is written as the built-in type it stands for."""
    t = c.tree
    declared = set(re.findall(r"\btypedef\b[^;]*?\b([A-Za-z_]\w*)\s*;", c.text))
    for n in t.nodes:
        d = t.decl(n)
        if not d or d[2] or "*" in d[0] or "&" in d[0]:
            continue
        head = " ".join(w for w in d[0].split() if w not in ("const", "volatile", "register", "static"))
        if head in SIGN and c.on_node(n, (d[1],)):
            src = t.src(n)
            m = re.search(re.escape(d[0].strip()).replace(r"\ ", r"\s+"), src)
            other = SIGN[head]
            if other in BUILTIN and other not in declared:
                other = BUILTIN[other]
            if m:
                keep = [w for w in d[0].split() if w in ("const", "volatile", "register", "static")]
                yield f"{d[1]}: {head} -> {other}", c.replace(n.start + m.start(), n.start + m.end(), " ".join(keep + [other]))
    for m in re.finditer(r"\btypedef\s+((?:unsigned\s+|signed\s+)?char)\s+([A-Za-z_]\w*)\s*;", c.text[:t.span[0]]):
        if c.aim is not None or not uses(m.group(2), c.text[t.span[0]:t.span[1]]):
            continue            # a whole-file change has no site: blind use only
        for other in ("char", "unsigned char", "signed char"):
            if other != " ".join(m.group(1).split()):
                yield f"typedef {m.group(2)}: {m.group(1)} -> {other}", c.replace(m.start(1), m.end(1), other)


WRITES = r"(?<![\w.>])(?<!->){0}\s*(?:=(?!=)|\+\+|--|[-+*/%|&^]=|<<=|>>=)|(?:\+\+|--)\s*{0}\b|&\s*{0}\b(?!\s*(?:->|\.|\[))"
STEP = r"(?:{0}\s*\+\+|\+\+\s*{0}|{0}\s*\+=\s*1)"
LOOPS = ("for", "while", "do")


def _writes(name, src):
    """How often the text assigns, steps or takes the address of the variable itself (`*x = v`
    stores through it and is not one)."""
    return sum(1 for m in re.finditer(WRITES.format(re.escape(name)), src)
               if not (src[m.start():m.start() + 1] not in "+-&" and src[:m.start()].rstrip().endswith("*")
                       and not re.search(r"[\w)\]]\s*\*\s*$", src[:m.start()])))


def _written(name, src):
    return _writes(name, src) > 0


def _plain_assign(t, n):
    """(name, value text) of `x = e;` or `T x = e;` (one plain variable, a plain `=`), else None."""
    d = t.decl(n)
    if d:
        return (d[1], d[3]) if d[3] is not None and not d[2] and "&" not in d[0] else None
    if n.kind != "simple" or n.word in KEYWORDS:
        return None
    m = re.match(r"([A-Za-z_]\w*)\s*=(?!=)\s*(.*);\s*$", t.src(n), re.S)
    return (m.group(1), m.group(2)) if m else None


def _line_removed(text, a, b):
    """text without [a, b), and without the line it stood on if nothing else is on it."""
    start = text.rfind("\n", 0, a) + 1
    end = text.find("\n", b)
    if text[start:a].strip() == "" and end >= 0 and text[b:end].strip() == "":
        return text[:start] + text[end + 1:]
    return text[:a] + text[b:]


@rule("loop_first_use", ("order", "registers"), "judge",
      "worker edit that closed a certified draft: 003d5920 (`base = (s32 *)(arg0 + 0xC);` from above the two loops to right "
      "before its first use in the inner one: the hoisted `addiu` then follows the hoisted `lui`); mined: statement moved 2 "
      "or more places 9 closing + 20 steps",
      "003d5920", ordered=True)
def loop_first_use(c):
    """`x = e;` above a loop whose body is the first to use x, moved into the loop: right before the
    statement of its first use, and to the top of each loop body on the way down. The compiler
    hoists the invariant out again, but in the order of the loop's own insns: that orders the
    values set up before the loop (a `lui` against an `addiu`) and the registers they get. The
    reverse too: an invariant `x = e;` that is a statement of a loop body, moved above the loop.
    Made when e has no call or assignment and the loop writes neither x nor a variable e names;
    a `for` or `while` that runs zero times would leave x unset, so only a MATCH proves it."""
    t = c.tree
    for n in t.nodes:
        if n.parent is None or n.parent.kind != "block":
            continue
        pa = _plain_assign(t, n)
        if not pa or not pure(pa[1]):
            continue
        name, value = pa
        operands = [w for w in set(IDENT.findall(value)) if w != name]
        d = t.decl(n)
        site = f"{name} (line {t.line(n.start)})"
        # into the loop
        later = n.parent.kids[n.index + 1:]
        loop = next((x for x in later if uses(name, t.src(x))), None)
        if loop is not None and loop.kind in LOOPS and loop.body.kind == "block" and c.on_node(n, (name,)) and \
                not _written(name, t.src(loop)) and not any(_written(w, t.src(loop)) for w in operands) and \
                not (loop.kind != "do" and uses(name, t.cond(loop))) and \
                not any(_written(w, c.text[n.end:loop.start]) for w in operands):
            places, body = [], loop.body
            while body is not None and body.kids:
                places.append((body.kids[0].start, f"top of the loop of line {t.line(body.parent.start)}"))
                first = next((k for k in body.kids if uses(name, t.src(k))), None)
                if first is None:
                    break
                if first is not body.kids[0]:
                    places.append((first.start, f"before its first use, line {t.line(first.start)}"))
                body = first.body if first.kind in LOOPS and first.body.kind == "block" and \
                    not (first.kind != "do" and uses(name, t.cond(first))) else None
            seen = set()
            for pos, where in reversed(places):          # the deepest place first: the worker's edit
                if pos in seen:
                    continue
                seen.add(pos)
                new = c.text[:pos] + f"{name} = {value.strip()};\n{indent_of(c.text, pos)}" + c.text[pos:]
                new = new[:n.start] + declare(d[0], name) + ";" + new[n.end:] if d else _line_removed(new, n.start, n.end)
                yield f"{site} into the loop, {where}", new
        # out of the loop
        owner = n.parent.parent
        if d is None and owner is not None and owner.kind in LOOPS and c.on_node(n, (name,)):
            inside = c.text[owner.start:n.start] + c.text[n.end:owner.end]
            if _written(name, inside) or any(_written(w, t.src(owner)) for w in operands) or \
                    uses(name, c.text[owner.body.start:n.start]):
                continue
            top = owner
            while top is not None:
                if top.parent is None or top.parent.kind != "block":
                    break
                new = _line_removed(c.text, n.start, n.end)
                new = new[:top.start] + f"{name} = {value.strip()};\n{indent_of(c.text, top.start)}" + new[top.start:]
                yield f"{site} above the loop of line {t.line(top.start)}", new
                up = top.parent.parent
                top = up if up is not None and up.kind in LOOPS and not any(_written(w, t.src(up)) for w in operands + [name]) else None


def _split_sum(e):
    """(left, right) at the last `+` at depth 0 of an expression, else None."""
    depth, cut, i = 0, None, 0
    while i < len(e):
        ch = e[i]
        depth += ch in "([{"
        depth -= ch in ")]}"
        if ch == "+" and depth == 0 and e[i - 1:i] != "+" and e[i + 1:i + 2] not in ("+", "=") and re.search(r"[\w)\]]\s*$", e[:i]):
            cut = i
        i += 1
    return (e[:cut].strip(), e[cut + 1:].strip()) if cut else None


@rule("index_walk", ("registers", "order", "length"), "judge",
      "worker edit that closed a certified draft: 003e3748 (`u8 *v = (u8 *)arg0 + 0x58; ... *v ... v++;` beside `i++` -> "
      "`((u8 *)arg0)[0x58 + i]`, the pointer gone); mined: access form 12 closing + 28 steps",
      "003e3748")
def index_walk(c):
    """A pointer that walks one element a turn beside the loop's counter, written as an indexed
    access and dropped: `T *v = b + K; do { ... *v ... i++; v++; } while (...)` -> `b[K + i]`.
    One induction variable instead of two: other registers, no second increment, another
    addressing order. Made when v is declared right for that loop, stepped once a turn as a
    statement of the loop body beside a counter that starts at 0, and not used after the loop.
    The counter's start and the base's constancy are read from the text only: the judge proves it."""
    t = c.tree
    for n in t.nodes:
        d = t.decl(n)
        if not d or d[3] is None or d[2] or not d[0].rstrip().endswith("*") or n.parent.kind != "block" or not pure(d[3]):
            continue
        name, base = d[1], d[3].strip()
        later = n.parent.kids[n.index + 1:]
        loop = next((x for x in later if uses(name, t.src(x))), None)
        if loop is None or loop.kind not in LOOPS or loop.body.kind != "block" or not c.on_node(n, (name,)):
            continue
        if uses(name, c.text[loop.end:n.parent.end]):
            continue
        steps = [k for k in loop.body.kids if k.kind == "simple" and re.fullmatch(STEP.format(re.escape(name)) + r"\s*;", t.src(k).strip())]
        body_rest = "".join(t.src(k) for k in loop.body.kids if k not in steps)
        if len(steps) != 1 or _written(name, body_rest) or any(_written(w, t.src(loop)) for w in set(IDENT.findall(base))):
            continue
        counters = []
        for k in loop.body.kids:
            m = re.fullmatch(r"(?:([A-Za-z_]\w*)\s*\+\+|\+\+\s*([A-Za-z_]\w*)|([A-Za-z_]\w*)\s*\+=\s*1)\s*;", t.src(k).strip()) if k.kind == "simple" else None
            if m and (m.group(1) or m.group(2) or m.group(3)) != name:
                counters.append((m.group(1) or m.group(2) or m.group(3), k.start))
        if loop.kind == "for":
            parts = _semis(t.cond(loop))
            m = re.fullmatch(r"\s*(?:([A-Za-z_]\w*)\s*\+\+|\+\+\s*([A-Za-z_]\w*))\s*", parts[2]) if len(parts) == 3 else None
            if m:
                counters.append((m.group(1) or m.group(2), loop.body.end))
        split = _split_sum(base)
        for counter, at in counters[:2]:
            head = c.text[t.span[0]:loop.body.start]
            starts = re.findall(rf"(?<![\w.>]){re.escape(counter)}\s*=(?!=)\s*([^;,)]+)", head)
            stepped = _writes(counter, t.src(loop.body))
            if not starts or starts[-1].strip() != "0" or stepped != (0 if at == loop.body.end else 1):
                continue

            def index(pos, order):
                off = (pos > steps[0].start) - (pos > at)
                i = counter + (" + 1" if off > 0 else " - 1" if off < 0 else "")
                if split:
                    left = split[0] if re.fullmatch(r"[\w.]+", split[0]) or strip_parens(split[0]) != split[0] else f"({split[0]})"
                    return left, f"{split[1]} + {i}" if order == 0 else f"{i} + {split[1]}"
                return (base if re.fullmatch(r"[\w.]+", base) else f"({base})"), i

            for order in ((0, 1) if split else (0,)):
                out, last, ok = [], loop.start, True
                for m in re.finditer(rf"(?<![\w.>])(?<!->){re.escape(name)}\b", c.text[loop.start:loop.end]):
                    a, b = loop.start + m.start(), loop.start + m.end()
                    if steps[0].start <= a < steps[0].end:
                        continue
                    left, idx = index(a, order)
                    before = c.text[last:a]
                    star = re.search(r"\*\s*$", before)
                    after = c.text[b:].lstrip()
                    if star and not re.search(r"[\w)\]]\s*\*\s*$", c.text[:a]) and not after.startswith(("[", "->", "(")):
                        out.append(before[:star.start()] + f"{left}[{idx}]")
                    elif after.startswith("["):
                        ok = False
                        break
                    else:
                        out.append(before + f"({left} + {idx})")
                    last = b
                if not ok:
                    break
                new = c.text[:loop.start] + "".join(out) + c.text[last:loop.end] + c.text[loop.end:]
                shift = len(new) - len(c.text)
                # the step statement, then the declaration: both whole lines
                s_at = new.find(t.src(steps[0]), loop.start)
                new = _line_removed(new, s_at, s_at + steps[0].end - steps[0].start) if s_at >= 0 else new
                new = _line_removed(new, n.start, n.end)
                yield f"{name} (line {t.line(n.start)}) as an index by {counter}" + (", counter first" if order else ""), new


def _own_header(c):
    """(start, header text, name) of the function's own header when it says `void NAME(`: what a
    rule that gives the function a return value rewrites. The name is never touched."""
    text, a = c.text, c.tree.span[0]
    start = max(text.rfind(";", 0, a), text.rfind("}", 0, a)) + 1
    header = text[start:a]
    m = re.search(r"\bvoid(\s+)((?:[A-Za-z_]\w*\s*::\s*)*[A-Za-z_]\w*)\s*\(", header)
    return (start, header, m.group(2)) if m and "::" not in m.group(2) else None


@rule("return_store", ("order", "registers"), "judge",
      "worker edit that closed a certified draft: 00556d80 (`void f(...) { ... *(s32 *)(arg0 + 0x284) = (r == 0); }` -> "
      "`s32 f(...)` ending `return r == 0;`: the stored value is the result, and the epilogue restores its registers in "
      "the other order); mined: own return type 5 closing + 1 step",
      "00556d80")
def return_store(c):
    """A void function whose last statement stores a value, made to return that value: the
    header's `void` becomes `s32` (or `int`), `return VALUE;` follows the store. The value is
    then live in `$v0` to the end, which moves the store against the epilogue and the order the
    saved registers are restored in. The symbol keeps its name; that the original does leave the
    value in `$v0` is what the MATCH proves (callers ignore it either way). A last statement
    wrapped in `do { } while (0)` is unwrapped."""
    t = c.tree
    own = _own_header(c)
    if not own or not c.void_function() or not t.root.kids or re.search(r"\breturn\b", c.text[t.span[0]:t.span[1]]):
        return
    start, header, fname = own
    last = t.root.kids[-1]
    inner = last
    if last.kind == "do" and t.cond(last).strip() == "0" and last.body.kind == "block" and len(last.body.kids) == 1:
        inner = last.body.kids[0]
    if inner.kind != "simple" or t.decl(inner) or inner.word in KEYWORDS:
        return
    src = t.src(inner)
    ops = top_ops(src[:-1])
    if not ops or ops[0][1] != "=" or src[ops[0][0]] != "=" or src[ops[0][0] - 1] in "+-*/%&|^<>":
        return
    value = strip_parens(src[ops[0][0] + 1:-1])
    if not pure(value) or not pure(src[:ops[0][0]]):
        return
    ret = "s32" if re.search(r"\bs32\b", c.text[:t.span[0]]) else "int"
    retype = lambda s: re.sub(rf"\bvoid\s+(?={re.escape(fname)}\s*\()", ret + " ", s)
    ind = indent_of(c.text, last.start)
    body = c.text[t.span[0]:last.start] + src + f"\n{ind}return {value};" + c.text[last.end:t.span[1]]
    yield f"returns the value stored on line {t.line(last.start)}", retype(c.text[:start]) + retype(header) + body + c.text[t.span[1]:]


@rule("drop_base", ("registers", "order", "length"), "judge",
      "worker edit that closed a certified draft: 00566f90 (`Slot *it = &o->slots[value]; it->state` twice -> "
      "`o->slots[value].state`: the operands of the `addu` change places); mined: temporary removed 7 closing + 16 steps "
      "(00458e08, 001e2a30); orc_rewrite folds a temporary only when it is used once",
      "00566f90")
def drop_base(c):
    """The reverse of name_base: a pointer set once from an expression without a call and only
    read through, written out at each of its uses and its declaration dropped: `T *p = &a->e[i];
    p->f ... p->g` -> `a->e[i].f ... a->e[i].g`, `T *p = (T *)(b + n); p->f` -> `((T *)(b + n))->f`.
    The address is then formed at each use (CSE joins them again, with the operands in the
    expression's order) instead of living in a pseudo of its own. Made for up to four uses, when
    nothing after the declaration writes p or a variable the expression names; memory it reads
    may still change between the uses, so the judge is the proof."""
    t = c.tree
    for n in t.nodes:
        d = t.decl(n)
        if not d or d[3] is None or d[2] or not d[0].rstrip().endswith("*") or n.parent.kind != "block" or not pure(d[3]):
            continue
        name, init = d[1], strip_parens(d[3])
        if not c.on_node(n, (name,)):
            continue
        rest = c.text[n.end:n.parent.end]
        count = len(uses(name, rest))
        if not 1 <= count <= 4 or (len(init) > 60 and count > 2) or _written(name, rest) or \
                any(_written(w, rest) for w in set(IDENT.findall(init))):
            continue
        m = re.match(r"^&\s*(.+)$", init, re.S)
        obj = m.group(1).strip() if m and re.fullmatch(r"[A-Za-z_]\w*(?:\s*(?:->|\.)\s*\w+|\s*\[(?:[^\[\]]|\[[^\[\]]*\])*\])*", m.group(1).strip()) else None
        whole = init if re.fullmatch(r"[A-Za-z_]\w*(?:\s*(?:->|\.)\s*\w+|\s*\[(?:[^\[\]]|\[[^\[\]]*\])*\])*", init) else f"({init})"
        out, last = [], 0
        for u in re.finditer(rf"(?<![\w.>])(?<!->){re.escape(name)}\b", rest):
            before, after = rest[last:u.start()], rest[u.end():]
            star = re.search(r"\*\s*$", before)
            unary = star and not re.search(r"[\w)\]]\s*\*\s*$", rest[:u.start()])
            arrow = re.match(r"\s*->\s*", after)
            if arrow:
                out.append(before + (obj + "." if obj else whole + "->"))
                last = u.end() + arrow.end()
                continue
            if unary and obj and not after.lstrip().startswith(("[", "(")):
                out.append(before[:star.start()] + obj)
            elif obj:
                out.append(before + (f"&{obj}" if before.rstrip()[-1:] in "(,=" and after.lstrip()[:1] in "),;" else f"(&{obj})"))
            else:
                out.append(before + whole)
            last = u.end()
        new_rest = "".join(out) + rest[last:]
        line_start = c.text.rfind("\n", 0, n.start) + 1
        alone = c.text[line_start:n.start].strip() == "" and new_rest.startswith("\n")
        yield f"{name} (line {t.line(n.start)}) written out at its {count} use(s)", \
            (c.text[:line_start] + new_rest[1:] if alone else c.text[:n.start] + new_rest) + c.text[n.parent.end:]


RETURNS = r'(?m)^[ \t]*(?:extern\s+"C"\s+|extern\s+|static\s+|inline\s+)*((?:(?:const|unsigned|signed|struct)\s+)*[A-Za-z_]\w*(?:\s+(?:int|char|short|long))*[\s*]*?)\b{0}\s*\('


def _calls(src):
    """[(start, end, name, depth)] of the calls `name(...)` in a statement's text, depth being how
    many parentheses enclose each."""
    out, stack = [], []
    for m in re.finditer(r"\b([A-Za-z_]\w*)\s*\(", src):
        if m.group(1) in KEYWORDS or m.group(1) in ("sizeof", "__typeof__"):
            continue
        depth, i = 0, m.end() - 1
        while i < len(src):
            depth += src[i] in "([{"
            depth -= src[i] in ")]}"
            if depth == 0:
                break
            i += 1
        if depth == 0:
            before = src[:m.start()]
            out.append((m.start(), i + 1, m.group(1), before.count("(") - before.count(")")))
    return out


@rule("name_call", ("order", "registers"), "judge",
      "mined 2026-10-12 (second mining, 58 new closing edits): 0039d218 (`s32 r = func_003F1F78(...); vc_i(w, 0xA8, r);` "
      "for the nested call, `s32 nz = sp0 != 0;` for a comparison passed as an argument); class temporary added: a "
      "subexpression given a name 8 closing + 15 steps. orc_rewrite names such an argument only with `__typeof__`",
      "0039d218")
def name_call(c):
    """A call that is an argument of another call (or an operand of a larger expression), and a
    comparison passed as an argument, given a name on the line before: `g(a, f(x));` ->
    `T r = f(x); g(a, r);` with T the return type the text's own prototype of f gives, `g(a, b !=
    0);` -> `s32 flag = b != 0; g(a, flag);`. The result is then a pseudo of its own, set before
    any argument of the outer call is: that is the order of the argument set-up, and whether the
    result waits in `$v0` or in a saved register. Evaluation order changes against the other
    arguments, so the judge is the proof."""
    if not c.cplusplus:
        return
    t = c.tree
    head = c.text[:t.span[0]]
    word_type = "s32" if re.search(r"\bs32\b", head) else "int"
    for n in t.nodes:
        if n.kind != "simple" or n.parent is None or n.parent.kind != "block" or t.jump(n) and n.word != "return" or not c.on_node(n):
            continue
        src, ind = t.src(n), indent_of(c.text, n.start)
        d = t.decl(n)
        lo = src.index("=") + 1 if d and d[3] is not None else 0
        made = 0
        calls = _calls(src)
        ops = top_ops(src[:-1])
        value_at = lo if lo else ops[0][0] + 1 if ops and ops[0][1] == "=" else len("return") if n.word == "return" else 0
        whole = strip_parens(src[value_at:-1])
        for a, b, fname, depth in calls:
            if a < lo or made >= 3 or src[a:b] == whole or re.search(r"(?:->|\.)\s*$", src[:a]):
                continue        # the statement's own value already, or a member call
            pm = re.search(RETURNS.format(re.escape(fname)), head)
            if not pm:
                continue
            ret = " ".join(pm.group(1).split())
            if ret in ("void", "return", "else") or ret.split()[0] in KEYWORDS:
                continue
            tmp = c.fresh("r")
            made += 1
            yield f"line {t.line(n.start)}: the result of {fname}", \
                c.text[:n.start] + f"{declare(ret, tmp)} = {src[a:b]};\n{ind}" + src[:a] + tmp + src[b:] + c.text[n.end:]
        for a, b, fname, depth in calls:
            if a < lo:
                continue
            args, start, level = [], a + src[a:b].index("(") + 1, 0
            for k in range(start, b):
                level += src[k] in "([{"
                level -= src[k] in ")]}"
                if (src[k] == "," and level == 0) or k == b - 1:
                    args.append((start, k))
                    start = k + 1
            for x, y in args:
                arg = src[x:y]
                kinds = {op for _, op in top_ops(arg)}
                if kinds & {"==", "!=", "<", ">", "<=", ">="} and not kinds & {"?", ":", "=", ","} and pure(arg):
                    tmp = c.fresh("flag")
                    lead = len(arg) - len(arg.lstrip())
                    yield f"line {t.line(n.start)}: the comparison {arg.strip()[:30]}", \
                        c.text[:n.start] + f"{word_type} {tmp} = {arg.strip()};\n{ind}" + src[:x + lead] + tmp + src[x + len(arg.rstrip()):] + c.text[n.end:]


def _chain_of(e, op):
    """The operands of e when it is `a OP b OP c` at depth 0 with nothing of lower precedence
    beside it (OP one of | ^ &), else None."""
    lower = {"|": ("||", "&&", "?", ":", "=", ","), "^": ("||", "&&", "?", ":", "=", ",", "|"),
             "&": ("||", "&&", "?", ":", "=", ",", "|", "^")}[op]
    parts, depth, start, i = [], 0, 0, 0
    while i < len(e):
        j = skip(e, i)
        if j != i:
            i = j
            continue
        ch, two = e[i], e[i:i + 2]
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        elif depth == 0:
            if two in ("||", "&&"):
                return None
            if two in ("|=", "&=", "^=", "==", "!=", "<=", ">="):
                if two[0] in lower or two in ("|=", "&=", "^="):
                    return None
                i += 2
                continue
            if ch in lower:
                return None
            if ch == op and (op != "&" or re.search(r"[\w)\]]\s*$", e[:i])):
                parts.append(e[start:i].strip())
                start = i + 1
        i += 1
    parts.append(e[start:].strip())
    return parts if len(parts) >= 2 and all(parts) else None


@rule("split_op", ("order", "registers", "length"), "exact",
      "mined 2026-10-12 (second mining): 005b7bb8 (`mode = (mode & 0xFFFFFFFCU) | arg0 | 0x300;` -> `mode = (mode & "
      "0xFFFFFFFCU) | arg0; mode |= 0x300;`); class other body edit 4 closing + 12 steps; knowledge: the order of the "
      "operations of a chain follows the statements, not the expression",
      "005b7bb8")
def split_op(c):
    """A chain of one bitwise operator split into two statements, and two such statements
    joined: `x = a | b | c;` <-> `x = a | b; x |= c;` (`|`, `&`, `^`). The compiler combines a
    chain as one tree and may reassociate it; two statements fix which operation is last and
    give the intermediate value a life of its own. Same value either way (the part split off
    must not name x)."""
    t = c.tree
    for n in t.nodes:
        if n.kind != "simple" or n.parent is None or n.parent.kind != "block" or not c.on_node(n):
            continue
        pa = _plain_assign(t, n)
        ind, site = indent_of(c.text, n.start), f"line {t.line(n.start)}"
        if pa:
            name, value = pa
            for op in "|^&":
                parts = _chain_of(value, op)
                if parts and not uses(name, parts[-1]) and pure(value):
                    keep = f" {op} ".join(parts[:-1])
                    at = t.src(n).rindex(value)
                    first = t.src(n)[:at] + keep + t.src(n)[at + len(value):]
                    yield site + f": the last `{op}` as a statement of its own", \
                        c.replace(n.start, n.end, first + f"\n{ind}{name} {op}= {parts[-1]};")
                    break
            sib = n.parent.kids
            nxt = sib[n.index + 1] if n.index + 1 < len(sib) else None
            m = re.fullmatch(rf"{re.escape(name)}\s*([|^&])=\s*(.*);", t.src(nxt).strip(), re.S) if nxt is not None and nxt.kind == "simple" else None
            if m and pure(value) and pure(m.group(2)) and not uses(name, m.group(2)):
                op = m.group(1)
                left = value.strip() if _chain_of(value, op) or not top_ops(value) and not re.search(r"[|^&]", value) else f"({value.strip()})"
                right = m.group(2).strip() if not top_ops(m.group(2)) and not re.search(r"[|^&]", m.group(2)) else f"({m.group(2).strip()})"
                at = t.src(n).rindex(value)
                joined = t.src(n)[:at] + f"{left} {op} {right}" + t.src(n)[at + len(value):]
                yield site + f": joined with the `{op}=` after it", c.text[:n.start] + joined + _line_removed(c.text, nxt.start, nxt.end)[n.end:] \
                    if c.text[n.end:nxt.start].strip() == "" else c.replace(n.start, nxt.end, joined)


CALLEE = re.compile(
    r'^(?P<pre>[ \t]*(?:extern\s+"C"\s+|extern\s+|static\s+|inline\s+)*)'
    r'(?P<ret>(?:(?:const|unsigned|signed|struct|class)\s+)*[A-Za-z_]\w*(?:\s+(?:int|char|short|long))*)(?P<stars>[\s*&]*?)'
    r'(?P<name>\b[A-Za-z_]\w*)\s*\((?P<args>[^;{}]*)\)\s*(?P<post>(?:throw\s*\(\s*\))?\s*;)', re.M)
BARRIER = re.compile(r"\bdo\s*\{\s*([^{};]*;)\s*\}\s*while\s*\(\s*0\s*\)\s*;")


@rule("callee_return", ("order", "registers"), "judge",
      "cause found by an Opus worker in the sched dumps, 2026-10-12 (001d1598 `void func_001CBFE0` -> `void *`, 001d42e0 "
      "`void func_0057DA20` -> `int`; 00493918): a pick decided by dependents N+1 against N where the insn reads or sets "
      "`$v0`/`$v1` before a call. A call declared void only clobbers `$v0`, so the last use of `$v0` before it keeps its "
      "dependent after it; a call that returns a value sets `$v0` and that dependence is gone. Mined: callee returns void "
      "<-> a value 12 closing + 1 step. orc_rewrite's callee_returns knows built-in return types only",
      "001d42e0", ordered=True)
def callee_return(c):
    """One callee's declared return type toggled, every prototype of the text in turn: `void f()`
    -> `int f()` and `void *f()` (constructor-like callees return `this`), any other type ->
    `void`. No body edit. It changes which insns depend on `$v0` across that call (scheduler
    picks decided by dependents, the order of argument set-up and of stores around the call) and
    whether `$v0` is free after it (allocation). A callee whose result is used cannot become
    void: the compiler says. The callees called on the lines the report names come first."""
    t = c.tree
    body = c.text[t.span[0]:t.span[1]]
    called = {}
    for m in re.finditer(r"\b([A-Za-z_]\w*)\s*\(", body):
        called.setdefault(m.group(1), []).append(t.line(t.span[0] + m.start()))
    near = set((c.aim or {}).get("call_lines") or ()) | c.lines
    found = []
    for m in CALLEE.finditer(c.text[:t.span[0]]):
        name, ret = m.group("name"), " ".join(m.group("ret").split())
        if name not in called or ret in KEYWORDS or ret.split()[0] in ("return", "typedef", "else"):
            continue
        aimed = any(l in near for l in called[name])
        pointer = "*" in m.group("stars")
        if ret == "void" and not pointer:
            for new_ret, spelled in (("int", "int "), ("void *", "void *")):
                found.append((not aimed, m.start(), f"{name}: void -> {new_ret}",
                              c.text[:m.start("ret")] + spelled + c.text[m.end("stars"):]))
        else:
            found.append((not aimed, m.start(), f"{name}: {ret}{' *' if pointer else ''} -> void",
                          c.text[:m.start("ret")] + "void " + c.text[m.end("stars"):]))
    for _, _, site, new in sorted(found, key=lambda f: f[:2]):
        yield site, new


@rule("falls_off_end", ("order", "registers"), "judge",
      "cause found by an Opus worker in the sched dumps, 2026-10-12 (00555088; it explains 00556d80 too): a non-void "
      "function that falls off its end has `(clobber $v0)` and `(use $v0)` at the exit, so every reader of `$v0` in the "
      "last block gains a dependent and the `use` resets the last scheduled insn: the epilogue restores come out in "
      "source order `s0, s1, ra`. A `do { } while (0)` around the last statement hides the effect. Mined: own return "
      "type 5 closing + 1 step",
      "00555088")
def falls_off_end(c):
    """A void function with no `return` declared `int`, the body unchanged: it falls off its end
    with `$v0` in use. Moves the order of the stores and of the saved registers' restores in the
    last block, and keeps `$v0` busy to the end. A second variant also unwraps every `do { one
    statement } while (0)`: such a barrier keeps the scheduler from showing the effect. The
    symbol keeps its name; callers ignore the value either way, the MATCH is the proof."""
    t = c.tree
    own = _own_header(c)
    body = c.text[t.span[0]:t.span[1]]
    if not own or not c.void_function() or re.search(r"\breturn\b", body):
        return
    start, header, fname = own
    retype = lambda s: re.sub(rf"\bvoid(\s+)(?={re.escape(fname)}\s*\()", r"int\1", s)
    yield "declared int, no return statement", retype(c.text[:start]) + retype(header) + c.text[t.span[0]:]
    plain = BARRIER.sub(lambda m: m.group(1), body)
    if plain != body:
        yield "declared int, no return statement, `do { } while (0)` unwrapped", \
            retype(c.text[:start]) + retype(header) + plain + c.text[t.span[1]:]
        yield "`do { } while (0)` unwrapped", c.text[:t.span[0]] + plain + c.text[t.span[1]:]


@rule("barrier_last", ("order",), "exact",
      "an Opus worker's fallback, 2026-10-12, for a restore order when `$v0` is live at the exit and falls_off_end "
      "cannot apply; mined: do { } while (0) wrapper 3 closing (00431df0), all from the blind rewriter. review() flags "
      "the result: a MATCH with it is held back for a person",
      "00431df0")
def barrier_last(c):
    """The last store of the function wrapped in `do { ... } while (0);`: a loop note the
    scheduler does not move insns across, so the store stays ahead of the epilogue's restores.
    The unnatural form of the table: review() reports it, and no tool saves a source with it."""
    t = c.tree
    kids = t.root.kids if t.root is not None else []
    stores = [k for k in kids if k.kind == "simple" and not t.decl(k) and not t.jump(k) and _target(t, k)]
    if not stores or not c.on_node(stores[-1]):
        return
    last = stores[-1]
    if kids[-1] is not last and not (kids[-1].word == "return" and kids[-2] is last):
        return
    yield f"line {t.line(last.start)}", c.replace(last.start, last.end, "do { " + t.src(last) + " } while (0);")


@rule("count_up_for", ("order", "registers", "length"), "judge",
      "cause found by an Opus worker in the sched dumps, 2026-10-12 (0047ec98, 0047f4c8): two register copies before a "
      "loop label (`k = m; q = p;`) are ordered by the first scheduler's weight, the copy whose source dies first, "
      "whatever the source order; an indexed `for (k = 0; k < bound; k++)` with `p[k]` lets loop.c make the two "
      "initial values itself, which tie and stay in source order",
      "0047ec98")
def count_up_for(c):
    """A hand-rolled count-down loop over a walking pointer written as an indexed `for`:
    `if (m > 0) { k = m; q = p; do { ... q ...; q++; } while (--k != 0); }` -> `for (int k = 0;
    k < m; k++) { ... &p[k] ... }`, the bound written inline when `m` is a local used for
    nothing else. The step of q may be `q++`, or `T *nx = q + 1; ... q = nx;` (nx is then
    `&p[k + 1]`). The count runs the other way and the entry test is the `for`'s own: only a
    MATCH proves the loop is the original's."""
    t = c.tree
    for n in t.nodes:
        if n.kind != "do" or n.body.kind != "block" or n.parent is None or n.parent.kind != "block" or not c.on_node(n):
            continue
        cond = " ".join(t.cond(n).split())
        m = re.fullmatch(r"--\s*([A-Za-z_]\w*)(?:\s*!=\s*0)?|([A-Za-z_]\w*)\s*(?:!=\s*0|>\s*0)", cond)
        if not m:
            continue
        k = m.group(1) or m.group(2)
        kids = list(n.body.kids)
        drop = []
        if m.group(2):
            dec = [x for x in kids if x.kind == "simple" and re.fullmatch(rf"(?:{k}\s*--|--\s*{k}|{k}\s*-=\s*1)\s*;", t.src(x).strip())]
            if len(dec) != 1:
                continue
            drop.append(dec[0])
        # the two copies before the loop: k = BOUND; q = BASE; (declarations or assignments, either order)
        before = n.parent.kids[:n.index]
        inits = {}
        for x in before[-2:]:
            pa = _plain_assign(t, x)
            if pa and pure(pa[1]):
                inits[pa[0]] = (x, pa[1].strip())
        if k not in inits or len(inits) != 2:
            continue
        q = next(v for v in inits if v != k)
        bound, base = inits[k][1], inits[q][1]
        if not re.fullmatch(r"[A-Za-z_]\w*", base):
            continue
        # how q steps: `q++;`, or `T *nx = q + 1;` ... `q = nx;`
        nx = None
        step = [x for x in kids if x.kind == "simple" and re.fullmatch(STEP.format(re.escape(q)) + r"\s*;", t.src(x).strip())]
        if len(step) != 1:
            step = []
            for x in kids:
                d = t.decl(x)
                if d and d[3] and re.fullmatch(rf"{re.escape(q)}\s*\+\s*1", d[3].strip()):
                    back = [y for y in kids if y.kind == "simple" and re.fullmatch(rf"{re.escape(q)}\s*=\s*{re.escape(d[1])}\s*;", t.src(y).strip())]
                    if len(back) == 1:
                        nx, step = d[1], [x, back[0]]
            if not step:
                continue
        drop += step
        rest = [x for x in kids if x not in drop]
        inner = "".join(t.src(x) for x in rest)
        if not rest or _written(q, inner) or _written(k, inner) or uses(k, inner) or _written(base, inner) or \
                uses(q, c.text[n.end:n.parent.end]) or uses(k, c.text[n.end:n.parent.end]):
            continue
        ind = indent_of(c.text, n.start)

        def spell(src):
            for name, idx in ((nx, f"{k} + 1"), (q, k)):
                if not name:
                    continue
                src = re.sub(rf"\*\s*{re.escape(name)}\b(?!\s*(?:\[|->|\())", f"{base}[{idx}]", src)
                src = re.sub(rf"(?<![\w.>])(?<!->){re.escape(name)}\s*->\s*", f"{base}[{idx}].", src)
                src = re.sub(rf"(?<![\w.>])(?<!->){re.escape(name)}\b", f"&{base}[{idx}]", src)
            return src

        first = min(inits[k][0], inits[q][0], key=lambda x: x.start)
        for bound_text, lo, hi, note in _bounds(c, n, bound, first):
            at = indent_of(c.text, lo)
            lines = [spell(reindent(t.src(x), indent_of(c.text, x.start), at + "    ")) for x in rest]
            body = ("\n" + at + "    " + lines[0]) if len(lines) == 1 else \
                " {\n" + "\n".join(at + "    " + l for l in lines) + "\n" + at + "}"
            loop = f"for (int {k} = 0; {k} < {bound_text}; {k}++)" + body
            new = c.text[:lo] + loop + c.text[hi:]
            # a count or pointer declared at the top is left without a use: its bare `T k;` goes too
            for name in (k, q):
                bare = re.search(rf"\n[ \t]*{TYPEWORD}[A-Za-z_]\w*[\s*]+{re.escape(name)}\s*;", new[:lo])
                if bare and not t.decl(inits[name][0]) and len(uses(name, new[:lo] + new[lo + len(loop):])) == 1:
                    new = new[:bare.start()] + new[bare.end():]
            yield f"line {t.line(n.start)}: {k} counts up over {base}{note}", new


def _bounds(c, loop, bound, first):
    """(bound text, start, end, note) of the stretches a count_up_for loop replaces: the two
    copies and the loop; with the guard `if (bound > 0) { }` around them when that is all it
    holds; with the bound's own one-use declaration `T m = e;` before the guard folded in."""
    t = c.tree
    block = loop.parent
    out = [(bound if re.fullmatch(r"[\w.]+", bound) else bound, first.start, loop.end, "")]
    guard = block.parent
    if guard is not None and guard.kind == "if" and guard.els is None and guard.then is block and \
            len(block.kids) == loop.index + 1 and first.index == 0 and \
            re.fullmatch(rf"{re.escape(bound)}\s*(?:>\s*0|!=\s*0|>=\s*1)", " ".join(t.cond(guard).split())):
        out.insert(0, (bound, guard.start, guard.end, ", its guard gone"))
        if guard.parent is not None and guard.parent.kind == "block" and guard.index > 0:
            prev = guard.parent.kids[guard.index - 1]
            d = t.decl(prev)
            if d and d[1] == bound and d[3] and pure(d[3]) and not uses(bound, c.text[guard.end:guard.parent.end]):
                out.insert(0, (d[3].strip(), prev.start, guard.end, ", the bound written inline"))
    return out


# ---------------------------------------------------------------- the interface

def review(text):
    """Spellings in a source that a person should look at before it is kept: they match, and
    multiplying them makes src/ read like a tool's output."""
    out = []
    if "__typeof__" in text:
        out.append("__typeof__ temporary (write its type)")
    code = re.sub(r"^[ \t]*#(?:[^\n\\]|\\.|\\\n)*", "", text, flags=re.M)
    if re.search(r"\bdo\s*\{[^{};]*;\s*\}\s*while\s*\(\s*0\s*\)\s*;", code):
        out.append("do { } while (0) around one statement")
    if re.search(r"\b[tv]\d+_\d+\b", text):
        out.append("generated temporary name")
    return out


@rule("rotate_long", ("order",), "judge",
      "2026-10-17: 004a4de0 (seven stores of a GS DMA tag builder), W1 lesson `the last source statement is emitted "
      "first: to get emitted C,0,10,14,8 write 0,10,14,8,C`; rotate_run only reaches runs of exactly three",
      "00555aa0")
def rotate_long(c):
    """Four to seven adjacent independent stores rotated by every amount and reversed: the
    scheduler emits a run of stores in an order of its own, which is a rotation of the source order
    (the last statement first, then the others as written). rotate_run reaches runs of three; the
    packet builders of the network unit write six or seven field stores in a row."""
    t = c.tree
    for b in t.nodes:
        if b.kind != "block":
            continue
        n = len(b.kids)
        i = 0
        while i < n:
            j = i
            while j < n and b.kids[j].kind == "simple" and not t.decl(b.kids[j]) and _target(t, b.kids[j]) \
                    and pure(_rhs(t, b.kids[j])):
                j += 1
            if j - i < 4:
                i = max(j, i + 1)
                continue
            run = b.kids[i:min(j, i + 7)]
            i = max(j, i + 1)
            if not all(_independent(t, x, y) for x in run for y in run if x is not y) \
                    or not any(c.on_node(x) for x in run):
                continue
            gaps = [c.text[run[k].end:run[k + 1].start] for k in range(len(run) - 1)]
            srcs = [t.src(x) for x in run]
            orders = [(f"rotated left by {k}", [(m + k) % len(run) for m in range(len(run))])
                      for k in range(1, len(run))]
            orders.append(("reversed", list(range(len(run) - 1, -1, -1))))
            for name, order in orders:
                body = srcs[order[0]]
                for g, o in zip(gaps, order[1:]):
                    body += g + srcs[o]
                yield f"lines {t.line(run[0].start)}-{t.line(run[-1].start)} {name}", \
                    c.replace(run[0].start, run[-1].end, body)


@rule("tail_return", ("order", "registers"), "judge",
      "2026-10-17: W1/W2/W3 lessons on SDK glue and destructors: `a void wrapper that ends in the call becomes a "
      "frameless sibling j; if the original has jal and a normal epilogue the callee has an extra argument and the "
      "wrapper returns its int result`; `if (f & 1) return f2(this);` is what gives the sibling j in a destructor",
      "00582da0")
def tail_return(c):
    """The function's last call statement written `return call(...);` (the function's own type
    made `int` when it was void), and the reverse (`return call(...);` -> `call(...);`). A
    returned call is a sibling `j` when the callee's type allows, a plain `jal` with the epilogue
    when the wrapper returns an int the callee also declares; the two spellings differ in the
    frame, the delay slot of the last store and the register of the result."""
    t = c.tree
    kids = t.root.kids if t.root is not None else []
    if not kids:
        return
    last = kids[-1]
    s = t.src(last)
    if last.kind != "simple" or t.decl(last):
        return
    if re.match(r"^\s*return\s+[A-Za-z_]\w*\s*\(.*\)\s*;\s*$", s, re.S):
        yield f"line {t.line(last.start)}: do not return the call", \
            c.replace(last.start, last.end, re.sub(r"^(\s*)return\s+", r"\1", s, count=1))
    elif re.match(r"^\s*[A-Za-z_]\w*\s*\(.*\)\s*;\s*$", s, re.S):
        new_stmt = "return " + s.lstrip()
        own = _own_header(c)
        if c.void_function() and own:
            start, header, fname = own
            text = c.replace(last.start, last.end, new_stmt)
            head = re.sub(rf"\bvoid(\s+)(?={re.escape(fname)}\s*\()", r"int\1", header)
            yield f"line {t.line(last.start)}: return the last call, own type int", \
                text[:start] + head + text[start + len(header):]
        else:
            yield f"line {t.line(last.start)}: return the last call", c.replace(last.start, last.end, new_stmt)


FLOAT_LIT = re.compile(r"(?<![\w.])(\d+\.\d{5,})([fF])\b")
DOUBLE_LIT = re.compile(r"(?<![\w.])(\d+\.\d{2,})(?![\dfFeE])")


@rule("float_lit", ("registers", "length", "other"), "judge",
      "2026-10-17 (W3, 0057d488 expf): `a float literal like 1.442695f rounds one ulp low in this compiler: write the "
      "constant as a double literal assigned to a float`; the reverse for 0011e198 (2.55f read as 2.5f: a double "
      "literal there turns the multiply into double arithmetic)",
      "0057d488")
def float_lit(c):
    """A float literal with five or more decimals written without its `f` (a double literal that
    the assignment narrows), and a double literal given its `f`: one literal at a time. The
    compiler rounds `1.442695f` and `(float)1.442695` to different bit patterns, and a double
    operand changes the arithmetic from single to double."""
    a, b = c.tree.span
    body = c.text[a:b]
    for m in FLOAT_LIT.finditer(body):
        yield f"{m.group(1)}{m.group(2)} -> {m.group(1)}", c.text[:a + m.start(2)] + c.text[a + m.end(2):]
    for m in DOUBLE_LIT.finditer(body):
        yield f"{m.group(1)} -> {m.group(1)}f", c.text[:a + m.end(1)] + "f" + c.text[a + m.end(1):]


HOLD_LIT = re.compile(r"(?:(?<=[=!<>]=\s)|(?<=[<>]\s)|(?<==\s))(-?(?:0x[0-9A-Fa-f]+|\d+))\b(?!\s*[.\w])")


@rule("hold_const", ("registers",), "judge",
      "2026-10-17 (W1, 00565c30 `int busy = 1;` kept in a saved register across a poll loop; 0060b548 `the align "
      "constants must live in variables or gcc folds them`)",
      "00565c30")
def hold_const(c):
    """An integer constant that the body compares or assigns more than once given a local at the
    top of the body (`int kc = 1;`) and used through it. The original keeps such a constant in a
    callee-saved register across a loop or a call, which a literal never does."""
    a, b = c.tree.span
    body = c.text[a:b]
    counts = collections.Counter(m.group(1) for m in HOLD_LIT.finditer(body))
    for val, n in counts.most_common(4):
        if n < 2 or val == "0":
            continue
        name = c.fresh("kc")
        new_body = HOLD_LIT.sub(lambda m: name if m.group(1) == val else m.group(0), body)
        brace = new_body.index("{") + 1
        yield f"constant {val} ({n} uses) held in a local", \
            c.text[:a] + new_body[:brace] + f"\n    int {name} = {val};" + new_body[brace:] + c.text[b:]


def rules_for(*classes):
    """The names of the rules that answer any of the given classes of difference (the words of
    attempt_store.classify, which the oracle's natural_class / residual_class use too). "other",
    None or no class gives every rule: that class does not discriminate."""
    wanted = {c for c in classes if c}
    if not wanted or "other" in wanted:
        return list(RULES)
    return [name for name, r in RULES.items() if wanted & set(r["answers"])]


def variants(text, aim=None, cap=None, seed=0, cplusplus=True, rules=None):
    """[(rule, site, new text)]: the single-step variants of a draft, the same shape as
    orc_rewrite.variants. aim: orc_aim.sites(row) or None; cap: at most that many in all, the rules
    taking turns in table order (without an aim, seed shuffles inside a rule, except the rules
    that yield their likeliest variants first); rules: names to
    use, default all; cplusplus False (a .c draft) leaves out the rules that declare in mid-block."""
    try:
        c = Ctx(text, aim, cplusplus)
    except Exception:
        return []
    if c.tree.root is None:
        return []
    by_rule, seen = collections.OrderedDict(), {text}
    for name in (rules or RULES):
        out = []
        try:
            for site, new in RULES[name]["fn"](c) or ():
                if new not in seen:
                    seen.add(new)
                    out.append((name, site, new))
        except Exception:       # a shape the parser did not foresee: that rule gives nothing here
            if os.environ.get("REWRITE_RULES_DEBUG"):
                raise
        if out:
            if aim is None and cap is not None and not RULES[name]["ordered"]:
                random.Random(seed).shuffle(out)
            by_rule[name] = out
    flat = []
    queues = [list(v) for v in by_rule.values()]
    while any(queues):
        for q in queues:
            if q:
                flat.append(q.pop(0))
    if cap is None:
        return [v for vs in by_rule.values() for v in vs]
    return flat[:cap]


# ---------------------------------------------------------------- measuring

def _setup():
    tools = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, tools)
    import finish_near
    return finish_near


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def cmd_list(a):
    for name, r in RULES.items():
        print(f"{name:14} proof: {r['proof']:5}  answers: {', '.join(r['answers'])}\n    {r['doc']}\n    evidence: {r['evidence']}\n")


def cmd_show(a):
    text = open(a.file, encoding="utf-8", errors="replace").read()
    vs = variants(text, cplusplus=a.file.endswith(".cpp"), rules=a.rule.split(",") if a.rule else None)
    for name, site, new in vs:
        print(f"=== {name}: {site}" + (f"   [review: {'; '.join(review(new))}]" if review(new) else ""))
        for l in difflib.unified_diff(text.split("\n"), new.split("\n"), lineterm="", n=1):
            if not l.startswith(("---", "+++")):
                print("   " + l)
    print(f"{len(vs)} variants: " + ", ".join(f"{k} {v}" for k, v in collections.Counter(v[0] for v in vs).items()))


def cmd_measure(a):
    F = _setup()
    import project
    import tu_context
    root = F.ROOT
    out_dir = os.path.join(root, "build", "rewrite_rules")
    names = a.rules.split(",") if a.rules else list(RULES)
    only = {f"{int(x, 16):08x}" for x in a.only.split(",")} if a.only else None
    done = set(project.sources(refresh=True))
    todo = [(addr, d, path) for addr, (d, path) in sorted(F.closest().items())
            if d <= a.max_distance and int(addr, 16) not in done and os.path.exists(os.path.join(root, path))
            and (not only or addr in only)]
    log(f"measure {a.tag}: {len(todo)} near-miss drafts within {a.max_distance} instructions, rules: {', '.join(names)}")
    pairs, owner, plan = [], {}, {}
    made = collections.Counter()
    caps = {k: int(v) for k, v in (x.split("=") for x in a.cap_rule.split(","))} if a.cap_rule else {}
    for addr, d, path in todo:
        text = open(os.path.join(root, path), encoding="utf-8", errors="replace").read()
        ext = os.path.splitext(path)[1]
        base = os.path.join("build", "rewrite_rules", "variants", a.tag, addr, "base" + ext)
        os.makedirs(os.path.join(root, os.path.dirname(base)), exist_ok=True)
        F.write(base, text)
        pairs.append((int(addr, 16), base))
        owner[base] = (addr, None, "the draft")
        plan[addr] = {"draft": path, "known": d, "variants": {}}
        for name in names:
            vs = variants(text, cap=caps.get(name, a.cap), seed=int(addr, 16), cplusplus=ext == ".cpp", rules=[name])
            for k, (_, site, new) in enumerate(vs):
                p = os.path.join(os.path.dirname(base), f"{name}_{k}{ext}")
                F.write(p, new)
                pairs.append((int(addr, 16), p))
                owner[p] = (addr, name, site)
            made[name] += len(vs)
    log(f"{len(pairs) - len(todo)} variants to judge: " + ", ".join(f"{k} {v}" for k, v in made.items()))
    if a.dry:
        return
    scores = {}
    for n, (path, sc) in enumerate(F.judge_batch(pairs, a.jobs), 1):
        scores[path] = sc
        if n % 500 == 0:
            log(f"  judged {n} of {len(pairs)}")
    per = {name: {"drafts": 0, "variants": 0, "compiled": 0, "matched": [], "closer": [], "saved": {}, "review": {}} for name in names}
    best = {}
    for path, (addr, name, site) in owner.items():
        if name is None:
            plan[addr]["base"] = scores.get(path)
            continue
        best.setdefault((addr, name), []).append((scores.get(path), path, site))
    saved_addr = {}
    for (addr, name), items in sorted(best.items()):
        base = plan[addr]["base"]
        r = per[name]
        r["drafts"] += 1
        r["variants"] += len(items)
        judged = [(sc, p, site) for sc, p, site in items if sc is not None]
        r["compiled"] += len(judged)
        if not judged or base is None:
            continue
        sc, p, site = min(judged)
        if sc == tu_context.MATCH and base != tu_context.MATCH:
            hits = [(q, s) for x, q, s in judged if x == tu_context.MATCH]
            natural = [(q, s) for q, s in hits if not review(open(os.path.join(root, q), encoding="utf-8").read())]
            r["matched"].append(addr)
            if natural and addr not in saved_addr:
                q, s = natural[0]
                msg = F.save(int(addr, 16), q) if not a.no_save else "not saved (--no-save)"
                saved_addr[addr] = name
                r["saved"][addr] = {"variant": q, "site": s, "save": msg}
                log(f"{addr}: MATCH by {name} ({s}): {msg}")
            elif not natural:
                q, s = hits[0]
                keep = os.path.join("build", "rewrite_rules", "review", f"{addr}_{name}{os.path.splitext(q)[1]}")
                os.makedirs(os.path.join(root, os.path.dirname(keep)), exist_ok=True)
                F.write(keep, open(os.path.join(root, q), encoding="utf-8").read())
                r["review"][addr] = {"variant": keep, "site": s, "why": review(open(os.path.join(root, q), encoding="utf-8").read())}
                log(f"{addr}: MATCH by {name} ({s}), kept for review at {keep}: {'; '.join(r['review'][addr]['why'])}")
            else:
                log(f"{addr}: MATCH by {name} too ({hits[0][1]}); already saved by {saved_addr[addr]}")
        elif sc[0] < base[0]:
            r["closer"].append({"addr": addr, "from": base[0], "to": sc[0], "site": site, "variant": p})
    result = {"tag": a.tag, "drafts": len(todo), "judged": len(pairs), "rules": per}
    json.dump(result, open(os.path.join(out_dir, f"measure_{a.tag}.json"), "w"), indent=1)
    print(f"\n{'rule':14} {'proof':5} {'drafts':>6} {'variants':>8} {'compile':>7} {'match':>5} {'closer':>6}  matches")
    for name in names:
        r = per[name]
        print(f"{name:14} {RULES[name]['proof']:5} {r['drafts']:6} {r['variants']:8} {r['compiled']:7} {len(r['matched']):5} "
              f"{len(r['closer']):6}  {' '.join(r['matched'])}" + (f"  (review: {' '.join(r['review'])})" if r["review"] else ""))
    print(f"of {len(todo)} drafts; {len(pairs)} judge calls; written: build/rewrite_rules/measure_{a.tag}.json")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("list")
    p = sub.add_parser("show")
    p.add_argument("file")
    p.add_argument("--rule")
    p = sub.add_parser("measure")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--max-distance", type=int, default=20)
    p.add_argument("--cap", type=int, default=12, help="variants of one rule on one draft")
    p.add_argument("--cap-rule", help="RULE=N,RULE=N: another cap for these rules")
    p.add_argument("--rules")
    p.add_argument("--only")
    p.add_argument("--tag", default="r1")
    p.add_argument("--dry", action="store_true", help="count the variants, judge nothing")
    p.add_argument("--no-save", action="store_true")
    a = ap.parse_args()
    {"list": cmd_list, "show": cmd_show, "measure": cmd_measure}[a.cmd](a)


if __name__ == "__main__":
    main()
