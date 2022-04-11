#include <iostream>
#include <string>

std::string* addEntry(std::string* array, int& size, std::string newEntry);

std::string *deleteEntry(std::string *array, int &size, std::string entrytoDelete);

int main()
{
  int entryCount = 3;
  std::string* EntryRec = new std::string[entryCount];
  
  std::cout << "Enter your name: ";
  getline(std::cin, EntryRec[0]);

  std::cout << "Enter your address: ";
  getline(std::cin, EntryRec[1]);

  std::cout << "Enter your phone number: ";
  getline(std::cin, EntryRec[2]);

  // std::cout << "Name: " << EntryRec[0] << std::endl;
  // std::cout << "Address: " << EntryRec[1] << std::endl;
  // std::cout << "Phone Number: " << EntryRec[2] << std::endl;

  EntryRec = addEntry(EntryRec, entryCount, "Gaussian Ballz");
  
  for (int i = 0; i < entryCount; i++)
  {
    std::cout << EntryRec[i] << std::endl;
  }
  
  EntryRec = addEntry(EntryRec, entryCount, "Euler Rox");
  
  for (int i = 0; i < entryCount; i++)
  {
    std::cout << EntryRec[i] << std::endl;
  }
  
  EntryRec = deleteEntry(EntryRec, entryCount, "Gaussian Ballz");

  for (int i = 0; i < entryCount; i++)
  {
    std::cout << EntryRec[i] << std::endl;
  }

}

std::string *addEntry(std::string* array, int &size, std::string newEntry)
{
  // Create a new array to store the elements
  std::string* newArray = new std::string[size+1];

  // Copy over the elements from the old array to the new one
  for (int i = 0; i < size; i++)
  {
    newArray[i] = array[i];
  }

  // Add in the new element into the new array
  newArray[size] = newEntry;

  // Delete the data stored in the previous array
  delete [] array;

  // Update the size of the array
  size += 1;

  return newArray;
}

std::string *deleteEntry(std::string *array, int &size, std::string entrytoDelete)
{
  // Linear Search for the entry to be deleted
  
  int entryLocator = -1;
  for (int i = 0; i < size; i++)
  {
    if (array[i] == entrytoDelete)
      entryLocator = i;
  }

  // If entry not located, return unmodifed array
  if (entryLocator == -1)
    return array;
  
  // Else return an array with that entry removed

  std::string* newArray = new std::string [size-1];

  // Copy the elements into the new array

  // Shared index until the entry to be deleted
  for (int i = 0; i < entryLocator; i++)
  {
    if (i != entryLocator)
      newArray[i] = array[i];
  }
  
  // Skip over the entry to be deleted
  for (int i = entryLocator + 1; i < size; i++)
  {
    newArray[i-1] = array[i];
  }

  // Delete the old array to prevent memory leaks
  delete [] array;

  size -= 1;
  
  return newArray;
}