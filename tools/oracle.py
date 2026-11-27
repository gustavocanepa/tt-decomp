#!/usr/bin/env python3
"""Decision oracle: ask Sony's own compiler which decisions separate a draft from the original.

The compilers Sony shipped are not stripped. gdb can stop `cc1plus` where it decides something,
read the inputs of the decision, and make it decide otherwise (tools/oracle/orc_gdb.py, by symbol
name only). This tool does that for register allocation, for the scheduler's picks and for the
delay-slot pass, composes the three in the compiler's order, and reads what the passes before
them did from the dumps.

    oracle.py trace  ADDR DRAFT        the allocation decisions as data: local-alloc quantities in
                                       the order they were placed (priority, range, suggestions,
                                       register, what held the registers before it), then global's
                                       order with each find_reg result
    oracle.py slots  ADDR DRAFT [--search]
                                       the delay-slot pass as data: every instruction with a slot,
                                       what fills it, which phase of reorg put it there and from
                                       which thread, annulled or not, the original's slot beside it;
                                       every thread tried with what the liveness scan found live at
                                       the other side and the calls it stopped at; the candidates
                                       refused and why. --search: the delay-slot decisions that
                                       give the original's slots
    oracle.py early  ADDR DRAFT [--ledger N]
                                       the passes before allocation, from the dumps: per pass the
                                       insns deleted, made and rewritten; for an instruction only
                                       one side has, the pass and source line it comes from
    oracle.py force  ADDR DRAFT [--set PSEUDO=REG,...] [--at reload|alloc] [--steer]
                     [--slot live:INSN:+REG,take:BRANCH:INSN,reject:BRANCH:INSN,predict:BRANCH:V,nothrow:CALL|all]
                                       replay with decisions overridden. Without options: vote the
                                       original's register for each pseudo from the differing
                                       instructions, check that no two live values collide, force,
                                       compile, compare, vote again, to a fixed point. --steer moves
                                       the scheduler toward the original's order; --slot overrides
                                       delay-slot decisions
    oracle.py report ADDR DRAFT        the smallest set of allocation decisions that turns the
                                       draft's output into the original, each with the inputs that
                                       decided it, the rival it lost to or beat, and the variable
                                       and source line it belongs to; when allocation alone does
                                       not give the original, allocation, scheduler and delay slots
                                       forced together, as one decision list or as what is left
    oracle.py measure [-j3] [--only ADDR,..] [--fresh] [--limit N] [--compiler NAME]
                                       report on every kept near-miss draft of an unmatched
                                       function; prints the distribution of decision distance and
                                       the classification across passes. --compiler: the kept
                                       drafts that ask for that profile (the SDK's ee-gcc2.9-991111)
    oracle.py aim [-j3] [--max-distance 2] [--blind N] [--no-mined] [--allocation-only] [--dry]
                                       source rewrites aimed by the report, judged: the table of
                                       tools/oracle/orc_rewrite.py and the rules mined from closing
                                       edits (tools/rewrite_rules.py, those that answer the passes
                                       of the certificate), on every draft certified within that
                                       many decisions, by allocation alone or across passes; the
                                       same tables applied blindly for comparison. A variant that
                                       rewrite_rules.review() flags is not judged; a real MATCH is
                                       saved by finish_near.save() unless review() flags its source
                                       (then it is listed under `held` in aim.json).
    oracle.py sched [-j3]              the scheduler alone, then delay slots, for drafts whose
                                       residual is a pure permutation
    oracle.py status [--compiler NAME] the last measurement again

A forced compile is a CERTIFICATE that the draft's logic is the original's (nobody needs to touch
it again, only the shape that moves the named decisions); it is never a match. Only `aim` can save
anything, and only what the judge matches on unforced compiler output.

Files under build/oracle/ (fields are only ever added, never renamed):

  ADDR_SHA.json                 one draft's report (SHA: of the draft's text)
    addr, draft, sha, profile, function
    original, instructions      instruction counts of the original and of the draft's compile
    differ, natural_class       the judge's count and the class of the difference as compiled
    kind                        match | allocation | allocation+operand order | allocation+other |
                                other | error. Says what ALLOCATION ALONE achieves.
    certified                   true: forcing registers alone gives the original
    distance                    allocation decisions (causal), null when not reduced
    pseudos_moved, operand_swaps
    reload                      the fixed point at reload: rounds, force {pseudo: [from, to]}, result,
                                differ_forced, score_forced, residual_class, swaps, unexplained
    causal                      result, decisions [...], force, untie, refused, note
    residual_class              class of what allocation leaves
    logic                       complete | open | unknown. complete: some forced compile (of
                                allocation alone or of the passes together) equals the original.
                                open: none does. That is not a verdict on the logic: `combined`
                                says what could not be aligned or reproduced
    aligned                     instructions that differ once the listings are aligned (the
                                judge's `differ` is row by row: one instruction more and every
                                later row differs)
    combined                    the passes together:
        certified               true: allocation + scheduler + delay slots forced give the original
        differ, aligned         the judge's count after all forcing, and the aligned count
        decisions               {allocation: n, sched: n, reorg: n}; total; passes [names involved]
        list                    the decisions as sentences
        residual_class, only_original, only_draft
                                when not certified: what is left, and the instructions one side has
                                and the other has not
        blocked                 when the same instructions cannot be put in the original's order:
                                the dependence that forbids it (and the loop note that makes it)
        reason                  why the passes were not forced (instructions without a counterpart)
    passes                      the detail behind `combined`:
        differ                  {start, "round N": score} (score = judge's count + bag distance)
        order                   the passes that made progress, in the order they did
        allocation              {pseudos, force {pseudo: [from, to]}, causal (as above, with the
                                other passes still forced: its decisions are the count)}
        sched                   {passes, slots, stall, picks_changed, stalls, picks [{step, ready,
                                picked, forced, line, picked_line, stall, rank {natural, wanted
                                (priority, dependents, luid, weight, after_last), decided_by,
                                text}, why, need}], permutation} or null
        sched_blocked           [{want, line, by [{insn, kind, line, barrier}]}]
        reorg                   {overrides [[kind, ...]], decisions [{decision, why, need, ...}],
                                tried} or null. Kinds: live (a register live or dead at a
                                target), nothrow (a call the liveness scan may pass), take (the
                                candidate the slot must hold), reject, predict
    only_original, only_draft   instructions (text) one side has and the other has not, whatever
                                the registers, the order or the branch form; unaccounted = their
                                number; unaccounted_forced = the same after all forcing
    early                       for 1 to 4 such instructions: extra [{instruction, uid, line,
                                made_by, history}], missing [{instruction, kind, line, candidates
                                [{pass, what, uid, line, rtl}]}], ledger {pass: counts}, text
    gdb_runs, error
  ADDR_SHA.trace.json / .force.json / .slots.json / .early.json   the commands of the same name
  summary.json                  the last full measurement: drafts, functions, by_draft, by_function
                                (allocation alone), certified_drafts, certified_functions,
                                matching_as_is, gdb_runs, seconds; and across passes:
                                passes_by_draft, passes_by_function ("class | sub-class": count),
                                logic_complete_*, not_certified_*, pass_involved_*, early {drafts,
                                accounted, instructions {where it comes from: count}}
  index.json                    one line per draft: addr, draft, sha, kind, distance, differ,
                                original, natural_class, residual_class, pseudos_moved, error,
                                logic, unaccounted, decisions, total, differ_combined
  summary_NAME.json, index_NAME.json     the same for `measure --compiler NAME`
  summary_partial.json, index_partial.json    for `measure --only` / `--limit`
  sched.json                    `sched`: drafts, results, rows
  aim.json                      `aim`: drafts, functions, rounds [tallies], per_draft {distance,
                                passes, rounds [{n, match, closer}], climbed}, matched {label:
                                [addr]}, rules {label: {rule: drafts}}, saved, held

Another Sony EE compiler: the hook addresses functions, globals and fields by name, and reads both
table layouts (2.96 `struct qty` / `struct allocno`, 2.9 parallel arrays) and both dump namings
(2.96 `t.19.lreg`, 2.9 `t.lreg`); the driver's command line is taken through a stub, so a source
whose first line names another `[compilers.NAME]` profile is traced with that compiler's own
cc1 / cc1plus. The scheduler is steered at every pick only where the issue loop takes the insns
it has just made ready (2.96); on 2.9 once per cycle. One gdb is kept per draft for all its
compiles (orc_core.SERVER): starting gdb costs more than the compile it watches.
"""
import argparse
import collections
import json
import multiprocessing
import os
import signal
import sys
import time

