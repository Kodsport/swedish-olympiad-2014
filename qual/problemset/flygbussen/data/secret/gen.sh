#!/bin/bash

PROBLEMNAME="flygbussen"

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


# N <= 15, K <= 15
small=(0 1)

# N <= 100, K <= 100
medium=(2 3 4)

# N,K <= 1000
large=(5 6 7 8 9)

# min_n, k, max_t, max_group_size, max_duplicate

for i in ${small[@]}
do
    echo "3 2 61 2 1 2$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.1.in
    echo "4 5 61 4 5 3$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.2.in
    echo "4 15 100 2 6 4$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.3.in
done

for i in ${medium[@]}
do
    echo "76 97 10000 10 3 2$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.1.in
    echo "90 34 10000 10 2 3$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.2.in
    echo "84 19 10000 10 4 4$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.3.in
done

for i in ${large[@]}
do
    echo "200 55 1000000 60 5 2$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.1.in
    echo "201 1000 1000000 60 6 3$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.2.in
    echo "202 999 1000000 40 5 4$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.3.in
    echo "202 998 1000000 40 5 4$i" | ruby generate.rb > g$i/$PROBLEMNAME.g$i.4.in
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
