#include <iostream>


int main()
{
  // Read in the amount of numbers to be entered by the user
  int N;
  std::cin >> N;

  // Create an array of N integers
  double* Nums = new double[N];

  // Read in the numbers
  for (int i = 0; i < N; i++)
  {
    std::cin >> Nums[i];
  }

  // Print out the numbers in reverse
  for (int i = N - 1; i >= 0; i--)
  {
    std::cout << Nums[i] << " ";
  }

  std::cout << std::endl;

  // Free up allocated memory
  delete[] Nums;



}