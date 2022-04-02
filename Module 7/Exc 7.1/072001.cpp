// Print every other line in a file;

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Enter the name of the file: "; 
  string fname;
  cin >> fname;
  // Output File Stream
  ifstream fin;
  fin.open(fname.c_str());

  if (fin.fail())
  {
    cout << "Error in opening fine!";
    exit(1);
  }
  
  int wordCount {0};
  string word;
  while (fin >> word)
  {
    if (wordCount % 2 == 0)
      cout << word << endl;
    wordCount++;
  }

  return 0;
}