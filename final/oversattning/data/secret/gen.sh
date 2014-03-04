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
# random gen - words, entries, sentencelen, seed
# worst gen - entries, sentencelen, seed

# small data sets
small=(0 1 2 3)

# length, seed
for i in ${small[@]}
do
    # one line here per file in test group
    echo "100 100 100 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "20 100 100 2$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "100 100 3$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "50 100 4$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.4.in
done

# large data sets
large=(4 5 6 7 8 9)

for i in ${large[@]}
do
    # one line here per file in test group
    echo "1000 1000 100 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "200 1000 100 2$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "1000 100000 3$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "500 100000 4$i" | python gen_worst.py > g$i/$PROBLEMNAME.g$i.4.in
done

# generate solutions for all files
if [[ ! -z $SOLVER ]]
then
    for i in ${subfolders[@]}
    do
        for f in $i/*.in
        do
            ./$SOLVER < $f > ${f%???}.ans
        done
    done
fi
