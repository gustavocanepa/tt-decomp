#!/usr/bin/env python3
"""Finish, on the CPU only, the near misses the agents leave behind.

Every give-up keeps its closest draft (build/swarm/WORKER/ADDR*.c*, build/swarm/local/ADDR.*), and
no tool looked at those: cpu_pipeline's permuter stage only takes m2c's own near misses. The drafts
`swarm.py try` judged and kept (drafts/, tools/attempt_store.py) are read too, the closest two per
function, and each step is noted there on the text it ran on.

    finish_near.py sweep [-jN] [--max-distance 20]
        judges every draft of every unmatched function, keeps the closest one per function, and
        judges it again under each compiler profile (project.toml [compilers.*]: strict aliasing,
        sibling calls, gcse and the 2004 assembler each move a few instructions).
    finish_near.py permute [--seconds 300] [--jobs 4] [--max-distance 5] [--limit N]
        decomp-permuter on the closest drafts, closest first. It reads C only: a draft with member
        functions or references is reported as "not C" and left to the agents.
    finish_near.py context [-jN] [--max-distance 20] [--only ADDR,ADDR]
    finish_near.py rewrite [-jN] [--max-distance 20] [--variants 30] [--only ADDR,ADDR]
    finish_near.py status

A match from the sweep, context or rewrite is saved by `swarm.py try ... --worker finisher` (judged
again, logged); permute.py saves its own. State: build/finish/results.jsonl, one row per step and
draft content, so a rerun only works drafts that are new or changed. Run it again after every swarm
session, in this order: sweep, context, rewrite, permute. Each step starts from the function's
closest draft so far, which is the agent's own or a closer variant an earlier step kept under
build/finish/ADDR/.

Context: what the rest of the translation unit told the compiler
    A one-function source cannot say which callees the original compiler knew could not throw
    (those defined above the caller in its unit, or declared `throw()`), and that decides `beq`
    against `beql` and delay-slot fills: such a draft is right and still one or a few instructions
    off. `context` searches the subsets of the draft's callee prototypes to declare `throw()`
    (tools/tu_context.py: none, all, the callees at a lower address, then single toggles by
    coordinate descent), each with both aliasing profiles, all drafts judged together a round at a
    time, and stops a draft at its first MATCH. The set is then reduced to one with no callee left
    to drop, and the source is saved with those `throw()` and the profile marker written in. With
    no match, a variant with fewer differing instructions becomes the function's closest draft
    (build/finish/ADDR/context.cpp). C drafts and drafts without a callee prototype are recorded
    and skipped. Eight judge calls a draft on average (six for the first round, then one per callee
    and round), two minutes for 143 drafts at 4 jobs.

Rewrite: one round of source shapes that move registers and order
    `rewrite` judges up to --variants single-step variants of each draft from regsearch.variants
    (order of the leading local declarations, operands of one commutative operator, one statement
    wrapped in a block, two adjacent statements exchanged); they work on text, so C++ is accepted.
    A MATCH is saved; else the variant with the fewest differing instructions, if fewer than the
    draft's, becomes the closest draft (build/finish/ADDR/rewrite.*). That is a new draft, so every
    rerun climbs one more round on the functions that moved and skips the others. Five and a half
    minutes for 184 drafts (4,038 judge calls) at 4 jobs. Only a MATCH proves a variant: two
    exchanged statements can differ in fewer instructions and no longer do the same thing, so a
    closer variant is a lead for the next round, not a better source.
"""
import argparse
import collections
import concurrent.futures
import glob
import hashlib
import json
import difflib
import os
import random
import re
import subprocess
import sys
import time

import attempt_store
import match
import project
import regsearch
import rewrite_rules
import swarm
import symbols
import tu_context

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "finish")
RESULTS = os.path.join(OUT, "results.jsonl")
DRAFT = re.compile(r"^([0-9a-fA-F]{8})(?:[_.].*)?\.(c|cpp)$")
# Only the nosched1 pair stays out (it hides a store-order difference instead of explaining it).
# The libraries' -g profiles (nsa-g: soft-float libm and stdio, 30+ closings on 2026-10-17) and the
# SDK's 2.9 (glue below LIBRARY_START too, tried as C and as C++) were skipped until then, and were
# the profile behind most of that day's closings.
SKIP_PROFILES = ("ee-gcc2.9-", "nosched1")
SWEEP_VERSION = 2  # a sweep row of an older version is redone: the profile list grew
STEPS = ("sweep", "context", "rewrite")  # the steps that judge a draft and can keep a closer one
DIFFER = re.compile(r"(\d+) of (\d+) instructions differ")
VERSION = attempt_store.digest(attempt_store.read(__file__))[:8]  # of this tool, for the attempt store's pass rows


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def rows():
    if not os.path.exists(RESULTS):
        return []
    return [json.loads(line) for line in open(RESULTS) if line.strip()]


