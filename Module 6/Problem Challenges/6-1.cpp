// 6-1.cpp
// Selection Sort Implementation in ascending order
// Created by Shaheer Ziya on Mar 24, 2022

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void printArr(int Arr[], int arrSize)
// Print elements in an array with integer elements
{
  for (int i{0}; i < arrSize; i++)
  {
    cout << Arr[i] << " ";
  }
  cout << endl;
}


void sort(int Arr[], int arrSize)
// Sort an integer array using selection sort
{
  for (int i{0}; i < arrSize; i++)
  {
    int minValIdx = i;
    int minVal = Arr[i];

    for (int j{i}; j < arrSize; j++)
    {
      if (minVal > Arr[j])
      {
        minValIdx = j;
        minVal = Arr[j];
      }
          
    }
    swap(Arr[i], Arr[minValIdx]);
  }
}


void swap(int& T1, int& T2)
// Swap two variables passing by reference
{
  int Temp = T1;
  T1 = T2;
  T2 = Temp;
}


int main()
{
  const int arrSize{10};
  int array [arrSize] = {};

  // Set seed for program
  srand(time(NULL));
  for (int i {0}; i < arrSize; i++)
  {
    // Randomnly assign elements of array in range [-50, 50)
    array[i] = (rand() % 100) - 50;
  }
  
  cout << "The elements of the array before sorting: " << endl;
  printArr(array, arrSize);
  cout << endl;

  sort(array, arrSize);

  cout << "The elements of the array after the sorting: " << endl;
  printArr(array, arrSize);
  cout << endl;

  
  return 0;
}