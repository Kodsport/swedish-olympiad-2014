import sys
import random
import string

entries, sentencelen, seed = map(int, sys.stdin.readline().split())
random.seed(seed)

# words are at most length 20
char_set = string.ascii_lowercase
real_entries = entries - int(entries * (random.random() * 0.2))

words = set()
words1 = []
while len(words) < real_entries:
    wordlen = random.randrange(1,20)
    words.add(''.join(random.sample(char_set*wordlen, wordlen)))

wordlist = list(words)
random.shuffle(wordlist)

used_words = set()

output = []
output.append((wordlist[0], wordlist[1]))
used_words.add(wordlist[0])
for i in xrange(1,real_entries/2):
    output.append((wordlist[i], wordlist[i]))
    output.append((wordlist[i], wordlist[i+1]))
    used_words.add(wordlist[i])

print len(output)
for (x, y) in output:
    print x, y

l = list(used_words)

for i in xrange(sentencelen):
    sys.stdout.write(random.choice(l))
    sys.stdout.write(" ")

print ""
