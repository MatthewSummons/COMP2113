// Checkpoint 7.1
// Created by Shaheer Ziya

#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  ofstream fout;
  fout.open("c.txt", ios::ate | ios::binary);

  if (fout.fail())
  {
    cout << "Error opening file" << endl;
    return 1;
  }

  fout << "Yo" << endl;

  return 0;
}