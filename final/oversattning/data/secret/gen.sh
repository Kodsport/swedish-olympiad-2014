#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="oversattning"

# Set this if you want to generate answers.
SOLVER=sol

# 1. Create subdirectories and set them to "min"
#    grading mode.

subfolders=(g0 g1 g2 g3 g4 g5 g6 g7 g8 g9)
for i in ${subfolders[@]}
do
    if [ ! -d $i ]
    then
        mkdir $i
    fi
    if [ ! -f $i/testdata.yaml ]
    then
        touch $i/testdata.yaml
        echo "grader_flags: min" > $i/testdata.yaml
    fi
done

# parameter list follows:
# random gen - words, entries, around, sentencelen, seed
# worst gen - entries, sentencelen, seed

# small data sets
small=(0 1 2 3)

# length, seed
for i in ${small[@]}
do
    # one line here per file in test group
    echo "30 100 100000 100 5$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "50 100 10 100 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "20 100 10 100 2$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "100 100 3$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "50 100 4$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.5.in
done

# large data sets
large=(4 5 6 7 8 9)

for i in ${large[@]}
do
    # one line here per file in test group
    echo "70 1000 10 100000 5$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "100 1000 1000 100000 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "100 1000 2 100000 2$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "1000 100000 3$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "500 100000 4$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.5.in
done

# generate solutions for all files
if [[ ! -z $SOLVER ]]
then
    for i in ${subfolders[@]}; do for f in $i/*.in; do echo -n '.'; done; done
	printf '\r'
    for i in ${subfolders[@]}
    do
        for f in $i/*.in
        do
            ./$SOLVER < $f > ${f%???}.ans
			echo -n '='
        done
    done
	printf '\r'
    for i in ${subfolders[@]}; do for f in $i/*.in; do echo -n ' '; done; done
	printf '\r'
fi
