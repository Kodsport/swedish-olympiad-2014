#/usr/bin/env python
import re
import sys
int_re = "^(0|\-?[1-9][0-9]*)$"
two_ints_re = "^(0|\-?[1-9][0-9]*) (0|\-?[1-9][0-9]*)$"

line = sys.stdin.readline()
words = line.split()
assert re.match(two_ints_re, line)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


max_n = int(cmdlinearg('max_n'))
max_coord = int(cmdlinearg('max_coord'))

N, T = map(int, words)

assert 1 <= N <= max_n
assert 1 <= T <= 10**9

for i in xrange(N):
    l = sys.stdin.readline()
    assert re.match(two_ints_re, l)
    x, y = map(int, l.split())
    assert -max_coord <= x <= max_coord
    assert -max_coord <= y <= max_coord

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