TOOLS = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(TOOLS, "oracle"))
sys.path.insert(0, TOOLS)

import orc_core as C  # noqa: E402
import orc_early as E  # noqa: E402
import orc_pass as P  # noqa: E402
import orc_rtl as R  # noqa: E402
import project  # noqa: E402

ROOT = project.ROOT
OUT = os.path.join(ROOT, "build", "oracle")
BUCKETS = ("0", "1", "2", "3-5", "more")


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, flush=True)


def rel(path):
    return os.path.relpath(os.path.abspath(path), ROOT)


def out_path(addr, src, suffix=".json"):
    os.makedirs(OUT, exist_ok=True)
    return os.path.join(OUT, f"{addr:08x}_{C.digest(src)}{suffix}")


def var(e):
    name = e.get("var")
    where = f"line {e['line']}" if e.get("line") else None
    if name:
        return f"`{name}`" + (f" ({e['kind']}, declared line {e['declared']})" if e.get("declared") else "")
    return "a temporary" + (f" first set on {where}" if where else "")


# ---------------------------------------------------------------- trace

def trace_tables(s, rec):
    """The hook's record as two tables of decisions, each with what held the earlier registers."""
    order = s.decisions(rec)
    ren = {int(p): h for p, h in rec.get("renumber", {}).items()}
    index = {p: i for i, (p, _, _) in enumerate(order)}
    local, glob = [], []
    for i, (p, phase, c) in enumerate(order):
        got = c.get("result", -1)
        st = s.stats.get(p, {})
        row = dict(s.name(p, rec), order=i, reg=R.regname(got), refs=st.get("refs"), live_length=st.get("length"),
                   calls_crossed=st.get("calls"))
        busy = set(c.get("live", [])) if phase == "local" else set(c.get("conflicts", []))
        before = []
        if got is not None and got >= 0:
            lo = 32 if got >= 32 else 2
            for h in range(lo, got):
                if h in busy:
                    holder = next((q for q in s.graph.get(p, ()) if q >= s.first and ren.get(q) == h
                                   and index.get(q, 10 ** 6) < i), None)
                    before.append({"reg": R.regname(h), "by": holder if holder is not None else "hard register or other block"})
        row["before"] = before
        if phase == "local":
            if c.get("pseudos", [p])[0] != p:
                continue
            row.update(block=c["block"], qty=c["qty"], tied=c["pseudos"], birth=c.get("birth"), death=c.get("death"),
                       born=c["born"], dead=c["dead"], n_refs=c.get("n_refs"),
                       priority=s.priority(c.get("n_refs"), (c.get("death") or 0) - (c.get("birth") or 0), c.get("size", 1)),
                       suggested=[R.regname(h) for h in c.get("copy_sugg", []) + c.get("sugg", [])],
                       by_suggestion=bool(c.get("just_try_suggested")))
            local.append(row)
        else:
            row.update(allocno=c["allocno"], n_refs=c.get("n_refs"), length=c.get("live_length"),
                       priority=s.priority(c.get("n_refs"), c.get("live_length"), c.get("size", 1)),
                       preferred=[R.regname(h) for h in c.get("copy_prefs", []) + c.get("prefs", [])],
                       retrying=c.get("retrying"), alt_regs=c.get("alt_regs_p"))
            glob.append(row)
    return {"local": local, "global": glob, "global_order": s.order, "calls": {"local": len(rec.get("local", [])),
                                                                                "global": len(rec.get("global", []))}}


