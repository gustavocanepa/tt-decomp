"""Deterministic source rewrites that move register-allocation decisions, with site selection.

Each rewrite is one of the shapes the project's rules name as a lever on the allocators
(knowledge/gcc296-codegen-map.md "The allocators", knowledge/gt4.md): the order in which values
are born (statement order, declaration order, where a declaration sits), how often a value is
referenced (an alias used in place of what it copies, a temporary folded into its use), how long it
lives and whether it is one pseudo or two (a temporary's scope, a variable split at its second
assignment), which operand is first, and whether a callee returns a value (`$v0` is then set by
the call).

They work on text with a small statement scanner, so C++ drafts are accepted. No rewrite is
checked for meaning: the judge is the check, a variant either compiles to the original's exact
instructions or it is discarded.

    variants(text, aim=None, cap=None, seed=0) -> [(kind, site, new text)]

aim = {"vars": names, "lines": 1-based source lines, "call_lines": lines whose callees matter}
keeps only the sites the oracle's report points to; without it every site is used (the blind
baseline).
"""
import random
import re

KEYWORDS = {"return", "goto", "delete", "new", "case", "else", "break", "continue", "throw", "sizeof", "if", "for",
            "while", "do", "switch", "default", "typedef", "using", "namespace"}
TYPEWORD = r"(?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+|class\s+|union\s+|enum\s+|register\s+|static\s+|long\s+|short\s+)*"
DECL = re.compile(
    rf"^\s*({TYPEWORD}[A-Za-z_]\w*(?:\s*::\s*\w+)*(?:\s*<[^;=(){{}}]*>)?(?:\s+(?:const|long|int|char|short))*[\s*&]*(?:const\s+)?[\s*&]*)"
    r"\b([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*(?:=\s*(?!=)(.*?))?;\s*$", re.S)
IDENT = re.compile(r"[A-Za-z_]\w*")
PROTO = re.compile(
    r'^(?P<pre>[ \t]*(?:extern\s+"C"\s+|extern\s+|static\s+|inline\s+)*)'
    r'(?P<ret>void|int|s32|u32|s8|u8|s16|u16|char|short|long|float|unsigned int|bool)(?P<stars>[\s*]*?)'
    r'(?P<name>\b[A-Za-z_]\w*)\s*\((?P<args>[^;{}]*)\)\s*(?P<post>(?:throw\s*\(\s*\))?\s*;)', re.M)
COMMUTE = re.compile(r"(\b[A-Za-z_][\w.]*(?:->\w+)*|\b\d+\b)\s*([+*|&^]|==|!=)\s*(\b[A-Za-z_][\w.]*(?:->\w+)*|\b\d+\b)(?![\w(\[.]|->)")


KIND_ORDER = ["self_returns", "callee_returns", "name_subexpr", "swap", "commute", "decl_before", "fold_temp", "decl_join", "decl_hoist",
              "split_var", "alias_use", "alias_drop", "move_up2", "move_down2", "scope", "decl_hoist_top"]


def body_span(text):
    """(start, end) of the function body: the last top-level `{ ... }` of the file."""
    depth, start, last = 0, None, None
    i, n = 0, len(text)
    while i < n:
        i = _skip(text, i)
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
    return last


def _skip(text, i):
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


class Stmt:
    __slots__ = ("start", "end", "kind", "block", "index", "depth")

    def __init__(self, start, end, kind, block, index, depth):
        self.start, self.end, self.kind, self.block, self.index, self.depth = start, end, kind, block, index, depth


