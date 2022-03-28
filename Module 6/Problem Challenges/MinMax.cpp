// MinMax.cpp
// Find the minimun and maximum values in a 2x2x3 array
// Created by Shaheer Ziya

#include <iostream>
using namespace std;

int main()
{
  const int Rows = 2, Cols = 2, Depth = 3;
  double x[Rows][Cols][Depth] = {{{3, 4, 2}, {0, -3, 9}}, {{13, 4, 56}, {5, 9, 3}}};
  
  double min, max = 0;

  for (int i{0}; i < Rows; i++)
  {
    for (int j{0}; j < Cols; j++)
    {
      for (int k{0}; k < Depth; k++)
      {
        if (x[i][j][k] > max)
        {
          max = x[i][j][k];
        }
        else if (x[i][j][k] < min)
        {
          min = x[i][j][k];
        }
      }
    }
  }

  cout << "The minium value is: " << min << endl;
  cout << "The maximum value is: " << max << endl;
  
  return 0;
}