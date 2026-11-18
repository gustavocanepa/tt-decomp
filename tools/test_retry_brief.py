"""The retry report: distance and order of kept drafts, the decisions in plain terms, the queue
behind `swarm.py assign --certified`, and that assign is unchanged without the option."""
import contextlib
import io
import json
import os
import tempfile
import types
import unittest
from unittest import mock

import attempt_store
import retry_brief as rb
import swarm

ADDR = 0x100000
SOURCE = """extern "C" void func_00100010(int *p);
extern "C" s32 func_00100020(int *p);
extern "C" void func_00100000(Obj *a, Src *b) {
    E *e;
    func_00100010(a->p);
    e = (E *)b->e;
    a->x = e->x + 1;
}
"""
DECISION = {"pseudo": 86, "line": 6, "var": "e", "declared": 4, "kind": "local1", "got": "$s1", "want": "$s2",
            "phase": "global", "refs": 8, "live_length": 31, "calls_crossed": 4, "n_refs": 8, "priority": 7741,
            "blocked": False, "why": "$s1 was the first free register; in the original a value live at the same time holds it",
            "rivals": [{"pseudo": 84, "line": 3, "var": "a", "declared": 3, "kind": "param", "reg": "$s2",
                        "decided": "after", "phase": "global", "refs": 10, "live_length": 40, "priority": 7500}],
            "need": "allocate the rival before this one"}
TEMP = {"pseudo": 90, "line": 7, "got": "$v0", "want": "$v1", "phase": "local", "n_refs": 2, "birth": 4, "death": 6,
        "priority": 10000, "blocked": False, "why": "$v0 was the first free register and $v1 came later in the order"}


class Scratch(unittest.TestCase):
    """A scratch oracle directory, attempt store and root: nothing of the project is read."""

    def setUp(self):
        self.dir = tempfile.TemporaryDirectory()
        self.addCleanup(self.dir.cleanup)
        root = self.dir.name
        for target, name, value in ((rb, "ROOT", root), (rb, "ORACLE", os.path.join(root, "build", "oracle")),
                                    (rb, "INDEX", os.path.join(root, "build", "oracle", "briefs.json")),
                                    (rb, "UNIT_CONTEXT", False), (attempt_store, "STORE", os.path.join(root, "drafts")),
                                    (attempt_store, "true_length", lambda addr: 54)):
            p = mock.patch.object(target, name, value)
            p.start()
            self.addCleanup(p.stop)
        os.makedirs(rb.ORACLE)

    def draft(self, name, text=SOURCE):
        path = os.path.join(self.dir.name, name)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w") as f:
            f.write(text)
        return path, rb.digest(path)

    def row(self, name, text=SOURCE, addr=ADDR, **fields):
        path, sha = self.draft(name, text)
        row = dict({"addr": f"{addr:08x}", "draft": name, "sha": sha, "original": 54, "instructions": 54, "differ": 19,
                    "kind": "other", "natural_class": "mixed", "reload": {"differ_forced": 19, "force": {}}}, **fields)
        rb.dump(os.path.join(rb.ORACLE, f"{addr:08x}_{sha}.json"), row)
        return sha

    def certified(self, name, decisions, **fields):
        return self.row(name, kind="allocation", certified=True, distance=len(decisions), operand_swaps=0,
                        causal={"result": "match", "decisions": decisions}, **fields)


