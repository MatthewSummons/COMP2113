// C4.cpp
// Reverse a 3 digit number
// Created by Shaheer Ziya

#include <iostream>

int main()
{
    // Obtain the number to be stored
    int OC_num;
    std::cout << "Please enter a 3 digit integer: ";
    std::cin >> OC_num;
    
    // Extracting the digits
    int hunderths, tens, units;
    hunderths = OC_num / 100;
    tens = (OC_num % 100) / 10;
    units = (OC_num % 10);

    // Reverse the number
    int reversed = (units * 100) + (tens * 10) + (hunderths);

    // Output reversed number
    std::cout << "The number " << OC_num << " reversed is " << reversed << std::endl;
    
    return 0;
}