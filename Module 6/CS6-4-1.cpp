// CS6-4-1.cpp
// Variance
// Created by Shaheer Ziya

#include <iostream>
#include <cmath>
using namespace std;

double Mean (double data[], int dataLen)
// Calculate the mean of a data set
{
  double sum {0};
  for (int i {0}; i < dataLen; i++)
  {
    sum += data[i];
  }
  return sum / dataLen;
}


double Variance (double data[], int dataLen)
// Calculate the varaince of a data set
{
  double Var {0};
  double mu = Mean (data, dataLen);
  
  // Var = (x-mu)^2 / n
  for (int i {0};  i < dataLen; i++)
  {
    Var += pow ((data[i] - mu), 2);
  }
  
  Var /= dataLen;
  
  return Var;
}

int main()
{
  const int arrLen {20};
  double Data[arrLen] = {0};

  // Obtain the number of Data Entries
  int DataLen;
  cin >> DataLen;

  // Obtain the Data
  double temp;
  for (int i {0}; i < DataLen; i++)
  {
    cin >> Data[i];
  }

  cout << "Variance = " << Variance(Data, DataLen) << endl;
  
  // // Print the elements of the array
  // for (int i {0}; i < DataLen; i++)
  // {
  //   // cout << "The variance of the Data is: " << variance(Data, DataLen) << endl;
  //   cout << Data[i] << " ";
  // }
  // cout << endl;




  return 0;
}