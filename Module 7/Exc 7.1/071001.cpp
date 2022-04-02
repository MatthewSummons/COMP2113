#include <iostream>
#include <fstream>
#include <string>
// #include <cstdlib>

using namespace std;

int main()
{
  cout << "Please enter the filename for the file you want to copy: " << endl;
  char fname [80]; // Declare a C-string to store the name of the file & assume it's a short name
  cin >> fname;

  // Input File Stream
  // Open the file to be read & copied
  ifstream fin;
  fin.open(fname);

  // Error handling in case file doesn't exist/open
  if (fin.fail())
  {
    cout << "Error opening file!" << endl;
    exit(1);
  }

  // Output File Stream

  string fnameCP = "cp_" + string(fname); // name of the file the data is copied to

  // Open a file to copy the data to
  ofstream fout;
  fout.open(fnameCP);

  // Keep reading from the INPUT file until eof is reached
  string line;
  while (getline(fin, line))
  {
    fout << line << endl;
  }

  // Close all the opened files
  fin.close();
  fout.close();

  
  return 0;
}
