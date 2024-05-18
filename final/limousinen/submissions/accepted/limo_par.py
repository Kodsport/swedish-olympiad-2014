#!/usr/bin/python3

import sys

lines=sys.stdin.readlines()

N,T=[int(x) for x in lines[0].split()]

k=[]
for line in lines:
    x,y=[int(x) for x in line.split()]
    k.append(2*(abs(x)+abs(y)))
k.sort()

t=0
for n,s in enumerate(k):
    t+=s
    if t>T: break
print(n)
