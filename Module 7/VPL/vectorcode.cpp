#include <iostream>
#include <vector>
#include <cstdlib>  // for the rand(), srand() functions to generate random numbers
#include <ctime>    // for the time() function which feeds the current time to initize the random number generator

using namespace std;

// this function computes the max and min of an input vector of integers
// and returns a vector of integers with the first element storing the max and
// the second element storing the min
// assumption: num contains at least 1 element
vector<int> maxmin(vector<int>& num)
{
  vector<int> result(2, 0);   // create a vector of integers with 2 elements, each initialized to 0

  int max, min;

  max = min = num[0];   // num[0] is the first element of the vector

  for (int i = 0; i < num.size(); ++i) {  // num.size() gives the number of elements stored in num
      if (max < num[i])
        max = num[i];
      if (min > num[i])
        min = num[i];
  }

  // store the max / min values in the result vector
  result[0] = max;
  result[1] = min;

  return result;

}

int main()
{
  vector<int> numbers(10);  // create a vector of 10 integers, uninitialized

  // generate 10 random numbers in the range 1-100 and store in the vector
  srand ((int) time(0));   //  initialize random seed, without this statement, the random number generated will be the same everything you run the code
  for (int i = 0; i < numbers.size(); ++i) {
    numbers[i] = (rand() % 100) + 1;  // generate a random number in range 1-100
  }

  // pass the vector to the maxmin function, return result stores in answer
  vector<int> answer = maxmin(numbers);

  // print the contents of the vector, and the max & min values
  for (int i = 0; i < numbers.size(); ++i) {
    cout << numbers[i] << ' ';
  }
  cout << endl;
  cout << "max = " << answer[0] << endl;
  cout << "min = " << answer[1] << endl;

}