def record(row):
    os.makedirs(OUT, exist_ok=True)
    with open(RESULTS, "a") as f:
        f.write(json.dumps(row) + "\n")
    # the attempt store notes which steps a kept text has been through (no-op for other texts)
    attempt_store.mark_pass(row["addr"], row["sha"], row["step"], VERSION, row.get("matched") or row.get("best_distance"))


def digest(path):
    return hashlib.sha1(open(path, "rb").read()).hexdigest()[:16]


def drafts():
    """{addr: [paths]} of the saved drafts of functions that still have no source."""
    done = set(project.sources())
    skip = swarm.sdk_functions()
    out = collections.defaultdict(list)
    for path in glob.glob(os.path.join(ROOT, "build", "swarm", "*", "*")):
        m = DRAFT.match(os.path.basename(path))
        if m:
            addr = int(m.group(1), 16)
            if addr not in done and addr not in skip:
                out[addr].append(os.path.relpath(path, ROOT))
    # what `swarm.py try` and `giveup` kept (tools/attempt_store.py): the closest texts per function
    for addr, paths in attempt_store.drafts(out).items():
        if addr not in done and addr not in skip:
            out[addr] += paths
    return out


# Library addresses also get the SDK's compiler: 00589b20 and 00590ca0 were "one scheduler decision
# off" under ee-gcc 2.96 for as long as nobody tried 2.9; config/compiler_sdk.txt does not list
# every SDK function.
SDK_PROFILE = "ee-gcc2.9-991111"
LIBRARY_START = 0x5547E8
SDK_START = 0x3AC140  # the first function the SDK compiler built (autoloop.other_compiler)


def with_profile(path, profile, addr, as_cpp=False):
    """A copy of the draft asking for `profile` on its first line (None: the project's compiler)."""
    lines = open(os.path.join(ROOT, path), encoding="utf-8", errors="replace").read().split("\n")
    if lines and project.COMPILER_MARKER.match(lines[0]):
        lines = lines[1:]
    ext = os.path.splitext(path)[1]
    if profile == SDK_PROFILE and not as_cpp:
        # The SDK's compiler takes C: a C++ draft is tried as C with its linkage markers dropped
        # (one that needs C++ just fails to compile and is not counted).
        ext = ".c"
        lines = re.sub(r'extern\s+"C"\s+(?!\{)', "", "\n".join(lines)).split("\n")
    if profile:
        lines.insert(0, f"/* compiler: {profile} */")
    out = os.path.join(OUT, f"{addr:08x}", f"{profile or 'default'}{'-cpp' if as_cpp else ''}{ext}")
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(lines))
    return os.path.relpath(out, ROOT)


BRANCH_TARGET = re.compile(r"\. [+-] 4 [+-] \(-?0x[0-9A-Fa-f]+ << 2\)")


def aligned_distance(diff):
    """Instructions that differ once the two listings are aligned. The judge counts row by row, so
    one inserted nop makes every later row differ ("102 of 163" for a draft three instructions
    off); branch targets move with an insertion and are compared as one token."""
    left, right = [], []
    for line in diff.split("\n"):
        if "|" in line and line[:2] in ("  ", "! "):
            a, b = line[2:].split("|", 1)
            a = BRANCH_TARGET.sub(".L", a.strip())
            b = BRANCH_TARGET.sub(".L", re.sub(r"\s+<[^>]*>\s*$", "", b).strip())
            if a != "-":
                left.append(a)
            if b != "-":
                right.append(b)
    if not left or not right:
        return None
    blocks = difflib.SequenceMatcher(None, left, right, autojunk=False).get_matching_blocks()
    return max(1, max(len(left), len(right)) - sum(b.size for b in blocks))