class Rules(unittest.TestCase):
    def test_rank_and_the_smallest_flip(self):
        self.assertEqual(rb.priority(8, 31), 7741)
        self.assertEqual(rb.priority(10, 40), 7500)
        hint = rb.flip_hint("`a`", 10, 40, "`e`", 8, 31)
        self.assertIn("1 more use of `a` (8250)", hint)
        self.assertIn("1 fewer of `e`", hint)
        self.assertEqual(rb.flip_hint("`a`", 8, 31, "`e`", 10, 40), "")     # already ahead

    def test_classes(self):
        self.assertEqual(rb.decision_class(DECISION), "saved-swap")
        self.assertEqual(rb.decision_class(TEMP), "v0-taken")
        self.assertEqual(rb.decision_class(dict(TEMP, blocked=True, why="$v0 was busy over this value's range")), "v0-free")
        self.assertEqual(rb.decision_class(dict(TEMP, why="$a2 was suggested by a copy to or from that register")), "copy")
        self.assertEqual(rb.decision_class({"decision": "tie"}), "tie")
        every = set(rb.EDITS) | set(rb.SCHED_EDITS)
        self.assertEqual(every, set(rb.TITLES))

    def test_calls_before_reads_the_declared_return_type(self):
        calls = rb.calls_before(SOURCE.split("\n"), 7)
        self.assertEqual([(c, t) for c, _, t in calls], [("func_00100010", "void")])

    def test_instructions_that_stay(self):
        self.assertEqual(rb.heaviest_increasing([0, 1, 5, 2, 3, 4], [1] * 6), {0, 1, 3, 4, 5})
        # two exchanged: the weight says which one is reported as moved
        self.assertEqual(rb.heaviest_increasing([1, 0], [1.01, 1.0]), {0})

    def test_displaced_names_the_one_early_instruction(self):
        words = [0x8C510000, 0xFFBF0018, 0xE7B40020, 0xFFB20010, 0x00000000]       # lw; sd ra; swc1; sd s2; nop
        mine = [words[0], words[1], words[2], words[3], words[4]]
        original = [words[1], words[2], words[3], words[0], words[4]]
        session = types.SimpleNamespace(addr=ADDR, by_uid={23: None}, padded=lambda n: original,
                                        line_of=lambda uid: 22 if uid == 23 else None)
        lst = types.SimpleNamespace(linked=mine, words=[(4 * i, w, 23 if i == 0 else 400 + i) for i, w in enumerate(mine)])
        moves = rb.displaced(session, lst)
        self.assertEqual(len(moves), 1)
        m = moves[0]
        self.assertTrue(m["insn"].startswith("lw"))
        self.assertEqual((m["line"], m["early"], m["crossed"]), (22, True, 3))
        self.assertEqual(rb.move_class(m), "prologue")
        text = rb.move_lines(1, 1, m)[0][0]
        self.assertIn("3 instructions earlier than in the original", text)
        self.assertIsNone(rb.displaced(session, types.SimpleNamespace(linked=mine[:4] + [1], words=lst.words)))


