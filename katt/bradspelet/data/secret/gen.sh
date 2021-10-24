#!/bin/bash

# Set the problem name to generate correct file names
PROBLEMNAME="bradspelet"

# Set this if you want to generate answers.
SOLVER=BradSpelet

# small data sets
small=(0 1)

mkdir g1 g2

for i in ${small[@]}
do
    echo $i
    # one line here per file in test group
    echo "10 0 1$i" | python3 generate_testcase.py > g1/$PROBLEMNAME.g$i.1.in
    echo "10 1 2$i" | python3 generate_testcase.py > g1/$PROBLEMNAME.g$i.2.in
    echo "10 0 3$i" | python3 generate_testcase.py > g1/$PROBLEMNAME.g$i.3.in
    echo "10 1 7$i" | python3 generate_testcase.py > g1/$PROBLEMNAME.g$i.4.in
    echo "10 1 9$i" | python3 generate_testcase.py > g1/$PROBLEMNAME.g$i.5.in
    echo "10 1 11$i" | python3 generate_testcase.py > g1/$PROBLEMNAME.g$i.6.in
done

# large data sets
large=(2 3 4 5 6 7 8 9)

for i in ${large[@]}
do
    echo $i
    # one line here per file in test group
    echo "100 0 11$i" | python3 generate_testcase.py > g2/$PROBLEMNAME.g$i.1.in
    echo "100 1 21$i" | python3 generate_testcase.py > g2/$PROBLEMNAME.g$i.2.in
    echo "100 0 31$i" | python3 generate_testcase.py > g2/$PROBLEMNAME.g$i.3.in
    echo "100 1 41$i" | python3 generate_testcase.py > g2/$PROBLEMNAME.g$i.4.in
    echo "100 1 45$i" | python3 generate_testcase.py > g2/$PROBLEMNAME.g$i.5.in
    echo "100 1 46$i" | python3 generate_testcase.py > g2/$PROBLEMNAME.g$i.6.in
done

subfolders=(g1 g2)
# generate solutions for all files
if [[ ! -z $SOLVER ]]
then
    for i in ${subfolders[@]}
    do
        for f in $i/*.in
        do
            echo "solving $f"
            java $SOLVER < $f > ${f%???}.ans
        done
    done
fi
