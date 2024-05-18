#!/usr/bin/python3
import sys

N, T = list(map(int, sys.stdin.readline().split()))

coords = []
marked = []

for i in range(N):
    x, y = list(map(int, sys.stdin.readline().split()))
    coords.append((x, y))
    marked.append(False)

elapsed = 0
ans = 0

while True:
    best = 10**9
    chosen = -1
    for i in range(N):
        if not marked[i]:
            dist = 2*(abs(coords[i][0]) + abs(coords[i][1]))
            if dist < best:
                best = dist
                chosen = i
                print(("cur best is", chosen, "with dist", best))
    if chosen == -1:
        break
    if elapsed + best <= T:
        elapsed += best
        marked[chosen] = True
        print(("chose ", chosen))
        ans += 1
    else:
        break

print(ans)


