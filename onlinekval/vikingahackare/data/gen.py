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

n = int(cmdlinearg('n'))
t = int(cmdlinearg('t'))
random.seed(int(cmdlinearg('seed')))


keys = [chr(i) for i in range(ord('a'), ord('z')+1)]
keys.extend(chr(i) for i in range(ord('A'), ord('Z')+1))
keys.extend(chr(i) for i in range(ord('0'), ord('9')+1))

bins = []
for i in range(16):
    s = bin(i)[2:]
    bins.append("0"*(4-len(s))+s)
binsleft = [i for i in bins]

print(t)
for i in range(t):
    chosenbin = random.choice(binsleft)
    chosenkey = random.choice(keys)
    print(chosenkey, chosenbin)
    keys.remove(chosenkey)
    binsleft.remove(chosenbin)

for i in range(n):
    print(random.choice(bins),end="")
print("")