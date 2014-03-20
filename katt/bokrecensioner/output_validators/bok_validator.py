#/usr/bin/env python

import sys
import re

def say(*stuff):
    return  # Uncomment for debugging
    with open('/home/arash/po2014/katt/bokrecensioner/OUTPUT', 'a') as f:
        for l in stuff:
            f.write(str(l) + " \t")
        f.write('\n')
    return

# say('Starting yaaaay')
# say(os.getcwd())

# say(*sys.argv)

# ./validator input judgeanswer feedbackdir < teamoutput

this_file, input_file, judgeanswer_file, feedback_dir = sys.argv
judge_feedback_file = '{}/judgemessage.txt'.format(feedback_dir)


# Gives
# (N, M, R, [(i, <rel>, j)])
#  where <rel> = is a binary function
def parse_input(raw_problem_input):
    N, M, R = map(int, raw_problem_input[0].split())
    return (N, M, R, [parse_rel_line(line) for line in raw_problem_input[1:]])


def parse_rel_line(line):
    i, rel, j = line.split()
    d = {'<': lambda x, y: x < y,
         '=': lambda x, y: x == y,
         '<=': lambda x, y: x <= y}
    rel = d[rel]
    return (int(i), rel, int(j))


def they_are_right():
    sys.exit(42)


def they_are_wrong(reason):
    say('NOOOOOOOOOOO')
    say(reason)
    with open(judge_feedback_file, 'w') as f:
        f.write(reason + '\n')
    sys.exit(43)

# Read input file
with open(input_file) as f:
    raw_problem_input = f.readlines()
N, M, R, relations = parse_input(raw_problem_input)

# Read answer of team
line = sys.stdin.readline()

# check answer format
try:
    team_answer = map(int, line.split())
except:
    they_are_wrong("Incorrect input format")

# Read anwer of judg
with open(judgeanswer_file) as f:
    judg_answer_lines = f.readlines()
# print judg_answer_lines
assert len(judg_answer_lines) == 1
judg_answer = judg_answer_lines[0].strip().split()
# print judg_answer

# They are list of ints so:
team_answer = map(int, team_answer)
judg_answer = map(int, judg_answer)


def make_sure_both_found_answer(them, us):
    if them == [-1] and them == us:
        they_are_right()
    elif them == [-1]:
        they_are_wrong("Team didn't find an answer, but judge says there is")
    elif us == [-1]:
        they_are_wrong("Team claims an answer, but judge says there isn't")

make_sure_both_found_answer(team_answer, judg_answer)

if len(team_answer) != N:
    they_are_wrong('You outputted {} reviews, not {}'.format(len(team_answer),
                                                             N))

for ix in range(N):
    rev = team_answer[ix]
    if not (1 <= rev <= M):
        they_are_wrong("A book can't have review {}".format(rev))

for ix in range(R):
    i, rel, j = relations[ix]
    x = team_answer[i - 1]
    y = team_answer[j - 1]
    if not rel(x, y):
        rel_string = raw_problem_input[ix + 1]
        they_are_wrong("You failed to satisfy {}".format(rel_string))

they_are_right()