def cmd_trace(a):
    addr = int(a.addr, 16)
    with C.Session(addr, a.draft) as s:
        s.natural()
        rec = s.forced("t", {}, at="alloc", trace="full")[4]
        t = trace_tables(s, rec)
        t.update(addr=f"{addr:08x}", draft=rel(a.draft), function=s.fname, judge=s.report.split("\n")[0])
    path = out_path(addr, a.draft, ".trace.json")
    json.dump(t, open(path, "w"), indent=1)
    print(t["judge"])
    print(f"local-alloc: {len(t['local'])} quantities ({t['calls']['local']} find_free_reg calls)")
    print("  blk qty  pseudos        refs  range     pri  reg   how          held before it")
    for r in t["local"]:
        held = ", ".join(f"{b['reg']}<-{b['by']}" if isinstance(b["by"], int) else b["reg"] for b in r["before"])
        how = ("sugg " + "/".join(r["suggested"])) if r["by_suggestion"] else "first free"
        name = ",".join(map(str, r["tied"])) + (f" {r['var']}" if r.get("var") else "")
        print(f"  {r['block']:3} {r['qty']:3}  {name:14} {str(r['n_refs']):>4}  {str(r['birth']):>3}-{str(r['death']):<4} "
              f"{r['priority']:5}  {r['reg']:5} {how:12} {held}")
    print(f"global: {len(t['global'])} find_reg calls; order {' '.join(map(str, t['global_order']))}")
    print("  rank pseudo         refs/len    pri  calls reg   prefers   held before it")
    for k, r in enumerate(t["global"]):
        held = ", ".join(f"{b['reg']}<-{b['by']}" if isinstance(b["by"], int) else b["reg"] for b in r["before"])
        name = f"{r['pseudo']}" + (f" {r['var']}" if r.get("var") else "")
        print(f"  {k:4} {name:14} {str(r['n_refs']):>3}/{str(r['length']):<5} {r['priority']:6}  {str(r['calls_crossed']):>4}  "
              f"{r['reg']:5} {'/'.join(r['preferred']):9} {held}")
    print("written:", rel(path))


# ---------------------------------------------------------------- force

def parse_reg(text):
    text = text.strip().lstrip("$")
    if text.isdigit():
        return int(text)
    if text in R.REGS:
        return R.REGS.index(text)
    if text.startswith("f") and text[1:].isdigit():
        return 32 + int(text[1:])
    raise SystemExit(f"unknown register {text!r}")


def parse_slots(text):
    """`live:T:+v0,live:T:-a1,take:B:X,reject:B:X,predict:B:2,nothrow:C,nothrow:all` as the hook's `reorg`."""
    cfg = {}
    for item in filter(None, (text or "").split(",")):
        kind, _, rest = item.partition(":")
        parts = rest.split(":")
        if kind == "live":
            cfg = P.with_override(cfg, ("live", int(parts[0]), "remove" if parts[1][0] == "-" else "add", parse_reg(parts[1].lstrip("+-"))))
        elif kind in ("take", "reject", "predict"):
            cfg = P.with_override(cfg, (kind, int(parts[0]), int(parts[1])))
        elif kind == "nothrow":
            cfg = P.with_override(cfg, ("nothrow", True if parts[0] == "all" else int(parts[0])))
        else:
            raise SystemExit(f"unknown delay-slot override {item!r}")
    return cfg


def cmd_force(a):
    addr = int(a.addr, 16)
    with C.Session(addr, a.draft) as s:
        s.natural()
        print("as is:", s.report.split("\n")[0])
        if a.set or a.slot or a.steer:
            force = {int(k): parse_reg(v) for k, v in (x.split("=") for x in a.set.split(","))} if a.set else {}
            reorg = parse_slots(a.slot)
            final = dict(s.disp)
            final.update(force)
            for p, why in s.conflicts(final, force).items():
                print(f"  collision: pseudo {p} -> {R.regname(force[p])}: {why}")
            sched, picks = None, None
            if a.steer:
                st = P.steer(s, force, reorg or None)
                sched, picks = st["cfg"], st.get("picks_changed")
                print(f"scheduler steered toward the original's order: {st['result']}"
                      + (f", {picks} pick(s) changed, {st.get('stalls', 0)} cycle(s) ended early" if sched else ""))
            ok, report, lst, disp, rec, errors = s.forced("f", force, at=a.at, trace="light", sched=sched, reorg=reorg or None)
            out = {"addr": f"{addr:08x}", "draft": rel(a.draft), "at": a.at, "force": {str(p): h for p, h in force.items()},
                   "reorg": reorg, "sched_picks_changed": picks, "reorg_applied": (rec.get("reorg") or {}).get("forced", []),
                   "judge": report.split("\n")[0], "certificate": ok,
                   "refused": [c.get("pseudos") or [c.get("pseudo")] for c in rec.get("local", []) + rec.get("global", [])
                               if c.get("force_failed")]}
            print(f"forced {len(force)} register(s) at {a.at}, {len(P.overrides(reorg))} delay-slot decision(s): {out['judge']}"
                  + ("  [certificate, not a match]" if ok else ""))
            for e in out["reorg_applied"]:
                print("  applied:", " ".join(map(str, e)))
            if not ok and a.listing:
                print("\n".join(l for l in report.split("\n") if l.startswith("!")))
        else:
            out = s.fixed_point()
            out.update(addr=f"{addr:08x}", draft=rel(a.draft))
            for i, r in enumerate(out["rounds"]):
                moved = ", ".join(f"{p}->{R.regname(h)}" for p, h in r["added"].items())
                print(f"  round {i}: {moved}; {len(r['collisions'])} collision(s); {r['differ']} instructions differ")
            print(f"fixed point: {out['result']}; {len(out['force'])} pseudos overridden at reload: "
                  + ", ".join(f"{p}: {R.regname(v[0])} -> {R.regname(v[1])}" for p, v in out["force"].items()))
            if out["result"] == "match":
                print("  [certificate: the draft is the original up to these registers; not a match]")
    path = out_path(addr, a.draft, ".force.json")
    json.dump(out, open(path, "w"), indent=1)
    print("written:", rel(path))


