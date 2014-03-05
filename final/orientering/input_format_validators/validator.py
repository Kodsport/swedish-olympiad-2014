#/usr/bin/env python

import re
import sys

line1_re = "^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]* [1-9][0-9]*$"
rest_lines_re = "^[\.\^\<\>v]+$"

line = sys.stdin.readline()
assert re.match(line1_re, line)

h, b, y_dest, x_dest = map(int, line.strip().split())

assert 1 <= h <= 2000
assert 1 <= b <= 2000
assert 1 <= y_dest <= h
assert 1 <= x_dest <= b

for i in xrange(h):
    line = sys.stdin.readline().strip()
    assert re.match(rest_lines_re, line)
    assert len(line) == b

line = sys.stdin.readline()
assert len(line) == 0

# TODO: Check that the problem is solveable

sys.exit(42)
