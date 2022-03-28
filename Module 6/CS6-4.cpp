// CS6-4.cpp
// Array Manipulation

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  const int arrSize {15};
  long Arr[arrSize] {0};
  
  // Obtain i from the user
  int i;
  cin >> i;

  for (int j {0}; (j < i) && (j < arrSize); j++)
  // Assign the first i elements of the array to be i^2
  {
    Arr[j] = (j*j);
  }

  for (int k = i; (k <= i + 5) && (k < arrSize); k++)
  // Assgin the next 5 elements (if available) to be zero
  { 
    Arr[k] = 0;
  }

  for (int l {i+5}; (l < arrSize); l++)
  // Assign any remaining elements to be 3^i
  {
    Arr[l] = pow(3, l);
  }



  // Print the elements of the array
  for (int i{0}; i < arrSize; i++)
  {
    cout << Arr[i] << " ";
  }
  cout << endl;




  return 0;
}