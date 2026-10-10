#!/usr/bin/env python3
"""Regression and input-backed invariants for fragment CPU-section mapping."""
import json
from pathlib import Path
import struct
import unittest

from map_fragment_sections import load_image, map_image, relocations, word


def fixture(words, records=(), entry=0x20):
    """Create a small synthetic fragment; never contains retail ROM bytes."""
    end = 0x20 + len(words) * 4
    image = bytearray(end + 4 + len(records) * 4)
    struct.pack_into(">8I", image, 0, 0x08400000 | (entry >> 2), 0,
                     0x46524147, 0x4D454E54, 0x20, end, len(image), end)
    for index, value in enumerate(words):
        struct.pack_into(">I", image, 0x20 + index * 4, value)
    struct.pack_into(">I", image, end, len(records))
    for index, (kind, position) in enumerate(records):
        struct.pack_into(">I", image, end + 4 + index * 4, kind << 24 | position)
    return bytes(image), {
        "link_base": "0x81000000", "entry_offset": hex(entry),
        "rom_start": "0x100000", "storage": "raw", "decoded_sha256": "synthetic",
    }


class SyntheticTests(unittest.TestCase):
    def test_header_nops_are_not_code(self):
        image, metadata = fixture([0] * 16)
        self.assertEqual(map_image(image, metadata)["instruction_bytes"], 0)

    def test_valid_texture_words_are_not_code(self):
        image, metadata = fixture([0xDE31DE31, 0xD62FD5ED] * 32)
        self.assertEqual(map_image(image, metadata)["instruction_bytes"], 0)

    def test_leaf_stack_entry(self):
        image, metadata = fixture([0x27BDFFE0, 0x27BD0020, 0x03E00008, 0])
        report = map_image(image, metadata)
        self.assertEqual(report["instruction_ranges"], [["0x20", "0x30"]])
        self.assertFalse(report["rejected"])

    def test_delay_relocation_does_not_fall_into_data(self):
        image, metadata = fixture(
            [0x03E00008, 0x24420000, 0xDE31DE31, 0xDE31DE31], [(6, 0x24)])
        report = map_image(image, metadata)
        self.assertEqual(report["instruction_ranges"], [["0x20", "0x28"]])
        self.assertFalse(report["rejected"])

    def test_data_pointer_is_not_code_seed(self):
        image, metadata = fixture([0x81000024, 0, 0, 0], [(2, 0x20)])
        report = map_image(image, metadata)
        self.assertEqual(report["instruction_bytes"], 0)
        self.assertFalse(report["data_pointer_targets_not_traversed"][0]["already_code"])


class InputBackedTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        root = Path(__file__).resolve().parents[1]
        rom_path = root / "baseroms/jp/baserom.z64"
        manifest_path = root / "docs/mappings/resident-fragments.json"
        if not rom_path.exists() or not manifest_path.exists():
            raise unittest.SkipTest("private input ROM and mapping manifest required")
        cls.rom = rom_path.read_bytes()
        cls.metadata = json.loads(manifest_path.read_text())["fragments"]
        cls.images = [load_image(cls.rom, item) for item in cls.metadata]
        cls.reports = [map_image(image, item)
                       for image, item in zip(cls.images, cls.metadata)]

    def test_all_image_partitions_are_exact(self):
        for image, report in zip(self.images, self.reports):
            position = 0
            for section in report["sections"]:
                self.assertEqual(int(section["start"], 0), position)
                position = int(section["end"], 0)
                self.assertGreater(position, int(section["start"], 0))
            self.assertEqual(position, len(image))

    def test_instruction_relocations_are_covered(self):
        for image, report in zip(self.images, self.reports):
            code = {position for start, end in report["instruction_ranges"]
                    for position in range(int(start, 0), int(end, 0), 4)}
            for kind, position in relocations(image):
                if kind in (4, 5, 6) and position >= 0x20:
                    self.assertIn(position, code)
            self.assertFalse(report["rejected"])
            self.assertFalse(report["invalid_words_in_envelope_gaps"])
            self.assertFalse(report["data_relocation_sites_in_envelope"])

    def test_code_and_noncode_inventory(self):
        self.assertEqual(len(self.reports), 259)
        self.assertEqual(sum(bool(report["instruction_bytes"])
                             for report in self.reports), 187)
        for index in range(106, 259):
            self.assertEqual(self.reports[index]["instruction_ranges"],
                             [["0x20", "0x3C"]])
        self.assertEqual(self.reports[0]["text_envelope"], ["0x20", "0x1C4E8"])
        for index in [26, 27, 28, 29, 35, 36, 37, 41, 42, *range(43, 106)]:
            self.assertEqual(self.reports[index]["instruction_bytes"], 0)


if __name__ == "__main__":
    unittest.main(verbosity=2)
