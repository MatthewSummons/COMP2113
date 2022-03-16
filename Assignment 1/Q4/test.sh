#!/bin/zsh

g++ -pedantic-errors -std=c++11 4.cpp -o 4

for i in {1..1000}
do
    echo "$i" | ./4
done