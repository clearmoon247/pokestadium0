#!/usr/bin/env python3
"""Check pragma ownership, conditional structure, scoped bytes and C syntax."""
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess
import unittest

from generate_pragmas import conditional, LISTING_WORD
from map_fragment_sections import load_image

ROOT = Path(__file__).resolve().parents[1]
PRAGMA = re.compile(r'#pragma GLOBAL_ASM\("([^"]+)"\)')


class TemplateTests(unittest.TestCase):
    def test_reference_conditional_direction(self):
        text = conditional("func_80000460", "asm/jp/nonmatchings/1060/func_80000460.s")
        self.assertTrue(text.startswith("#ifdef NON_MATCHING\n"))
        self.assertIn("#else\n#pragma GLOBAL_ASM", text)
        self.assertTrue(text.endswith("#endif\n"))
        self.assertNotIn("void func_", text)


class InventoryTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.inventory = json.loads((ROOT / "docs/pragma-inventory.json").read_text())

    def test_source_inventory_and_guards(self):
        count = 0
        for row in self.inventory["sources"]:
            data = (ROOT / row["source"]).read_bytes()
            self.assertEqual(hashlib.sha256(data).hexdigest(), row["source_sha256"])
            source = data.decode()
            pragmas = PRAGMA.findall(source)
            self.assertEqual(len(pragmas), row["pragma_count"])
            self.assertEqual(source.count("#ifdef NON_MATCHING"), len(pragmas))
            self.assertEqual(source.count("#else"), len(pragmas))
            self.assertEqual(source.count("#endif"), len(pragmas))
            for path in pragmas:
                self.assertTrue((ROOT / path).is_file())
            count += len(pragmas)
        self.assertEqual(count, self.inventory["summary"]["pragma_owners"])

    def test_global_symbol_names_are_unique(self):
        names = []
        for row in self.inventory["owners"]:
            names.extend([row["name"], *row["aliases"]])
        self.assertEqual(len(names), len(set(names)))

    def test_no_owners_for_resource_only_images(self):
        sections = json.loads((ROOT / "docs/sections/refined/fragment-sections.json").read_text())
        allowed = {row["image_index"] for row in sections["images"] if row["text_envelope"]}
        present = {row["image_index"] for row in self.inventory["owners"]
                   if row["image_index"] is not None}
        self.assertEqual(present, allowed)
        self.assertEqual(len(present), 187)

    def test_unresolved_transfers_do_not_block_owners(self):
        with (ROOT / "docs/sections/refined/runtime-watchlist.csv").open() as source:
            import csv
            sites = list(csv.DictReader(source))
        self.assertEqual(len(sites), 71)
        for site in sites:
            index, offset = int(site["image_index"]), int(site["offset"], 0)
            owners = [row for row in self.inventory["owners"]
                      if row["image_index"] == index
                      and int(row["start"], 0) <= offset < int(row["end"], 0)]
            self.assertEqual(len(owners), 1, site)

    def test_generated_c_syntax_in_both_modes(self):
        compiler = shutil.which("cc") or shutil.which("gcc")
        if compiler is None:
            self.skipTest("host C compiler unavailable")
        paths = [str(ROOT / row["source"]) for row in self.inventory["sources"]]
        for defines in ([], ["-DNON_MATCHING"]):
            subprocess.run([compiler, "-fsyntax-only", "-Wno-unknown-pragmas",
                            "-I", str(ROOT / "include"), *defines, *paths],
                           check=True, capture_output=True)
        sample = ROOT / self.inventory["sources"][0]["source"]
        ordinary = subprocess.run([compiler, "-E", "-P", "-I", str(ROOT / "include"),
                                   str(sample)], check=True, capture_output=True, text=True).stdout
        nonmatching = subprocess.run([compiler, "-E", "-P", "-DNON_MATCHING",
                                     "-I", str(ROOT / "include"), str(sample)],
                                    check=True, capture_output=True, text=True).stdout
        self.assertTrue(PRAGMA.findall(ordinary))
        self.assertFalse(PRAGMA.findall(nonmatching))

    def test_owner_ranges_and_listing_bytes_match_private_input(self):
        rom_path = ROOT / "baseroms/jp/baserom.z64"
        if not rom_path.exists():
            self.skipTest("private input ROM unavailable")
        rom = rom_path.read_bytes()
        mapping = json.loads((ROOT / "docs/mappings/resident-fragments.json").read_text())
        sections = json.loads((ROOT / "docs/sections/refined/fragment-sections.json").read_text())
        images = {}
        for row in self.inventory["owners"]:
            start, stop = int(row["start"], 0), int(row["end"], 0)
            index = row["image_index"]
            if index is None:
                self.assertGreaterEqual(start, 0x1060)
                self.assertLessEqual(stop, 0x5D8C0)
                raw = rom[start:stop]
                for excluded in self.inventory["excluded_ranges"]:
                    if excluded["image"] == "resident":
                        self.assertFalse(start < int(excluded["end"], 0)
                                         and stop > int(excluded["start"], 0))
            else:
                if index not in images:
                    images[index] = load_image(rom, mapping["fragments"][index])
                self.assertGreaterEqual(start, 0x20)
                self.assertLessEqual(stop, int(sections["images"][index]["text_envelope"][1], 0))
                raw = images[index][start:stop]
            self.assertEqual(hashlib.sha256(raw).hexdigest(), row["input_sha256"])
            data = (ROOT / row["assembly"]).read_bytes()
            self.assertEqual(hashlib.sha256(data).hexdigest(), row["assembly_sha256"])
            listed = b"".join(int(value, 16).to_bytes(4, "big")
                              for value in LISTING_WORD.findall(data.decode()))
            self.assertEqual(listed, raw)


if __name__ == "__main__":
    unittest.main(verbosity=2)
