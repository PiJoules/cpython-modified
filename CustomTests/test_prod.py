#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
The custom function, prod(), should be available in the builtin namespace,
meaning I will be able to use this function without having to import anything
just like sum(), abs(), map(), etc.
"""

assert prod(range(1, 6)) == 120
assert prod([]) == 1  # Default start is 1
assert prod(range(5)) == 0  # 0 is included
assert prod(range(-3, 4, 2)) == 9
assert prod(range(-5, 4, 2)) == -45
assert prod((1, 2), 10) == 20  # New start, also tuple
assert prod([2, 2**64]) == 2**65  # Test very large numbers

