#!/usr/bin/env python

import sys

sample_mode = "sample" in sys.argv
min_mode = "min" in sys.argv
multiply_10 = "multiply_10" in sys.argv
verdicts = {"AC" : 0, "WA" : 0, "TLE" : 0, "RTE" : 0}

total_score = 0
if min_mode:
  total_score = -1

for line in sys.stdin.readlines():
  verdict, score = line.split()
  verdicts[verdict] += 1
  if sample_mode:
    if verdict != "AC":
      print verdict, 0
      exit()
  elif min_mode:
    if total_score == -1:
      total_score = float(score)
    else:
      total_score = min(total_score, float(score))
  else:
    total_score += float(score)

if total_score < 0:
  total_score = 0

if total_score:
  score = int(total_score)
  if multiply_10:
    score *= 10
  print "AC", score
else:
  if verdicts["RTE"]:
    print "RTE 0"
  elif verdicts["TLE"]:
    print "TLE 0"
  elif verdicts["WA"]:
    print "WA 0"
  else:
    print "AC 0"
