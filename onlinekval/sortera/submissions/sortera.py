#!/usr/bin/python3
import sys

def minswaps(v):
    N=len(v)
    s=0
    for i in range(N):
        for j in range(i+1,N):
            if(v[j]<v[i]): s+=1
    return s

print(minswaps([int(x) for x in input().split()[1:]]))

