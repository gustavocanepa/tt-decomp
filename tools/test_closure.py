"""The nothrow closure inside `swarm.py try`: when it runs, what it returns, what it costs."""
import json
import os
import re
import tempfile
import unittest
from unittest import mock

import swarm

ADDR = 0x100100
DRAFT = """extern "C" {
int func_00100010(int);
int func_00100020(int);
int func_00200030(int);
}
int func_00100100(int a) { return func_00100010(a) + func_00100020(a) + func_00200030(a); }
"""
LIKELY = ("func_00100100: 1 of 20 instructions differ (original 20, mine 20)\n"
          "  nop                                          | nop\n"
          "! beqz        $v0, . + 4 + (0x4 << 2)          | beql        $v0, $zero, . + 4 + (0x4 << 2)")
REGISTERS = ("func_00100100: 1 of 20 instructions differ (original 20, mine 20)\n"
             "! addu        $v0, $a0, $a1                    | addu        $v1, $a0, $a1")


def nothrow_in(text):
    return set(re.findall(r"(func_\w+)\(int\) throw\(\);", text))


class ClosureTests(unittest.TestCase):
    def setUp(self):
        self.dir = tempfile.TemporaryDirectory()
        self.addCleanup(self.dir.cleanup)
        self.judged = []
        for name, value in (("SWARM", self.dir.name), ("CLOSURE_LOG", os.path.join(self.dir.name, "closure.jsonl"))):
            p = mock.patch.object(swarm, name, value)
            p.start()
            self.addCleanup(p.stop)

    def judge_with(self, needed):
        """A judge for which a variant matches when exactly the callees in `needed` are throw()."""
        def check(addr, path):
            with open(path) as f:
                got = nothrow_in(f.read())
            self.judged.append(got)
            return (True, "func_00100100: MATCH (20 instructions)") if got == needed else (False, LIKELY)
        return mock.patch.object(swarm, "check", side_effect=check)

    def run_closure(self, report=LIKELY, path="x/00100100.cpp"):
        return swarm.nothrow_closure(ADDR, path, DRAFT, report, "w1")

    def rows(self):
        path = swarm.CLOSURE_LOG
        return [json.loads(l) for l in open(path)] if os.path.exists(path) else []

    def test_other_differences_cost_nothing(self):
        with self.judge_with({"func_00100020"}):
            self.assertIsNone(self.run_closure(REGISTERS))
            self.assertIsNone(self.run_closure("compile failed"))
            self.assertIsNone(self.run_closure(path="x/00100100.c"))
            with mock.patch.dict(os.environ, {"SWARM_NO_CLOSURE": "1"}):
                self.assertIsNone(self.run_closure())
        self.assertEqual((self.judged, self.rows(), os.listdir(self.dir.name)), ([], [], []))

    def test_one_callee(self):
        with self.judge_with({"func_00100020"}):
            got = self.run_closure()
        self.assertEqual(got["callees"], ["func_00100020"])
        self.assertEqual(nothrow_in(got["text"]), {"func_00100020"})
        self.assertEqual(got["report"], "func_00100100: MATCH (20 instructions)")
        self.assertEqual(got["path"], os.path.join(self.dir.name, "w1", "00100100_nothrow.cpp"))
        with open(got["path"]) as f:
            self.assertEqual(f.read(), got["text"])
        self.assertEqual(os.listdir(os.path.join(self.dir.name, "w1")), ["00100100_nothrow.cpp"])  # no variant left
        self.assertTrue(got["note"].startswith("note: the draft matched once func_00100020 was declared `throw()`"))
        self.assertNotIn("\n", got["note"])
        row, = self.rows()
        self.assertEqual((row["matched"], row["callees"], row["judged"]), (["func_00100020"], 3, len(self.judged)))
        self.assertNotIn(set(), self.judged)  # the draft itself is not judged again

    def test_a_set_that_cannot_shrink(self):
        both = {"func_00100010", "func_00100020"}
        with self.judge_with(both):  # the callees at a lower address, and only together
            got = self.run_closure()
        self.assertEqual(got["callees"], sorted(both))
        self.assertIn("were declared", got["note"])

    def test_nothing_matches(self):
        with self.judge_with({"func_00999999"}):
            self.assertIs(self.run_closure(), False)
        row, = self.rows()
        self.assertEqual((row["matched"], row["judged"]), (None, len(self.judged)))
        self.assertEqual(os.listdir(os.path.join(self.dir.name, "w1")), [])

    def test_a_failure_inside_is_not_the_workers_problem(self):
        with mock.patch.object(swarm, "check", side_effect=RuntimeError("judge died")):
            self.assertIs(self.run_closure(), False)


if __name__ == "__main__":
    unittest.main()
