#!/usr/bin/env python

import sys

x, n = map(int, sys.stdin.readline().split())
assert 5 <= x and x <= 100
assert n <= 20
items = map(int, sys.stdin.readline().split())
assert len(items) == n

for h in items:
    assert (2 <= h and h <= 100)

exit(42)
