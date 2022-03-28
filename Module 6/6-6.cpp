// 6-6.cpp
// Replace the occurences
// Created by Shaheer Ziya

#include <iostream>
#include <string>
using namespace std;

string Replace (string line, string findWord, string replaceWord)
// Replace all occurences of "find" with "replace" in "line"
{
  int hitIndex = line.find(findWord, 0);
  // Check if first word is a hit (Special Case)
  if (hitIndex == 0)
  {
    line.replace(0, findWord.length(), replaceWord);
    hitIndex = line.find(findWord, hitIndex + replaceWord.length());
  }

  while (hitIndex != -1)
  {
    line.replace(hitIndex, findWord.length(), replaceWord);
    hitIndex = line.find(findWord, hitIndex + replaceWord.length());
  }

  return line;
}

int main()
{
  // Get initial inputs
  string line, find, replace;
  getline(cin, line);
  getline(cin, find);
  getline(cin, replace);

  // Replace the occurences
  cout << Replace(line, find, replace) << endl;
  
  return 0;
}