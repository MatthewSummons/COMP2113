// 6-7.cpp
// Palindrome searcher which accounts for spaces, punctuation and different lettercases 
// Created by Shaheer Ziya


#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string candidate)
{
  // Change the case of all characters in the string to lowercase
  for (int i{0}; i < candidate.length(); i++)
  {
    candidate[i] = tolower(candidate[i]);
  }

  string result = "";
  // Remove all whitespaces & punctuations in the string
  for (int i{0}; i < candidate.length(); i++)
  {
    if (isalpha(candidate[i]))
    {
      result += candidate[i];
    }
  }

  // Check if the string is a palindrome
  for (int i{0}; i < result.length() / 2; i++)
  {
    if (result[i] != result[result.length() - 1 - i])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  string pal;
  getline(cin, pal);

  if (isPalindrome(pal))
  {
    cout << "The input string is a palindrome!" << endl;
  }
  else
  {
    cout << "The input string is not a palindrome!" << endl;
  }

  return 0;
}