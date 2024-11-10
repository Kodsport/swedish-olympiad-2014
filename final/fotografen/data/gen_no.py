#!/usr/bin/python3

import sys
import random

# maxN - length
# ratio
# seed - random seed

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


seed = int(cmdlinearg('seed', sys.argv[-1]))
N = int(cmdlinearg('n'))
ratio = float(cmdlinearg('ratio'))

rotations = ['U', 'H', 'N', 'V']

# vary N a bit
if random.randrange(10) < 5:
    N -= random.randrange(N // 2)
k = max(1,int(ratio * N))

offsets = [0] * N
sweep = [0] * N

print(N, k)

for i in range(N-k+2):
    offsets[i] = random.randrange(4)
    if offsets[i] == 0:
        offsets[i] = 1

cur = 0
for i in range(N):
    cur += offsets[i]
    cur += sweep[i]
    if i + k < N:
        sweep[i+k] = 4-offsets[i]
    cur %= 4
    sys.stdout.write(rotations[cur])

print("")
