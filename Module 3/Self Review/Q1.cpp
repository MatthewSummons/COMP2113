// Q1.cpp
// Print a large HI
// Created by Shaheer Ziya on UTC 09:08

#include <iostream>

int main()
{
    // Upper Header
    std::cout << "**********************" << std::endl;
    std::cout << "*                    *" << std::endl;

    // Top Body
    for (int i = 0; i<=3; i++)
        {std::cout << "*  HH    HH      II  *" << std::endl;}
    
    // Middle bar for H
    std::cout << "*  HHHHHHHH      II  *" << std::endl;

    // Bottom Body
    for (int i = 0; i<=3; i++)
        {std::cout << "*  HH    HH      II  *" << std::endl;}
    
    // Lower Header
    std::cout << "*                    *" << std::endl;
    std::cout << "**********************" << std::endl;

    return 0;
}