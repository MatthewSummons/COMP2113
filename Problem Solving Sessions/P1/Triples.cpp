// Triples.cpp
// Find all pythagorean triples below 300
// Created by Shaheer Ziya on Feb 21, 2022

#include <iostream>

int main()
{
    for(int i = 1; i <= 300; i++)
    {
        for(int j = i; j<= 300; j++)
        {
            for(int k = j; k <= 300; k++)
                if (i*i + j*j == k*k)
                    {std::cout << i <<"^2 + " << j << "^2 = " << k << "^2" << std::endl; }
        }
    }
    return 0;
}

// Change interations in loops to avoid duplicates
