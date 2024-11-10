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
N -= random.randrange(N // 2)
k = max(1,int(ratio * N))

offsets = [0] * N

print(N, k)

for i in range(N):
    sys.stdout.write(rotations[random.randrange(4)])
print("")
