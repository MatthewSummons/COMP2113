// 6-13.cpp
// Read in a 5x5 pattern and tanspose it
// Created by Shaheer Ziya on Mar 24, 2022

#include <iostream>
using namespace std;

// Declare the quantity of rows & columns in the main array to be used
const int numRows{5}, numCols{5};


void fillArr(char Arr[][numCols], int numRows)
// Read from standard output & add elements into an array
{
  for (int row{0}; row < numRows; row++)
  {
    for (int col{0}; col < numCols; col++)
    {
      cin >> Arr[row][col];
    }
  }
}


void printArr(char Arr[][numCols],int numRows)
// Print the elements of a 2D character array
{
  for (int row{0}; row < numRows; row++)
  {
    for (int col{0}; col < numCols; col++)
    {
      cout << Arr[row][col];
    }
    cout << endl;
  }
}


void TransposeArr(char Arr[][numCols], int numRows)
// Rotate the array by 90 DEG clockwise (Perform a matrix transpose)
{
  for (int row{0}; row < numRows; row++)
  {
    // Iterate until row, col equal to avoid re-swapping elements
    for (int col{0}; col <= row; col++)
    {
      swap(
        Arr[row][col],
        Arr[col][row]
      );
    } 
  }
}


void swap(int& row, int& col)
{
  int temp = row;

  row = col;
  col = temp;
}


int main()
{
  char patternArray [numRows][numCols];

  fillArr(patternArray, numRows);
  // printArr(patternArray, numRows);
  
  cout << endl;
  cout << "The pattern after a matrix transposition is: " << endl;
  cout << endl;

  TransposeArr(patternArray, numRows);
  printArr(patternArray, numRows);

  return 0;
}