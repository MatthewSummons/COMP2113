#!/bin/zsh

g++ -pedantic-errors -std=c++11 4.cpp -o 4

touch output.txt

for i in {1..1000}
do
     echo $i "Loading ..."
     echo "$i" | ./4 >> output.txt
done

touch nums.txt
grep -n "flush" output.txt > nums.txt
cut -d":" -f1 nums.txt > nums.txt
cat nums.txt

rm nums.txt
rm output.txt