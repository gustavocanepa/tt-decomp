#!/usr/bin/env python3
"""Translation-unit context a one-function source lacks: which of its callees cannot throw.

The original compiler saw the whole unit, so it knew that a callee defined (or declared `throw()`)
above the caller cannot throw; reorg then scans past the call, which decides `beq` against `beql`
and what fills a delay slot. A draft that is right but declares its callees plainly is then one or
a few instructions off, every one of them a branch against its branch-likely form.

This module finds the callee prototypes of a C++ source and searches the subsets to declare
`throw()`; it compiles nothing itself. `Search` hands out the variants to judge and takes the
scores back, so one caller can drive many drafts in batches (finish_near.py context) and another a
single draft:

    s = Search(addr, text)
    while True:
        variants = s.frontier()            # [(nothrow set, profile)], empty when the search is over
        if not variants:
            break
        s.feed([(chosen, profile, score_of(s.render(chosen, profile))) for chosen, profile in variants])
    s.best                                 # (score, nothrow set, profile), score MATCH on a match

A score is any tuple that orders verdicts, MATCH for a match, None for a variant that did not
compile.
"""
import re

import project
import symbols

MATCH = (0, 0)
NO_STRICT_ALIASING = "ee-gcc2.96-no-strict-aliasing"
PROFILES = (None, NO_STRICT_ALIASING)  # None: the project's compiler
ROUNDS = 8

KEYWORDS = re.compile(r"\b(return|else|do|case|goto|delete|new|throw|sizeof|if|while|for|switch)\b")
PROTO = re.compile(r"^(?P<head>[^=;{}()]*?[\w\*&>\s])(?P<name>[A-Za-z_]\w*)\s*"
                   r"(?P<args>\((?:[^;{}()]|\([^()]*\))*\))\s*(?P<cv>const)?\s*;", re.S)


def split_statements(text):
    """(start, end) of each `...;` chunk outside function bodies (file scope, extern "C" blocks
    and class bodies)."""
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
        if c == "{":
            head = text[start:i]
            if re.search(r'extern\s+"C(\+\+)?"\s*$', head):
                kinds.append("lang")
            elif re.search(r"\b(struct|class|union|enum|namespace)\b[^;{}()=]*$", head):
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
                yield start, i + 1
            start = i + 1
        i += 1


def prototypes(text, own=None):
    """[(offset, address)] of the callee prototypes that can take a `throw()`: the offset is where
    it goes, the address the callee's. Prototypes that already have one, typedefs, function
    pointers, names the symbol table does not know and the function's own declaration are left
    out."""
    out = []
    for s, e in split_statements(text):
        chunk = text[s:e]
        lead = len(chunk) - len(chunk.lstrip())
        m = PROTO.match(chunk.lstrip())
        if not m or KEYWORDS.search(m.group("head")) or "throw" in chunk or "typedef" in m.group("head"):
            continue
        if "(*" in chunk[:lead + m.start("name")]:
            continue
        try:
            addr = symbols.address_of(m.group("name"))
        except Exception:
            addr = None
        if addr is None or addr == own:
            continue
        out.append((s + lead + (m.end("cv") if m.group("cv") else m.end("args")), addr))
    return out


def strip_marker(text):
    """(text without its `/* compiler: NAME */` first line, NAME or None)."""
    first, _, rest = text.partition("\n")
    m = project.COMPILER_MARKER.match(first)
    return (rest, m.group(1)) if m else (text, None)


class Search:
    """Coordinate descent over the nothrow subsets of one draft's callees, as experiment E1b ran
    it: the draft as it is, every callee, the callees at a lower address (a unit is laid out in
    source order, so those are the ones the compiler had seen), each under every profile; then
    rounds that toggle each callee singly from the best state and keep the best strict
    improvement. When a round improves nothing, the end state is judged under the other profiles
    once more. It stops at the first MATCH."""

    def __init__(self, addr, text, profiles=PROFILES):
        self.addr = addr
        self.body, self.own = strip_marker(text)
        self.protos = prototypes(self.body, addr)
        self.callees = list(dict.fromkeys(a for _, a in self.protos))
        self.profiles = list(dict.fromkeys([self.own, *profiles]))
        self.base = None    # score of the draft as it is
        self.best = None    # (score, nothrow set, profile)
        self.judged = 0
        self.done = not self.callees
        self._phase, self._round, self._tried = "start", 0, set()

    def render(self, chosen, profile):
        """The draft with `throw()` on the prototypes of `chosen` and the marker of `profile`."""
        out, last = [], 0
        for cut, addr in self.protos:
            if addr in chosen:
                out.append(self.body[last:cut] + " throw()")
                last = cut
        out.append(self.body[last:])
        return (f"/* compiler: {profile} */\n" if profile else "") + "".join(out)

    def _candidates(self):
        if self._phase == "start":
            everything = frozenset(self.callees)
            sets = [frozenset(), everything, frozenset(a for a in everything if a < self.addr)]
            return [(s, p) for s in sets for p in self.profiles]
        _, chosen, profile = self.best
        if self._phase == "descend":
            return [(chosen ^ frozenset([c]), profile) for c in self.callees]
        return [(chosen, p) for p in self.profiles]

    def _advance(self, improved):
        if self.best is None or self.best[0] == MATCH or self._round >= ROUNDS:
            self.done = True  # nothing compiled, matched, or out of rounds
        elif self._phase == "start":
            self._phase = "descend"
        elif self._phase == "descend":
            if not improved:
                self._phase = "profiles"
        elif improved:
            self._phase = "descend"
        else:
            self.done = True

    def frontier(self):
        """The (nothrow set, profile) variants to judge next; empty when the search is over."""
        while not self.done:
            new = [c for c in dict.fromkeys(self._candidates()) if c not in self._tried]
            if new:
                self._tried.update(new)
                return new
            self._advance(False)
        return []

    def feed(self, results):
        """Take the scores of the last frontier: [(nothrow set, profile, score or None)]."""
        improved = False
        for chosen, profile, score in results:
            self.judged += 1
            if not chosen and profile == self.own:
                self.base = score
            if score is not None and (self.best is None or score < self.best[0]):
                self.best, improved = (score, chosen, profile), True
        self._round += 1
        self._advance(improved)


def minimise(chosen, matches):
    """The nothrow set reduced to one that still matches with no callee left to drop
    (`matches(set)` judges). A set found by search can hold callees that do not matter, and every
    `throw()` saved is a claim about the original unit."""
    chosen = frozenset(chosen)
    for c in sorted(chosen):
        if matches(chosen - {c}):
            chosen = chosen - {c}
    return chosen
