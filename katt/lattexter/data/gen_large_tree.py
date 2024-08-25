from __future__ import division
import math
import string
import sys
import random

inputs = sys.stdin.readline().strip().split()

lim = int(1e18)

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

N = int(cmdlinearg('n'))
Q = int(cmdlinearg('q'))
random.seed(int(cmdlinearg('seed')))
F = 0.2

print(str(N) + ' ' + str(Q))
lens = []
not_huge = [0]
for i in range(N):
    if i == 0:
        s = 'abcdefghij'
        print('0 ' + s)
        lens.append(len(s))
    else:
        first = 0
        second = 0
        while True:
            first = random.choice(not_huge)
            second = i - 1
            if random.choice([True, False]):
                first, second = second, first
            if lens[first] < lim:
                break

        print(str(first+1) + ' ' + str(second+1))
        l = lens[first] + lens[second]
        if l < lim:
            not_huge.append(i)
        lens.append(l)

last_len = lens[-1]
sys.stderr.write('length ' + str(last_len) + ', log10 = ' + str(math.log10(last_len)) + '\n')

for i in range(Q):
    ind = random.randrange(min(last_len, int(1e18)))
    print(ind+1)