class Scan:
    """The statements of a function body: every statement of every block, with the block it
    belongs to and its position in it."""

    def __init__(self, text):
        self.text = text
        self.span = body_span(text)
        self.stmts = []
        self.blocks = {}          # block id -> (start of `{`, end after `}`, depth)
        self._next = 0
        if self.span:
            try:
                self._block(self.span[0], 0)
            except (IndexError, RecursionError):
                self.stmts = []

    def line(self, pos):
        return self.text.count("\n", 0, pos) + 1

    def lines(self, st):
        return range(self.line(st.start), self.line(max(st.start, st.end - 1)) + 1)

    def src(self, st):
        return self.text[st.start:st.end]

    def _ws(self, i):
        t, n = self.text, len(self.text)
        while i < n:
            j = _skip(t, i)
            if j != i and (t.startswith("//", i) or t.startswith("/*", i)):
                i = j
                continue
            if t[i].isspace():
                i += 1
                continue
            return i
        return n

    def _parens(self, i):
        """i at `(`: index after the matching `)`."""
        t, depth = self.text, 0
        while i < len(t):
            i = _skip(t, i)
            if t[i] in "([":
                depth += 1
            elif t[i] in ")]":
                depth -= 1
                if depth == 0:
                    return i + 1
            i += 1
        raise IndexError

    def _block(self, i, depth):
        """i at `{`: scans the block, returns the index after its `}`."""
        bid = self._next
        self._next += 1
        start = i
        i += 1
        index = 0
        while True:
            i = self._ws(i)
            if self.text[i] == "}":
                self.blocks[bid] = (start, i + 1, depth)
                return i + 1
            s = i
            i, kind = self._statement(i, depth)
            self.stmts.append(Stmt(s, i, kind, bid, index, depth))
            index += 1

    def _word(self, i):
        m = IDENT.match(self.text, i)
        return m.group(0) if m else ""

    def _statement(self, i, depth):
        t = self.text
        if t[i] == "{":
            return self._block(i, depth + 1), "block"
        if t[i] == "#":
            j = t.find("\n", i)
            return (len(t) if j < 0 else j), "pp"
        w = self._word(i)
        if w in ("if", "for", "while", "switch"):
            i = self._parens(self._ws(i + len(w)))
            i, _ = self._nested(self._ws(i), depth)
            if w == "if":
                j = self._ws(i)
                if self._word(j) == "else":
                    i, _ = self._nested(self._ws(j + 4), depth)
            return i, "compound"
        if w == "do":
            i, _ = self._nested(self._ws(i + 2), depth)
            i = self._ws(i)
            i = self._parens(self._ws(i + 5))
            return self._ws(i) + 1, "compound"
        if w in ("case", "default"):
            depth_p = 0
            while not (t[i] == ":" and depth_p == 0 and t[i + 1] != ":" and t[i - 1] != ":"):
                i = _skip(t, i)
                depth_p += t[i] in "(["
                depth_p -= t[i] in ")]"
                i += 1
            return i + 1, "case"
        m = re.match(r"[A-Za-z_]\w*\s*:(?!:)", t[i:i + 80])
        if m and w not in KEYWORDS:
            return i + m.end(), "case"
        d = 0
        while True:
            i = _skip(t, i)
            c = t[i]
            if c in "([{":
                d += 1
            elif c in ")]}":
                d -= 1
            elif c == ";" and d == 0:
                return i + 1, "simple"
            i += 1

    def _nested(self, i, depth):
        """A statement that is the body of a compound one: its own entry only if it is a block."""
        if self.text[i] == "{":
            return self._block(i, depth + 1), "block"
        s = i
        i, kind = self._statement(i, depth + 1)
        return i, kind

    # -------------------------------------------------------- queries

    def decl(self, st):
        """(type text, name, array suffix, initialiser or None) if the statement declares one local."""
        if st.kind != "simple":
            return None
        m = DECL.match(self.src(st))
        if not m or self._word(st.start) in KEYWORDS:
            return None
        head = m.group(1).strip()
        if not head or head in KEYWORDS or not re.search(r"[A-Za-z_]", head) or "(" in head:
            return None
        return head, m.group(2), m.group(3), m.group(4)

    def siblings(self, st):
        return sorted((s for s in self.stmts if s.block == st.block), key=lambda s: s.index)

    def names(self, st):
        return set(IDENT.findall(self.src(st)))


def _swap(text, a, b):
    """text with two statements exchanged (a before b), the text between them kept."""
    return text[:a.start] + text[b.start:b.end] + text[a.end:b.start] + text[a.start:a.end] + text[b.end:]


def _indent(text, pos):
    start = text.rfind("\n", 0, pos) + 1
    m = re.match(r"[ \t]*", text[start:pos])
    return m.group(0) if m else ""


def _replace_ident(src, old, new, which=None):
    """src with identifier old replaced by new: every occurrence, or only the which-th."""
    out, k, last = [], 0, 0
    for m in re.finditer(rf"(?<![\w.>])(?<!->){re.escape(old)}\b", src):
        if which is None or k == which:
            out.append(src[last:m.start()] + new)
            last = m.end()
        k += 1
    return "".join(out) + src[last:], k


