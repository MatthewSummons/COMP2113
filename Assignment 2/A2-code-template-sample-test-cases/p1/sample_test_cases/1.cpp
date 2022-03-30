// Pokemon Name Sorter
// Sort in descending word length
// Created by Shaheer Ziya on Mar 30, 2020

#include <iostream>   // For I/O
#include <string>     // For the string class
#include <cctype>     // For tolower()
using namespace std;

void swap(string arr[], int index1, int index2)
// Swap the contents of a string arr at indices 1 & 2
{
  string temp = arr[index1];
  
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

string lowercase(string str)
// Return a lowercase copy of the entered string
{
  for(int i{0}; i < str.length(); i++)
  {
    str[i] = tolower(str[i]);
  }
  return str;
}

int main()
{
  //! Obtain the names of the Pokemon
  string PokeNames[30];
  // Obtain the first pokemon name
  string name;
  cin >> name;
  // Keeps count of pokemon names entered (Offseted to account for "???"" end of input) [*1]
  int numPokemons {0};
  while (name != "???")
  {
    PokeNames[numPokemons] = name;
    cin >> name;
    numPokemons++;
  }

  //! Sort names in descending order of length & order lexicographically in case same lenght
  // Implemented using Selection Sort (Set aside minimum/maximum to beginning)

  for (int i{0}; i <= numPokemons; i++)
  {
    // Assume the first element in the i-th pass has the most characters
    int maxLenIdx {i};        // Store the index of the largest string
    
    // Iterate from the i-th element till the end
    for (int j{i+1}; j <= numPokemons; j++)
    {
      if (PokeNames[maxLenIdx].length() < PokeNames[j].length())
        maxLenIdx = j;
      // If length of names same, then compare lexicographically
      else if (PokeNames[maxLenIdx].length() == PokeNames[j].length())
      {
        // Initialize the values of left & right with the lowercase strings to be compared
        string left {lowercase(PokeNames[maxLenIdx])}, right {lowercase(PokeNames[j])};

        // If the left is not lexicographically larger than the right, send it to the beginning
        if (left > right)
          maxLenIdx = j;
        
        // Otherwsise, do nothing
      }
    }

    // Keep Sending the longest legnth elements to the beginning of the array
    swap(PokeNames, i, maxLenIdx);
  }



  // Print names of pokemon in the array
  for (int i{0}; i < numPokemons; i++)
  {
    cout << PokeNames[i] << endl;
    // cout << PokeNames[i].length() << endl;
  }


  return 0;
}

// Footnotes
//! [*1] The counting is zero-indexed to account for the last line which indicates end-of-input
//  Say for example we have two pokemons, call them A & B
//     Input  numPokemons
//        A   <- 0
//        B   <- 1
//       ???  <- 2
//    Thus at the end we have numPokemons equal to 2.
//  Another conseqeunce of this is that nothing is output if "???" is the first input!
