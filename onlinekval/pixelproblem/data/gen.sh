#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh



compile create_case.py python3



i=1

for filename in images/*; do
group group$i 4
padded=$((i+1000))
split=(${filename//// })
split2=(${split[1]//./ })
echo ${split2[0]}
tc ${split2[0]} create_case "$filename" "secret/group$i/${padded:1:3}-${split2[0]}.ans"
((i++))
done

: '
for ((i=1;i<6;i++)); do
group group$i 4
limits allowed=less
tc g1-$(($i*0+1)) gen 
tc g1-$(($i*0+2)) gen 
tc g1-$(($i*0+3)) gen 
tc g1-$(($i*0+4)) gen 
tc g1-$(($i*0+5)) gen 
done
'