def verdict(addr, path):
    """match.py check's verdict as a dict: status match/different/error, distance (differing
    instructions), original (instruction count), norm, the diff text and a fingerprint of it."""
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "match.py"), "check", f"{addr:08x}", path],
                         capture_output=True, text=True)
    out = (res.stdout + res.stderr).strip()
    head = out.splitlines()[0] if out else ""
    m = re.search(r"MATCH \((\d+) instructions\)", head)
    if m:
        return {"status": "match", "distance": 0, "original": int(m.group(1)), "norm": 0.0,
                "diff": "", "fingerprint": "match"}
    m = re.search(r"(\d+) of (\d+) instructions differ \(original (\d+)", head)
    if not m:
        return {"status": "error", "norm": float("inf"), "error": out[-2000:]}
    differ, original = int(m.group(1)), int(m.group(3))
    diff = "\n".join(l for l in out.splitlines()[1:] if l.startswith(("!", " ", "-", "+")))
    return {"status": "different", "distance": differ, "original": original,
            "norm": differ / max(1, original), "diff": diff,
            "fingerprint": hashlib.sha1(diff.encode()).hexdigest()}


def judge(addr, path):
    """verdict() with `distance` taken as the smaller of the judge's row count (kept as
    `positional`) and the aligned distance: that is what decides whether a draft is within reach."""
    try:
        v = verdict(addr, os.path.join(ROOT, path))
    except (Exception, SystemExit) as e:
        return {"status": "error", "error": str(e)}
    if v.get("status") == "different":
        v["positional"] = v["distance"]
        a = aligned_distance(v.get("diff", ""))
        if a is not None and a < v["distance"]:
            v["aligned"] = v["distance"] = a
    return v


def defined_elsewhere(addr):
    """A source that already defines this function under its real name inside another function's
    file (upstream has a few two-function files; project.sources() only knows files by name)."""
    name = symbols.name_of(addr)
    if not name or name.startswith("func_"):
        return None
    res = subprocess.run(["git", "grep", "-lE", rf"\b{re.escape(name)}\([^;]*\)\s*\{{", "--", "src"],
                         capture_output=True, text=True, cwd=ROOT)
    return res.stdout.split("\n")[0] or None


def save(addr, path):
    other = defined_elsewhere(addr)
    if other:
        return f"not saved: {other} already defines it"
    def attempt(p):
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "swarm.py"), "try", f"{addr:08x}",
                              os.path.join(ROOT, p), "--worker", "finisher"], capture_output=True, text=True, cwd=ROOT)
        return (res.stdout + res.stderr).strip()
    out = attempt(path)
    if "must define" in out:
        # A draft that defines the function under its real name (the judge accepts it, try wants
        # func_ADDR; organize.py gives the real name back at integration).
        name, src = symbols.name_of(addr), open(os.path.join(ROOT, path), encoding="utf-8").read()
        fixed = re.sub(rf"\bfunc_{addr:08x}\b", f"func_{addr:08X}", src, flags=re.I)
        if name and not name.startswith("func_"):
            fixed = re.sub(rf"\b{re.escape(name)}\b", f"func_{addr:08X}", fixed)
        if fixed != src:
            renamed = os.path.join(os.path.dirname(path), "renamed_" + os.path.basename(path))
            with open(os.path.join(ROOT, renamed), "w", encoding="utf-8", newline="\n") as f:
                f.write(fixed)
            out = attempt(renamed)
    return out.splitlines()[-1] if out else "no output"


def sweep_one(addr, paths, profiles, swept, max_distance):
    judged = [(judge(addr, p), p) for p in paths]
    hit = next((p for v, p in judged if v["status"] == "match"), None)
    if hit:
        return {"step": "sweep", "addr": f"{addr:08x}", "draft": hit, "sha": digest(os.path.join(ROOT, hit)),
                "distance": 0, "matched": "as is", "saved": save(addr, hit)}
    judged = [(v, p) for v, p in judged if v["status"] == "different"]
    if not judged:
        return None
    best, path = min(judged, key=lambda x: x[0]["distance"])
    sha = digest(os.path.join(ROOT, path))
    if best["distance"] > max_distance or (f"{addr:08x}", sha) in swept:
        return None
    row = {"step": "sweep", "addr": f"{addr:08x}", "draft": path, "sha": sha, "distance": best["distance"],
           "positional": best["positional"], "original": best["original"], "profiles": {}, "matched": None}
    current = project.source_compiler(os.path.join(ROOT, path))
    row["v"] = SWEEP_VERSION
    tries = [(p, False) for p in [None] + profiles]
    if addr >= SDK_START:
        tries += [(SDK_PROFILE, False), (SDK_PROFILE, True)]  # as C, and as C++ (ring-buffer init, 005AEF80)
        row["sdk"] = True
    for profile, as_cpp in tries:
        if profile == current and not as_cpp:
            continue
        variant = with_profile(path, profile, addr, as_cpp)
        v = judge(addr, variant)
        name = (profile or "default") + ("+cpp" if as_cpp else "")
        if v["status"] == "match":
            row["matched"], row["saved"] = name, save(addr, variant)
            break
        if v["status"] == "different":
            row["profiles"][name] = v["distance"]
            if v["distance"] < row.get("best_distance", best["distance"]):
                row["best_distance"], row["best_draft"] = v["distance"], variant
    return row


