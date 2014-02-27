#/usr/bin/env python
import re
import sys
int_re = "^(0|\-?[1-9][0-9]*)$"
two_ints_re = "^(0|\-?[1-9][0-9]*) (0|\-?[1-9][0-9]*)$"

line = sys.stdin.readline()
words = line.split()
assert re.match(two_ints_re, line)

N, T = map(int, words)

assert 1 <= N <= 100000
assert 1 <= T <= 10**9

for i in xrange(N):
    l = sys.stdin.readline()
    assert re.match(two_ints_re, l)
    x, y = map(int, l.split())
    assert -10**8 <= x <= 10**8
    assert -10**8 <= y <= 10**8

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
