"""Synthetic controls for the deliberately narrow ROM comparison."""
import struct
import unittest

from compare_library_overlap import address_mask, canonical_extent


def pack(*values):
    return struct.pack(f">{len(values)}I", *values)


class OverlapTests(unittest.TestCase):
    def test_return_delay_preserved(self):
        self.assertEqual(canonical_extent(pack(0x03E00008, 0, 0, 0)),
                         pack(0x03E00008, 0))

    def test_nonterminal_zeros_preserved(self):
        data = pack(0x24020001, 0, 0)
        self.assertEqual(canonical_extent(data), data)

    def test_call_address_only(self):
        self.assertEqual(address_mask(pack(0x0C001234))[0], pack(0x0C000000))
        self.assertNotEqual(address_mask(pack(0x08001234))[0],
                            address_mask(pack(0x0C001234))[0])

    def test_absolute_pair(self):
        self.assertEqual(address_mask(pack(0x3C088001, 0x25081234))[0],
                         address_mask(pack(0x3C088002, 0x25085678))[0])

    def test_nonaddress_constant_survives(self):
        data = pack(0x3C081234, 0x25085678)
        self.assertEqual(address_mask(data)[0], data)

    def test_register_and_stack_survive(self):
        self.assertNotEqual(address_mask(pack(0x3C088001, 0x25081234))[0],
                            address_mask(pack(0x3C098001, 0x25291234))[0])
        data = pack(0x8FA20010, 0x10400004)
        self.assertEqual(address_mask(data)[0], data)

    def test_nonadjacent_pair_not_masked(self):
        data = pack(0x3C088001, 0, 0x25081234)
        self.assertEqual(address_mask(data)[0], data)

    def test_wrong_base_not_masked(self):
        data = pack(0x3C088001, 0x25291234)
        self.assertEqual(address_mask(data)[0], data)

    def test_branch_displacement_preserved(self):
        self.assertNotEqual(address_mask(pack(0x10400004))[0],
                            address_mask(pack(0x10400005))[0])

    def test_nonzero_after_return_not_trimmed(self):
        data = pack(0x03E00008, 0, 0x24020001, 0)
        self.assertEqual(canonical_extent(data), data)


if __name__ == "__main__":
    unittest.main()
