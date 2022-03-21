#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double e = 2.72;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is

// Function: sigmoid activation function
// Input: double x: the input of sigmoid activation function
// Ouput: the output of sigmoid activation function
double sigmoid(double x)
{
// ==========================
return 1.0 / (1 + pow(e, -x))
// ==========================
}

// Function: tanh activate function
// Input: double x: the input of tanh activation function
// Ouput: double: the output of tanh activation function.
double tanh(double x)
{
  // ==========================

  // Write your code here

  // ==========================
}

// Function: compute the next hidden value in an RNN cell
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: next hidden value in RNN cell
double ComputeH(double x, double h)
{
  // ==========================

  // Write your code here

  // ==========================
}

// Function: compute the output value at current time step
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: current output value
double ComputeO(double x, double h)
{
  // ==========================

  // Write your code here

  // ==========================

}

// Function: print the values stored in a 1D-array to screen
// Input: double xs[100]: the value of the sequence
//        int seq_len: the length of the sequence
void PrintSeqs(double xs[100], int seq_len)
{
  // ==========================

  // Write your code here

  // ==========================
}

// Function: main function
int main()
{
  // ==========================

  cout << sigmoid(1.23);

  // ==========================

}
