#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="limousinen"

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
small=(0 1)

# N, amplitude, fraction, seed

for i in ${small[@]}
do
    # one line here per file in test group
    echo "10 1000 0.2 1$i" | python gen.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "10 1000 0.5 2$i" | python gen.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "10 600 0.8 3$i" | python gen.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "10 100 1 4$i" | python gen.py > g$i/$PROBLEMNAME.g$i.4.in
done

# medium data sets
medium=(2 3 4)

for i in ${medium[@]}
do
    # one line here per file in test group
    echo "1000 1000000 0.2 1$i" | python gen.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "1000 100000 0.5 2$i" | python gen.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "999 10000 0.8 3$i" | python gen.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "777 100000 1 4$i" | python gen.py > g$i/$PROBLEMNAME.g$i.4.in
done

# large data sets
large=(5 6 7 8 9)

for i in ${large[@]}
do
    # one line here per file in test group
    echo "100000 10000000 0.2 1$i" | python gen.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "100000 50000 0.5 2$i" | python gen.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "99034 1000 0.8 3$i" | python gen.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "100000 100 0.91 1241$i" | python gen.py > g$i/$PROBLEMNAME.g$i.4.in
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
