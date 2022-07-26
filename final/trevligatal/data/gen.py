#!/usr/bin/python3

import sys
import random

# N - length
# seed - random seed


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


N = int(cmdlinearg('n'))
seed = int(cmdlinearg('seed'))

random.seed(seed)

x = random.randrange(1,10)
sys.stdout.write("%d" % x)

for i in range(N-1):
    x = random.randrange(10)
    sys.stdout.write("%d" % x)
print("")
