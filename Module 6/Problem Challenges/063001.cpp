// 063001.cpp
// Erase characters in a C-String
// Created by Shaheer Ziya on Mar 25, 2022

#include <iostream>
using namespace std;

void shiftLeft(char[], int);

void erase (char str[], int pos, int len)
// Erase characters starting at positin pos until length len
{
  for (int i {pos}; i < pos + len - 1; i++)
  {
    shiftLeft(str, i);
  }
}

void shiftLeft (char str[], int pos)
// Shift all characters left, deleting the character at position pos
{
  while (str[pos] != '\0')
  // Iterate until the end of the string
  {
    str[pos] = str[pos + 1];
    pos++;
  }
}

int main()
{
  char str[] = "Happy B-Day";
  erase(str, 6, 2);

  cout << str << endl;

  return 0;
}