def subexprs(src):
    """[(start, end)] of the subexpressions of one statement that can be given a name: a
    parenthesised group with an operator in it (not a cast), an argument of a call that is more
    than a name or a number."""
    out, stack = [], []
    i, n = 0, len(src)
    while i < n:
        j = _skip(src, i)
        if j != i:
            i = j
            continue
        c = src[i]
        if c == "(":
            stack.append(i)
        elif c == ")" and stack:
            a = stack.pop()
            inner = src[a + 1:i]
            before = src[:a].rstrip()
            called = bool(re.search(r"[\w\]>]$", before)) and not re.search(r"\b(?:return|if|while|for|switch|case|sizeof|__typeof__)$", before)
            if re.search(r"(?<![=!<>+\-*/|&^])=(?!=)|\+\+|--|\b(?:if|for|while|sizeof)\b", inner):
                pass                                    # an assignment inside: leave it where it is
            elif called:
                depth, start = 0, a + 1
                for k in range(a + 1, i + 1):
                    ch = src[k]
                    depth += ch in "([{"
                    depth -= ch in ")]}" and k != i
                    if (ch == "," and depth == 0) or k == i:
                        arg = src[start:k]
                        if re.search(r"[-+*/|&^<>]|->|\[", arg.strip()) and not re.match(r"^\s*&?\s*[\w.]+\s*$", arg) \
                                and not re.match(r'^\s*-?[\d.xXa-fA-F]+[fFuUlL]*\s*$', arg) and '"' not in arg:
                            lead = len(arg) - len(arg.lstrip())
                            out.append((start + lead, start + len(arg.rstrip())))
                        start = k + 1
            elif re.search(r"[-+/|^<>]|\w\s*[*&]\s*[\w(]|->", inner) and not re.match(r"^[\w\s:]+[\s*&]*$", inner):
                out.append((a, i + 1))
        i += 1
    return sorted(set(out))


