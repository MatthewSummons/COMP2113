// Chain.cpp
// Chaining shortahand operators += etc
// Created by REDACTED

#include <iostream>

int main()
{
    int a = 4, b = 3, c = 2;
    std::cout << a += b += c;
    std::cout << a *= b *= c;
    std::cout << a += b %= c;
    std::cout << (a += b) %= c;


    

    return 0;
}