# ---------------------------------------------------------------- early passes

def cmd_early(a):
    addr = int(a.addr, 16)
    with C.Session(addr, a.draft) as s:
        s.natural()
        print(s.report.split("\n")[0])
        led, _ = E.ledger(s)
        e = E.explain(s, s.lst, s.report)
        if a.ledger:
            for row in led:
                print(f"{row['pass']}: {len(row['deleted'])} deleted, {len(row['created'])} made, {len(row['changed'])} rewritten")
                for u, kind, line, p in row["deleted"][:a.ledger]:
                    print(f"   - insn {u} (line {line}, {kind}): {p[:110]}")
                for u, kind, line, p in row["created"][:a.ledger]:
                    print(f"   + insn {u} (line {line}, {kind}): {p[:110]}")
                for c in row["changed"][:a.ledger]:
                    print(f"   ~ insn {c[0]} (line {c[2]}): {c[3][:70]}  ->  {c[4][:70]}")
        else:
            print("per pass (deleted/made/rewritten): " + ", ".join(
                f"{k} {v['deleted']}/{v['created']}/{v['changed']}" for k, v in e["ledger"].items()))
        print("\n".join(E.sentences(e)) or "no instruction that only one side has")
    path = out_path(addr, a.draft, ".early.json")
    json.dump(dict(e, addr=f"{addr:08x}", draft=rel(a.draft), passes=led), open(path, "w"), indent=1)
    print("written:", rel(path))


# ---------------------------------------------------------------- delay slots

def cmd_slots(a):
    addr = int(a.addr, 16)
    with C.Session(addr, a.draft) as s:
        s.natural()
        ok, report, lst, _, rec, errors = s.forced("t", {}, trace="none", reorg={"trace": "full"})
        rows = P.slot_table(s, lst, rec)
        rg = rec.get("reorg") or {}
        text = C.columns(report)
        mine = lambda i: text[1][i] if i < len(text[1]) else "?"
        orig = lambda j: text[0][j] if j < len(text[0]) else "?"
        print(report.split("\n")[0])
        print(f"{len(rows)} instructions with a delay slot; before reorg the chain is "
              + " ".join(f"{u}{'' if k == 'i' else k}" for u, k in rg.get("before", []))[:1500])
        print("  uid   line  instruction                        slot                               filled by      from")
        for r in rows:
            o = r.get("original")
            print(f"  {str(r['uid']):5} {str(r['line'] or ''):5} {mine(r['index'])[:34]:34} {mine(r['index'] + 1)[:34]:34} "
                  f"{r.get('phase', '-'):14} {r.get('from', '')}")
            if r.get("differs"):
                print(f"        the original: {orig(o['index'])[:34]:34} {orig(o['index'] + 1)[:34]}"
                      + (f"   (insn {r['original_uid']} here)" if r.get("original_uid") is not None else ""))
        live = {}
        for l in rg.get("live", []):
            live[(l["target"], l["for"])] = l
        print("threads tried (fill_slots_from_thread):")
        for t in rg.get("threads", []):
            l = live.get((t["opposite"], t["insn"]))
            print(f"  {t['phase']:10} branch {t['insn']}: thread at insn {t['thread']} ("
                  + ("target" if t["if_true"] else "fall-through") + (", its own" if t["own"] else ", shared")
                  + (", likely" if t["likely"] else "") + f"); other side at insn {t['opposite']}"
                  + (": live there " + " ".join(R.regname(h) for h in l["live"] if h not in (0, 26, 27, 28, 29, 31))
                     + (f"; scan stopped at call(s) {l['stops']}" if l["stops"] else "") if l else ""))
        if rg.get("predict"):
            print("mostly_true_jump: " + ", ".join(f"insn {u}: {v}" for u, v in rg["predict"]))
        for ph, b, x, kind, okay in rg.get("trials", []):
            if not okay:
                print(f"  {ph}: insn {x} is not eligible for the slot of insn {b} ({kind})")
        blocked = collections.defaultdict(list)
        for ph, b, x, what in rg.get("blocked", []):
            if x not in blocked[(ph, b, what)]:
                blocked[(ph, b, what)].append(x)
        for (ph, b, what), xs in blocked.items():
            print(f"  {ph}: for insn {b}, refused ({what}): " + " ".join(map(str, xs[:16])))
        for e in rg.get("events", [])[:40]:
            print("  " + e[0] + ": " + e[1] + " " + " ".join(str(x) for x in e[2:]))
        out = {"addr": f"{addr:08x}", "draft": rel(a.draft), "function": s.fname, "judge": report.split("\n")[0], "slots": rows,
               "reorg": rg, "errors": errors}
        if a.search and not ok:
            ss = P.slot_search(s, {}, None)
            out["search"] = {"result": ss["result"], "differ": ss.get("best"), "tried": ss["tried"],
                             "overrides": [list(c) for c in P.overrides(ss["cfg"])],
                             "decisions": P.describe_slots(s, ss["cfg"], ss["lst"], ss["rec"]) if ss["cfg"] else []}
            print(f"search over delay-slot decisions: {ss['result']} ({ss['tried']} compiles); {out['differ'] if 'differ' in out else ss.get('best')} "
                  "instructions differ after it" + ("  [certificate, not a match]" if ss["result"] == "reproduced" else ""))
            for e in out["search"]["decisions"]:
                print("   -", e["why"])
                print("     to move it:", e["need"])
    path = out_path(addr, a.draft, ".slots.json")
    json.dump(out, open(path, "w"), indent=1)
    print("written:", rel(path))