def cmd_sweep(a):
    profiles = [p for p in project.compilers() if not any(s in p for s in SKIP_PROFILES)]
    todo = drafts()
    swept = {(r["addr"], r["sha"]) for r in rows() if r["step"] == "sweep" and r.get("v") == SWEEP_VERSION}
    log(f"sweep: {len(todo)} unmatched functions with drafts ({sum(len(v) for v in todo.values())} files), "
        f"profiles: default + {', '.join(profiles)}")
    matched = closer = kept = 0
    with concurrent.futures.ThreadPoolExecutor(a.jobs) as pool:
        futures = [pool.submit(sweep_one, addr, paths, profiles, swept, a.max_distance) for addr, paths in sorted(todo.items())]
        for i, fut in enumerate(concurrent.futures.as_completed(futures), 1):
            row = fut.result()
            if row:
                record(row)
                kept += 1
                if row["matched"]:
                    matched += 1
                    log(f"{row['addr']}: MATCH ({row['matched']}, was {row['distance']} off): {row.get('saved', '')}")
                elif "best_distance" in row:
                    closer += 1
                    log(f"{row['addr']}: {row['distance']} -> {row['best_distance']} off with {os.path.basename(row['best_draft'])}")
            if i % 50 == 0:
                log(f"progress: {i} of {len(futures)} functions, {matched} matched, {closer} closer")
    log(f"sweep done: {kept} functions within {a.max_distance} instructions, {matched} matched, {closer} closer under another profile")


def closest():
    """{addr: (distance, draft)} from the rows of the judging steps, for functions still unmatched."""
    done = set(project.sources())
    out = {}
    for r in rows():
        if r["step"] in STEPS and not r["matched"] and int(r["addr"], 16) not in done:
            cand = (r.get("best_distance", r["distance"]), r.get("best_draft", r["draft"]))
            if r["addr"] not in out or cand[0] < out[r["addr"]][0]:
                out[r["addr"]] = cand
    return out


def cmd_permute(a):
    tried = {(r["addr"], r["sha"]) for r in rows() if r["step"] == "permute"}
    todo = sorted((d, addr, path) for addr, (d, path) in closest().items()
                  if d <= a.max_distance and os.path.exists(os.path.join(ROOT, path))
                  and (addr, digest(os.path.join(ROOT, path))) not in tried)[:a.limit]
    log(f"permute: {len(todo)} drafts within {a.max_distance} instructions, {a.seconds}s each, {a.jobs} jobs")
    matched = not_c = 0
    for distance, addr, path in todo:
        if project.source_for(int(addr, 16)):
            continue
        res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "permute.py"), addr, os.path.join(ROOT, path),
                              "--seconds", str(a.seconds), "--jobs", str(a.jobs)], capture_output=True, text=True, cwd=ROOT)
        out = (res.stdout + res.stderr).strip().splitlines()
        verdict = "match" if any(l.startswith("MATCH") or ": MATCH" in l for l in out) else \
            "not C" if any(l.startswith("NOT C") for l in out) else "no match"
        matched += verdict == "match"
        not_c += verdict == "not C"
        record({"step": "permute", "addr": addr, "draft": path, "sha": digest(os.path.join(ROOT, path)),
                "distance": distance, "seconds": a.seconds, "result": verdict, "output": out[-2:]})
        log(f"{addr}: {verdict} (was {distance} off){': ' + out[-1][:120] if out else ''}")
    log(f"permute done: {matched} matched, {not_c} not C, of {len(todo)}")


