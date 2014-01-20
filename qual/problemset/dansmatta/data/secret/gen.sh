#!/bin/bash

PROBLEMNAME="dansmatta"

# Set this if you want to generate answers.
SOLVER=sol

# 1. Create subdirectories and set them to "min"
#    grading mode.

subfolders=(g01 g02 g03 g04 g05 g06 g07 g08 g09 g10)
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

# N = 10 single
./rand_gen 10 295798 1 > g01/$PROBLEMNAME.g01.1.in
./rand_gen 10 295799 1 > g01/$PROBLEMNAME.g01.2.in
./rand_gen 10 34598 1 > g01/$PROBLEMNAME.g01.3.in

# N = 100000 single
./rand_gen 2000 295800 1 > g02/$PROBLEMNAME.g02.3.in
./rand_gen 2000 295801 1 > g02/$PROBLEMNAME.g02.4.in
./rand_gen 100000 295802 1 > g02/$PROBLEMNAME.g02.5.in
./rand_gen 100000 295803 1 > g02/$PROBLEMNAME.g02.6.in

# N = 100, 10 points
./rand_gen 100 295804 0 > g03/$PROBLEMNAME.g03.1.in
./rand_gen 100 295805 0 > g03/$PROBLEMNAME.g03.2.in
./rand_gen 100 295806 0 > g03/$PROBLEMNAME.g03.3.in

# N = 800, 10 points
./rand_gen 800 295807 0 > g04/$PROBLEMNAME.g04.1.in
./rand_gen 800 295808 0 > g04/$PROBLEMNAME.g04.2.in
./rand_gen 800 295809 0 > g04/$PROBLEMNAME.g04.3.in

# N = 2000, 10 points
./rand_gen 2000 295810 0 > g05/$PROBLEMNAME.g05.1.in
./rand_gen 2000 295811 0 > g05/$PROBLEMNAME.g05.2.in
./rand_gen 2000 295812 0 > g05/$PROBLEMNAME.g05.3.in

# N = 5000, 10 points
./rand_gen 5000 295813 0 > g06/$PROBLEMNAME.g06.1.in
./rand_gen 5000 295814 0 > g06/$PROBLEMNAME.g06.2.in
./rand_gen 5000 295815 0 > g06/$PROBLEMNAME.g06.3.in

# N = 10000, 10 points
./rand_gen 10000 295816 0 > g07/$PROBLEMNAME.g07.1.in
./rand_gen 10000 295817 0 > g07/$PROBLEMNAME.g07.2.in
./rand_gen 10000 295818 0 > g07/$PROBLEMNAME.g07.3.in


large=(08 09 10)

for i in ${large[@]}
do
	./rand_gen 100000 295821$i 0 > g$i/$PROBLEMNAME.g$i.1.in
	./rand_gen 100000 295822$i 0 > g$i/$PROBLEMNAME.g$i.2.in
	./rand_gen 100000 295823$i 0 > g$i/$PROBLEMNAME.g$i.3.in
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
