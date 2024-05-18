
from sys import stdin
trans = dict([tuple(stdin.readline().split()[::-1]) for i in range(int(stdin.readline()))])
line = stdin.readline().strip()
print "".join([trans.get(line[i:i+4], "?") for i in range(0, len(line), 4)])