def score(ok, report):
    """A judge report as (differing instructions, instructions outside the longest common
    alignment): MATCH is (0, 0), None is a draft that did not compile or was refused. The second
    number breaks ties: one inserted instruction shifts every row after it, and counts 1 there."""
    if ok:
        return tu_context.MATCH
    first = report.split("\n")[0]
    m = DIFFER.search(first)
    if not m or report.startswith("compile failed") or "REFUSED" in first:
        return None
    left, right = [], []
    for line in report.split("\n")[1:]:
        if "|" in line and line[:2] in ("  ", "! "):
            a, b = line[2:].split("|", 1)
            a, b = a.strip(), re.sub(r"\s+<[^>]*>\s*$", "", b).strip()
            if a != "-":
                left.append(a)
            if b != "-":
                right.append(b)
    blocks = difflib.SequenceMatcher(None, left, right, autojunk=False).get_matching_blocks()
    return int(m.group(1)), max(len(left), len(right)) - sum(b.size for b in blocks)


def judge_batch(pairs, jobs):
    """[(addr, path relative to the root)] judged together, `jobs` compiles at a time: yields
    (path, score) in order. The cheap way to judge many variants; save() judges a match again."""
    for _, src, ok, report in match.judge_many([(addr, os.path.join(ROOT, p)) for addr, p in pairs], jobs=jobs, chunk=200):
        yield os.path.relpath(src, ROOT), score(ok, report)


def work(a, step):
    """[(addr, distance, draft)] of the closest drafts within reach that `step` has not worked: a
    row of that step with the same content, or a variant the context step wrote itself (its search
    had already converged on it)."""
    seen = set()
    for r in rows():
        if r["step"] == step:
            seen.add((r["addr"], r["sha"]))
            if step == "context" and r.get("best_sha"):
                seen.add((r["addr"], r["best_sha"]))
    only = {f"{int(x, 16):08x}" for x in a.only.split(",")} if a.only else None
    return [(addr, d, path) for addr, (d, path) in sorted(closest().items())
            if d <= a.max_distance and (not only or addr in only) and os.path.exists(os.path.join(ROOT, path))
            and (addr, digest(os.path.join(ROOT, path))) not in seen]


def variant_path(addr, name, ext):
    out = os.path.join(OUT, addr, name + ext)
    os.makedirs(os.path.dirname(out), exist_ok=True)
    return os.path.relpath(out, ROOT)


def write(path, text):
    with open(os.path.join(ROOT, path), "w", encoding="utf-8", newline="\n") as f:
        f.write(text)


def context_done(s):
    """The row of one finished search; saves a match, keeps a closer variant."""
    row = {"step": "context", "addr": s.key, "draft": s.draft, "sha": s.sha,
           "distance": s.base[0] if s.base else s.was, "callees": len(s.callees), "judged": s.judged, "matched": None}
    if s.best is None:
        return dict(row, error="no variant compiled")
    (differing, _), chosen, profile = s.best
    kept = variant_path(s.key, "context", ".cpp")
    if s.best[0] == tu_context.MATCH:
        def matches(subset):
            write(kept, s.render(subset, profile))
            row["judged"] += 1
            return judge(s.addr, kept)["status"] == "match"
        # match.py check has the last word, here and again in save(): never save on the batch's verdict
        if not matches(chosen):
            return dict(row, error="the batch judged MATCH, match.py check did not")
        chosen = tu_context.minimise(chosen, matches)
        write(kept, s.render(chosen, profile))
        row["throws"], row["profile"] = sorted(f"{c:08X}" for c in chosen), profile or "default"
        row["matched"] = (f"throw() on {', '.join(row['throws'])}" if chosen else "as is") + \
            (f", {profile or 'default'}" if profile != s.own else "")
        row["saved"] = save(s.addr, kept)
    elif differing < row["distance"]:
        write(kept, s.render(chosen, profile))
        row.update(best_distance=differing, best_draft=kept, best_sha=digest(os.path.join(ROOT, kept)),
                   throws=sorted(f"{c:08X}" for c in chosen), profile=profile or "default")
    return row


def report(row, counts):
    """Record one row of a judging step, log what happened, count it."""
    record(row)
    counts["worked"] += 1
    if row["matched"]:
        counts["matched"] += 1
        log(f"{row['addr']}: MATCH ({row['matched']}, was {row['distance']} off): {row.get('saved', '')}")
    elif "best_distance" in row:
        counts["closer"] += 1
        log(f"{row['addr']}: {row['distance']} -> {row['best_distance']} off, kept {row['best_draft']}")
    elif "error" in row:
        log(f"{row['addr']}: {row['error']}")


