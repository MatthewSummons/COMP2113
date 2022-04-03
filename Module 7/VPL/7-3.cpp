// Calculate the average temperature in a given day & record it in a file
// Created by Shaheer Ziya

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define NUM_TEMPS 24


double average(double arr[], int arrSize)
{
  double Sum;
  for (int i{0}; i < arrSize; i++)
  {
    Sum += arr[i];
  }
  return Sum / arrSize;
}


int main()
{
  
  // Open Temperatures File
  ifstream Temp;
  Temp.open("temperature.txt");

  if (Temp.fail())
  {
    cout << "Error opening file." << endl;
    exit (1);
  }

  // Open Avergae File
  ofstream Avg;
  Avg.open("average.txt");

  if (Avg.fail())
  {
    cout << "Error opening file." << endl;
    exit (1);
  }

  // Read Temperatures File
  double TempArr[NUM_TEMPS];

  string Day;
  // Read until eof
  while (Temp >> Day)
  {
    // Store Temperatures in Array
    for (int i{0}; i < NUM_TEMPS; i++)
    {
      Temp >> TempArr[i];
    }

    // Calculate Average
    double AvgTemp = average(TempArr, NUM_TEMPS);
    
    // Write to the Average File
    Avg << Day << " ";
    Avg << setprecision(1) << fixed << AvgTemp << endl;
  }

  
  // Close the files
  Temp.close();
  Avg.close();
  
  return 0;
}