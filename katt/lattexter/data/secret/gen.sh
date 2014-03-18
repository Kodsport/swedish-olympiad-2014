#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="lattexter"

# TODO

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

for i in ${small[@]}
do
    echo $i
    echo 1 5000 8000 20 0.01 1$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.1.in
    echo 1 5000 8000 100 0.8 2$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.2.in
    echo 1 5000 8000 3 0.6 3$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.3.in
    echo 1 5000 8000 1 0.4 4$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.4.in
done

# medium data sets
medium=(2 3 4 5 6 7)

for i in ${medium[@]}
do
    echo $i
    echo 1 500000 80000 20 0.01 1$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.1.in
    echo 1 500000 80000 3 0.2 2$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.2.in
    echo 1 500000 80000 2 0.15 3$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.3.in
    echo 1 500000 80000 1 0.15 4$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.4.in
done

# large data sets
large=(8 9)

for i in ${large[@]}
do
    echo $i
    echo 0 500000 80000 20 0.01 1$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.1.in
    echo 0 500000 80000 4 1 2$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.2.in
    echo 0 500000 80000 3 0.2 3$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.3.in
    echo 0 500000 80000 2 0.15 4$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.4.in
    echo 0 500000 80000 1 0.25 5$i | python gen_hard.py > g$i/$PROBLEMNAME.g$i.5.in
    echo 500000 80000 6$i | python gen_large_tree.py > g$i/$PROBLEMNAME.g$i.6.in
done

# generate solutions for all files
if [[ ! -z $SOLVER ]]
then
    for i in ${subfolders[@]}
    do
        for f in $i/*.in
        do
            echo "solving $f"
            ./$SOLVER < $f > ${f%???}.ans
        done
    done
fi