# ---------------------------------------------------------------- report

def print_report(row):
    print(f"{row['addr']} {row['draft']}: {row.get('differ')} of {row.get('original')} instructions differ "
          f"({row.get('natural_class')})")
    if row["kind"] == "match":
        print("  matches as it is")
        return
    if row["kind"] == "error":
        print("  error:", row.get("error"))
        return
    fp = row.get("reload", {})
    if not row.get("certified"):
        print(f"  not allocation-only: forcing {len(fp.get('force', {}))} pseudos leaves {fp.get('differ_forced')} "
              f"differing ({row.get('residual_class')})")
        print_combined(row)
        return
    ca = row["causal"]
    print(f"  CERTIFICATE: the original up to register allocation ({row['pseudos_moved']} pseudos sit elsewhere). "
          f"Decision distance: {row['distance'] if row['distance'] is not None else 'not reduced (' + ca['result'] + ')'}")
    for sw in fp.get("swaps", []):
        print(f"  operand order, line {sw['line']}: the original has `{sw['original']}`, the draft `{sw['mine']}`: "
              "exchange the operands of that commutative operator in the source")
    if ca.get("note"):
        print("  note:", ca["note"])
    for k, d in enumerate(ca["decisions"], 1):
        if d.get("decision") == "tie":
            print(f"  {k}. pseudo {d['pseudo']} = {var(d)} is tied to pseudo {d['tied_to']['pseudo']} = {var(d['tied_to'])} "
                  f"[local, block {d['block']}, quantity {d['qty']}, line {d['line']}]")
            print(f"     why: {d['why']}")
            print(f"     to move it: {d['need']}")
            continue
        print(f"  {k}. pseudo {d['pseudo']} = {var(d)}: got {d['got']}, the original has {d['want']} "
              f"[{d['phase']}" + (f", block {d['block']}, quantity {d['qty']}" if d["phase"] == "local" else f", rank {d.get('rank')}")
              + f", priority {d.get('priority')}, {d.get('n_refs')} refs]")
        print(f"     why: {d['why']}")
        for r in d.get("rivals", []):
            print(f"     rival: pseudo {r['pseudo']} = {var(r)} in {r['reg']}, decided {r['decided']}, priority {r.get('priority')}"
                  + (f", born {r['birth']}" if "birth" in r else ""))
        print(f"     to move it: {d['need']}")


def print_combined(row):
    c = row.get("combined")
    if not c:
        return
    if c.get("certified"):
        n = c["decisions"]
        print(f"  CERTIFICATE across passes: the original up to {c['total']} decision(s): {n['allocation']} register(s), "
              f"{n['sched']} scheduler pick(s), {n['reorg']} delay-slot decision(s). The logic is complete.")
        for line in c.get("list", []):
            print("   -", line)
        needs = [p["need"] for p in ((row.get("passes") or {}).get("sched") or {}).get("picks", []) if p.get("need")]
        needs += [e["need"] for e in ((row.get("passes") or {}).get("reorg") or {}).get("decisions", [])]
        for need in dict.fromkeys(needs):
            print("     to move it:", need)
        return
    if c.get("reason"):
        print(f"  not certified: {c['reason']} ({c.get('aligned')} instructions differ once the listings are aligned, "
              f"{c.get('differ')} row by row)")
    else:
        print(f"  not certified: allocation, scheduling and delay slots forced together leave {c.get('aligned')} instructions "
              f"that differ once aligned ({c.get('differ')} row by row"
              + (f", {c['residual_class']}" if c.get("residual_class") else "") + ")")
    rows_o, rows_d = c.get("only_original") or [], c.get("only_draft") or []
    if rows_o or rows_d:
        print("    could not align:")
        for label, rows in (("only in the original", rows_o), ("only in the draft", rows_d)):
            if rows:
                print(f"      {label}: " + "; ".join(rows))
    elif not c.get("reason"):
        print("    every instruction has its counterpart: what is left is their registers or their order")
    for line in c.get("blocked", []):
        print("    order:", line)
    for line in (row.get("early") or {}).get("text", []):
        print("    early passes:", line)


def one_report(addr, src, passes=True):
    with C.Session(addr, src) as s:
        try:
            row = s.report_all(rel(src))
            if row["kind"] in ("match", "allocation", "allocation+operand order"):
                row["logic"] = "complete"
                if row["kind"] != "match":
                    n = row["distance"] if row.get("distance") is not None else row.get("pseudos_moved", 0)
                    row["combined"] = {"certified": True, "differ": 0, "decisions": {"allocation": n, "sched": 0, "reorg": 0},
                                       "total": n, "passes": ["allocation"]}
            elif passes and row["kind"] in ("other", "allocation+other"):
                try:
                    P.compose(s, row)
                except C.OracleError as e:
                    row["combined"] = {"certified": False, "error": str(e)[:200]}
                    row["logic"] = "unknown"
                row["gdb_runs"] = s.n_gdb
        except C.OracleError as e:
            row = {"addr": f"{addr:08x}", "draft": rel(src), "sha": C.digest(src), "kind": "error", "error": str(e)[:300]}
    json.dump(row, open(out_path(addr, src), "w"), indent=1)
    return row


