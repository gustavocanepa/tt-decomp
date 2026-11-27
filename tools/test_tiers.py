"""Swarm tiers: escalation of give-ups, the slot plan, the tier recorded from the lease."""
import unittest
from unittest import mock

import swarm

TIERS = {
    "haiku": {"model": "haiku", "fresh": [8, 256], "retries": [], "count": 6},
    "local": {"fresh": [129, 2048], "retries": ["haiku"], "retry_max_bytes": 2048, "count": 4},
    "sonnet": {"model": "sonnet", "fresh": [257, 1024], "retries": ["haiku", "local"], "retry_max_bytes": 1024, "count": 4},
    "opus": {"model": "opus", "fresh": [1025, 8192], "retries": ["sonnet"], "retry_max_bytes": 8192, "count": 2, "slots": 1},
}


def fake_candidates(max_bytes, min_bytes=8, deferred=False):
    fresh = {0x100: 100, 0x200: 300, 0x300: 2000}
    given_up = {0x400: 120, 0x500: 600, 0x600: 900}
    pool = given_up if deferred else fresh
    return {a: n for a, n in pool.items() if min_bytes <= n <= max_bytes}


LOG = [
    {"addr": "00000400", "matched": False, "worker": "w1"},                     # old row: haiku
    {"addr": "00000500", "matched": False, "worker": "local", "tier": "local"},
    {"addr": "00000600", "matched": False, "worker": "s1", "tier": "sonnet"},
]


class TierTests(unittest.TestCase):
    def setUp(self):
        patches = [mock.patch.object(swarm, "tiers", return_value=TIERS),
                   mock.patch.object(swarm, "candidates", side_effect=fake_candidates),
                   mock.patch.object(swarm, "log_rows", return_value=LOG)]
        for p in patches:
            p.start()
            self.addCleanup(p.stop)

    def test_fresh_bands(self):
        self.assertEqual(set(swarm.tier_candidates("haiku")), {0x100})
        self.assertEqual(set(swarm.tier_candidates("opus")) & {0x300}, {0x300})

    def test_give_ups_escalate_to_the_next_tier_only(self):
        self.assertIn(0x400, swarm.tier_candidates("local"))       # haiku -> local
        self.assertNotIn(0x500, swarm.tier_candidates("local"))    # never back to the same tier
        self.assertTrue({0x400, 0x500} <= set(swarm.tier_candidates("sonnet")))
        self.assertIn(0x600, swarm.tier_candidates("opus"))        # sonnet -> opus
        self.assertNotIn(0x600, swarm.tier_candidates("sonnet"))

    def test_plan_gives_every_tier_with_work_a_slot_and_caps_opus(self):
        slots = swarm.plan(5, {"haiku": 100, "local": 500, "sonnet": 400, "opus": 900})
        self.assertNotIn("local", {k for k, v in slots.items() if v})  # not a Claude tier
        self.assertEqual(slots["opus"], 1)
        self.assertEqual(sum(slots.values()), 5)
        self.assertGreaterEqual(slots["haiku"], 1)

    def test_plan_with_one_slot_takes_the_longest_queue(self):
        self.assertEqual(swarm.plan(1, {"haiku": 10, "sonnet": 400, "opus": 0}), {"haiku": 0, "sonnet": 1, "opus": 0})

    def test_plan_skips_tiers_capped_at_zero(self):
        capped = dict(TIERS, haiku=dict(TIERS["haiku"], slots=0))
        with mock.patch.object(swarm, "tiers", return_value=capped):
            slots = swarm.plan(3, {"haiku": 1000, "sonnet": 400, "opus": 100})
        self.assertEqual(slots["haiku"], 0)
        self.assertEqual(slots["sonnet"] + slots["opus"], 3)

    def test_lease_tier(self):
        leases = {"leases": {"00000100": {"worker": "s1", "area": "a", "time": "", "tier": "sonnet"}}, "last_area": {}}
        with mock.patch.object(swarm, "load_leases", return_value=leases):
            self.assertEqual(swarm.lease_tier(0x100), "sonnet")
            self.assertIsNone(swarm.lease_tier(0x200))


if __name__ == "__main__":
    unittest.main()
