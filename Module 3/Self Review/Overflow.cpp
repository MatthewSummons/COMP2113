// Overflow.cpp
// Tackling with Overflow
// Created by Shaheer Ziya on UTC 09:08

#include <iostream>

int main()
{
    long long product = 654321LL * 123456;
    std::cout << product << std::endl; 
    return 0;
}

// long long is 64-bit int, long double is the float couterpart
// 1LL indicates that the literal 1 is a long long type and not 32-bit (signed) int
