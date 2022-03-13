//void PrintSeqs(double xs[100], int seq_len)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double e = 2.72;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is

// The Sigmoid Activation Function
double sigmoid(double x)
{
  // sigmoid (x) = 1 / (1 + exp(-x))
  return 1 / (1 + pow(e, -x));
}

// Hyperbolic Tangent Function
double tanh(double x)
{
  return ( 2 * sigmoid (2 * x) ) - 1;
}

// Function: compute the next hidden value in an RNN cell
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: next hidden value in RNN cell
double ComputeH(double x, double h)
{
  // h_{t+1} = \tanh( 0.5x_t - 2h_t)
  return tanh((0.5 * x) - (2 * h));
}

// Function: compute the output value at current time step
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: current output value
double ComputeO(double x, double h)
{
  // o_t = sigmoid(0.1x_t + 1.5h_t) 
  return sigmoid( (0.1 * x) + (1.5 * h));
}

// // Function: print the values stored in a 1D-array to screen
// // Input: double xs[100]: the value of the sequence
// //        int seq_len: the length of the sequence
// {
//   // ==========================

//   // Write your code here

//   // ==========================
// }

// Function: main function
int main()
{
  // ==========================

  // First Line Input
  int T = 0;            // Recurrent Times (1 ≤ T ≤ 100)
  double hZero;     // Initial Hidden State
  cin >> T >> hZero;
  // Second Line Input
  int TimeArray[T - 1];
  for (int index = 0; index < T; index++)
  {
      cin >> TimeArray[index];
  }  
  for (int i = 0; i < T; i++)
  {
      cout << TimeArray[i] << endl;
  }


  // ==========================
  return 0;
}
