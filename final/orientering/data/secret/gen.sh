#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="orientering"

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

# small data sets
small=(0 1 2 3 4)

# length, seed
for i in ${small[@]}
do
    # one line here per file in test group
    echo "200 200 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "200 200 2$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "200 200 3$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "200 200 4$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.4.in
done

# large data sets
large=(5 6 7 8 9)

for i in ${large[@]}
do
    # one line here per file in test group
    echo "2000 2000 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "2000 2000 2$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "2000 2000 3$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "2000 2000 4$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.4.in
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