def cmd_report(a):
    row = one_report(int(a.addr, 16), a.draft)
    print_report(row)
    print("written:", rel(out_path(int(a.addr, 16), a.draft)))


# ---------------------------------------------------------------- measure

def corpus():
    """[(addr, path)] of every kept draft of a function that has no source: the workers' drafts
    (build/swarm/*/), the drafts and closer variants the finisher recorded (build/finish/
    results.jsonl), and the research corpus (build/research/). One entry per content."""
    import finish_near
    done = set(project.sources())
    seen, out = set(), []

    def add(addr, path):
        full = os.path.join(ROOT, path) if not os.path.isabs(path) else path
        if addr in done or not os.path.isfile(full) or os.path.splitext(full)[1] not in (".c", ".cpp"):
            return
        key = (addr, C.digest(full))
        if key not in seen:
            seen.add(key)
            out.append((addr, full))

    for addr, paths in finish_near.drafts().items():
        for p in paths:
            add(addr, p)
    for r in finish_near.rows():
        for k in ("draft", "best_draft"):
            if r.get(k):
                add(int(r["addr"], 16), r[k])
    research = os.path.join(ROOT, "build", "research")
    if os.path.exists(os.path.join(research, "corpusA.json")):
        for r in json.load(open(os.path.join(research, "corpusA.json"))):
            add(int(r["addr"], 16), r.get("best_draft") or r["draft"])
    for sub in ("e4", "matched"):
        d = os.path.join(research, sub)
        for name in sorted(os.listdir(d)) if os.path.isdir(d) else ():
            m = finish_near.DRAFT.match(name)
            if m:
                add(int(m.group(1), 16), os.path.join(d, name))
    return sorted(out)


def corpus_of(compiler):
    """[(addr, path)] of the kept drafts that ask for one compiler profile on their first line
    (`/* compiler: NAME */`), whatever their distance: the workers' files and the attempt
    store. finish_near.py leaves the SDK's functions out, so corpus() never sees them."""
    import glob
    import attempt_store
    import finish_near
    done = set(project.sources())
    seen, out = set(), []

    def add(addr, full):
        if addr in done or not os.path.isfile(full) or os.path.splitext(full)[1] not in (".c", ".cpp"):
            return
        try:
            if project.source_compiler(full) != compiler:
                return
        except (OSError, SystemExit):
            return
        key = (addr, C.digest(full))
        if key not in seen:
            seen.add(key)
            out.append((addr, full))

    for path in glob.glob(os.path.join(ROOT, "build", "swarm", "*", "*")):
        m = finish_near.DRAFT.match(os.path.basename(path))
        if m:
            add(int(m.group(1), 16), path)
    try:
        for addr, paths in attempt_store.drafts({}, closest=3).items():
            for p in paths:
                add(addr, os.path.join(ROOT, p))
    except Exception as e:      # the store is another tool's: a draft list without it is still a list
        log(f"attempt store not read: {type(e).__name__}: {e}")
    return sorted(out)


class Timeout(Exception):
    pass


def _alarm(*_):
    raise Timeout()


def measure_one(item):
    addr, src, seconds, fresh = item
    path = out_path(addr, src)
    if not fresh and os.path.exists(path):
        try:
            row = json.load(open(path))
            if "logic" in row or row.get("kind") == "error":     # a report from before the passes were composed is redone
                return row
        except ValueError:
            pass
    signal.signal(signal.SIGALRM, _alarm)
    signal.alarm(seconds)
    try:
        row = one_report(addr, src)
    except Timeout:
        row = {"addr": f"{addr:08x}", "draft": rel(src), "sha": C.digest(src), "kind": "error", "error": f"over {seconds}s"}
        json.dump(row, open(path, "w"))
    except Exception as e:  # one bad draft must not stop the run
        row = {"addr": f"{addr:08x}", "draft": rel(src), "sha": C.digest(src), "kind": "error",
               "error": f"{type(e).__name__}: {e}"[:300]}
        json.dump(row, open(path, "w"))
    finally:
        signal.alarm(0)
    return row


def bucket(row):
    if row["kind"] == "match":
        return "0"
    if row["kind"] in ("allocation", "allocation+operand order"):
        d = row.get("distance")
        if d is None:
            return "certified, no allocation path (a value's life differs)"
        b = "0" if d == 0 else "1" if d == 1 else "2" if d == 2 else "3-5" if d <= 5 else "more"
        return b if row["kind"] == "allocation" else f"allocation ({b}) and operand order of a commutative instruction"
    if row["kind"] == "allocation+other":
        return "not allocation-only: registers and " + str(row.get("residual_class"))
    if row["kind"] == "other":
        return "not allocation-only: " + str(row.get("residual_class") or row.get("natural_class"))
    return "error"


PASS_NAMES = {"allocation": "allocation", "sched": "scheduler", "reorg": "delay slots"}


def bucket2(row):
    """The classification across passes: (class, sub-class)."""
    if row["kind"] == "match":
        return "matches as it is", ""
    if row["kind"] == "error":
        return "error", ""
    c = row.get("combined") or {}
    if row.get("logic") == "complete" or c.get("certified"):
        names = " + ".join(PASS_NAMES[k] for k in c.get("passes", ["allocation"])) or "allocation"
        n = c.get("total", 0)
        return "logic complete", f"{names}: {n if n <= 2 else '3-5' if n <= 5 else '6-10' if n <= 10 else 'more than 10'} decision(s)"
    if "combined" not in row:
        return "passes not composed (older report)", str(row.get("residual_class") or row.get("natural_class"))
    if c.get("reason"):
        return "not certified", "3 or more instructions without a counterpart (passes not forced)"
    if c.get("blocked") and c.get("residual_class") == "order":
        return "not certified", "same instructions, the original's order blocked by a dependence"
    n = row.get("unaccounted_forced")
    return "not certified", (f"all passes forced: {n} instruction(s) without a counterpart" if n else
                             f"all passes forced, same instructions, left: {c.get('residual_class') or 'error'}")