class Reports(Scratch):
    def test_certified_draft_comes_first_and_names_the_decision(self):
        self.row("build/swarm/a/00100000.cpp", differ=3, reload={"differ_forced": 3, "force": {}})
        self.certified("build/swarm/b/00100000.cpp", [DECISION], text=SOURCE + "\n")
        found = rb.candidates(ADDR)
        self.assertEqual([c["level"] for c in found], [0, 1])
        text = rb.report(ADDR, lazy=False)
        self.assertIn("Start from build/swarm/b/00100000.cpp: 19 of 54 instructions differ", text)
        self.assertIn("CERTIFIED", text)
        self.assertIn("`a` must be allocated first", text)
        self.assertIn("in each other's registers", text)
        self.assertIn("line 6: e = (E *)b->e;", text)
        self.assertNotIn("line 3:", text)                                   # a parameter's line is the header
        self.assertIn("Fewer instructions differ in build/swarm/a/00100000.cpp (3)", text)
        self.assertLessEqual(len(text.split("\n")), 25)

    def test_temporary_lists_the_calls_before_it(self):
        self.certified("build/swarm/b/00100000.cpp", [TEMP])
        text = rb.report(ADDR, lazy=False)
        self.assertIn("a temporary first set on line 7 took $v0", text)
        self.assertIn("func_00100010 (line 5, declared `void`)", text)

    def test_aligned_distance_decides_and_both_counts_are_shown(self):
        near = self.row("build/swarm/a/00100000.cpp", differ=5)
        shifted = self.row("build/swarm/b/00100000.cpp", text=SOURCE + "// nop\n", differ=40, natural_class="length")
        self.assertEqual(rb.candidates(ADDR)[0]["sha"], near)
        rb.merge(ADDR, shifted, {"aligned": 4, "positional": 40})
        best = rb.candidates(ADDR)[0]
        self.assertEqual((best["sha"], best["differ"], best["rows"]), (shifted, 4, 40))
        text = rb.report(ADDR, lazy=False)
        self.assertIn("4 instructions differ once the listings are aligned (the judge's row-by-row count says 40 of 54", text)
        rb.update_index([ADDR])
        self.assertEqual([(a, e["left"]) for a, e in rb.queue(within=4)], [(ADDR, 4)])
        self.assertEqual(rb.queue(within=3), [])

    def test_a_changed_draft_is_found_in_the_store_or_dropped(self):
        sha = self.certified("build/swarm/b/00100000.cpp", [DECISION])
        path = os.path.join(self.dir.name, "build/swarm/b/00100000.cpp")
        with open(path, "a") as f:
            f.write("// edited\n")
        self.assertEqual(rb.candidates(ADDR), [])
        attempt_store.keep_text(ADDR, SOURCE, "cpp")
        self.assertEqual([c["sha"] for c in rb.candidates(ADDR)], [sha])
        self.assertTrue(rb.candidates(ADDR)[0]["path"].startswith("drafts/00100000/"))

    def test_stored_drafts_nobody_measured(self):
        report = "func_00100000: 2 of 54 instructions differ (original 54, mine 54)\n! addu $v0, $a0, $a1 | addu $v0, $a1, $a0"
        attempt_store.put(ADDR, SOURCE, "cpp", report, "s1", "sonnet")
        text = rb.report(ADDR, lazy=False)
        self.assertIn("2 of 54 instructions differ", text)
        self.assertIn("kept from s1 (sonnet)", text)
        self.assertIn("Not measured by the oracle yet", text)
        self.assertEqual(rb.report(0x200000, lazy=False), "")

    def test_queue_is_certified_first_then_by_decisions(self):
        self.certified("build/swarm/a/00100000.cpp", [DECISION, TEMP])
        self.certified("build/swarm/a/00100100.cpp", [DECISION], addr=0x100100)
        self.row("build/swarm/a/00100200.cpp", addr=0x100200, differ=2, kind="allocation+other", reload={"differ_forced": 1, "force": {}})
        self.row("build/swarm/a/00100300.cpp", addr=0x100300, differ=30)
        rb.update_index([0x100000, 0x100100, 0x100200, 0x100300])
        self.assertEqual([a for a, _ in rb.queue()], [0x100100, 0x100000, 0x100200])
        kinds = {a: e["report"] for a, e in rb.queue()}
        self.assertEqual(kinds[0x100100], "specific")


TIERS = {"sonnet": {"model": "sonnet", "fresh": [257, 1024], "retries": ["haiku"], "retry_max_bytes": 1024, "count": 2},
         "opus": {"model": "opus", "fresh": [1025, 8192], "retries": ["sonnet"], "retry_max_bytes": 8192, "count": 2}}
SIZES = {0x100: 300, 0x200: 600, 0x300: 4000, 0x400: 500}
QUEUE = [(0x200, {"draft": "d2", "certified": "allocation", "decisions": 1, "level": 0, "differ": 9, "time": "2026-10-12 12:00:00"}),
         (0x300, {"draft": "d3", "certified": "schedule", "decisions": 2, "level": 0, "differ": 4, "time": "2026-10-12 12:00:00"}),
         (0x100, {"draft": "d1", "certified": None, "decisions": None, "level": 1, "differ": 2, "time": "2026-10-12 12:00:00"}),
         (0x900, {"draft": "d9", "certified": "allocation", "decisions": 1, "level": 0, "differ": 2, "time": "2026-10-12 12:00:00"})]


