// Finds the mode of discrete data in the range [0,10]
#include <iostream>
using namespace std;

const int freqLen {11};
int freq[freqLen] = {0};

void printArr(int arr[], int arrSize);


int findMax(int arr[], int arrSize)
{
  
  printArr(arr, arrSize);
  int max {0};
  // =========
  printArr(arr, arrSize);
  // =========
  for (int i{0}; i < arrSize; i++)
  {
    cout << "i: " << i << " arr[i] = " << arr[i] <<" max = " << max << endl;
    if (arr[i] >= max)
      {max = i;}
  }

  return max;
}

void printArr(int arr[], int arrSize)
{
  for (int i{0}; i < arrSize; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}


int main()
{
  
  int input {0};
  cout << "Enter a sequence of numbers in the range [0,10]: ";
  
  // Record frequencies of numbers an array
  while (input != -1)
  {
    cin >> input;
    if ((input < 11) && (input > -1))
      freq[input]++;
  }
  
  // Mode is the value with the highest frequency
  int mode = findMax(freq, freqLen);
  
  // // Output frequencies of values and the mode for the data set
  // for (int i {0}; i < freqLen; i++)
  // {
  //   cout << "Frequency of " << i << " is " << freq[i] << endl;
  // }
  // cout << "The mode is : " << mode << endl;

  return 0;
}