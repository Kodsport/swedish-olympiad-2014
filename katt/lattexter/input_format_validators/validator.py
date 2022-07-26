#/usr/bin/env python

import re
import sys

re_num = re.compile("^[1-9][0-9]*$")
re_def = re.compile("^(?:0 [a-z]{1,10}|[1-9][0-9]* [1-9][0-9]*)$")

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*$", line)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

max_n = int(cmdlinearg('max_n'))
max_q = int(cmdlinearg('max_q'))
small = bool(int(cmdlinearg('small')))

N, Q = map(int, line.split())

assert 1 <= N <= max_n
assert 1 <= Q <= max_q

lens = []
for i in range(N):
    line = sys.stdin.readline()
    assert re_def.match(line)
    parts = line.split()
    a = int(parts[0])
    if a == 0:
        s = parts[1]
        lens.append(len(s))
    else:
        b = int(parts[1])
        assert 1 <= a <= i
        assert 1 <= b <= i
        lens.append(lens[a-1] + lens[b-1])

if small:
    assert lens[-1] <= int(1e18)
final_len = min(lens[-1], int(1e18))


for i in range(Q):
    line = sys.stdin.readline()
    assert re_num.match(line)
    n = int(line)
    assert 1 <= n <= final_len

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)

