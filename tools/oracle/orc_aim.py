"""oracle.py aim / sched: what the oracle's report is worth as a direction.

aim    For every draft the measurement certified as one or two decisions away from the original
       (allocation alone, or allocation, scheduler and delay slots together), apply the rewrites
       of orc_rewrite.py and the mined rules of tools/rewrite_rules.py that answer those passes
       at the sites the report names (the variable and line of the misplaced value and of its
       rival, the lines of the insns to issue in the other order, of a branch and its slot) and
       judge them; apply the same two tables at sites drawn blindly, the same number of
       variants, and judge those. A variant rewrite_rules.review() flags is not judged, and a
       matching source it flags is held back. A MATCH on plain compiler
       output is saved through finish_near.save() (swarm.py try judges it again). With --rounds
       N, a draft that did not match goes on from its best variant by decision distance.
climb  The search that came after `aim` (orc_climb.py, registered here): every variant is scored
       by which named decisions its plain compile takes the original's way and by the decision
       units it leaves, the best are certified and the search goes on from them.
sched  For drafts whose residual is a pure permutation of the original's instructions (as they
       are, or once the registers are forced): steer the scheduler's pick toward the original's
       order at every pick (orc_pass.steer), then search the delay-slot decisions for what is
       left (orc_pass.slot_search), and count how many reproduce. Certificates only.
"""
import collections
import glob
import json
import multiprocessing
import os
import shutil
import sys
import time

import orc_climb
import orc_core as C
import orc_pass as P
import orc_rewrite as W
import orc_rtl as R
import match
import project
import rewrite_rules as RR      # the rules mined from closing edits (tools/rewrite_rules.py)

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "oracle")


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def load_rows():
    rows = []
    for p in sorted(glob.glob(os.path.join(OUT, "????????_????????????????.json"))):
        try:
            rows.append(json.load(open(p)))
        except ValueError:
            pass
    return rows


def total(row):
    """Decisions that separate a certified draft from the original: allocation alone, or the
    passes together (oracle.py report). None when no forced compile gives the original."""
    if row.get("certified") and row.get("distance") is not None:
        return row["distance"]
    c = row.get("combined") or {}
    return c.get("total") if c.get("certified") else None


def decisions(row):
    """The allocation decisions of a report, whichever certificate holds them."""
    alloc = ((row.get("passes") or {}).get("allocation") or {}).get("causal") or {}
    return (row.get("causal") or {}).get("decisions", []) + alloc.get("decisions", [])


def rule_classes(row):
    """The classes of difference (the words of rewrite_rules.RULES[..]["answers"]) that the
    passes of the certificate stand for."""
    n = (row.get("combined") or {}).get("decisions") or {}
    out = [k for k, on in (("registers", n.get("allocation") or row.get("certified")), ("order", n.get("sched")),
                           ("branch-form", n.get("reorg")), ("order", n.get("reorg"))) if on]
    return list(dict.fromkeys(out)) or ["registers"]


def sites(row):
    """The source sites a report points to: variables and lines of each misplaced value and of
    the rivals it lost to or should have followed; the lines of the insns the scheduler must
    issue in the other order; the lines of a branch and of what its delay slot must hold."""
    names, lines, calls = set(), set(), set()
    for d in decisions(row):
        if {d.get("got"), d.get("want")} & {"$v0", "$v1"}:
            # $v0 is the first register in the order and the one a call's result arrives in: a
            # callee declared void leaves it free after the call, one that returns a value does
            # not. The calls shortly before the misplaced value decide (codegen map, class 1).
            for e in [d] + d.get("rivals", []):
                if e.get("line"):
                    calls.update(range(e["line"] - 8, e["line"] + 3))
        for e in [d] + d.get("rivals", []) + ([d["tied_to"]] if d.get("tied_to") else []):
            if e.get("var"):
                names.add(e["var"])
            if e.get("line"):
                lines.add(e["line"])
            if e.get("declared") and e.get("kind") != "param":
                lines.add(e["declared"])
    for sw in row.get("reload", {}).get("swaps", []):
        if sw.get("line"):
            lines.add(sw["line"])
    passes = row.get("passes") or {}
    for pick in (passes.get("sched") or {}).get("picks", []):
        here = [x for x in (pick.get("line"), pick.get("picked_line")) if x]
        lines.update(here)
        # the dependences on $v0 and on the argument registers come from the calls around: a
        # callee's return type moves priorities and dependents alike (00113320, 00493918)
        for x in here:
            calls.update(range(x - 8, x + 3))
    for e in (passes.get("reorg") or {}).get("decisions", []):
        lines.update(x for x in (e.get("line"), e.get("candidate_line")) if x)
    return {"vars": names, "lines": lines, "call_lines": calls | lines, "v0": bool(calls)}


