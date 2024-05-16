#!/usr/bin/python3
import sys

A,B = map(int, sys.stdin.readline().split())

if A%2 == B%2:
    print("B")
else:
    print("A")
