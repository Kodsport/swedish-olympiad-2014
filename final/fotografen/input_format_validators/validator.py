#/usr/bin/env python

import re
import sys

line1_re = "^[1-9][0-9]* [1-9][0-9]*$"
line2_re = "^[UNVH]+$"

line = sys.stdin.readline()
assert re.match(line1_re, line)

N, k = map(int, line.strip().split())

assert 1 <= N <= 100000
assert 1 <= k <= N

line = sys.stdin.readline()
assert re.match(line2_re, line)

assert len(line) == N+1

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