class Assign(unittest.TestCase):
    def setUp(self):
        self.dir = tempfile.TemporaryDirectory()
        self.addCleanup(self.dir.cleanup)
        self.log = [{"addr": "00000200", "matched": False, "tier": "haiku", "time": "2026-10-12 11:00:00"}]
        fake = lambda max_bytes, min_bytes=8, deferred=False: {
            a: n for a, n in SIZES.items() if min_bytes <= n <= max_bytes and (a == 0x200) == deferred}
        for target, name, value in ((swarm, "SWARM", self.dir.name), (swarm, "LEASES", os.path.join(self.dir.name, "leases.json")),
                                    (swarm, "tiers", lambda: TIERS), (swarm, "candidates", fake),
                                    (swarm, "takable_sizes", lambda addrs: {a: SIZES[a] for a in addrs if a in SIZES}),
                                    (swarm, "log_rows", lambda: self.log), (swarm, "area_of", lambda addr: f"unit_{addr >> 9}"),
                                    (swarm, "rtti_name", lambda addr: None), (swarm, "queue_items", lambda: {}),
                                    (swarm, "paused_areas", lambda: set()), (rb, "queue", lambda within=rb.NEAR: list(QUEUE))):
            p = mock.patch.object(target, name, value)
            p.start()
            self.addCleanup(p.stop)

    def assign(self, *args):
        ns = dict(worker="w1", count=None, tier=None, fresh=False, area=None, new_area=False, max_bytes=256, min_bytes=8,
                  deferred=False, certified=False)
        ns.update(args[0] if args else {})
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            swarm.cmd_assign(types.SimpleNamespace(**ns))
        return json.loads(out.getvalue())

    def test_certified_goes_closest_first_within_the_tier_size(self):
        got = self.assign({"certified": True, "tier": "sonnet"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000200", "00000100"])   # 0x300 is too large, 0x900 not takable
        self.assertEqual((got["area"], got["certified"], got["remaining_in_area"]), ("certified", True, 0))
        leases = swarm.load_leases()
        self.assertEqual(leases["leases"]["00000200"], dict(leases["leases"]["00000200"], worker="w1", tier="sonnet", area="unit_1"))
        self.assertEqual(leases["last_area"], {})
        got = self.assign({"certified": True, "tier": "opus", "worker": "w2"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000300"])               # the others are leased

    def test_a_give_up_after_the_report_leaves_it_to_the_other_tiers(self):
        self.log.append({"addr": "00000200", "matched": False, "tier": "sonnet", "time": "2026-10-12 13:00:00"})
        got = self.assign({"certified": True, "tier": "sonnet"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000100"])
        got = self.assign({"certified": True, "tier": "opus", "worker": "w2"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000200", "00000300"])
        self.log.append({"addr": "00000100", "matched": False, "worker": "w3", "time": "2026-10-12 13:00:00"})
        swarm.save_leases({"leases": {}, "last_area": {}})
        got = self.assign({"certified": True, "worker": "w3", "count": 9})                  # no tier: its own give-ups
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000200", "00000300"])

    def test_the_latest_give_up_of_the_tier_or_a_higher_one_escalates_whatever_the_report_time(self):
        # the give-up left a new closest draft, so the report (12:00) is newer than the give-up (11:30)
        self.log.append({"addr": "00000200", "matched": False, "tier": "sonnet", "time": "2026-10-12 11:30:00"})
        got = self.assign({"certified": True, "tier": "sonnet"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000100"])               # not back to sonnet
        got = self.assign({"certified": True, "tier": "opus", "worker": "w2"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000200", "00000300"])   # up to opus
        swarm.save_leases({"leases": {}, "last_area": {}})
        self.log.append({"addr": "00000200", "matched": False, "tier": "opus", "time": "2026-10-12 11:40:00"})
        got = self.assign({"certified": True, "tier": "sonnet"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000100"])               # nor down from opus
        got = self.assign({"certified": True, "tier": "opus", "worker": "w2"})
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000300"])
        swarm.save_leases({"leases": {}, "last_area": {}})
        self.log.append({"addr": "00000200", "matched": False, "tier": "haiku", "time": "2026-10-12 11:50:00"})
        got = self.assign({"certified": True, "tier": "sonnet"})                            # a lower tier's give-up: offered
        self.assertEqual([f["addr"] for f in got["functions"]], ["00000200", "00000100"])

    def test_without_the_option_assign_is_as_before(self):
        got = self.assign({"max_bytes": 1024})
        self.assertEqual(set(got), {"worker", "tier", "area", "remaining_in_area", "draft_dir", "functions"})
        self.assertEqual([set(f) for f in got["functions"]][0], {"addr", "bytes", "name"})
        self.assertNotIn("00000200", [f["addr"] for f in got["functions"]])                 # deferred: not without --deferred
        self.assertEqual(swarm.load_leases()["last_area"]["w1"], got["area"])

    def test_an_empty_certified_queue_falls_through_to_the_usual_one(self):
        with mock.patch.object(rb, "queue", lambda within=rb.NEAR: []):
            got = self.assign({"certified": True, "max_bytes": 1024})
        self.assertNotIn("certified", got)
        self.assertTrue(got["functions"])


class PredictedContext(unittest.TestCase):
    """`swarm.py try`: one more compile of a near miss with the unit map's context written in."""
    DRAFT = 'extern "C" void func_00100010(int *p);\nextern "C" void func_00100000(int *p) { func_00100010(p); }\n'
    HEAD = "func_00100000: {n} of 54 instructions differ (original 54, mine 54)\n! beql | beq"

    def setUp(self):
        self.dir = tempfile.TemporaryDirectory()
        self.addCleanup(self.dir.cleanup)
        self.judged = []
        self.verdict = (True, "func_00100000: MATCH (54 instructions)")

        def check(addr, path):
            self.judged.append(open(path).read())
            return self.verdict

        for target, name, value in ((swarm, "SWARM", self.dir.name), (swarm, "CONTEXT_LOG", os.path.join(self.dir.name, "context.jsonl")),
                                    (swarm, "check", check), (swarm, "sdk_functions", lambda: set())):
            p = mock.patch.object(target, name, value)
            p.start()
            self.addCleanup(p.stop)

    def run_it(self, n=3, nothrow=(0x100010,), flag="nsa", src=None, path="x/00100000.cpp"):
        import unit_map
        predict = lambda addr, callees=None: {"flag": flag, "nothrow": {c: "defined above it in its unit" for c in nothrow},
                                              "const": [], "maybe": [], "plain": []}
        with mock.patch.object(unit_map, "the_map", return_value=types.SimpleNamespace(predict=predict)):
            return swarm.predicted_context(ADDR, path, src or self.DRAFT, self.HEAD.format(n=n), "w1")

    def test_a_near_miss_is_judged_once_with_the_context_and_saved_as_a_variant(self):
        got = self.run_it()
        self.assertEqual(len(self.judged), 1)
        self.assertTrue(self.judged[0].startswith("/* compiler: ee-gcc2.96-no-strict-aliasing */\n"))
        self.assertIn("func_00100010(int *p) throw();", self.judged[0])
        self.assertEqual(got["text"], self.judged[0])
        self.assertEqual(open(got["path"]).read(), got["text"])
        self.assertTrue(got["path"].endswith(os.path.join("w1", "00100000_context.cpp")))
        self.assertTrue(got["note"].startswith("note: the draft matched once the translation-unit context predicted"))
        self.assertIn("`throw()` on func_00100010", got["note"])
        self.assertEqual((got["callees"], got["log"]), (["func_00100010"], {"context": "predicted"}))
        row = json.loads(open(swarm.CONTEXT_LOG).read())
        self.assertEqual((row["matched"], row["differ"], row["worker"]), (True, 3, "w1"))

    def test_a_variant_that_differs_leaves_the_search_its_turn(self):
        self.verdict = (False, "func_00100000: 2 of 54 instructions differ (original 54, mine 54)")
        self.assertIs(self.run_it(), False)
        self.assertEqual(os.listdir(os.path.join(self.dir.name, "w1")), [])
        self.assertEqual(json.loads(open(swarm.CONTEXT_LOG).read())["differ_with"], 2)

    def test_nothing_is_compiled_when_it_cannot_help(self):
        said = '/* compiler: ee-gcc2.96-no-strict-aliasing */\n' + self.DRAFT.replace("(int *p);", "(int *p) throw();")
        self.assertIsNone(self.run_it(src=said))                         # the draft already says it
        far = "func_00100000: 21 of 54 instructions differ (original 54, mine 54)\n" + "\n".join(
            "! a%d | b%d" % (i, i) for i in range(21))
        import unit_map
        with mock.patch.object(unit_map, "apply") as applied:
            self.assertIsNone(swarm.predicted_context(ADDR, "x/00100000.cpp", self.DRAFT, far, "w1"))   # rows and aligned
        applied.assert_not_called()
        self.assertIsNone(self.run_it(path="x/00100000.c"))              # C has no throw()
        with mock.patch.dict(os.environ, {"SWARM_NO_CONTEXT": "1"}):
            self.assertIsNone(self.run_it())
        self.assertIsNone(swarm.predicted_context(ADDR, "x/00100000.cpp", self.DRAFT, "compile failed", "w1"))
        self.assertEqual(self.judged, [])
        self.assertFalse(os.path.exists(swarm.CONTEXT_LOG))

    def test_a_shifted_listing_counts_by_its_aligned_distance(self):
        rows = ["  a%d | a%d" % (i, i) for i in range(30)]
        shifted = "func_00100000: 30 of 31 instructions differ (original 30, mine 31)\n" + "\n".join(
            ["! a0 | nop"] + ["! a%d | a%d" % (i + 1, i) for i in range(29)] + ["! - | a29"])
        self.assertEqual(swarm.aligned_differ(shifted), 1)
        with mock.patch.object(rb, "merge") as merge:                    # try notes it for the report; a near draft needs none
            swarm.keep_distance(ADDR, "text", shifted)
            swarm.keep_distance(ADDR, "text", "func_00100000: 3 of 30 instructions differ (original 30, mine 30)\n! a | b")
        merge.assert_called_once_with(ADDR, attempt_store.digest("text"), {"aligned": 1, "positional": 30})
        self.assertEqual(swarm.aligned_differ("func_00100000: 3 of 30 instructions differ (original 30, mine 30)\n" + "\n".join(rows)), 3)
        self.assertIsNone(swarm.aligned_differ("compile failed"))


class Prompt(unittest.TestCase):
    def test_the_report_is_one_part_and_failures_stay_out(self):
        with mock.patch.object(rb, "report", return_value="Retry report"):
            self.assertEqual(swarm.retry_report(ADDR), ["Retry report\n"])
        with mock.patch.object(rb, "report", return_value=""):
            self.assertEqual(swarm.retry_report(ADDR), [])
        with mock.patch.object(rb, "report", side_effect=RuntimeError("boom")):
            self.assertEqual(swarm.retry_report(ADDR), [])
        with mock.patch.dict(os.environ, {"SWARM_NO_BRIEF": "1"}), mock.patch.object(rb, "report", return_value="x"):
            self.assertEqual(swarm.retry_report(ADDR), [])


if __name__ == "__main__":
    unittest.main()
