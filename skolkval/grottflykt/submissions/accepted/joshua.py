#!/usr/bin/python3

from collections import deque

w,h = [int(i) for i in input().split()]


cave = []
for i in range(h):
    cave.append(input())

player = []
bear = []
escape = []

for j in range(w):
    for i in range(h):
        if cave[i][j] == 'S':
            player = (i,j)
        if cave[i][j] == 'B':
            bear = (i,j)
        if cave[i][j] == 'U':
            escape = (i,j)

q = deque()
q.append([player,bear,(-1,-1), (-1,-1),0])

dp = {}
parent_pos = {}

dirs = [[0,1],[0,-1],[1,0],[-1,0]]

def valid_position(pos, cave):
    if pos[0] < 0 or pos[1] < 0 or pos[0]>=h or pos[1]>=w or cave[pos[0]][pos[1]]=='#':
        return False
    return True

while len(q):
    pos, bear_pos, parent, parent_bear_pos, steps = q.popleft()
    
    if (pos,bear_pos) in dp:
        continue

    


    dp[(pos,bear_pos)] = steps
    parent_pos[(pos,bear_pos)] = (parent, parent_bear_pos)

    if cave[pos[0]][pos[1]] == 'U':
        path = []
        bear_path = []
        key = (pos, bear_pos)
        while key != ((-1,-1),(-1,-1)):
            path.append(key[0])
            bear_path.append(key[1])
            key = parent_pos[key]
        
        path = list(reversed(path))
        bear_path = list(reversed(bear_path))

        dir_to_move = {(0,1):'V',(0,-1):'H',(1,0):'U',(-1,0):'N'}
        moves = []
        for i in range(len(path)-1):
            diff = (path[i][0]-path[i+1][0],path[i][1]-path[i+1][1])
            moves.append(dir_to_move[diff])
        print("".join(moves))
        break


    for direction in dirs:
        new_pos = (pos[0]+direction[0],pos[1]+direction[1])
        if not valid_position(new_pos, cave):
            continue

        new_bear_pos = [bear_pos[0],bear_pos[1]]

        
        movesdone = 0
        bear_moves = [1,1,0,0]
        for i in bear_moves:
            if new_bear_pos[i]>new_pos[i]:
                new_bear_pos[i]-=1
                if not valid_position(new_bear_pos, cave):
                    new_bear_pos[i]+=1
                else:
                    movesdone+=1

            elif new_bear_pos[i]<new_pos[i]:
                new_bear_pos[i]+=1
                if not valid_position(new_bear_pos, cave):
                    new_bear_pos[i]-=1
                else:
                    movesdone+=1

            if movesdone == 2:
                break


            
        
        if tuple(new_bear_pos) == new_pos and new_pos != escape:
            continue

        q.append([new_pos, tuple(new_bear_pos), pos, bear_pos, steps+1])




