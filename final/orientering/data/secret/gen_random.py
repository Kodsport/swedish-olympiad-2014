import sys
import random

# N hojd
# M bredd
# seed

inp = sys.stdin.readline().strip().split()
N, M, seed = map(int, inp)

values = ['^', '>', 'v', '<'] + (5 * ['.'])
random.seed(seed)

# vary N and M a bit
N -= random.randint(0, 5)
M -= random.randint(0, 5)

# We dont know if this is reachable or not, but hopefully it is.
# Otherwise validator will find out! :)
R = random.randint(1, N)
C = random.randint(1, M)


def random_square(_ignore):
    return random.choice(values)

print N, M, R, C

for i in xrange(N):
    print ''.join(map(random_square, range(M)))
