from __future__ import division
import sys
import random
import string

entries, leaves, sentencelen, seed = map(int, sys.stdin.readline().split())
random.seed(seed)

# words are at most length 20
char_set = string.ascii_lowercase
real_entries = entries - int(entries * (random.random() * 0.2))

words = set()
words1 = []
while len(words) < real_entries:
    wordlen = random.randrange(3, 20)
    words.add(''.join(random.sample(char_set*wordlen, wordlen)))

wordlist = list(words)
random.shuffle(wordlist)

used_words = []

output = []
output.append((wordlist[0], wordlist[1]))
used_words.append(wordlist[0])
last_index = -1
for i in xrange(1, (real_entries - leaves) // 2 - 1):
    output.append((wordlist[i], wordlist[i]))
    output.append((wordlist[i], wordlist[i+1]))
    last_index = i
    used_words.append(wordlist[i])

for i in xrange(leaves):
    s = wordlist[last_index+i+1]
    output.append((s, wordlist[last_index + 1]))
    # make leaves more likely than words in the middle
    used_words.append(s)
    used_words.append(s)

# Dummy entries to make the expected output not consist only of one word
# repeated an endless number of times
output.append(('a', 'b'))
output.append(('c', 'b'))
used_words.extend(['a', 'c', 'c', 'c'])

print len(output)
for (x, y) in output:
    print x, y

print sentencelen
for i in xrange(sentencelen):
    sys.stdout.write(random.choice(used_words))
    if i != sentencelen-1:
        sys.stdout.write(" ")
print ""
