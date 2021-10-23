# coding=UTF-8
#!/usr/bin/env python

# Skolkvalsgrader
# Använd med 3 testdata-grupper
# 3 grupper = 100p
# 2 grupper = 50p
# 0-1 grupper = 0p

import sys

if "sample" in sys.argv:
	for line in sys.stdin.readlines():
		verdict, score = line.split()
		if verdict != "AC":
			print verdict, 0
			exit()
	print "AC 0"
else:
	total_score = 0
	wa = 0
	tle = 0
	rte = 0
	for line in sys.stdin.readlines():
		verdict, score = line.split()
		if verdict == "WA":
			wa += 1
		elif verdict == "TLE":
			tle += 1
		elif verdict == "RTE":
			rte += 1
		total_score += float(score)
	if total_score:
		score = int(total_score)
		if score < 2:
			score = 0
		elif score == 2:
			score = 50
		elif score == 3:
			score = 100
		print "AC", score
	else:
		if rte:
			print "RTE 0"
		elif tle:
			print "TLE 0"
		else:
			print "WA 0"
