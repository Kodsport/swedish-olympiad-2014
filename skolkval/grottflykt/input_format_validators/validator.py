#/usr/bin/env python

import sys

split = sys.stdin.readline().split()
assert len(split) == 2
w = int(split[0])
h = int(split[1])
b = 0
s = 0
u = 0
for i in xrange(h):
    line = sys.stdin.readline().strip()
    assert len(line) == w
    for ch in line:
        if ch == 'B':
            b += 1
        elif ch == 'S':
            s += 1
        elif ch == 'U':
            u += 1
        else:
            assert ch in '.#'
line = sys.stdin.readline()
assert len(line) == 0
assert b == 1 and s == 1 and u == 1
exit(42)