def variants(text, aim=None, cap=None, seed=0, cplusplus=True):
    sc = Scan(text)
    if not sc.span or not sc.stmts:
        return []
    out = []
    lines = set(aim["lines"]) if aim else None
    names = set(aim["vars"]) if aim else None
    if aim:
        # the locals read or written on the lines the report names are sites too
        local = {d[1] for d in map(sc.decl, sc.stmts) if d}
        for st in sc.stmts:
            if st.kind == "simple" and any(l in lines for l in sc.lines(st)):
                names |= sc.names(st) & local

    def on(st, var=None, near=0):
        """Is this statement a site the report points to?"""
        if aim is None:
            return True
        if var is not None and var in names:
            return True
        if lines and any(l + k in lines for l in sc.lines(st) for k in range(-near, near + 1)):
            return True
        return False

    def touches(st):
        return aim is None or bool(names & sc.names(st)) or on(st)

    def add(kind, site, new):
        if new != text:
            out.append((kind, site, new))

    decls = {}
    for st in sc.stmts:
        d = sc.decl(st)
        if d:
            decls[st] = d

    # 1. two adjacent statements of a block exchanged: the values they create are born in the
    #    other order (local-alloc numbers quantities by birth, ties go to the lower number), and
    #    a declaration moved past a statement gets its pseudo earlier or later
    for st in sc.stmts:
        sib = sc.siblings(st)
        if st.index + 1 >= len(sib):
            continue
        nxt = sib[st.index + 1]
        if st.kind in ("case", "pp") or nxt.kind in ("case", "pp"):
            continue
        if sc.src(st).lstrip().startswith(("return", "break", "continue", "goto")):
            continue
        if st in decls and decls[st][1] in sc.names(nxt):
            continue                # a declaration cannot go below a statement that uses it
        if touches(st) or touches(nxt):
            add("swap", f"lines {sc.line(st.start)}/{sc.line(nxt.start)}", _swap(text, st, nxt))

    # 2. a statement moved two places (past two neighbours), for births that are not adjacent
    for st in sc.stmts:
        sib = sc.siblings(st)
        if st.index + 2 < len(sib) and st.kind == "simple" and on(st, decls.get(st, (0, None))[1]):
            a, b = sib[st.index + 1], sib[st.index + 2]
            if a.kind in ("simple", "compound", "block") and b.kind in ("simple", "compound", "block") and \
                    not (st in decls and decls[st][1] in (sc.names(a) | sc.names(b))) and \
                    not sc.src(st).lstrip().startswith(("return", "break", "continue", "goto")):
                moved = text[:st.start] + text[a.start:b.end] + text[st.end:a.start] + sc.src(st) + text[b.end:]
                add("move_down2", f"line {sc.line(st.start)}", moved)
        if st.index >= 2 and st.kind == "simple" and on(st, decls.get(st, (0, None))[1]):
            a, b = sib[st.index - 2], sib[st.index - 1]
            if a.kind in ("simple", "compound", "block") and b.kind in ("simple", "compound", "block") and \
                    not any(x in decls and decls[x][1] in sc.names(st) for x in (a, b)):
                moved = text[:a.start] + sc.src(st) + text[b.end:st.start] + text[a.start:b.end] + text[st.end:]
                add("move_up2", f"line {sc.line(st.start)}", moved)

    # 3. declaration order: one declaration placed right before another of the same block (pseudo
    #    numbers follow declaration order; global breaks priority ties by pseudo number)
    by_block = {}
    for st, d in decls.items():
        by_block.setdefault(st.block, []).append(st)
    for group in by_block.values():
        group.sort(key=lambda s: s.index)
        for a in group:
            for b in group:
                if a is b or abs(a.index - b.index) < 2:
                    continue        # adjacent ones are rewrite 1
                if not (on(a, decls[a][1]) and on(b, decls[b][1])) and aim is not None:
                    continue
                if decls[a][3] is not None and a.index < b.index:
                    continue        # an initialised declaration moved down past its uses cannot compile
                ind = _indent(text, b.start)
                if a.start < b.start:
                    new = text[:a.start] + text[a.end:b.start] + sc.src(a) + "\n" + ind + text[b.start:]
                else:
                    new = text[:b.start] + sc.src(a) + "\n" + ind + text[b.start:a.start] + text[a.end:]
                add("decl_before", f"{decls[a][1]} before {decls[b][1]}", new)

    # 4. where a declaration sits: `T x = e;` split into `T x;` at the top of its block and
    #    `x = e;` in place; and `T x; ... x = e;` joined at the first assignment
    for st, (head, name, arr, init) in decls.items():
        if not on(st, name):
            continue
        sib = sc.siblings(st)
        if init is not None and not arr and st.index > 0 and "&" not in head and not head.startswith("const"):
            first = sib[0]
            ind = _indent(text, first.start)
            new = text[:first.start] + f"{head} {name};\n{ind}" + text[first.start:st.start] + f"{name} = {init};" + text[st.end:]
            add("decl_hoist", name, new)
            if sc.blocks[st.block][2] > 0:      # also to the top of the function
                top = min(sc.stmts, key=lambda s: s.start)
                ind0 = _indent(text, top.start)
                new = text[:top.start] + f"{head} {name};\n{ind0}" + text[top.start:st.start] + f"{name} = {init};" + text[st.end:]
                add("decl_hoist_top", name, new)
        if init is None and not arr:
            for later in sib[st.index + 1:]:
                m = re.match(rf"\s*{re.escape(name)}\s*=(?!=)\s*(.*);\s*$", sc.src(later), re.S) if later.kind == "simple" else None
                if m:
                    gap = text[st.end:later.start]
                    new = text[:st.start].rstrip(" \t") + gap.lstrip("\n") if gap.startswith("\n") else text[:st.start] + gap
                    new += f"{head} {name} = {m.group(1)};" + text[later.end:]
                    add("decl_join", name, new)
                    break
                if name in sc.names(later):
                    break

    # 5. references: an alias used in place of what it copies and the reverse (`T x = y;`: one
    #    later `y` written `x` gives x one more reference and y one less), and a temporary used
    #    once folded into its use
    for st, (head, name, arr, init) in decls.items():
        if init is None or arr:
            continue
        m = re.match(r"^(?:\(([^()]+)\)\s*)?([A-Za-z_]\w*)$", init.strip())
        block_end = sc.blocks[st.block][1]
        rest = text[st.end:block_end]
        if m and on(st, name) or (m and aim is not None and m.group(2) in names):
            other = m.group(2)
            cast = f"({head.strip()})" if m.group(1) else ""
            _, n_other = _replace_ident(rest, other, name, which=-1)
            for k in range(min(n_other, 6)):
                new_rest, _ = _replace_ident(rest, other, name, which=k)
                add("alias_use", f"{other} -> {name} #{k}", text[:st.end] + new_rest + text[block_end:])
            _, n_name = _replace_ident(rest, name, f"({cast}{other})" if cast else other, which=-1)
            for k in range(min(n_name, 6)):
                new_rest, _ = _replace_ident(rest, name, f"({cast}{other})" if cast else other, which=k)
                add("alias_drop", f"{name} -> {other} #{k}", text[:st.end] + new_rest + text[block_end:])
        if on(st, name):
            uses = len(re.findall(rf"(?<![\w.>])(?<!->){re.escape(name)}\b", rest))
            if uses == 1 and not re.search(rf"(?<![\w.>]){re.escape(name)}\s*(?:[-+*/|&^]?=(?!=)|\+\+|--)", rest) \
                    and not re.search(rf"&\s*{re.escape(name)}\b", rest):
                new_rest, _ = _replace_ident(rest, name, f"({init.strip()})")
                line_start = text.rfind("\n", 0, st.start) + 1
                alone = text[line_start:st.start].strip() == "" and new_rest.startswith("\n")
                add("fold_temp", name, (text[:line_start] + new_rest[1:] if alone else text[:st.start] + new_rest) + text[block_end:])

    # 6. one pseudo or two: a variable assigned again as a statement of the same block becomes a
    #    fresh variable from there on (`T x2 = ...`), so each life is its own pseudo
    for st, (head, name, arr, init) in decls.items():
        if arr or not on(st, name) or "&" in head:
            continue
        sib = sc.siblings(st)
        for later in sib[st.index + 1:]:
            if later.kind != "simple":
                continue
            m = re.match(rf"(\s*){re.escape(name)}\s*=(?!=)\s*(.*);\s*$", sc.src(later), re.S)
            if m and not re.search(rf"(?<![\w.>])(?<!->){re.escape(name)}\b", m.group(2)):
                block_end = sc.blocks[later.block][1]
                fresh = name + "_2"
                rest, _ = _replace_ident(text[later.end:block_end], name, fresh)
                add("split_var", f"{name} at line {sc.line(later.start)}",
                    text[:later.start] + f"{head} {fresh} = {m.group(2)};" + rest + text[block_end:])
                break

    # 7. a temporary's scope: a declaration and the statements up to its last use wrapped in a
    #    block of their own
    for st, (head, name, arr, init) in decls.items():
        if not on(st, name):
            continue
        sib = sc.siblings(st)
        last = None
        for later in sib[st.index + 1:]:
            if name in sc.names(later):
                last = later
        if last is not None and last.index < len(sib) - 1 and st.index > 0 and \
                not any(s.kind == "case" for s in sib[st.index:last.index + 1]):
            others = [decls[s][1] for s in sib[st.index + 1:last.index + 1] if s in decls]
            after = text[last.end:sc.blocks[st.block][1]]
            if not any(re.search(rf"\b{re.escape(o)}\b", after) for o in others):
                ind = _indent(text, st.start)
                inner = text[st.start:last.end].replace("\n", "\n    ")
                add("scope", name, text[:st.start] + "{\n" + ind + "    " + inner + "\n" + ind + "}" + text[last.end:])

    # 8. which operand comes first (the first register operand that dies is the one tied to the
    #    result's quantity)
    body = text[sc.span[0]:sc.span[1]]
    for m in COMMUTE.finditer(body):
        a, op, b = m.group(1), m.group(2), m.group(3)
        pos = sc.span[0] + m.start()
        before = body[:m.start()].rstrip()
        if a == b or (op in "*&" and before.endswith(("(", "=", ",", "*", "&", "return", ";", "{", "}"))):
            continue        # a dereference or an address, not a product
        if aim is not None and not (sc.line(pos) in lines or ({a.split(".")[0].split("-")[0], b.split(".")[0].split("-")[0]} & names)):
            continue
        add("commute", f"line {sc.line(pos)}: {a} {op} {b}", text[:pos] + f"{b} {op} {a}" + text[sc.span[0] + m.end():])

    # 9. a callee that returns a value sets $v0 at the call, a void one does not: the prototype's
    #    return type toggled (the result must be unused where it becomes void: the compiler says)
    called = {}
    for m in re.finditer(r"\b([A-Za-z_]\w*)\s*\(", body):
        called.setdefault(m.group(1), []).append(sc.line(sc.span[0] + m.start()))
    for m in PROTO.finditer(text[:sc.span[0]]):
        name = m.group("name")
        if name not in called:
            continue
        if aim is not None and not any(l in aim.get("call_lines", lines) for l in called[name]):
            continue
        pointer = "*" in m.group("stars")
        if m.group("ret") == "void" and not pointer:
            for ret in ("int", "void *"):
                add("callee_returns", f"{name}: void -> {ret}",
                    text[:m.start("ret")] + ret + " " + text[m.end("stars"):] if ret == "int" else
                    text[:m.start("ret")] + ret + text[m.end("stars"):])
        else:
            add("callee_returns", f"{name}: {m.group('ret')}{'*' if pointer else ''} -> void",
                text[:m.start("ret")] + "void " + text[m.end("stars"):])

    # 11. the function's own return value: `$v0` stays occupied to the end when the function
    #     returns what a call gave it, and a function declared to return a value that has no
    #     return statement keeps the last call's `$v0` alive the same way (knowledge/gt4.md,
    #     "Return types again")
    head_start = max(text.rfind(";", 0, sc.span[0]), text.rfind("}", 0, sc.span[0])) + 1
    header = text[head_start:sc.span[0]]
    hm = re.search(r"\bvoid\b(?=[\s]+(?:[A-Za-z_]\w*\s*::\s*)*([A-Za-z_]\w*)\s*\()", header)
    if hm and (aim is None or aim.get("v0")) and not re.search(r"\breturn\b", body):
        fname = hm.group(1)

        def retyped(ret, tail_text):
            new_header = header[:hm.start()] + ret + header[hm.end():]
            before = re.sub(rf"\bvoid(\s+(?:[A-Za-z_]\w*\s*::\s*)*{re.escape(fname)}\s*\()", ret + r"\1", text[:head_start])
            return before + new_header + tail_text

        top = [st for st in sc.stmts if st.block == 0 and st.kind == "simple"]
        protos = {m.group("name"): m for m in PROTO.finditer(text[:sc.span[0]])}
        for st in reversed(top):
            m = re.match(r"\s*([A-Za-z_]\w*)\s*\(.*\)\s*;\s*$", sc.src(st), re.S)
            if not m or m.group(1) in KEYWORDS:
                continue
            pm = protos.get(m.group(1))
            if pm is None or (pm.group("ret") == "void" and "*" not in pm.group("stars")):
                continue
            ret = (pm.group("ret") + pm.group("stars")).strip()
            close = sc.span[1] - 1
            ind = _indent(text, st.start)
            tail_text = text[sc.span[0]:st.start] + f"{ret} ret_ = " + sc.src(st).lstrip() + text[st.end:close].rstrip() \
                + f"\n{ind}return ret_;\n" + text[close:]
            add("self_returns", f"returns the result of {m.group(1)} (line {sc.line(st.start)})", retyped(ret, tail_text))
            break
        add("self_returns", "declared int, no return statement", retyped("int", text[sc.span[0]:]))

    # 10. a subexpression given a name: `T q = e + n; ... q->b` instead of `(e + n)->b`. The
    #     value becomes a pseudo of its own, born at the declaration: other ties, another birth
    #     order, another operand order in the insn that used it
    if cplusplus:
        for st in sc.stmts:
            if st.kind != "simple" or not on(st):
                continue
            src = sc.src(st)
            ind = _indent(text, st.start)
            for k, (x, y) in enumerate(subexprs(src)[:8]):
                expr = src[x:y]
                inner = expr[1:-1] if expr.startswith("(") and expr.endswith(")") else expr
                tmp = f"t{sc.line(st.start)}_{k}"
                add("name_subexpr", f"line {sc.line(st.start)}: {inner[:40]}",
                    text[:st.start] + f"__typeof__({inner}) {tmp} = {inner};\n{ind}" + src[:x] + tmp + src[y:] + text[st.end:])

    seen, uniq = {text}, []
    for kind, site, new in out:
        if new not in seen:
            seen.add(new)
            uniq.append((kind, site, new))
    if cap is not None and len(uniq) > cap:
        if aim is None:
            random.Random(seed).shuffle(uniq)
        else:
            # every kind of rewrite gets its turn inside the budget, the kinds in a fixed order
            by_kind = {}
            for v in uniq:
                by_kind.setdefault(v[0], []).append(v)
            queues = [by_kind[k] for k in sorted(by_kind, key=lambda k: KIND_ORDER.index(k) if k in KIND_ORDER else 99)]
            uniq = []
            while any(queues):
                for q in queues:
                    if q:
                        uniq.append(q.pop(0))
        uniq = uniq[:cap]
    return uniq
