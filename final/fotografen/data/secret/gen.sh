#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="fotografen"

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
small=(0)

# length, seed
for i in ${small[@]}
do
    # one line here per file in test group
    echo "10 0.5 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "10 0.95 2$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "10 0.5 3$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "10 1 4$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "10 0.9 5$i" | python gen_no.py > g$i/$PROBLEMNAME.g$i.5.in
done

# medium data sets
medium=(1 2 3 4)

for i in ${medium[@]}
do
    # one line here per file in test group
    echo "5000 0.1 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "5000 1 2$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "5000 0.77 3$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "5000 0.1 4$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "5000 0.07 5$i" | python gen_no.py > g$i/$PROBLEMNAME.g$i.5.in
done

# large data sets
large=(5 6 7 8 9)

for i in ${large[@]}
do
    # one line here per file in test group
    echo "100000 0.1 1$i" | python gen_random.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "100000 1 2$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "100000 0.5 3$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "100000 0.97 4$i" | python gen_yes.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "100000 0.0036 5$i" | python gen_no.py > g$i/$PROBLEMNAME.g$i.5.in
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
