// "Rolling" Average.cpp
// Finds the average of 5 numbers using only 2 variables
// Created by REDACTED

#include <iostream>

int main()
{
    double container, sum;

    for (int i = 1; i <=5; i++)
    {
        std::cin >> container;
        sum += container;
    }

    std::cout << "The avergae is: " << sum / 5 << std::endl;

    return 0;
}