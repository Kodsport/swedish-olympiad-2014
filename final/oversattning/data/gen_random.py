import sys
import random
import string

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default


words = int(cmdlinearg('words'))
entries = int(cmdlinearg('ent'))
around = int(cmdlinearg('leaf'))
sentencelen = int(cmdlinearg('sentlen'))
seed = int(cmdlinearg('seed'))

random.seed(seed)

#words, entries, around, sentencelen, seed = map(int, sys.stdin.readline().split())

# words are at most length 20
char_set = string.ascii_lowercase

words1 = []
for i in range(words):
    wordlen = random.randrange(3,20)
    words1.append(''.join(random.sample(char_set*wordlen, wordlen)))

words2 = []
for i in range(words):
    wordlen = random.randrange(3,20)
    words2.append(''.join(random.sample(char_set*wordlen, wordlen)))

picked = set()

num_entries = entries - int(entries * (random.random() * 0.2))
print(num_entries)

for i in range(num_entries):
    # pick words from a sliding window of size 2*around
    low = max(int(words * i / num_entries) - around, 0)
    high = min(int(words * i / num_entries) + around + 1, words)
    w1 = words1[random.randrange(low, high)]
    w2 = words2[random.randrange(low, high)]
    picked.add(w1)
    print(w1, w2)

candidates = list(picked)

print(sentencelen)

for i in range(sentencelen):
    sys.stdout.write(random.choice(candidates))
    if i != sentencelen-1:
        sys.stdout.write(" ")
print("")