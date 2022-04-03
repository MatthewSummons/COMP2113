// Count the frequency of words in a text file
// Created by Shaheer Ziya

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;


bool chooseFile()
{
  // Determine if the user wants to choose the file
  bool chooseFile {false};
  cout << "Do you want to choose the file you want to read? (Y/n)" << endl;
  char answer;
  cin >> answer;
  if (answer == 'Y' || answer == 'y')
    chooseFile = true;

  return chooseFile;
}

string fileName (bool chooseFile)
{
  string fname;
  if (chooseFile)
  {
    cout << "Enter the name of the file you want to read: " << endl;
    cin >> fname;
  }

  else
  {
    fname = "sample.txt";
  }

  return fname;
}


struct wordFreq
{
  string word;
  int frequency;
};

int main()
{
  // Determine if the user wants to choose the file
  bool selectFile {chooseFile()};
  // Determine the name of the file
  string fname {fileName(selectFile)};
  // Open the file
  ifstream fin;
  fin.open(fname.c_str());

  if (fin.fail())
  {
    cout << "Error opening file." << endl;
    exit (1);
  }

  // Declare an array to store the words and their frequencies
  wordFreq lexicon[1000];

  int UniqueWords {0};

  // Read the file
  string word;
  while (fin >> word)
  {
    // Determine if the word is already in the array
    bool found{false};
    int index{0};
    while (index < UniqueWords && !found)
    {
      if (lexicon[index].word == word)
        found = true;
      else
        index++;
    }

    // If the word is not in the array, add it
    if (!found)
    {
      lexicon[UniqueWords].word = word;
      lexicon[UniqueWords].frequency = 1;
      UniqueWords++;
    }

    // If the word is in the array, increment the frequency
    else
    {
      lexicon[index].frequency++;
    }
  }

  // Sort the array
  for (int i{0}; i < UniqueWords - 1; i++)
  {
    for (int j{i + 1}; j < UniqueWords; j++)
    {
      if (lexicon[i].frequency < lexicon[j].frequency)
      {
        wordFreq temp;
        temp = lexicon[i];
        lexicon[i] = lexicon[j];
        lexicon[j] = temp;
      }
    }
  }

  // Display the results
  cout << "The words and their frequencies are:" << endl;
  for (int i{0}; i < UniqueWords; i++)
  {
    cout << lexicon[i].word << " " << lexicon[i].frequency << endl;
  }


  return 0;
}