def flagged(new, text):
    """Does the rewrite bring in a spelling a person would have to tidy (rewrite_rules.review)?
    Such a variant is neither judged nor saved."""
    return bool(set(RR.review(new)) - set(RR.review(text)))


def mix(first, second, cap):
    """Two variant lists taking turns, at most `cap` in all, one text once."""
    out, seen, queues = [], set(), [list(first), list(second)]
    while any(queues) and (cap is None or len(out) < cap):
        for q in queues:
            if q and (cap is None or len(out) < cap):
                v = q.pop(0)
                if v[2] not in seen:
                    seen.add(v[2])
                    out.append(v)
    return out


def write_variants(row, a, rnd, text=None, base=None):
    """Variant files of one draft: {path: (set of 'aimed'/'blind', kind, site)}."""
    src = os.path.join(ROOT, row["draft"]) if base is None else base
    text = text if text is not None else open(src, encoding="utf-8", errors="replace").read()
    ext = os.path.splitext(src)[1]
    cpp = ext == ".cpp"
    aim, seed = sites(row), int(row["addr"], 16) + rnd
    mined = lambda **kw: [("mined " + k, site, new) for k, site, new in RR.variants(text, cplusplus=cpp, **kw)] \
        if not a.no_mined else []
    clean = lambda vs: [v for v in vs if not flagged(v[2], text)]
    # aimed: both tables at the sites the report names, the mined rules that answer its passes
    aimed = clean(W.variants(text, aim=aim, cap=a.cap, cplusplus=cpp)) \
        + clean(mined(aim=aim, cap=a.cap, rules=RR.rules_for(*rule_classes(row))))
    blind_all = clean(W.variants(text, None, cplusplus=cpp)) + clean(mined())
    budget = max(len(aimed), 1) if a.blind == 0 else a.blind
    # blind: as many variants, from the same two tables taking turns, at sites drawn blindly
    blind = mix(clean(W.variants(text, None, cap=budget, seed=seed, cplusplus=cpp)), clean(mined(cap=budget, seed=seed)), budget)
    d = os.path.join(OUT, "aim", f"{row['addr']}_{row['sha']}", f"r{rnd}")
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(d)
    files, by_text = {}, {}
    sets = [("aimed", aimed), ("blind", blind)] + ([("all", blind_all)] if a.all else [])
    for label, vs in sets:
        for kind, site, new in vs:
            if new not in by_text:
                path = os.path.join(d, f"v{len(by_text)}{ext}")
                with open(path, "w", encoding="utf-8", newline="\n") as f:
                    f.write(new)
                by_text[new] = path
                files[path] = [set(), kind, site]
            files[by_text[new]][0].add(label)
    return files, {"aimed": len(aimed), "blind": len(blind), "all": len(blind_all)}


def _distance(item):
    addr, path = item
    try:
        with C.Session(addr, path) as s:
            row = s.report_all(os.path.relpath(path, ROOT))
            if row["kind"] in ("other", "allocation+other"):
                P.compose(s, row)       # the decisions may sit in the scheduler or in the delay slots
        return path, row
    except Exception as e:
        return path, {"kind": "error", "error": str(e)[:200]}


