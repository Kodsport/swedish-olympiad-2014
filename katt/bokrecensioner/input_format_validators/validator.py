#/usr/bin/env python

import re
import sys

first_re = "^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*$"
relation_re = "^[1-9][0-9]* (<|=|<=) [1-9][0-9]*$"

line = sys.stdin.readline()
assert re.match(first_re, line)

N, M, R = map(int, line.split())

assert 1 <= N <= 100000
assert 1 <= M <= 100000
assert 1 <= R <= 500000

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


allowed = cmdlinearg('allowed')
if allowed=='less': allowed_relations=['<'] 
if allowed=='equal_and_less': allowed_relations=['<','='] 
if allowed=='all': allowed_relations=['<','=','<='] 

seen = set()

for _ in range(R):
    line = sys.stdin.readline()
    assert re.match(relation_re, line)
    i, r, j = line.split()
    i, j = int(i), int(j)
    t = (min(i,j), max(i,j))
    assert t not in seen
    seen.add(t)
    assert i != j
    assert 1 <= i <= N
    assert 1 <= j <= N
    assert r in allowed_relations

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
