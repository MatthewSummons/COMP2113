// The Entry Struct
// Created by Shaheer Ziya

#include <iostream>
#include <string>
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
  return 0;
}