def cmd_aim(a):
    import finish_near
    done = set(project.sources())
    rows = [r for r in load_rows() if int(r["addr"], 16) not in done and os.path.exists(os.path.join(ROOT, r["draft"]))
            and C.digest(os.path.join(ROOT, r["draft"])) == r.get("sha")]       # a report of the file as it is now
    if a.only:
        only = {f"{int(x, 16):08x}" for x in a.only.split(",")}
        rows = [r for r in rows if r["addr"] in only]
    as_is = [r for r in rows if r["kind"] == "match"]
    work = [r for r in rows if r["kind"] != "match" and total(r) is not None and total(r) <= a.max_distance
            and (total(r) >= 1 or r.get("operand_swaps"))]
    if a.allocation_only:
        work = [r for r in work if r.get("certified")]
    log(f"aim: {len(work)} drafts of {len({r['addr'] for r in work})} functions are 1 to {a.max_distance} decisions away "
        f"({sum(1 for r in work if r.get('certified'))} by allocation alone); {len(as_is)} match as they are")
    result = {"drafts": len(work), "functions": len({r["addr"] for r in work}), "rounds": [], "saved": {}, "per_draft": {}}
    matched = collections.defaultdict(dict)      # label -> {addr: path}
    rules = collections.defaultdict(collections.Counter)    # label -> {rule of the first matching variant: drafts}
    for r in as_is:
        matched["as is"].setdefault(r["addr"], os.path.join(ROOT, r["draft"]))
    state = {(r["addr"], r["sha"]): (r, None, None) for r in work}      # row, text, base path
    for rnd in range(a.rounds):
        plan, counts = {}, collections.Counter()
        for key, (row, text, base) in state.items():
            files, n = write_variants(row, a, rnd, text, base)
            plan[key] = files
            for k, v in n.items():
                counts[k] += v
        pairs = [(int(key[0], 16), path) for key, files in plan.items() for path in files]
        log(f"round {rnd}: {len(state)} drafts, {counts['aimed']} aimed variants, {counts['blind']} blind"
            + (f", {counts['all']} at every site" if a.all else "") + f"; {len(pairs)} to judge")
        verdict = {}
        for n, (addr, src, ok, report) in enumerate(match.judge_many(pairs, jobs=a.jobs, chunk=150), 1):
            verdict[src] = (ok, C.differ(report))
            if n % 500 == 0:
                log(f"  judged {n} of {len(pairs)}")
        tally = collections.Counter()
        next_state = {}
        for key, files in plan.items():
            row = state[key][0]
            per = result["per_draft"].setdefault(f"{key[0]}_{key[1]}", {"addr": key[0], "draft": row["draft"],
                                                                        "distance": total(row), "rounds": [],
                                                                        "passes": (row.get("combined") or {}).get("passes")})
            entry = {"n": {}, "match": {}, "closer": {}}
            for label in ("aimed", "blind", "all"):
                mine = [(p, v) for p, v in files.items() if label in v[0]]
                if not mine and label == "all":
                    continue
                hits = [(p, v) for p, v in mine if verdict.get(p, (False, None))[0]]
                entry["n"][label] = len(mine)
                tally[label + " judged"] += len(mine)
                if hits:
                    entry["match"][label] = [f"{v[1]}: {v[2]}" for _, v in hits][:5]
                    tally[label + " drafts matched"] += 1
                    matched[label].setdefault(key[0], hits[0][0])
                    rules[label][hits[0][1][1]] += 1
                ds = [verdict[p][1] for p, _ in mine if verdict.get(p, (0, None))[1] is not None]
                if ds and row.get("differ") is not None and min(ds) < row["differ"]:
                    entry["closer"][label] = min(ds)
            per["rounds"].append(entry)
            if not any(verdict.get(p, (False,))[0] for p in files):
                next_state[key] = files
        result["rounds"].append(dict(tally))
        log(f"round {rnd}: " + ", ".join(f"{k} {v}" for k, v in sorted(tally.items())))
        if rnd + 1 >= a.rounds or not next_state:
            break
        # climb: the aimed variants of each open draft, ranked by decision distance (the judge's
        # count cascades with one register); the closest one that is still certified goes on
        cands = []
        for key, files in next_state.items():
            aimed = [p for p, v in files.items() if "aimed" in v[0] and verdict.get(p, (0, None))[1] is not None]
            aimed.sort(key=lambda p: verdict[p][1])
            cands += [(int(key[0], 16), p) for p in aimed[:a.climb]]
        log(f"climb: decision distance of {len(cands)} aimed variants of {len(next_state)} open drafts")
        with multiprocessing.Pool(a.jobs) as pool:
            reports = dict(pool.imap_unordered(_distance, cands))
        state = {}
        for key, files in next_state.items():
            old = result["per_draft"][f"{key[0]}_{key[1]}"]
            best = None
            for p in files:
                r = reports.get(p)
                if r and total(r) is not None and (total(r) >= 1 or r.get("operand_swaps")):
                    rank = (total(r), r.get("pseudos_moved", 99), r.get("differ", 999))
                    if best is None or rank < best[0]:
                        best = (rank, p, r)
            if best and best[0][0] <= old["distance"]:
                r = dict(best[2], addr=key[0], sha=key[1])
                state[key] = (r, open(best[1], encoding="utf-8").read(), best[1])
                old.setdefault("climbed", []).append({"to": os.path.relpath(best[1], ROOT), "distance": best[0][0]})
        if not state:
            break
    # save: what the judge matched on plain compiler output, one source per function
    for label in ("as is", "aimed", "blind", "all"):
        for addr, path in sorted(matched[label].items()):
            if addr in result["saved"]:
                continue
            reasons = RR.review(open(path, encoding="utf-8", errors="replace").read())
            if reasons:     # it matches, but a person has to tidy it first: kept under build/oracle/aim, not saved
                result.setdefault("held", {})[addr] = {"by": label, "variant": os.path.relpath(path, ROOT), "review": reasons}
                log(f"{addr}: MATCH by {label} ({os.path.relpath(path, ROOT)}) held back: {'; '.join(reasons)}")
                continue
            msg = finish_near.save(int(addr, 16), os.path.relpath(path, ROOT)) if not a.dry else "dry run: not saved"
            result["saved"][addr] = {"by": label, "variant": os.path.relpath(path, ROOT), "save": msg}
            log(f"{addr}: MATCH by {label} ({os.path.relpath(path, ROOT)}): {msg}")
    result["matched"] = {label: sorted(v) for label, v in matched.items()}
    result["rules"] = {label: dict(c) for label, c in rules.items()}
    json.dump(result, open(os.path.join(OUT, "aim.json"), "w"), indent=1)
    print(f"drafts 1 to {a.max_distance} decisions away: {result['drafts']} ({result['functions']} functions)")
    for label in ("as is", "aimed", "blind", "all"):
        if label in matched or label in ("aimed", "blind"):
            judged = sum(r.get(label + " judged", 0) for r in result["rounds"])
            print(f"  {label:6}: {len(matched[label]):3} functions matched" + (f" with {judged} judge calls" if judged else "")
                  + (": " + " ".join(sorted(matched[label])) if matched[label] else ""))
    for label in ("aimed", "blind", "all"):
        if rules.get(label):
            print(f"  {label} by rule: " + ", ".join(f"{k} {v}" for k, v in rules[label].most_common()))
    if result.get("held"):
        print("  held back (match, but the source needs tidying): " + " ".join(sorted(result["held"])))
    print("written: build/oracle/aim.json")


