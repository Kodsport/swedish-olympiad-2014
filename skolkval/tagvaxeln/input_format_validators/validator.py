#/usr/bin/env python

import re
import sys

int_pat = "(0|[1-9][0-9]*)"
input_re = "^" + int_pat + " " + int_pat + "$"

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

no_collide = int(cmdlinearg("no_collision"))

line = sys.stdin.readline()
assert re.match(input_re, line)
a, b = [int(x) for x in line.split()]

if no_collide:
    for i in range(1,1440):
        assert(not (i%a==0 and i%b==0))

assert 1 <= a < 1440 and 1 <= b < 1440 and a < b
line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
