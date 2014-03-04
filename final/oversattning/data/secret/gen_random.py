import sys
import random
import string

words, entries, sentencelen, seed = map(int, sys.stdin.readline().split())
random.seed(seed)

# words are at most length 20
char_set = string.ascii_lowercase

real_entries = entries - int(entries * (random.random() * 0.2))

print real_entries

words1 = []
for i in xrange(words):
    wordlen = random.randrange(1,20)
    words1.append(''.join(random.sample(char_set*wordlen, wordlen)))

words2 = []
for i in xrange(words):
    wordlen = random.randrange(1,20)
    words2.append(''.join(random.sample(char_set*wordlen, wordlen)))

picked = set()

for i in xrange(real_entries):
    w1 = random.choice(words1)
    w2 = random.choice(words2)
    picked.add(w1)
    print w1, w2

candidates = list(picked)

for i in xrange(sentencelen):
    sys.stdout.write(random.choice(candidates))
    sys.stdout.write(" ")

print ""
