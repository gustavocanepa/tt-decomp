#!/usr/bin/env python3
"""Exhaustive statement-order search over a block of independent statements. CPU only.

Near misses that differ only in the order of stores, address updates and the like are decided by
the order the statements are written in (the scheduler's tie-breaks follow it). rewrite_rules and
oracle.py aim exchange two neighbours at a time; the closing order is often further away (the
2026-10-17 004a4de0 case: seven stores of a DMA tag builder). This tries every permutation of the
chosen lines (each line one whole statement) and judges each; the first MATCH is saved through
`swarm.py try`, otherwise the best order is reported.

    stmt_permute.py ADDR DRAFT LO-HI [LO-HI ...] [--cap 5040] [--save] [--jobs 2]

LO-HI are 1-based inclusive line ranges of DRAFT, each a run of one-line statements that may be
reordered among themselves; several ranges are permuted together (the product, capped). A
statement that others depend on (a declaration, `p += 4`) belongs outside the range, or the
variant fails to compile and is skipped.
"""
import argparse
import itertools
import os
import random
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def judge(addr, text, ext):
    d = tempfile.mkdtemp(dir=os.path.join(ROOT, "build"), prefix="perm_")
    path = os.path.join(d, "func_%s.%s" % (addr, ext))
    open(path, "w", encoding="utf-8").write(text)
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", addr, path],
                       capture_output=True, text=True, errors="replace", timeout=600)
    head = (r.stdout.strip().splitlines() or [""])[0]
    if ": MATCH" in head:
        return 0, path
    m = re.search(r"(\d+) of (\d+) instructions differ", head)
    return (int(m.group(1)) if m else None), path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("addr")
    ap.add_argument("draft")
    ap.add_argument("ranges", nargs="+")
    ap.add_argument("--cap", type=int, default=5040)
    ap.add_argument("--save", action="store_true")
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    addr = a.addr.lower()
    ext = a.draft.rsplit(".", 1)[1]
    lines = open(a.draft, encoding="utf-8").read().split("\n")
    spans = []
    for r in a.ranges:
        lo, hi = (int(x) for x in r.split("-"))
        spans.append((lo - 1, hi))
    perms = [list(itertools.permutations(range(hi - lo))) for lo, hi in spans]
    combos = list(itertools.product(*perms))
    random.Random(0).shuffle(combos)
    combos = combos[:a.cap]
    print("%d orders to judge" % len(combos), flush=True)

    def build(c):
        out = list(lines)
        for (lo, hi), p in zip(spans, c):
            block = lines[lo:hi]
            out[lo:hi] = [block[i] for i in p]
        return "\n".join(out)

    best = (10 ** 9, None)
    with ThreadPoolExecutor(a.jobs) as ex:
        for c, (n, path) in zip(combos, ex.map(lambda c: judge(addr, build(c), ext), combos)):
            if n is not None and n < best[0]:
                best = (n, path)
                print("differ %d  order %s  %s" % (n, [list(x) for x in c], path), flush=True)
            if n == 0:
                break
    if best[0] == 0 and a.save:
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "swarm.py"), "try", addr, best[1],
                            "--worker", "permute"], capture_output=True, text=True, errors="replace")
        print(r.stdout.strip().splitlines()[-1] if r.stdout.strip() else r.stderr[-200:])
    print("best:", best)


if __name__ == "__main__":
    main()
