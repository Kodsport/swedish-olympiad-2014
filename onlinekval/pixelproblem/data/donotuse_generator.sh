#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

compile create_case.py python3

# Mildly unreadable. Creates in/out files for all images in ../images/. Might give some errors due to not using a solution file

i=1

for filename in ../images/*; do
# Pad the group/testcase number
padded=$((i+1000))
group group${padded:1:3} 4
# Name the testcase after the image. Requires a little splitting to get actual image name
split=(${filename//// })
split2=(${split[2]//./ })
tc ${split2[0]} create_case "$filename" "secret/group${padded:1:3}/${padded:1:3}-${split2[0]}.ans"
((i++))
done
