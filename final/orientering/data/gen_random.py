#!/usr/bin/python3

import sys
import random

# N hojd
# M bredd
# seed


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
M = int(cmdlinearg('m'))

values = ['^', '>', 'v', '<'] + (random.randint(0, 8) * ['.'])

# vary N and M a bit
N -= random.randint(0, 5)
M -= random.randint(0, 5)

# We dont know if this is reachable or not, but hopefully it is.
# Otherwise validator will find out! :)
R = random.randint(1, N)
C = random.randint(1, M)


print(N, M, R, C)

for i in range(N):
    print(''.join([random.choice(values) for _ignore in range(M)]))
