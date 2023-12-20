// Q4.cpp
// Print remainder and quotient of two ints taken from user
// Created by REDACTED on UTC 09:20

#include <iostream>

int main()
{
    int a,b;
    std::cout << "Please Input two integers: ";
    std::cin >> a >> b;

    std::cout << "The quotient is = " << a/b << " and the remainder = " << a % b << std::endl;  
    return 0;
}