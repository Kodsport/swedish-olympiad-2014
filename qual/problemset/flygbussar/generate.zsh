#!/bin/zsh

go () {
  typeset case_id="$1"; shift
  echo case_id
  # echo $@ | ruby generate.rb | sed -n 1,1p # > data/secret/flybussar.$case_id.in
  echo $@ | ruby generate.rb | > data/secret/flygbussar.$case_id.in
}

# min_n, k, max_t, max_group_size, max_duplicate = gets.split.map(&:to_i)
go 01 5 10 1000 2 1
go 02 20 10 10000 2 1
go 03 100 20 10000 2 1
go 04 50 10 10000 2 3
go 05 1500 99 100000 50 2
go 06 1700 100 100000 60 2
# 30 percent
go 07 7000 100 100000 60 4
go 08 8000 100 100001 61 4
go 07 9000 100 100002 63 4
go 09 10000 100 100003 63 4
for i in {10..20}
do
  go $i $(( $i * 1000)) $((80 + $i)) $(($i * 49000000)) $((100 + $i )) 4
done
