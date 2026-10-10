#!/usr/bin/env python3
"""Synthetic safety regressions and restored-image resolution invariants."""
import json
from pathlib import Path
import unittest

from map_fragment_sections import load_image, map_image, relocations, word
from resolve_fragment_flow import (code_words, inspected_links, reaches_clean,
                                   standard_switch, structural_check)
from test_fragment_sections import fixture


def switch_fixture(pointer_relocations=True, bound=2):
    # compare; guard; shift delay; high; index addition; pointer load; jr; nop;
    # two return targets; two relocated table pointers.
    words = [0x2C810000 | bound, 0x10200008, 0x00044880, 0x3C018100,
             0x00290821, 0x8C290050, 0x01200008, 0,
             0x03E00008, 0, 0x03E00008, 0, 0x81000040, 0x81000048]
    records = [(2, 0x50), (2, 0x54)] if pointer_relocations else []
    return fixture(words, records)


class SyntheticFlowTests(unittest.TestCase):
    def test_nonstandard_link_register_is_not_a_return(self):
        image, metadata = fixture([0x27BDFFE0, 0x03E0A809, 0, 0x03E00008, 0])
        self.assertEqual(map_image(image, metadata)["unresolved_indirect_jumps"], ["0x24"])

    def test_guarded_table_resolution(self):
        image, metadata = switch_fixture()
        result = standard_switch(image, metadata, 0x38, 0x50)
        self.assertEqual(result["targets"], ["0x40", "0x48"])
        self.assertEqual(result["guard"]["entry_count"], 2)

    def test_unrelocated_table_is_not_promoted(self):
        image, metadata = switch_fixture(False)
        self.assertIsNone(standard_switch(image, metadata, 0x38, 0x50))

    def test_table_bound_cannot_overrun_storage(self):
        image, metadata = switch_fixture(bound=32)
        self.assertIsNone(standard_switch(image, metadata, 0x38, 0x50))

    def test_delay_slot_arrival_retains_definition(self):
        image, _ = fixture([0x10200002, 0x00044880, 0, 0])
        self.assertTrue(reaches_clean(image, 0x20, 0x24, 4))

    def test_overwritten_definition_is_rejected(self):
        image, _ = fixture([0x24010002, 0, 0])
        self.assertFalse(reaches_clean(image, 0x20, 0x28, 1))

    def test_bypassed_writer_does_not_destroy_definition(self):
        image, _ = fixture([0x10000002, 0, 0x24010002, 0])
        self.assertTrue(reaches_clean(image, 0x20, 0x2C, 1))

    def test_branch_likely_annuls_fallthrough_delay_write(self):
        # Taken path leaves the inspected interval; untaken path skips delay.
        image, _ = fixture([0x50800004, 0x24010002, 0, 0])
        self.assertTrue(reaches_clean(image, 0x20, 0x28, 1))

    def test_structural_failure_does_not_claim_execution(self):
        image, metadata = fixture([0xFFFFFFFF, 0x10007FFF, 0])
        result = structural_check(image, metadata, 0x20, 0x28, 0x2C)
        self.assertEqual(result["status"], "failed")


class InputFlowTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.root = Path(__file__).resolve().parents[1]
        rom_path = cls.root / "baseroms/jp/baserom.z64"
        output_path = cls.root / "docs/sections/refined"
        if not rom_path.exists() or not (output_path / "flow-validation.json").exists():
            raise unittest.SkipTest("private ROM and freshly generated refinement required")
        cls.metadata = json.loads((cls.root / "docs/mappings/resident-fragments.json").read_text())["fragments"]
        rom = rom_path.read_bytes()
        cls.images = [load_image(rom, metadata) for metadata in cls.metadata]
        cls.flow = json.loads((output_path / "flow-validation.json").read_text())
        cls.sections = json.loads((output_path / "fragment-sections.json").read_text())

    def test_every_resolved_table_word_is_relocated_and_traversed(self):
        for index, detail in enumerate(self.flow["images"]):
            image = self.images[index]
            pointers = {p for kind, p in relocations(image) if kind == 2}
            code = code_words(self.sections["images"][index])
            for transfer in detail["transfers"]:
                if transfer["status"] not in ("resolved_static_bounded_table",
                                               "resolved_inspected_masked_table"):
                    continue
                start, stop = int(transfer["table_start"], 0), int(transfer["table_end"], 0)
                self.assertEqual(stop - start, 4 * len(transfer["targets"]))
                for position, target in zip(range(start, stop, 4), transfer["targets"]):
                    self.assertIn(position, pointers)
                    self.assertEqual(word(image, position),
                                     int(self.metadata[index]["link_base"], 0) + int(target, 0))
                    self.assertIn(int(target, 0), code)

    def test_coroutine_sets_include_resume_pcs(self):
        image, metadata = self.images[0], self.metadata[0]
        converter = inspected_links(image, metadata, 0x18594)
        self.assertEqual(len(converter["targets"]), 16)
        self.assertIn("0x182c8", converter["targets"])
        unpacker = inspected_links(image, metadata, 0x1BF0C)
        self.assertEqual(unpacker["targets"], ["0x1bf34", "0x1bf44", "0x1bf50", "0x1bf5c"])

    def test_gap_ledger_exactly_accounts_for_original_candidates(self):
        summary = self.flow["summary"]
        self.assertEqual(sum(summary["gap_bytes"].values()), 76484)
        self.assertEqual(summary["remaining_gap_structural_failures"], 0)
        self.assertEqual(summary["rejected_paths"], 0)

    def test_refined_partitions_cover_every_restored_byte(self):
        for image, report in zip(self.images, self.sections["images"]):
            position = 0
            for section in report["sections"]:
                self.assertEqual(int(section["start"], 0), position)
                position = int(section["end"], 0)
            self.assertEqual(position, len(image))

    def test_runtime_initializer_sets_are_not_reported_as_resolved(self):
        for index, detail in enumerate(self.flow["images"]):
            unresolved = self.sections["images"][index]["unresolved_indirect_jumps"]
            for transfer in detail["transfers"]:
                if "runtime_unresolved" in transfer["status"]:
                    self.assertIn(transfer["site"], unresolved)


if __name__ == "__main__":
    unittest.main(verbosity=2)
