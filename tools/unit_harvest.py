#!/usr/bin/env python3
"""Harvest translation-unit context from the matched sources: what each one needs to match.

A matched source is a measurement of the original unit. Judged again with one thing changed, it
says whether that thing mattered:

  nothrow   every callee prototype declared `throw()`, and none: when either stops the match, each
            callee is toggled alone. A callee whose `throw()` cannot be removed MUST be nothrow for
            this caller (it was defined above the caller in its unit, or it is a C library name the
            compiler knows); a callee that cannot take one MUST NOT be (another unit, or below the
            caller). Sensitive functions whose single toggles all still match are `joint`.
  aliasing  the same source under the other aliasing flag (default <-> no-strict-aliasing, and the
            nosib and nosched1 pairs): a function that stops matching needs the flag it has.

  const     `__attribute__((const))` on the callees below the caller whose machine code is free of
            side effects (unit_map.purity: no store outside the frame, no computed jump, callees
            the same), all at once, then singly when that stops the match. gcc marks a function it
            has compiled and found free of side effects as const for the callers after it in the
            unit, which then keep values cached across the call. A callee that cannot lose the
            attribute MUST be const for this caller; one that cannot take it MUST NOT be.

The source as it is is judged only when a variant fails (to tell a broken source from a sensitive
one), so an insensitive function costs two compiles. C sources and C++ sources without a callee
prototype get the aliasing test only.

    unit_harvest.py run [-j3] [--lo ADDR] [--hi ADDR] [--limit N] [--only ADDR,ADDR] [--batch 200]
    unit_harvest.py status

Output: build/units/harvest.jsonl, rows per (function, source content) naming the aspects they
hold (`ctx`: nothrow and aliasing, `const`); a rerun does the aspects a function lacks, and
the functions whose source is new or changed. Game code (below the library region)
is done first. Read-only for src/: every variant is written under build/units/tmp/ and removed.
tools/unit_map.py turns the rows into unit boundaries, flags and predicted contexts.
"""
import argparse
import collections
import hashlib
import json
import os
import shutil
import sys
import time

import match
import project
import unit_map

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "units")
ROWS = os.path.join(OUT, "harvest.jsonl")
TMP = os.path.join(OUT, "tmp")
NSA = unit_map.NSA
FLIP = unit_map.FLIP


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def rows():
    if not os.path.exists(ROWS):
        return []
    out = []
    for line in open(ROWS):
        try:
            out.append(json.loads(line))
        except ValueError:
            pass  # a row cut short by a kill: the function is done again
    return out


ASPECTS = ("ctx", "const")


