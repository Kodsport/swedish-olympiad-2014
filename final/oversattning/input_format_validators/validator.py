#/usr/bin/env python3
import re
import sys

input_re1 = "^[1-9][0-9]*$"
input_re2 = "^[a-z]+ [a-z]+$"
input_re3 = "^[a-z]+$"

line = sys.stdin.readline()
assert re.match(input_re1, line)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print(("missing parameter", name))
        exit(1)
    return default


max_n = int(cmdlinearg('max_n'))
max_m = int(cmdlinearg('max_m'))


N = int(line)

assert 1 <= N <= max_n

words = {}

for i in range(N):
    line = sys.stdin.readline()
    assert re.match(input_re2, line)
    w1, w2 = line.split()
    words[w1] = w2
    assert 1 <= len(w1) <= 20
    assert 1 <= len(w2) <= 20

line = sys.stdin.readline()
assert re.match(input_re1, line)
M = int(line)

assert 1 <= M <= max_m

line = sys.stdin.readline()
wordlist = line.split()

assert len(wordlist) == M

for i in range(len(wordlist)):
    w = wordlist[i]
    assert re.match(input_re3, w)
    assert 1 <= len(w) <= 20
    assert w in words

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
