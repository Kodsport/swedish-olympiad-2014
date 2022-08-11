#!/usr/bin/env python3
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

collide = int(cmdlinearg("collide"))
random.seed(int(cmdlinearg('seed')))

if not collide:
    while True:
        a,b=random.randint(1,1439),random.randint(1,1439)
        if a==b: continue
        works = True
        for i in range(1, 1440):
            if i%a==0 and i%b==0:
                works = False
                
        if works:
            print(min(a,b),max(a,b))
            break
else:
    while True:
        a,b=random.randint(1,1439),random.randint(1,1439)
        if a==b: continue
        print(min(a,b),max(a,b))
        break