import sys

l = sys.stdin.readline().split()
N = int(l[0])/6

sys.stdout.write("abc")
for i in xrange(N):
    sys.stdout.write("lo")
sys.stdout.write("ldef\n")

sys.stdout.write("abobc")
for i in xrange(2*N+1):
    sys.stdout.write("lo")
sys.stdout.write("ldef\n")
