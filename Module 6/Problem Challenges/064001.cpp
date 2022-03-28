// 064001.cpp
// Find all occurences of a substring in a string
// Created by Shaheer Ziya

#include <iostream>
#include <string>
using namespace std;

void allSubStr (string searchSpace, string searchTerm)
{
  int hitIndex {0};
  while (hitIndex != -1)
  {
    hitIndex = searchSpace.find(searchTerm, hitIndex);
    if (hitIndex != -1)
    {
      cout << "Found at index: " << hitIndex << endl;
      hitIndex++;
    }
  }
}

int main()
{
  string s = "Hello World! My name is Shaheer Ziya. I'm hoping we can make it to the next level. Hello again!";
  s = "FoMo, MoMos";
  allSubStr(s, "Mo");

  
  return 0;
}