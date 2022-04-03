// Entries Sorter
// Read data from a file and sort it by age
// Created by Shaheer Ziya

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Entry
{
  string firstName;
  string lastName;
  char dorm;
  int age;
};

// Check if two entries are equivalent
bool equal(Entry e1, Entry e2)
// Compare two entries entry-wise
{
  if ((e1.firstName == e2.firstName) && (e1.lastName == e2.lastName) && (e1.dorm == e2.dorm) && 
    (e1.age == e2.age))
    return true;
  else
    return false;
}


int main()
{
  // Open the given file
  ifstream fin;
  fin.open("./7-3-Data.txt");

  if (fin.fail())
  {
    cout << "Error opening file." << endl;
    exit(1);
  }

  // Declare an array holding all the entries
  Entry Entries[100];
  
  // Count the number of entries
  int entryCount {0};

  // Read the number of entries
  string firstName, lastName, Dorm, Age;
  while ((fin >> firstName >> lastName >> Dorm >> Age))
  {
    // Create a temporary entry to hold the data for the line
    Entry entryTemp = {firstName, lastName, Dorm[0], stoi(Age)};
    // Add the entry to the array
    Entries[entryCount] = entryTemp;
    // Increment the entry count
    entryCount++;
  }

  // Close the open file
  fin.close();


  // Sort the entries by age (Bubble Sort)
  for (int i{0}; i < entryCount; i++)
  {
    for (int j{i + 1}; j < entryCount; j++)
    {
      if (Entries[i].age > Entries[j].age)
      {
        // Swap the entries
        Entry temp = Entries[i];
        Entries[i] = Entries[j];
        Entries[j] = temp;
      }
    }
  }


  // Print the sorted entries
  for (int i{0}; i < entryCount; i++)
  {
    cout << Entries[i].firstName << " " << Entries[i].lastName << " " << Entries[i].dorm << " " << Entries[i].age << endl;
  }
}