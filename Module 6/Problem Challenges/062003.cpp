// 062003.cpp
// Change all lowercase letters in a C-string to uppercase
// Created by Shaheer Ziya on Mar 25, 2022

#include <iostream>
using namespace std;

void toUpper (char Cstr[], int strLength)
// Change all lowercase letters to uppercase in a C-String
{
  for (int c {0}; c < strLength; c++)
  {
    // If lowercase, convert to uppercase
    if (Cstr[c] >= 'a' && Cstr[c] <= 'z')
    {
      Cstr[c] = Cstr[c] - ('a' - 'A');
    }
  }
}

int main()
{
  const int strLength {8};
  char name[8] = {'S', 'h', 'a', 'h', 'e', 'e', 'r', '\0'};
  

  cout << "Changing all lowercase letters to uppercase..." << endl;
  cout << "-----------------------------------------------" << endl;
  cout << endl;
  cout << "Before: " << name << endl;
  cout << endl;
  toUpper(name, strLength);
  cout << "After: " << name << endl;
  cout << endl;
  
  
  return 0;
}