def summarise(rows):
    by_draft = collections.Counter(bucket(r) for r in rows)
    best = {}
    rank = lambda r: (0, r["distance"]) if r.get("distance") is not None else \
        (1, 0) if r.get("certified") else (2, r.get("reload", {}).get("differ_forced") or 999) \
        if r["kind"] in ("allocation+other", "other") else (3, 0)
    for r in rows:
        if r["addr"] not in best or rank(r) < rank(best[r["addr"]]):
            best[r["addr"]] = r
    by_func = collections.Counter(bucket(r) for r in best.values())
    # across passes: the best draft of a function is the one with the fewest decisions in all
    rank2 = lambda r: (0, 0) if r["kind"] == "match" else (1, (r.get("combined") or {}).get("total", 0)) \
        if r.get("logic") == "complete" else (2, (r.get("combined") or {}).get("differ") or 999) if r["kind"] != "error" else (3, 0)
    best2 = {}
    for r in rows:
        if r["addr"] not in best2 or rank2(r) < rank2(best2[r["addr"]]):
            best2[r["addr"]] = r
    # the passes before allocation, for the drafts a few instructions away in content
    early = [r["early"] for r in rows if isinstance(r.get("early"), dict) and "extra" in r["early"]]
    by_pass = collections.Counter()
    for e in early:
        for x in e["extra"]:
            by_pass["only the draft has it: " + str(x.get("made_by") or "unknown")] += 1
        for m in e["missing"]:
            by_pass["only the original has it: " + (m["candidates"][0]["pass"] + " " + m["candidates"][0]["what"].split(" ")[0]
                                                    if m["candidates"] else "no pass removed one like it")] += 1
    complete = lambda r: r["kind"] != "match" and r.get("logic") == "complete"
    per_pass = lambda rs: {k: sum(1 for r in rs if complete(r) and (r.get("combined") or {}).get("decisions", {}).get(k))
                           for k in ("allocation", "sched", "reorg")}
    return {"drafts": len(rows), "functions": len(best), "by_draft": dict(by_draft), "by_function": dict(by_func),
            "certified_drafts": sum(1 for r in rows if r["kind"].startswith("allocation") and r.get("certified")),
            "certified_functions": sum(1 for r in best.values() if r["kind"].startswith("allocation") and r.get("certified")),
            "matching_as_is": sorted({r["addr"] for r in rows if r["kind"] == "match"}),
            "gdb_runs": sum(r.get("gdb_runs", 0) for r in rows),
            "passes_by_draft": {" | ".join(k): v for k, v in collections.Counter(bucket2(r) for r in rows).items()},
            "passes_by_function": {" | ".join(k): v for k, v in collections.Counter(bucket2(r) for r in best2.values()).items()},
            "logic_complete_drafts": sum(1 for r in rows if complete(r)),
            "logic_complete_functions": sum(1 for r in best2.values() if complete(r)),
            "not_certified_drafts": sum(1 for r in rows if r.get("logic") == "open"),
            "not_certified_functions": sum(1 for r in best2.values() if r.get("logic") == "open"),
            "pass_involved_drafts": per_pass(rows), "pass_involved_functions": per_pass(best2.values()),
            "early": {"drafts": len(early), "accounted": sum(1 for e in early if e.get("accounted")), "instructions": dict(by_pass)}}


def print_summary(s):
    print(f"{s['drafts']} drafts of {s['functions']} unmatched functions")
    print(f"{'decision distance':58} {'drafts':>7} {'functions':>10}")
    keys = [k for k in BUCKETS] + [f"allocation ({k}) and operand order of a commutative instruction" for k in BUCKETS] \
        + ["certified, no allocation path (a value's life differs)"]
    keys += sorted(k for k in set(s["by_draft"]) | set(s["by_function"]) if k not in keys)
    for k in keys:
        if s["by_draft"].get(k) or s["by_function"].get(k):
            label = f"allocation only, {k} decision(s)" if k in BUCKETS else k
            print(f"  {label:56} {s['by_draft'].get(k, 0):7} {s['by_function'].get(k, 0):10}")
    print(f"certified logic-complete (forced compile equals the original): {s['certified_drafts']} drafts, "
          f"{s['certified_functions']} functions")
    if s["matching_as_is"]:
        print("match as they are (judge them and save):", " ".join(s["matching_as_is"]))
    if "passes_by_draft" not in s:
        return
    print()
    print(f"{'allocation, scheduler and delay slots forced together':66} {'drafts':>7} {'functions':>10}")
    d, f = s["passes_by_draft"], s["passes_by_function"]
    for k in sorted(set(d) | set(f)):
        print(f"  {k:64} {d.get(k, 0):7} {f.get(k, 0):10}")
    print(f"logic complete, k decisions across passes: {s['logic_complete_drafts']} drafts, {s['logic_complete_functions']} "
          f"functions; not certified: {s['not_certified_drafts']} drafts, {s['not_certified_functions']} functions")
    print("certificates that need a decision of the pass:  " + ", ".join(
        f"{PASS_NAMES[k]} {s['pass_involved_drafts'][k]} drafts / {s['pass_involved_functions'][k]} functions"
        for k in ("allocation", "sched", "reorg")))
    e = s.get("early")
    if e and e["drafts"]:
        print(f"\n1 to 4 instructions that only one side has: {e['drafts']} drafts; every one of them traced to a pass in "
              f"{e['accounted']}")
        for k, v in sorted(e["instructions"].items(), key=lambda kv: -kv[1]):
            print(f"  {k:64} {v:7}")


