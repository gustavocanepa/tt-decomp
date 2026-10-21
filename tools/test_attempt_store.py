"""The attempt store: classes of a judge report, what a try and a give-up keep, the reader for
finish_near.py, export and import."""
import io
import os
import tarfile
import tempfile
import unittest
from unittest import mock

import attempt_store as store

LINE = "{mark} {left:<44} | {right}"


def text_of(path):
    return store.read(path).decode()


def write(path, text):
    with open(path, "w") as f:
        f.write(text)


def report(pairs, original=10, mine=None, same=3):
    """A judge report: `same` equal lines, then one differing line per (original, mine) pair."""
    mine = original if mine is None else mine
    lines = [f"func_00100000: {len(pairs)} of {max(original, mine)} instructions differ (original {original}, mine {mine})"]
    lines += [LINE.format(mark=" ", left="nop", right="nop")] * same
    lines += [LINE.format(mark="!", left=a, right=b) for a, b in pairs]
    return "\n".join(lines)


class ClassTests(unittest.TestCase):
    def cls(self, pairs, **kw):
        return store.classify(report(pairs, **kw))

    def test_branch_form(self):
        got = self.cls([("beqz        $v0, . + 4 + (0x5 << 2)", "beql        $v0, $zero, . + 4 + (0x5 << 2)"),
                        ("bc1t        . + 4 + (0x5 << 2)", "bc1tl       . + 4 + (0x5 << 2)"),
                        ("bnel        $a0, $v1, . + 4 + (0x2 << 2)", "bne         $a0, $v1, . + 4 + (0x2 << 2)")])
        self.assertEqual((got["verdict"], got["class"], got["differ"], got["original"]), ("differs", "branch-form", 3, 10))

    def test_branch_with_another_target_is_not_branch_form(self):
        self.assertEqual(self.cls([("beqz        $v0, . + 4 + (0x5 << 2)", "beql        $v0, $zero, . + 4 + (0x6 << 2)")])["class"], "other")
        self.assertEqual(self.cls([("beqz        $v0, . + 4 + (0x5 << 2)", "bnez        $v0, . + 4 + (0x5 << 2)")])["class"], "other")

    def test_registers(self):
        self.assertEqual(self.cls([("addu        $v0, $a0, $a1", "addu        $v1, $a0, $a1"),
                                   ("lw          $s0, 0x10($sp)", "lw          $s1, 0x10($sp)   <D_00600000>")])["class"], "registers")

    def test_order(self):
        self.assertEqual(self.cls([("lw          $v0, 0x4($a0)", "sw          $v1, 0x8($a0)"),
                                   ("sw          $v1, 0x8($a0)", "lw          $v0, 0x4($a0)")])["class"], "order")

    def test_length_and_other(self):
        self.assertEqual(self.cls([("nop", "-")], original=10, mine=9)["class"], "length")
        self.assertEqual(self.cls([("lui         $v1, 0x62", "daddu       $a0, $sp, $zero")])["class"], "other")

    def test_reports_without_counts(self):
        self.assertEqual(store.classify("x.cpp:3: parse error\ncompile failed")["verdict"], "no-compile")
        self.assertEqual(store.classify("REFUSED by tools/asm_policy.py: raw words")["verdict"], "refused")
        self.assertEqual(store.classify("f: DIFFERS AFTER LINKING (matches alone): ...")["verdict"], "link")

    def test_context(self):
        text = ("/* compiler: ee-gcc2.96-no-strict-aliasing */\nextern \"C\" {\nint func_00100010(int) throw();\n"
                "int func_00100020(int);\nvoid A::f(int, char (*)(int)) const throw();\n}\nint func_00100000() { return 0; }\n")
        got = store.context(text)
        self.assertEqual(got["compiler"], "ee-gcc2.96-no-strict-aliasing")
        self.assertEqual(got["nothrow"], ["f", "func_00100010"])
        self.assertIn("-fno-strict-aliasing", got["command"])
        self.assertIsNone(store.context("int f();\n")["compiler"])


