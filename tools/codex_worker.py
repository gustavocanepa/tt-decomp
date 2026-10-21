#!/usr/bin/env python3
"""A matcher worker run by Codex with no lead: lease a batch, hand it to `codex exec`, check what
it really matched, release, repeat.

    codex_worker.py W --tier T [--certified] [--whole] [--batches 2] [--count N] [--minutes 45]
                      [--model gpt-6-luna] [--effort low]

The worker's rules are AGENTS.md ("Matcher worker"), which Codex reads by itself; the per-function
guidance is `swarm.py prompt` (predicted unit context, retry report). To steer a worker, edit
AGENTS.md or the queue: the next batch picks it up. Codex runs with its sandbox and approvals off
(it has to run the compilers and write build/swarm/W and, through `swarm.py try`, src/).

Per batch, in build/codex/W/: batch_K.prompt, batch_K.log (Codex's output), batch_K.json (its
report). One line per batch goes to build/codex/W/summary.log and to stdout; the matches counted
there are the leased addresses that have a source afterwards, not what the report claims. Lessons
are appended to build/codex/lessons.txt for the lead to file. `touch build/codex/STOP` stops every
worker after its current batch.
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time

import project

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "codex")
SCHEMA = os.path.join(ROOT, "tools", "codex_report.schema.json")


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def swarm(*args):
    res = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "swarm.py"), *args],
                         capture_output=True, text=True, cwd=ROOT)
    return res.returncode, res.stdout + res.stderr


def tries_of(tier):
    return project.CONFIG.get("swarm", {}).get("tiers", {}).get(tier, {}).get("tries") or 8


def later_tier(tier):
    """True when another tier picks up this tier's give-ups."""
    tiers = project.CONFIG.get("swarm", {}).get("tiers", {})
    return any(tier in (t.get("retries") or []) for t in tiers.values())


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("worker")
    ap.add_argument("--tier", required=True)
    ap.add_argument("--certified", action="store_true")
    ap.add_argument("--whole", action="store_true", help="no early give-up (implied for the last tier)")
    ap.add_argument("--batches", type=int, default=2)
    ap.add_argument("--count", type=int)
    ap.add_argument("--minutes", type=int, default=45, help="time limit of one batch")
    ap.add_argument("--model", default="gpt-6-luna")
    ap.add_argument("--effort", default="low")
    a = ap.parse_args()
    w, out = a.worker, os.path.join(OUT, a.worker)
    os.makedirs(out, exist_ok=True)
    stop = os.path.join(OUT, "STOP")
    matched = given = 0
    move = False
    done = [int(m.group(1)) for m in (re.match(r"batch_(\d+)\.prompt$", n) for n in os.listdir(out)) if m]
    first = max(done, default=0) + 1    # never overwrite an earlier run's reports
    for k in range(first, first + a.batches):
        if os.path.exists(stop):
            log(f"{w}: stop file present")
            break
        opts = ["--tier", a.tier] + (["--certified"] if a.certified else []) \
            + (["--count", str(a.count)] if a.count else []) + (["--new-area"] if move else [])
        code, text = swarm("assign", w, *opts)
        lease = json.loads(text) if code == 0 and text.strip().startswith("{") else {"functions": []}
        addrs = [f["addr"] for f in lease.get("functions", [])]
        if not addrs:
            log(f"{w}: nothing to lease ({text.strip()[:120]})")
            break
        kind = ("Each function has a kept draft a tool certified or found within a few instructions: start "
                "from the draft its Retry report names and change only what the report says is left. "
                if a.certified else "")
        last = "Whole budget. " if a.whole or not later_tier(a.tier) else ""
        prompt = (f"Matcher worker {w}. Follow \"Matcher worker\" in AGENTS.md. Budget: {tries_of(a.tier)} tries per "
                  f"function. {last}{kind}Your batch:\n{json.dumps(lease)}\n")
        base = os.path.join(out, f"batch_{k}")
        open(base + ".prompt", "w").write(prompt)
        started = time.time()
        with open(base + ".log", "w") as logf:
            try:
                res = subprocess.run(
                    ["codex", "exec", "-C", ROOT, "--dangerously-bypass-approvals-and-sandbox", "-m", a.model,
                     "-c", f'model_reasoning_effort="{a.effort}"', "--output-schema", SCHEMA,
                     "-o", base + ".json", prompt],
                    stdout=logf, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, cwd=ROOT,
                    timeout=a.minutes * 60)
                status = f"exit {res.returncode}"
            except subprocess.TimeoutExpired:
                status = f"time limit ({a.minutes} min)"
        seconds = round(time.time() - started)
        swarm("release", w)
        sources = project.sources(refresh=True)
        got = [x for x in addrs if int(x, 16) in sources]
        report, lessons = {}, []
        try:
            report = json.load(open(base + ".json"))
            lessons = [l for l in report.get("lessons", []) if l.strip()]
        except (OSError, ValueError):
            status += ", no readable report"
        claimed = sum(1 for f in report.get("functions", []) if f.get("result") == "match")
        used = re.findall(r"tokens used[^\d]*([\d,]+)", open(base + ".log", errors="replace").read())
        if lessons:
            with open(os.path.join(OUT, "lessons.txt"), "a") as f:
                f.write("".join(f"- {l.strip()}  ({w}, batch {k})\n" for l in lessons))
        matched += len(got)
        given += len(addrs)
        move = not got
        line = (f"{w} batch {k}: {len(got)} matched of {len(addrs)} in {lease.get('area')} "
                f"({seconds}s, {status}, report claims {claimed}"
                + (f", tokens {used[-1]}" if used else "") + f"); total {matched} of {given}")
        with open(os.path.join(out, "summary.log"), "a") as f:
            f.write(time.strftime("%Y-%m-%d %H:%M:%S ") + line + "\n")
        log(line)
    log(f"{w}: done, {matched} matched of {given}")


if __name__ == "__main__":
    main()
