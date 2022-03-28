// Str length
// Determine the legnth of a string
// Created by Shaheer Ziya

#include <iostream>
#include <string>
using namespace std;

int strLength (string s)
{
  int length {0};
  while (s[length] != '\0')
  {
    length++;
  }

  return length;
}

int main()
{
  string A = "Hello World";
  string B = "Lol";

  cout << strLength(A) << endl;
  cout << strLength(B) << endl;
  
  return 0;
}