def cmd_context(a):
    todo = work(a, "context")
    log(f"context: {len(todo)} drafts within {a.max_distance} instructions, {a.jobs} jobs")
    counts, searches, started, calls = collections.Counter(), {}, time.time(), 0
    for key, distance, path in todo:
        full = os.path.join(ROOT, path)
        s = tu_context.Search(int(key, 16), open(full, encoding="utf-8", errors="replace").read()) \
            if path.endswith(".cpp") else None
        if s is None or not s.callees:
            counts["no callee prototype" if s else "C"] += 1
            record({"step": "context", "addr": key, "draft": path, "sha": digest(full), "distance": distance,
                    "callees": 0, "judged": 0, "matched": None})
            continue
        s.key, s.draft, s.sha, s.was = key, path, digest(full), distance
        searches[key] = s
    log(f"context: {len(searches)} drafts with callee prototypes ({counts['C']} C drafts and "
        f"{counts['no callee prototype']} without one skipped)")
    rounds = 0
    while searches:
        pairs, meta = [], {}
        for key, s in list(searches.items()):
            frontier = [] if project.source_for(s.addr) else s.frontier()  # matched by a worker meanwhile
            if not frontier:
                if s.judged:
                    row = context_done(s)
                    calls += row["judged"]
                    report(row, counts)
                del searches[key]
            for k, (chosen, profile) in enumerate(frontier):
                path = variant_path(key, f"context_{k}", ".cpp")
                write(path, s.render(chosen, profile))
                pairs.append((s.addr, path))
                meta[path] = (key, chosen, profile)
        if not pairs:
            break
        log(f"round {rounds}: {len(pairs)} variants of {len(searches)} drafts")
        results = collections.defaultdict(list)
        for path, sc in judge_batch(pairs, a.jobs):
            key, chosen, profile = meta[path]
            results[key].append((chosen, profile, sc))
            os.remove(os.path.join(ROOT, path))
        for key, s in searches.items():
            s.feed(results[key])
        rounds += 1
    seconds = time.time() - started
    log(f"context done: {counts['worked']} drafts searched, {counts['matched']} matched, {counts['closer']} closer; "
        f"{calls} judge calls ({calls / max(1, counts['worked']):.1f} a draft), {seconds:.0f}s "
        f"({seconds / max(1, counts['worked']):.1f}s a draft at {a.jobs} jobs)")


def changed_lines(old, new):
    """The lines a variant changed, as a short diff for the row."""
    return [l for l in difflib.unified_diff(old.split("\n"), new.split("\n"), lineterm="", n=0)
            if l[:1] in "+-" and l[:3] not in ("+++", "---")][:12]


def rewrite_done(key, distance, draft, sha, variants, scores):
    """The row of one draft whose variants are all judged (variants[0] is the draft itself);
    saves a match, keeps the closest variant if it is closer, removes the other files."""
    addr, ext = int(key, 16), os.path.splitext(draft)[1]
    base = scores[variants[0]]
    row = {"step": "rewrite", "addr": key, "draft": draft, "sha": sha, "distance": base[0] if base else distance,
           "variants": len(variants) - 1, "matched": None}
    judged = [(scores[p], p) for p in variants[1:] if scores[p] is not None]
    best, path = min(judged) if judged else (None, None)
    kept = variant_path(key, "rewrite", ext)
    text = lambda p: open(os.path.join(ROOT, p), encoding="utf-8", errors="replace").read()
    if base == tu_context.MATCH:
        row["matched"], row["saved"] = "as is", save(addr, draft)
    elif best is not None and (best == tu_context.MATCH or best[0] < row["distance"]):
        row["change"] = changed_lines(text(draft), text(path))
        os.replace(os.path.join(ROOT, path), os.path.join(ROOT, kept))  # the draft itself may be an earlier rewrite.*
        if best == tu_context.MATCH:
            row["matched"], row["saved"] = "rewrite", save(addr, kept)
        else:
            row["best_distance"], row["best_draft"] = best[0], kept
    for p in variants:
        if os.path.exists(os.path.join(ROOT, p)):
            os.remove(os.path.join(ROOT, p))
    return row


