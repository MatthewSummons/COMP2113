// 6-131.cpp
// Read in a 5x5 pattern and rotate it
// Created by Shaheer Ziya on Mar 25, 2022

// Transpose swaps the rows and columns of a matrix [ (A^T)^T = A ]
// 90 DEG anticlockwise rotation is transpose of the original matrix followed by reversing its columns
// 90 DEG clockwise rotation is transpose of the original matrix followed by reversing its rows

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

void printArr(char Arr[][numCols], int numRows)
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

void rotateArr(char Arr[][numCols], int numRows)
// Rotate the array by 90 DEG clockwise (Perform a matrix transpose and then reverse rows)
{
  // Transpose the array
  for (int row{0}; row < numRows; row++)
  {
    // Iterate until row, col equal to avoid re-swapping elements
    for (int col{0}; col <= row; col++)
    {
      swap(Arr[row][col], Arr[col][row]);
    }
  }
  
  // Reverse the rows
  for (int row{0}; row < numRows; row++)
  {
    // Iterate until half the length 
    for (int col{0}; col < numCols / 2; col++)
    {
      // (0, 1, 2, 3, 4) -> (4, 3, 2, 1, 0)
      swap(Arr[row][col], Arr[row][numCols - col - 1]);
    }
  }
}

void swap(int &row, int &col)
{
  int temp = row;

  row = col;
  col = temp;
}

int main()
{
  char patternArray[numRows][numCols];

  fillArr(patternArray, numRows);
  // printArr(patternArray, numRows);

  cout << endl;
  cout << "The pattern after a 90 DEG clockwise rotation is: " << endl;
  cout << endl;

  rotateArr(patternArray, numRows);
  printArr(patternArray, numRows);

  return 0;
}