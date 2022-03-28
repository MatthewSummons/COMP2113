// Palindrom.cpp
// Palindrome searcher which accounts for spaces and different lettercases
// Created by Shaheer Ziya


#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string candidate)
{
  // Remove all whitespaces in the string
  for (int i{0}; i < candidate.length(); i++)
  {
    if (candidate[i] == ' ')
    {
      candidate.erase(i, 1);
    }
  }
  // Change the case of all characters in the string to lowercase
  for (int i{0}; i < candidate.length(); i++)
  {
    candidate[i] = tolower(candidate[i]);
  }
  // Check if the string is a palindrome
  for (int i{0}; i < candidate.length() / 2; i++)
  {
    if (candidate[i] != candidate[candidate.length() - 1 - i])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  string pal = "Was it a car or a cat I saw";
  if (isPalindrome(pal))
  {
    cout << "It is a palindrome!" << endl;
  }
  else
  {
    cout << "It is not a palindrome!" << endl;
  }
  return 0;
}