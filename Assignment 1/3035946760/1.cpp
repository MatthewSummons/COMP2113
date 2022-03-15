// Palindromic Numbers [1.cpp]
// Output Palindromic Numbers in [M,N] which may be products
//   of 2 three digit numbers
// Created by Shaheer Ziya on UTC+08 23:35

/*
General Layout of The Program

1. Obtain & store inputs from the user
  - Obtain the lower & upper bound for the search space
  - Obtain the character representing the display option

2. Find the numbers that match the display option (i.e are Palindromes, are
      products of 2 three digit numbers or both)
    - ./
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome (int num)
{
  // Get the power of highest digit in the number (10 ^ N)
  int maxPlaceValue = log10(num);
  // Iterate over the number comparing the left & rightmost digit and removing both in each
  //  iteration until the "index" variable dips below 1;
  for (int index = maxPlaceValue; index >= 0; index -= 2)
  {
    // Type-cast double to int
    int power = static_cast<int>(pow(10, index));

    // Obtain leftmost digit with intger division
    int leftDigit = num / power;
    // Obtain rightmost digit (requires both operands to be integers)
    int rightDigit = num % 10;

    // Debug Line
    // cout << "L: " << leftDigit << " R: " << rightDigit << endl;

    if (leftDigit != rightDigit)
    {
      return false;
    }

    // Remove leftmost digit with int division
    num %= power;
    // Remove rightmost digit with int division
    num /= 10;
  }
  
  return true;
}

bool isProduct (int num)
{
  // Iterate over all possible 3 digit divisors
  for (int divisor = 100; divisor <= 999; ++divisor)
  {
    // Check if the number is divisible by the divisor and confirm whether the dividend in 3 digits
    if ((num % divisor == 0) && ((num / divisor) >= 100) && ((num / divisor) < 1000)) 
      {
        return true;
      }
  }
  
  return false;
}

// Fucntion to switch output depending on option input
void selector (char option, int test, int end)
{
  if (option == 'p')
  {
    while (test <= end)
    {
      if  (isPalindrome( test )) {cout << test << endl;}
      ++test;
    }
  }
  else if (option == 't')
  {
    while (test <= end)
    {
      if (isProduct( test )) {cout << test << endl;}
      ++test;
    }
  }
  else if (option == 'b')
  {
    while (test <= end)
    {
      if ((isPalindrome( test )) && (isProduct( test ))) {cout << test << endl;}      
      ++test;
    }
  }
}

int main()
{
  // Obtain the lower & upper bound for the search space; Expect ints in [M,N]
  int M, N;
  cin >> M >> N; 
  
  // Obtain the character representing the display option
  char opt;
  cin >> opt;
  
  selector (opt, M, N);

  return 0;
}