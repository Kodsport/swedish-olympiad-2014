#!/usr/bin/python3

import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print(("missing parameter", name))
        exit(1)
    return default

max_product = int(cmdlinearg('product_max'))
h_one = int(cmdlinearg('h_one'))


split = sys.stdin.readline().split()
assert len(split) == 2
w = int(split[0])
h = int(split[1])
b = 0
s = 0
u = 0
assert w*h<=max_product
if h_one:
    assert h==1
for i in range(h):
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
