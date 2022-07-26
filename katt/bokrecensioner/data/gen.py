#!/usr/bin/env python2

from __future__ import division
from __future__ import print_function
import math
import sys
import random

# Sample usage:
# echo a yes 10 4 1000 -1 1 | python generate_testcase.py debug

debug = len(sys.argv) > 1 and sys.argv[1] == 'debug'

if debug:
    sys.stderr.write('running in debug mode\n')

inputs = sys.stdin.readline().strip().split()

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


random.seed(int(cmdlinearg('seed')))
mode = cmdlinearg('mode')
yesno = cmdlinearg('yesno')
N = int(cmdlinearg('n'))
M = int(cmdlinearg('m'))
max_R = int(cmdlinearg('r'))
ncomponents = int(cmdlinearg('components'))

# mode = inputs[0]
# yesno = inputs[1]
# N = int(inputs[2])
# M = int(inputs[3])
# max_R = int(inputs[4])
# ncomponents = int(inputs[5])
# seed = int(inputs[6])
# random.seed(seed)


look_behind = 10
# growth rate of rating seems to be 1 / (look_behind/2)

if ncomponents == -1:
    ncomponents = N

assert mode in ['a', 'b', 'c']
assert yesno in ['yes', 'no1', 'no2']
assert 1 <= ncomponents <= N
if mode == 'a':
    assert ncomponents == N


def get_rel():
    if mode == 'c' and random.random() < 0.9:
        return '<='
    return '='
def get_rel2():
    if mode == 'c' and random.random() < 0.3:
        return '<='
    return '<'

# Union find, from https://www.ics.uci.edu/~eppstein/PADS/UnionFind.py
class UnionFind:
    def __init__(self):
        self.weights = {}
        self.parents = {}

    def __getitem__(self, object):
        # check for previously unknown object
        if object not in self.parents:
            self.parents[object] = object
            self.weights[object] = 1
            return object

        # find path of objects leading to the root
        path = [object]
        root = self.parents[object]
        while root != path[-1]:
            path.append(root)
            root = self.parents[root]

        # compress the path and return
        for ancestor in path:
            self.parents[ancestor] = root
        return root
        
    def __iter__(self):
        return iter(self.parents)

    def union(self, *objects):
        roots = [self[x] for x in objects]
        heaviest = max([(self.weights[r],r) for r in roots])[1]
        for r in roots:
            if r != heaviest:
                self.weights[heaviest] += self.weights[r]
                self.parents[r] = heaviest

def directed_mst(size, away):
    comps = UnionFind()
    nodes = [[] for _ in range(size)]

    out = [[] for _ in range(size)]
    def dfs(ind, wherefrom):
        for to in nodes[ind]:
            if to != wherefrom:
                out[ind].append(to)
                dfs(to, ind)

    for i in range(size-1):
        [a, b] = random.sample(xrange(size), 2)
        while comps[a] == comps[b]:
            [a, b] = random.sample(xrange(size), 2)
        comps.union(a, b)
        nodes[a].append(b)
        nodes[b].append(a)

    dfs(0, -1)

    out2 = [[] for _ in range(size)]
    for a in range(size):
        for b in out[a]:
            (c, d) = (a, b) if away else (b, a)
            out2[c].append((d, get_rel()))
    return out2

def gen_component(size):
    if size == 1:
        return [[]]
    assert mode != 'a'

    mst1 = directed_mst(size, True)
    mst2 = [[]] * size if mode == 'b' else directed_mst(size, False)
    ed = [None] * size
    edset = [None] * size
    for a in range(size):
        ed[a] = mst1[a] + mst2[a]
        edset[a] = set(e for (e, rel) in ed[a])
    for a in range(size):
        eda = ed[a]
        seenyet = set()
        bi = 0
        while bi < len(eda):
            (b, rel) = eda[bi]

            # include relations only once
            if b in seenyet:
                del eda[bi]
                continue
            seenyet.add(b)

            if a in edset[b]:
                # two opposite relations combine to =
                eda[bi] = (b, '=')
                edset[b].remove(a)
                ed[b] = [x for x in ed[b] if x[0] != a]
            bi += 1

    # could add more edges here, but meh, this makes them O(N) at least
    return ed

