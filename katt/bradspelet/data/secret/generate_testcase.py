#!/usr/bin/env python3
import sys
import random

max_val,win,seed = map(int, sys.stdin.readline().split(" "))

random.seed(seed)

def gen(max_val, win):
    A = random.randint(max_val/2, max_val)
    B = random.randint(max_val/2, max_val)

    if max_val <= 10:
        A = random.randint(2, max_val)
        B = random.randint(2, max_val)

    if max_val > 10:
        A &= ~1
        B &= ~1
        if max_val > 10 and random.getrandbits(1):
            A &= ~2
            B &= ~2

    i = 0
    while True:
        if not A:
            A |= 1<<i
        if not B:
            B |= 1<<i
        ca = A & (1<<i)
        cb = B & (1<<i)
        if win:
            if ca and cb:
                if random.getrandbits(1):
                    A -= 1<<i
                    if not A:
                        A |= 1<<(i+1)
                else:
                    B -= 1<<i
                    if not B:
                        B |= 1<<(i+1)
                break
            elif ca or cb:
                break
        else:
            if ca and cb:
                break
            elif ca:
                A -= 1<<i
            elif cb:
                B -= 1<<i
        i += 1

    while A > max_val or B > max_val:
        A >>= 1
        B >>= 1

    if A*2 <= max_val and B*2 <= max_val:
        A <<= 1
        B <<= 1
    
    if A == B:
        return gen(max_val, win)
    return [A,B]

A,B = gen(max_val, win)
print(A,B)