class Job:
    """One function: its source, the variants to judge and what they said."""

    def __init__(self, addr, path, have_aspects=()):
        self.addr, self.path = addr, path
        text = open(path, encoding="utf-8", errors="replace").read()
        self.sha = hashlib.sha1(text.encode("utf-8", "replace")).hexdigest()[:16]
        self.have_aspects = have_aspects
        self.ext = os.path.splitext(path)[1]
        self.body, self.own = unit_map.strip_marker(text)
        self.files = {}   # variant name -> path
        self.res = {}     # variant name -> verdict

    def parse(self, done):
        """Read the prototypes; False when every aspect is already harvested."""
        self.aspects = [x for x in ASPECTS if x not in done.get((f"{self.addr:08x}", self.sha), ())]
        if not self.aspects:
            return False
        self.p = unit_map.Protos(self.body, self.addr) if self.ext == ".cpp" else None
        self.callees = self.p.callees if self.p else []
        self.have = self.p.have if self.p else frozenset()
        self.have_const = self.p.have_const if self.p else frozenset()
        self.cands = [c for c in self.callees if c in self.have_const or
                      (c < self.addr and unit_map.purity(c) != "impure")]
        return True

    def add(self, name, nothrow, const, profile, pairs):
        path = os.path.join(TMP, f"u{self.addr:08x}_{name}{self.ext}")
        body = self.p.render(nothrow, const) if self.p else self.body
        with open(path, "w", encoding="utf-8", newline="\n") as f:
            f.write((f"/* compiler: {profile} */\n" if profile else "") + body)
        self.files[name] = path
        pairs.append((self.addr, path))

    def stage1(self, pairs):
        if "ctx" in self.aspects:
            everything = frozenset(self.callees)
            if self.callees and self.have != everything:
                self.add("all", everything, self.have_const, self.own, pairs)
            if self.have:
                self.add("none", frozenset(), self.have_const, self.own, pairs)
            if self.own in FLIP:
                self.add("flag", self.have, self.have_const, FLIP[self.own], pairs)
        if "const" in self.aspects:
            if self.cands and self.have_const != frozenset(self.cands):
                self.add("kall", self.have, frozenset(self.cands), self.own, pairs)
            if self.have_const:
                self.add("knone", self.have, frozenset(), self.own, pairs)

    def stage2(self, pairs):
        if any(self.moved(n) for n in ("all", "none", "flag", "kall", "knone")):
            self.add("base", self.have, self.have_const, self.own, pairs)

    def stage3(self, pairs):
        if self.res.get("base") != "match":
            return
        if self.moved("all") or self.moved("none"):
            for c in self.callees:
                self.add(f"t{c:08x}", self.have ^ frozenset([c]), self.have_const, self.own, pairs)
        if self.moved("kall") or self.moved("knone"):
            for c in self.cands:
                self.add(f"k{c:08x}", self.have, self.have_const ^ frozenset([c]), self.own, pairs)

    def take(self, verdicts):
        for name, path in self.files.items():
            if path in verdicts:
                self.res[name] = verdicts[path]
                if os.path.exists(path):
                    os.remove(path)
        self.files = {n: p for n, p in self.files.items() if n not in self.res}

    def moved(self, name):
        return name in self.res and self.res[name] != "match"

    def determined(self, prefix, cands, have):
        """(must, must not, errors) from the single toggles of one kind."""
        must, must_not, unknown = [], [], []
        for c in cands:
            v = self.res.get(f"{prefix}{c:08x}")
            if v == "error":
                unknown.append(f"{c:08x}")
            elif v is not None and v != "match":
                (must if c in have else must_not).append(f"{c:08x}")
        return must, must_not, unknown

    def row(self):
        show = lambda v: v if isinstance(v, str) or v is None else f"differs:{v[1]}"
        r = {"addr": f"{self.addr:08x}", "sha": self.sha, "aspects": self.aspects,
             "src": os.path.relpath(self.path, ROOT).replace("\\", "/"),
             "profile": self.own or "default", "bytes": match.function_span(self.addr),
             "base": show(self.res.get("base"))}
        if "ctx" in self.aspects:
            r.update(callees=[f"{c:08x}" for c in self.callees], have=sorted(f"{c:08x}" for c in self.have),
                     all=show(self.res.get("all")), none=show(self.res.get("none")), flag=show(self.res.get("flag")))
            if any(n.startswith("t") for n in self.res):
                r["must"], r["must_not"], r["toggle_errors"] = self.determined("t", self.callees, self.have)
        if "const" in self.aspects:
            r.update(const_cands=[f"{c:08x}" for c in self.cands], have_const=sorted(f"{c:08x}" for c in self.have_const),
                     kall=show(self.res.get("kall")), knone=show(self.res.get("knone")))
            if any(n.startswith("k") and n not in ("kall", "knone") for n in self.res):
                r["must_const"], r["must_not_const"], r["const_errors"] = self.determined("k", self.cands, self.have_const)
        return r


def work(a):
    done = collections.defaultdict(set)
    for r in rows():
        done[(r["addr"], r["sha"])].update(r.get("aspects", ["ctx"]))
    srcs = project.sources(refresh=True)
    only = {int(x, 16) for x in a.only.split(",")} if a.only else None
    todo = [addr for addr in sorted(srcs) if a.lo <= addr < a.hi and (only is None or addr in only)]
    # game code first: the library region is mostly other people's units
    todo.sort(key=lambda addr: (addr >= unit_map.LIBRARY, addr))
    return todo, srcs, done


