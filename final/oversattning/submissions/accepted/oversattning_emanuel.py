n = int(raw_input())
A = []; B = []
for i in range(n):
        tmp = raw_input().split()
        A.append(tmp[0].strip())
        B.append(tmp[1].strip())
m = int(raw_input())
text = raw_input().split()
trA = {}; trB = {}
for i in range(n):
        if A[i] in trA and B[i] in trB: continue
        elif A[i] in trA:
                trB[B[i]] = trA[A[i]]
        elif B[i] in trB:
                trA[A[i]] = trB[B[i]]
        else:
                trA[A[i]] = A[i]
                trB[B[i]] = A[i]
for i in range(len(text)): text[i] = trA[text[i]] 
print(' '.join(text))