LOST = os.path.join(OUT, "lost.txt")


def lost_drafts():
    """Drafts whose trace killed its worker before (one path per line): measuring them again costs
    a full time limit each and never returns. Delete build/oracle/lost.txt to try them again."""
    if not os.path.exists(LOST):
        return set()
    return {l.split("\t")[1].strip() for l in open(LOST) if "\t" in l}


def mark_lost(addr, path):
    with open(LOST, "a") as f:
        f.write(f"{addr:08x}\t{os.path.relpath(path, ROOT)}\n")


def cmd_measure(a):
    items = corpus_of(a.compiler) if a.compiler else corpus()
    if a.only:
        only = {int(x, 16) for x in a.only.split(",")}
        items = [i for i in items if i[0] in only]
    lost = lost_drafts() if not a.fresh else set()
    items = [i for i in items if os.path.relpath(i[1], ROOT) not in lost]
    items = items[:a.limit]
    log(f"measure: {len(items)} drafts of {len({i[0] for i in items})} unmatched functions, {a.jobs} jobs"
        + (f"; {len(lost)} skipped (their trace killed a worker before)" if lost else ""))
    rows, started = [], time.time()
    with multiprocessing.Pool(a.jobs) as pool:
        # One result at a time with a time limit: a worker that dies under gdb never returns its
        # task and imap would wait for it for ever (the pool replaces the worker, the rest goes on).
        work = [(addr, src, a.seconds, a.fresh) for addr, src in items]
        pending = [(w, pool.apply_async(measure_one, (w,))) for w in work]
        for n, (w, res) in enumerate(pending, 1):
            try:
                rows.append(res.get(timeout=(a.seconds or 240) + 60))
            except multiprocessing.TimeoutError:
                log(f"no result (worker lost): {w[0]:08x} {os.path.relpath(w[1], ROOT)}")
                mark_lost(w[0], w[1])
            if n % 25 == 0:
                c = collections.Counter(r["kind"] for r in rows)
                log(f"progress: {n} of {len(items)}; {dict(c)}; {time.time() - started:.0f}s")
    s = summarise(rows)
    s["seconds"] = round(time.time() - started)
    # a partial run, or the drafts of another compiler, do not replace the measurement
    part = "_partial" if a.only or a.limit < 10 ** 6 else f"_{a.compiler}" if a.compiler else ""
    json.dump(s, open(os.path.join(OUT, f"summary{part}.json"), "w"), indent=1)
    json.dump([dict({k: r.get(k) for k in ("addr", "draft", "sha", "kind", "distance", "differ", "original", "natural_class",
                                           "residual_class", "pseudos_moved", "error", "logic", "unaccounted")},
                    decisions=(r.get("combined") or {}).get("decisions"), total=(r.get("combined") or {}).get("total"),
                    differ_combined=(r.get("combined") or {}).get("differ"))
               for r in sorted(rows, key=lambda r: r["addr"])],
              open(os.path.join(OUT, f"index{part}.json"), "w"), indent=0)
    print_summary(s)
    log(f"measure done in {s['seconds']}s, {s['gdb_runs']} compiles under gdb; build/oracle/summary{part}.json, index{part}.json")


def cmd_status(a):
    p = os.path.join(OUT, f"summary_{a.compiler}.json" if a.compiler else "summary.json")
    if not os.path.exists(p):
        raise SystemExit("no measurement yet: oracle.py measure")
    print_summary(json.load(open(p)))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name in ("trace", "force", "report"):
        p = sub.add_parser(name)
        p.add_argument("addr")
        p.add_argument("draft")
        if name == "force":
            p.add_argument("--set", help="PSEUDO=REG,... (REG: v0, $s1, f20 or gcc's number)")
            p.add_argument("--at", choices=("reload", "alloc"), default="reload")
            p.add_argument("--listing", action="store_true")
            p.add_argument("--slot", help="delay-slot overrides: live:INSN:+REG, live:INSN:-REG, take:BRANCH:INSN, "
                                          "reject:BRANCH:INSN, predict:BRANCH:VALUE, nothrow:CALL, nothrow:all")
            p.add_argument("--steer", action="store_true", help="steer the scheduler toward the original's order")
    p = sub.add_parser("measure")
    p.add_argument("-j", "--jobs", type=int, default=3)
    p.add_argument("--only")
    p.add_argument("--fresh", action="store_true")
    p.add_argument("--limit", type=int, default=10 ** 6)
    p.add_argument("--seconds", type=int, default=240, help="time limit per draft")
    p.add_argument("--compiler", help="only the kept drafts whose first line asks for this profile, e.g. ee-gcc2.9-991111 "
                                      "(the SDK's functions; written to summary_NAME.json)")
    sub.add_parser("status").add_argument("--compiler")
    p = sub.add_parser("early")
    p.add_argument("addr")
    p.add_argument("draft")
    p.add_argument("--ledger", type=int, default=0, metavar="N", help="print up to N entries of each pass's ledger")
    p = sub.add_parser("slots")
    p.add_argument("addr")
    p.add_argument("draft")
    p.add_argument("--search", action="store_true", help="search the delay-slot decisions that give the original")
    try:
        import orc_aim
        orc_aim.add_parsers(sub)
    except ImportError:
        orc_aim = None
    a = ap.parse_args()
    table = {"trace": cmd_trace, "force": cmd_force, "report": cmd_report, "measure": cmd_measure, "status": cmd_status,
             "slots": cmd_slots, "early": cmd_early}
    if orc_aim:
        table.update(orc_aim.COMMANDS)
    table[a.cmd](a)


if __name__ == "__main__":
    main()
