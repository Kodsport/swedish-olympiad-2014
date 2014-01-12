#!/usr/bin/env python

import sys

class Cave:
    UP = 0
    RIGHT = 1
    DOWN = 2
    LEFT = 3

    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]

    def __init__(self, grid):
        self.w = len(grid[0])
        self.h = len(grid)
        self.grid = grid
        self.s = [0, 0]
        self.b = [0, 0]
        for i in xrange(self.h):
            for j in xrange(self.w):
                if self.grid[i][j] == 'B':
                    self.b[0] = i
                    self.b[1] = j
                    self.grid[i][j] = '.'
                elif self.grid[i][j] == 'S':
                    self.s[0] = i
                    self.s[1] = j
                    self.grid[i][j] = '.'

    def is_won(self):
        return self.grid[self.s[0]][self.s[1]] == 'U'

    def is_lost(self):
        return not self.is_won() and self.s[0] == self.b[0] and self.s[1] == self.b[1]

    def move(self, d):
        if not self.move_dir(self.s, d):
            return
        # Move bear
        left = 2
        for d1 in [1, 3, 0, 2]:
            while left:
                if (abs(self.s[0] - self.b[0]) > abs(self.s[0] - self.b[0] - Cave.dr[d1]) or abs(self.s[1] - self.b[1]) > abs(self.s[1] - self.b[1] - Cave.dc[d1])) and self.move_dir(self.b, d1):
                    left -= 1
                else:
                    break

    def move_dir(self, pos, d):
        nr = pos[0] + Cave.dr[d]
        nc = pos[1] + Cave.dc[d]
        if self.on_grid(nr, nc) and self.grid[nr][nc] != '#':
            pos[0] = nr
            pos[1] = nc
            return 1
        else:
            return 0

    def on_grid(self, r, c):
        return r >= 0 and r < self.h and c >= 0 and c < self.w

    @staticmethod
    def parse(f):
        split = f.readline().split()
        w = int(split[0])
        h = int(split[1])
        grid = []
        for i in xrange(h):
            grid.append(list(f.readline().strip()))
        return Cave(grid)


f = open(sys.argv[1], 'r')
cave_instance = Cave.parse(f)
f.close()

answer = sys.stdin.readline().strip()
for ch in answer:
    if ch == 'U':
        cave_instance.move(Cave.UP)
    elif ch == 'H':
        cave_instance.move(Cave.RIGHT)
    elif ch == 'N':
        cave_instance.move(Cave.DOWN)
    elif ch == 'V':
        cave_instance.move(Cave.LEFT)
    else:
        exit(43)
    if cave_instance.is_lost():
        exit(43)
if cave_instance.is_won():
    exit(42)
else:
    exit(43)