# ---------------------------------------------------------------- scheduler

def target_order(s, lst, slots=False):
    """{insn uid: position in the original} when my instructions are a permutation of the
    original's (branch form aside), else None (orc_pass.order_map)."""
    order, exact = P.order_map(s, lst, slots)
    return order if exact else None


def sched_one(item):
    addr, src, force = item
    out = {"addr": f"{addr:08x}", "draft": os.path.relpath(src, ROOT), "result": "not a permutation"}
    try:
        with C.Session(addr, src) as s:
            s.natural()
            force = {int(p): h for p, h in force.items()}
            base = s.forced("p", force, trace="none", sched={"trace": True})
            if base[0]:
                out["result"] = "already equal"
                return out
            if not P.order_map(s, base[2])[1]:
                return out
            st = P.steer(s, force, tag="q", base=base)
            out.update({k: st[k] for k in ("steps", "tries", "passes", "slots", "stall", "stalls", "picks_changed", "picks", "best")
                        if k in st})
            out["differ"] = C.differ(base[1])
            out["result"] = st["result"]
            out["registers_forced"] = len(force)
            if st["result"] != "reproduced":
                # what the scheduler cannot give may be a delay-slot decision
                ss = P.slot_search(s, force, st["cfg"], tag="e")
                if ss["cfg"]:
                    out["reorg"] = {"overrides": [list(c) for c in P.overrides(ss["cfg"])], "differ": ss["best"], "tried": ss["tried"]}
                    if ss["result"] == "reproduced":
                        out["result"] = "reproduced with delay slots"
                    elif ss["best"] < st["best"]:
                        out["result"], out["best"] = "closer", ss["best"]
    except Exception as e:
        out["result"] = "error"
        out["error"] = f"{type(e).__name__}: {e}"[:200]
    return out


