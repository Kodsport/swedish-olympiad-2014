#!/usr/bin/python3

import sys
import random



def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


case = int(cmdlinearg('case'))

if   case == 1: n=50000; h=1000; print(n, h); print("\n".join(map(lambda x: "L {} 500".format(int((1+x)*(h/2))), range(n))))
elif case == 2: n=50000; h=1000; print(n, h); print("\n".join(map(lambda x: "L {} 500".format((1+x)*2), range(n))))
elif case == 3: n=50000; h=1000; print(n, h); print("\n".join(map(lambda x: "L {} 2".format((1+x)*400), range(n))))
elif case == 4: n=50000; h=1000; print(n, h); print("\n".join(map(lambda x: "L {} 999".format((1+x)*400), range(n))))