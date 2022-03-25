// 062001.cpp
// Take a character intger and return an int integer
// Created by Shaheer Ziya on Mar 25, 2022

#include <iostream>

int charToInt (char integer)
// Use ASCII to go from characters to integers
{
  return static_cast<int>(integer) - 48;
}

int main()
{
  
  // Test the function
  std::cout << charToInt('0') << std::endl;
  std::cout << charToInt('1') << std::endl;
  std::cout << charToInt('2') << std::endl;
  std::cout << charToInt('9') << std::endl;
  

  return 0;
}