def cmd_sched(a):
    done = set(project.sources())
    todo = []
    for r in load_rows():
        if int(r["addr"], 16) in done or not os.path.exists(os.path.join(ROOT, r["draft"])):
            continue
        fp = r.get("reload", {})
        if r.get("natural_class") == "order":
            todo.append((int(r["addr"], 16), os.path.join(ROOT, r["draft"]), {}))
        elif r.get("kind") == "allocation+other" and r.get("residual_class") == "order":
            todo.append((int(r["addr"], 16), os.path.join(ROOT, r["draft"]), {p: v[1] for p, v in fp.get("force", {}).items()}))
    if a.only:
        only = {int(x, 16) for x in a.only.split(",")}
        todo = [t for t in todo if t[0] in only]
    log(f"sched: {len(todo)} drafts whose residual is a pure permutation "
        f"({sum(1 for t in todo if t[2])} of them once registers are forced)")
    rows = []
    with multiprocessing.Pool(a.jobs) as pool:
        for n, row in enumerate(pool.imap_unordered(sched_one, todo), 1):
            rows.append(row)
            if row["result"].startswith("reproduced"):
                log(f"{row['addr']}: reproduced by steering pass {row.get('passes')}: {row.get('picks_changed', 0)} pick(s) changed"
                    + (f", {row['stalls']} cycle(s) ended early" if row.get("stalls") else "")
                    + (f", {len(row['reorg']['overrides'])} delay-slot decision(s)" if row.get("reorg") else "")
                    + (f", {row['registers_forced']} register(s) forced" if row["registers_forced"] else "") + "  [certificate]")
    c = collections.Counter(r["result"] for r in rows)
    json.dump({"drafts": len(rows), "results": dict(c), "rows": sorted(rows, key=lambda r: r["addr"])},
              open(os.path.join(OUT, "sched.json"), "w"), indent=1)
    print(f"{len(rows)} permutation drafts: " + ", ".join(f"{k} {v}" for k, v in c.most_common()))
    hist = collections.Counter(min(r.get("picks_changed", 0), 6) for r in rows if r["result"].startswith("reproduced"))
    if hist:
        print("picks changed in the reproduced ones: " + ", ".join(f"{k if k < 6 else '6+'}: {v}" for k, v in sorted(hist.items())))
    print("written: build/oracle/sched.json")


def add_parsers(sub):
    p = sub.add_parser("aim")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--max-distance", type=int, default=2)
    p.add_argument("--cap", type=int, default=40, help="aimed variants per draft at most")
    p.add_argument("--blind", type=int, default=0, help="blind variants per draft (0: as many as the aimed ones)")
    p.add_argument("--all", action="store_true", help="also judge the rewrites at every site (the ceiling)")
    p.add_argument("--rounds", type=int, default=1)
    p.add_argument("--climb", type=int, default=6, help="aimed variants per open draft whose decision distance is measured")
    p.add_argument("--only")
    p.add_argument("--dry", action="store_true", help="judge and count, save nothing")
    p.add_argument("--no-mined", action="store_true", help="leave out the rules of tools/rewrite_rules.py")
    p.add_argument("--allocation-only", action="store_true", help="only the drafts certified by allocation alone")
    p = sub.add_parser("sched")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--only")
    orc_climb.add_parsers(sub)      # climb, movers: the search scored by the named decisions


COMMANDS = {"aim": cmd_aim, "sched": cmd_sched}
COMMANDS.update(orc_climb.COMMANDS)
