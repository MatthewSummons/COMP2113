// lower&Uppercase.cpp
// Functions to convert between cases in the alphabet
// Created by Shaheer Ziya on Mar 25, 2022

#include <iostream>
using namespace std;
  

char lower (char c)
{
  if (c >= 'A' && c <= 'Z')
    return c + ('a' - 'A');
  else
    return c;
}

char upper (char c)
{
  if (c >= 'a' && c <= 'z')
    return c - ('a' - 'A');
  else
    return c;
}


int main()
{
  char f = 'f', G = 'G', l = 'l', U = 'U';
  
  cout << lower(f) << upper(f) << endl;
  cout << lower(G) << upper(G) << endl;
  cout << lower(l) << upper(l) << endl;
  cout << lower(U) << upper(U) << endl;
  
  return 0;
}