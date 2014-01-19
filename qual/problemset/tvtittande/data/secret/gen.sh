#!/bin/bash

PROBLEMNAME="tvtittande"

# Set this if you want to generate answers.
SOLVER=sol

# 1. Create subdirectories and set them to "min"
#    grading mode.

subfolders=(g1 g2 g3 g4 g5 g6 g7 g8 g9 g10)
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

small=(g1 g2 g3 g4 g5 g6 g7)

for i in ${small[@]}
do
    echo "100 0.01 1$i" | ./rand_gen > $i/$PROBLEMNAME.$i.1.in
    echo "100 0.5 2$i" | ./rand_gen > $i/$PROBLEMNAME.$i.2.in
    echo "100 0.99 3$i" | ./rand_gen > $i/$PROBLEMNAME.$i.3.in
done

large=(g8 g9 g10)

for i in ${large[@]}
do
    echo "1000 0.01 1$i" | ./rand_gen > $i/$PROBLEMNAME.$i.1.in
    echo "1000 0.5 2$i" | ./rand_gen > $i/$PROBLEMNAME.$i.2.in
    echo "1000 0.99 3$i" | ./rand_gen > $i/$PROBLEMNAME.$i.3.in
done

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
