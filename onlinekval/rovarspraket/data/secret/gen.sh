#!/bin/bash

PROBLEMNAME="rovarspraket"

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

# N <= 20, max 20 points
small=(g0 g1)

for i in ${small[@]}
do
    echo "20 0 1$i" | python gen_yes.py > $i/$PROBLEMNAME.$i.1.in
    echo "20 0.5 2$i" | python gen_yes.py > $i/$PROBLEMNAME.$i.2.in
    echo "20 0.5 3$i" | python gen_no.py > $i/$PROBLEMNAME.$i.3.in
    echo "20 0.5 4$i" | python gen_yes.py > $i/$PROBLEMNAME.$i.4.in
    echo "20 1 5$i" | python gen_no.py > $i/$PROBLEMNAME.$i.5.in
	cat fail1 > $i/$PROBLEMNAME.$i.6.in
	cat fail2 > $i/$PROBLEMNAME.$i.7.in
done

# N <= 100, max 50 points
med=(g2 g3 g4)

for i in ${med[@]}
do
    echo "100 0.5 1$i" | python gen_yes.py > $i/$PROBLEMNAME.$i.1.in
    echo "100 0.5 3$i" | python gen_no.py > $i/$PROBLEMNAME.$i.2.in
    echo "100 1 4$i" | python gen_yes.py > $i/$PROBLEMNAME.$i.3.in
    echo "100 0.5 5$i" | python gen_no.py > $i/$PROBLEMNAME.$i.4.in
	cat fail1 > $i/$PROBLEMNAME.$i.5.in
	cat fail2 > $i/$PROBLEMNAME.$i.6.in
    echo "100" | python gen_lolol_ja.py > $i/$PROBLEMNAME.$i.7.in
    echo "100" | python gen_lolol_nej.py > $i/$PROBLEMNAME.$i.8.in
done

# N <= 1000, max 100 points
large=(g5 g6 g7 g8 g9)

for i in ${large[@]}
do
    echo "1000 0.2 1$i" | python gen_yes.py > $i/$PROBLEMNAME.$i.1.in
    echo "1000 0.3 3$i" | python gen_no.py > $i/$PROBLEMNAME.$i.2.in
    echo "1000 1 4$i" | python gen_yes.py > $i/$PROBLEMNAME.$i.3.in
    echo "1000 0.99 5$i" | python gen_no.py > $i/$PROBLEMNAME.$i.4.in
	cat fail1 > $i/$PROBLEMNAME.$i.5.in
	cat fail2 > $i/$PROBLEMNAME.$i.6.in
    echo "1000" | python gen_lolol_ja.py > $i/$PROBLEMNAME.$i.7.in
    echo "1000" | python gen_lolol_nej.py > $i/$PROBLEMNAME.$i.8.in
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
