#!/bin/bash
allStudents= #Your answer in Q1
for student in $allStudents
do
    if #Your answer in Q2
    then 
        cd $student
        if #Your answer in Q3
        then
            g++ assign.cpp -o assign.o 2>error.txt
            if #Your answer in Q4
            then
                ./assign.o < ../input.txt > output.txt 
                result=`diff output.txt ../correct.txt`
                if #Your answer in Q5
                then
                    echo "$student: Wrong answer."
                else
                    echo "$student: Correct!"
                fi
            else
                echo "$student: Cannot be compiled."
            fi
        fi
        cd ..
    fi
done   