# distribute nodes over components according to some exponential distribution
left_to_take = N - ncomponents
sizes = [1] * ncomponents
if left_to_take:
    rat = 1.2
    exps = map(lambda(x): rat ** math.sqrt(x), range(ncomponents))
    s = sum(exps)
    for i in range(ncomponents):
        v = int(round(exps[i] * (N - ncomponents) / s))
        sizes[i] += v
        left_to_take -= v
    if left_to_take <= 0:
        sizes[-1] += left_to_take
        assert sizes[-1] >= 1
        random.shuffle(sizes)
    else:
        random.shuffle(sizes)
        for i in range(ncomponents):
            sizes[i] += 1
            left_to_take -= 1
            if not left_to_take:
                break
        else:
            sizes[1] += left_to_take

    if debug:
        hist = [0] * max(sizes)
        for s in sizes:
            hist[s - 1] += 1
        sys.stderr.write('component size counts: ' + str(hist) + '\n')

res_edges = []

compleft = []
base_ind = 0
for size in sizes:
    comp = gen_component(size)
    for i in range(size):
        for (j, rel) in comp[i]:
            res_edges.append((base_ind + i, base_ind + j, rel))
    compleft.append(base_ind)
    base_ind += size

should_inject_long_chain = (yesno == 'no1')

compvalues = [1 for _ in range(ncomponents)]
compedges = [[] for _ in range(ncomponents)]
hit_limit = (M == 1)
for i in range(ncomponents):
    if i >= 2:
        ed1 = i - 1 - random.randrange(min(i, look_behind))
        ed2 = random.randrange(i)
        ed = [(ed1, get_rel2())]
        if ed1 != ed2:
            ed.append((ed2, get_rel2()))
        v = max(compvalues[e[0]] + (1 if e[1] == '<' else 0) for e in ed)
        if v <= M:
            compvalues[i] = v
            compedges[i] = ed
        elif should_inject_long_chain:
            compvalues[i] = M # lie
            compedges[i] = ed
            should_inject_long_chain = False
        if v == M:
            hit_limit = True

assert hit_limit, 'M is suboptimal'
assert not should_inject_long_chain

for i in range(ncomponents):
    for (j, rel) in compedges[i]:
        # j relates as rel to i
        # find some representatives to bind together
        # if the relation is <, we may use both < and <= in mode c
        lim = random.randrange(1, 3) if sizes[i] > 1 and sizes[j] > 1 else 1
        used = []
        for k in range(lim):
            a = compleft[i] + random.randrange(sizes[i])
            b = compleft[j] + random.randrange(sizes[j])
            if (a, b) in used:
                break
            used.append((a, b))
            res_edges.append((a, b, rel))
            if rel == '<' and mode == 'c' and random.random() < 0.3:
                rel = '<='

if yesno == 'no2':
    # inject a cycle
    for _ in range(1000):
        j = random.choice(xrange(ncomponents))
        if not compedges[j]:
            continue
        q = [e for (e, rel) in compedges[j]]
        seen = set(q)
        k = 0
        while k < len(q):
            e = q[k]
            for (v, rel) in compedges[e]:
                if v not in seen:
                    seen.add(v)
                    q.append(v)
            k += 1

        i = random.choice(q)
        x = compleft[i] + random.randrange(sizes[i])
        y = compleft[j] + random.randrange(sizes[j])

        # inject i < j if possible
        if not any((a, b) == (x, y) or (a, b) == (y, x) for (a, b, e) in res_edges):
            res_edges.append((x, y, '<'))
            break
    else:
        assert False, "didn't find a cycle to inject"

R = len(res_edges)
assert 1 <= R <= max_R

tr = list(range(1, N+1))
if not debug:
    random.shuffle(tr)
    random.shuffle(res_edges)

print(N, M, R)
for (i, j, rel) in res_edges:
    if mode == 'a':
        assert rel == '<'
    elif mode == 'b':
        assert rel == '<' or rel == '='
    print(tr[i], rel, tr[j])