def cmd_run(a):
    os.makedirs(TMP, exist_ok=True)
    sys.setrecursionlimit(20000)  # unit_map.purity follows call chains
    todo, srcs, done = work(a)
    log(f"harvest: {len(todo)} matched sources in range, {len(done)} with rows already, {a.jobs} jobs")
    started, counts, n_new = time.time(), collections.Counter(), 0
    pending = []
    with open(ROWS, "a") as out:
        def flush(jobs_):
            for stage in (Job.stage1, Job.stage2, Job.stage3):
                pairs = []
                for j in jobs_:
                    stage(j, pairs)
                v = unit_map.judge_all(pairs, a.jobs, srcs)
                counts["compiles"] += len(pairs)
                for j in jobs_:
                    j.take(v)
            for j in jobs_:
                r = j.row()
                out.write(json.dumps(r) + "\n")
                counts["functions"] += 1
                if r["base"] == "match":
                    counts["nothrow-sensitive"] += j.moved("all") or j.moved("none")
                    counts["flag-sensitive"] += j.moved("flag")
                    counts["const-sensitive"] += j.moved("kall") or j.moved("knone")
                    counts["pairs"] += len(r.get("must", [])) + len(r.get("must_not", []))
                    counts["const pairs"] += len(r.get("must_const", [])) + len(r.get("must_not_const", []))
                elif r["base"] is not None:
                    counts["source does not match as it is"] += 1
            out.flush()

        for addr in todo:
            try:
                j = Job(addr, srcs[addr])
                if not j.parse(done):
                    continue
            except OSError:
                continue  # moved by an integration since the scan
            pending.append(j)
            n_new += 1
            if len(pending) >= a.batch:
                flush(pending)
                pending = []
                rate = counts["functions"] / max(1e-9, time.time() - started)
                log(f"{counts['functions']} functions ({rate:.1f}/s, at {addr:08x}), {counts['compiles']} compiles: "
                    f"{counts['nothrow-sensitive']} nothrow-sensitive ({counts['pairs']} pairs), "
                    f"{counts['const-sensitive']} const-sensitive ({counts['const pairs']} pairs), "
                    f"{counts['flag-sensitive']} need their flag, {counts['source does not match as it is']} broken")
            if a.limit and n_new >= a.limit:
                break
        if pending:
            flush(pending)
    log(f"harvest done: {dict(counts)} in {time.time() - started:.0f}s")


def cmd_status(a):
    rs = list(unit_map.harvest_rows().values())
    cpp = [r for r in rs if r.get("callees")]
    ok = lambda r: r["base"] in (None, "match")
    moved = lambda r, k: r.get(k) not in (None, "match", "error") and r["base"] == "match"
    sens = [r for r in cpp if moved(r, "all") or moved(r, "none")]
    print(f"{len(rs)} functions judged, {len(cpp)} C++ with callee prototypes, "
          f"{sum(1 for r in rs if not ok(r))} sources that do not match as they are")
    print(f"nothrow-sensitive: {len(sens)} ({100 * len(sens) / max(1, len(cpp)):.1f}% of those with callees); "
          f"pairs: {sum(len(r.get('must', [])) for r in sens)} must be nothrow, "
          f"{sum(len(r.get('must_not', [])) for r in sens)} must not; "
          f"{sum(1 for r in sens if not r.get('must') and not r.get('must_not'))} joint only")
    bands = [(0, 128), (129, 256), (257, 512), (513, 1024), (1025, 1 << 30)]
    for lo, hi in bands:
        inb = [r for r in cpp if lo <= r["bytes"] <= hi and ok(r)]
        s = [r for r in inb if moved(r, "all") or moved(r, "none")]
        print(f"  {lo:5}-{hi if hi < 1 << 30 else 'up':>5} B: {len(s):4} of {len(inb):5} ({100 * len(s) / max(1, len(inb)):.1f}%)")
    flag = [r for r in rs if moved(r, "flag")]
    c = collections.Counter(r["profile"] for r in flag)
    print(f"need their aliasing flag: {len(flag)} of {sum(1 for r in rs if r.get('flag'))} tested: {dict(c)}")
    kc = [r for r in rs if r.get("const_cands")]
    ks = [r for r in kc if moved(r, "kall") or moved(r, "knone")]
    print(f"const: {len(kc)} functions call a side-effect-free callee below them (of {sum(1 for r in cpp if 'kall' in r)} "
          f"with callees judged), {len(ks)} const-sensitive; pairs: {sum(len(r.get('must_const', [])) for r in ks)} "
          f"must be const, {sum(len(r.get('must_not_const', [])) for r in ks)} must not")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("run")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--lo", type=lambda x: int(x, 16), default=0)
    p.add_argument("--hi", type=lambda x: int(x, 16), default=1 << 32)
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--only")
    p.add_argument("--batch", type=int, default=200)
    sub.add_parser("status")
    a = ap.parse_args()
    {"run": cmd_run, "status": cmd_status}[a.cmd](a)


if __name__ == "__main__":
    main()
