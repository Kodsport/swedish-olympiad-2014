import sys
import random

# N - length
# seed - random seed

inputs = sys.stdin.readline().strip().split()

N = int(inputs[0])
seed = int(inputs[1])

random.seed(seed)
for i in xrange(N):
    x = random.randrange(10)
    sys.stdout.write("%d" % x)
print ""
