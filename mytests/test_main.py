#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Main python unit test module.
"""

import unittest


class MainTestCase(unittest.TestCase):
    """Main test case class."""

    def test_print(self):
        """Just print something without running into any errors."""
        print("ayy lmao")


if __name__ == "__main__":
    unittest.main()

