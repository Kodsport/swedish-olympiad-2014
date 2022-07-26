#!/usr/bin/python3

import sys
import random

# N - number of persons
# amplitude - max coordinate amplitude
# fraction - fraction of people who will make it (roughly)
# seed - random seed

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


random.seed(int(cmdlinearg('seed')))
N = int(cmdlinearg('n'))
amplitude = int(cmdlinearg('amplitude'))
fraction = float(cmdlinearg('fraction'))

coords = []
S = 0
for i in range(N):
    x = random.randrange(-amplitude, amplitude)
    y = random.randrange(-amplitude, amplitude)
    coords.append((x,y))
    S = S + abs(x) + abs(y)

print(N, min(int(2*S * fraction), 10**9))

for c in coords:
    print(c[0], c[1])
