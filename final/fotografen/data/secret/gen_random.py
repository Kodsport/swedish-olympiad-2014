import sys
import random

# maxN - length
# ratio
# seed - random seed

inputs = sys.stdin.readline().strip().split()

N = int(inputs[0])
ratio = float(inputs[1])
seed = int(inputs[2])

rotations = ['U', 'H', 'N', 'V']
random.seed(seed)

# vary N a bit
N -= random.randrange(N / 5)
k = max(1,int(ratio * N))

offsets = [0] * N

print N, k

for i in xrange(N):
    sys.stdout.write(rotations[random.randrange(4)])
print ""
