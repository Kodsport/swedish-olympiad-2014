#!/usr/bin/python3
import sys
N = int(sys.stdin.readline())
channels = [[] for _ in range(1440)]
for i in range(N):
    l = sys.stdin.readline()
    ls = l.split();
    for j in range(1,len(ls)):
        interval = ls[j]
        t1, t2 = interval.split('-')
        sh,sm = list(map(int,t1.split(':')))
        eh,em = list(map(int,t2.split(':')))
        channels[i].append((sh*60+sm, eh*60+em))
cur = 0
res = [0]*N
for t in range(1440):
    ad = False
    for c in channels[cur]:
        if t <= c[1] and t >= c[0]:
            ad = True
            break
    if ad:
        cur = (cur + 1) % N
    else:
        res[cur] += 1

for x in res:
    print(x)
