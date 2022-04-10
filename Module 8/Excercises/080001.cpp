// Return a pointer to the last element in an integer array
// Created by Shaheer Ziya

#include <iostream>

#define ARR_SIZE 10

int* MaxElementPtr(int Arr[], int arrSize)
{
  // Point to the maximum element in an array
  int *max = &Arr[0];
  for (int i{1}; i < arrSize; i++)
  {
    if (Arr[i] > *max)
      max = &Arr[i]; 
  }

  return max;
}

int main()
{
  int NumsArray[ARR_SIZE] = {1,2,3,4,5,13,7,8,9,10};

  // int* firstEle = &NumsArray[0];
  // // firstEle points to the first element in the array
  // std::cout << firstEle << std::endl;
  // // Dereference it to see the value it points to
  // std::cout << *firstEle << std::endl;
  
  int *maxEle;
  
  maxEle = MaxElementPtr(NumsArray, ARR_SIZE);
  std::cout << *maxEle << std::endl;
}