class StoreTests(unittest.TestCase):
    def setUp(self):
        self.dir = tempfile.TemporaryDirectory()
        self.addCleanup(self.dir.cleanup)
        p = mock.patch.object(store, "STORE", os.path.join(self.dir.name, "drafts"))
        p.start()
        self.addCleanup(p.stop)

    def test_try_keeps_text_and_row(self):
        near = report([("addu        $v0, $a0, $a1", "addu        $v1, $a0, $a1")])
        row = store.put(0x100000, "int a;\n", "cpp", near, "s1", "sonnet")
        self.assertEqual((row["event"], row["verdict"], row["class"], row["differ"], row["parent"]), ("try", "differs", "registers", 1, None))
        self.assertEqual(text_of(store.source_path(0x100000, row["sha"], "cpp")), "int a;\n")
        self.assertIsNone(store.put(0x100000, "int a;\n", "cpp", near, "s1", "sonnet"))  # the same try again
        second = store.put(0x100000, "int b;\n", "cpp", "compile failed", "s1", "sonnet")
        self.assertEqual((second["verdict"], second["parent"]), ("no-compile", row["sha"]))
        other = store.put(0x100000, "int a;\n", "cpp", near, "o1", "opus")  # another worker, the same text
        self.assertEqual(other["sha"], row["sha"])
        got = store.attempts(0x100000)
        self.assertEqual(len(got), 2)
        self.assertEqual((got[row["sha"]]["tries"], got[row["sha"]]["worker"]), (2, "o1"))
        self.assertEqual(len(os.listdir(store.folder(0x100000))), 3)  # two texts and the log

    def test_giveup_keeps_unjudged_files(self):
        drafts = os.path.join(self.dir.name, "s1")
        os.makedirs(drafts)
        for name, text in (("00100000.cpp", "int a;\n"), ("00100000_best.cpp", "int best;\n"), ("00100008.cpp", "int other;\n"),
                           ("00100000.txt", "notes")):
            write(os.path.join(drafts, name), text)
        tried = store.put(0x100000, "int a;\n", "cpp", report([("nop", "-")], mine=9), "s1", "sonnet")
        row = store.giveup(0x100000, "s1", "sonnet", 12, 1, "one register", drafts)
        self.assertEqual(sorted(row["drafts"]), sorted([tried["sha"], store.digest("int best;\n")]))
        got = store.attempts(0x100000)
        self.assertEqual(got[store.digest("int best;\n")]["verdict"], None)
        self.assertEqual(len(got), 2)
        self.assertEqual(store.functions(), ["00100000"])

    def test_reader_closest_first_without_duplicates(self):
        for n, text in ((7, "int seven;\n"), (2, "int two;\n"), (4, "int four;\n")):
            store.put(0x100000, text, "cpp", report([("nop", "sll $v0, $v0, 1")] * n), "s1", "sonnet")
        store.put(0x100000, "int bad;\n", "cpp", "compile failed", "s1", "sonnet")
        store.put(0x100000, "int unjudged;\n", "c", None, "s1", "sonnet", "kept")
        paths = store.drafts()[0x100000]
        texts = [text_of(os.path.join(store.ROOT, p)) for p in paths]
        self.assertEqual(texts, ["int two;\n", "int four;\n", "int unjudged;\n"])
        known = os.path.join(self.dir.name, "00100000.cpp")
        write(known, "int two;\n")
        texts = [text_of(os.path.join(store.ROOT, p))
                 for p in store.drafts({0x100000: [os.path.relpath(known, store.ROOT)]})[0x100000]]
        self.assertEqual(texts, ["int four;\n", "int unjudged;\n"])

    def test_stub_is_not_the_closest(self):
        store.put(0x100000, "int stub;\n", "cpp", report([("nop", "jr $ra")] * 2, original=2, same=0), "s1", "sonnet")
        store.put(0x100000, "int near;\n", "cpp", report([("nop", "sll $v0, $v0, 1")] * 3, original=40), "s1", "sonnet")
        with mock.patch.object(store, "true_length", return_value=40):
            first = store.drafts(closest=1)[0x100000]
        self.assertEqual(text_of(os.path.join(store.ROOT, first[0])), "int near;\n")

    def test_passes_and_match(self):
        row = store.put(0x100000, "int a;\n", "cpp", report([("nop", "sll $v0, $v0, 1")]), "s1", "sonnet")
        self.assertIsNone(store.mark_pass(0x100000, "0" * 16, "sweep", "v1"))  # not in the store
        store.mark_pass(0x100000, row["sha"], "sweep", "v1", "no profile matches")
        store.mark_pass(0x100000, row["sha"], "sweep", "v2", "closer: 0")
        self.assertEqual(store.attempts(0x100000)[row["sha"]]["passes"]["sweep"]["version"], "v2")
        m = store.matched(0x100000, "int done;\n", "s1", "sonnet")
        self.assertEqual((m["event"], m["parent"]), ("match", row["sha"]))
        self.assertIsNone(store.matched(0x100008, "int x;\n", "s1"))  # no attempt kept: no folder made
        self.assertEqual(store.functions(), ["00100000"])

    def test_export_import(self):
        a = store.put(0x100000, "int a;\n", "cpp", report([("nop", "sll $v0, $v0, 1")]), "s1", "sonnet")
        store.put(0x100008, "int b;\n", "c", "compile failed", "h1", "haiku")
        write(os.path.join(store.folder(0x100000), "stray.o"), "x")  # never exported
        archive = os.path.join(self.dir.name, "out.tar.gz")
        self.assertEqual(store.export(archive), (2, 4))
        with tarfile.open(archive) as tar:
            self.assertEqual(sorted(tar.getnames()), sorted([
                f"drafts/00100000/00100000_{a['sha']}.cpp", "drafts/00100000/log.jsonl",
                f"drafts/00100008/00100008_{store.digest('int b;' + chr(10))}.c", "drafts/00100008/log.jsonl"]))
            evil = os.path.join(self.dir.name, "evil.tar.gz")
            with tarfile.open(evil, "w:gz") as out:
                for name, data in (("drafts/00100010/00100010_" + "0" * 16 + ".cpp", b"wrong hash"),
                                   ("../escape.cpp", b"x"), ("drafts/00100010/note.txt", b"x"),
                                   ("drafts/00100010/log.jsonl", b'{"event": "try", "sha": "x"}\nnot json\n')):
                    info = tarfile.TarInfo(name)
                    info.size = len(data)
                    out.addfile(info, io.BytesIO(data))
        with mock.patch.object(store, "STORE", os.path.join(self.dir.name, "second")):
            self.assertEqual(store.import_(archive), (2, 2, 0))
            self.assertEqual(store.import_(archive), (0, 0, 0))  # merging twice changes nothing
            self.assertEqual(store.attempts(0x100000)[a["sha"]]["class"], "other")
            self.assertEqual(store.import_(evil), (0, 1, 3))
            self.assertFalse(os.path.exists(os.path.join(self.dir.name, "escape.cpp")))


if __name__ == "__main__":
    unittest.main()
