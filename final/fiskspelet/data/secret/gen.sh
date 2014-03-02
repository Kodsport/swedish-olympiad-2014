#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="fiskspelet"

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
MODE='lowdist'

# N, h, mode, seed
#MODES = ["lowdist", "noeat", "nomideat", "hardest"]

for i in ${small[@]}
do
    # one line here per file in test group
    echo "1000 50 $MODE 1$i" | python gen.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "1000 50 $MODE 2$i" | python gen.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "1000 50 $MODE 3$i" | python gen.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "1000 50 $MODE 4$i" | python gen.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "input_validator_flags : $MODE" >> g$i/testdata.yaml
done

# medium data sets
medium=(2 3)
MODE='noeat'

for i in ${medium[@]}
do
    # one line here per file in test group
    echo "10000 50 $MODE 1$i" | python gen.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "10000 50 $MODE 2$i" | python gen.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "10000 50 $MODE 3$i" | python gen.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "10000 50 $MODE 4$i" | python gen.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "input_validator_flags : $MODE" >> g$i/testdata.yaml
done

# large data sets
large=(4 5 6)
MODE='nomideat'

for i in ${large[@]}
do
    # one line here per file in test group
    echo "10000 50 $MODE 1$i" | python gen.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "10000 50 $MODE 2$i" | python gen.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "10000 50 $MODE 3$i" | python gen.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "10000 50 $MODE 4$i" | python gen.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "input_validator_flags : $MODE" >> g$i/testdata.yaml
done

# hardest!
larger=(7 8 9)
MODE='hardest'

for i in ${large[@]}
do
    # one line here per file in test group
    echo "10000 50 $MODE 1$i" | python gen.py > g$i/$PROBLEMNAME.g$i.1.in
    echo "10000 50 $MODE 2$i" | python gen.py > g$i/$PROBLEMNAME.g$i.2.in
    echo "10000 50 $MODE 3$i" | python gen.py > g$i/$PROBLEMNAME.g$i.3.in
    echo "10000 50 $MODE 4$i" | python gen.py > g$i/$PROBLEMNAME.g$i.4.in
    echo "input_validator_flags : $MODE" >> g$i/testdata.yaml
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
