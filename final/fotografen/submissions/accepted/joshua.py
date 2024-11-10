#!/usr/bin/env python3
# C++ -> Python using chatgpt

dist = [3, 2, 1, 0]
char_to_dist = {'H': 3, 'N': 2, 'V': 1, 'U': 0}
next_rot = {'H': 'N', 'N': 'V', 'V': 'U', 'U': 'H'}
next_n = {}

for c in next_rot:
    next_n[c] = [None] * 4
    curr = c
    for i in range(4):
        next_n[c][i] = curr
        curr = next_rot[curr]

n, k = map(int, input().split())
photos = input()

ans = 0
extra_rotations = 0
rotation_loss = [0] * n

for i in range(n - 1, -1, -1):
    extra_rotations -= rotation_loss[i]
    n_rotations = char_to_dist[next_n[photos[i]][extra_rotations % 4]]

    if i < k - 1 and n_rotations != 0:
        print(-1)
        exit(0)

    extra_rotations += n_rotations
    if i - k >= 0:
        rotation_loss[i - k] = n_rotations
    
    ans += n_rotations

print(ans)
