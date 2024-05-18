#!/usr/bin/python3
from sys import stdin

num_translations = int(stdin.readline())
trans = {stdin.readline().split()[1]: stdin.readline().split()[0] for _ in range(num_translations)}
line = stdin.readline().strip()
translated_line = "".join([trans.get(line[i:i+4], "?") for i in range(0, len(line), 4)])
print(translated_line)
