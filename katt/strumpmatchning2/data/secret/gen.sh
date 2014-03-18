#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="strumpmatchning2"

# Set this if you want to generate answers.
SOLVER=sol
make $SOLVER

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

for i in ${small[@]}
do
    echo $i
    # one line here per file in test group
    echo "300 3000 1$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "300 3000 2$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "300 3000 3$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "300 3000 7$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.4.in
done

# large data sets
large=(5 6 7 8 9)

for i in ${large[@]}
do
    echo $i
    # one line here per file in test group
    echo "50000 1000000000 11$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "50000 1000000000 21$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "50000 1000000000 31$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "50000 1000000000 41$i" | python generate_testcase.py > g$i/$PROBLEMNAME.g$i.4.in
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
