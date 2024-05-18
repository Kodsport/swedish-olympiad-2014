#!/usr/bin/python3

input()
value, key = input().split()
line = input()
print("".join([value if line[i:i+4] == key else "?" for i in range(0, len(line), 4)]))