def cmd_rewrite(a):
    todo = work(a, "rewrite")
    log(f"rewrite: {len(todo)} drafts within {a.max_distance} instructions, up to {a.variants} variants each, {a.jobs} jobs")
    counts, started = collections.Counter(), time.time()
    pairs, plan, owner = [], {}, {}
    for key, distance, draft in todo:
        text = open(os.path.join(ROOT, draft), encoding="utf-8", errors="replace").read()
        texts = [text] + regsearch.variants(text, random.Random(int(key, 16)), cap=a.variants)
        # The rules mined from real closing edits (tools/rewrite_rules.py); a variant its review()
        # flags as unnatural source (a `__typeof__`, a `do { } while (0)` wrapper) is not tried.
        mined = rewrite_rules.variants(text, cap=a.variants, seed=int(key, 16) & 0xFFFF, cplusplus=draft.endswith(".cpp"))
        texts += [t for _, _, t in mined if t not in texts and not rewrite_rules.review(t)]
        if len(texts) == 1:
            counts["no variant"] += 1
            record({"step": "rewrite", "addr": key, "draft": draft, "sha": digest(os.path.join(ROOT, draft)),
                    "distance": distance, "variants": 0, "matched": None})
            continue
        paths = [variant_path(key, f"rewrite_{k}", os.path.splitext(draft)[1]) for k in range(len(texts))]
        for p, t in zip(paths, texts):
            write(p, t)
            pairs.append((int(key, 16), p))
            owner[p] = key
        plan[key] = (distance, draft, digest(os.path.join(ROOT, draft)), paths)
    log(f"rewrite: {len(pairs) - len(plan)} variants of {len(plan)} drafts ({counts['no variant']} drafts gave none)")
    scores = collections.defaultdict(dict)
    for n, (path, sc) in enumerate(judge_batch(pairs, a.jobs), 1):
        key = owner[path]
        scores[key][path] = sc
        if len(scores[key]) == len(plan[key][3]):
            report(rewrite_done(key, *plan[key], scores.pop(key)), counts)
        if n % 500 == 0:
            log(f"progress: {n} of {len(pairs)} judged, {counts['matched']} matched, {counts['closer']} closer")
    seconds = time.time() - started
    log(f"rewrite done: {counts['worked']} drafts, {counts['matched']} matched, {counts['closer']} closer; "
        f"{len(pairs)} judge calls, {seconds:.0f}s ({seconds / max(1, counts['worked']):.1f}s a draft at {a.jobs} jobs)")


def cmd_status(a):
    r = rows()
    sweeps = [x for x in r if x["step"] == "sweep"]
    perms = [x for x in r if x["step"] == "permute"]
    print(f"sweep: {len(sweeps)} drafts, {sum(1 for x in sweeps if x['matched'])} matched "
          f"({collections.Counter(x['matched'] for x in sweeps if x['matched']).most_common()})")
    for step in ("context", "rewrite"):
        mine = [x for x in r if x["step"] == step]
        print(f"{step}: {len(mine)} drafts, {sum(1 for x in mine if x['matched'])} matched, "
              f"{sum(1 for x in mine if 'best_distance' in x)} closer")
    print(f"permute: {len(perms)} drafts, {collections.Counter(x['result'] for x in perms).most_common()}")
    left = closest()
    for n in (1, 2, 5, 10, 20):
        print(f"  still open within {n:2d} instructions: {sum(1 for d, _ in left.values() if d <= n)}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("sweep")
    p.add_argument("-j", "--jobs", type=int, default=4)
    p.add_argument("--max-distance", type=int, default=20)
    p = sub.add_parser("permute")
    p.add_argument("--seconds", type=int, default=300)
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--max-distance", type=int, default=5)
    p.add_argument("--limit", type=int, default=10000)
    for name in ("context", "rewrite"):
        p = sub.add_parser(name)
        p.add_argument("-j", "--jobs", type=int, default=4)
        p.add_argument("--max-distance", type=int, default=20)
        p.add_argument("--only", help="comma-separated addresses: work these functions only")
    p.add_argument("--variants", type=int, default=30)
    sub.add_parser("status")
    a = ap.parse_args()
    {"sweep": cmd_sweep, "context": cmd_context, "rewrite": cmd_rewrite, "permute": cmd_permute,
     "status": cmd_status}[a.cmd](a)


if __name__ == "__main__":
    main()
