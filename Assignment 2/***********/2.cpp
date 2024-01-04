// use https://www.sudoku-solutions.com/ to generate a board
// this website also supports using particular techniques to solve for a board
// from preferences, choose Naked-Singles only or partial solving
// then click "Solve Partially", you may then cross-check with your progran output

#include <iostream>

using namespace std;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is
//             You may add other functions wherever appropriate

// get user input and store the game board in the 2D array b
void ReadBoard(int b[][9])
{
  for (int i {0}; i < 9; i++)
  {
    for (int j {0}; j < 9; j++)
    {
      cin >> b[i][j];
    }
  }
}

// display the game board stored in the 2D array b
void PrintBoard(int b[][9])
{
  for (int i {0}; i < 9; i++)
  {
    // Print the horizontal padding b/w squares
    if (i == 3 || i == 6)
      cout << "------+-------+-------" << endl;
    
    for (int j {0}; j < 9; j++)
    {
      // Add the padding between sqaures
      if (j == 3 || j == 6)
        cout << "| ";
      
      // Print the digit if it is not 0
      if (b[i][j] != 0)
        cout << b[i][j] << " ";
      else
        cout << "x" << " ";
    }
    cout << endl;
  }
}


// Determine which row/column the 3x3 square starts at for a given box on the 9x9 board
int squareStart(int x)
{
  // Works equivalently for rows & column

  if (x < 3)
    return 0;
  else if (x < 6)
    return 3;
  else
    return 6;
}

// Determine if there is only a single 1 in an array
bool singleChoice(int arr[])
{
  int choices { 0 };
  for (int i {1}; i < 10; i++)
  {
    if (arr[i] == 1)
      choices++;
  }
 
  if (choices == 1)
    return true;
  else
    return false;
}

// Find the first 1 in an array
int findChoice(int arr[])
{
  for (int i {1}; i < 10; i++)
  {
    if (arr[i] == 1)
      return i;
  }
  // Error Code
  return -1;
}

// solve a game board stored in b using the Naked Single technique only
// the (partial) solution is stored in the input array b
void SolveBoard(int b[][9])
{
  // Iterate over the whole board [i:= rows, j:= columns]
  for (int i{0}; i < 9; i++)
  {
    for (int j{0}; j < 9; j++)
    {
      // Eliminate the non-possible choices for the box by iterating over the row, column &
      // 3x3 square that box corresponds to
      
      // Initialize a binary ("boolean") array which stores the possible choices for each square 
      int choices [10] = {0,1,1,1,1,1,1,1,1,1};
      // If the value of the box is 0, then there is a choice for that square
      if (b[i][j] == 0)
      {
        
        // Iterate over the row and eliminate choices
        for (int k{0}; k < 9; k++)
        {
          choices[b[i][k]] = 0;
        }
        
        // Iterate over the column and eliminate choices
        for (int k{0}; k < 9; k++)
        {
          choices[b[k][j]] = 0;
        }

        // Determine the starting row and column of the 3x3 square
        int row_start = squareStart(i), col_start = squareStart(j);
        // Iterate over the 3x3 square and eliminate choices
        for (int k {row_start}; k < row_start + 3; k++)
        {
          for (int l {col_start}; l < col_start + 3; l++)
          {
            // The inner index evaluates to the value in the 3x3 square
            // Setting that index of the choices array to 0 eliminates that choice
            choices[b[k][l]] = 0;
          }
        }


        // Check if there is only 1 possible choice for the box
        if (singleChoice(choices))
        {
          // If there is only 1 choice, set the square to that choice
          b[i][j] = findChoice(choices);
          
          // Try to solve the board again and see if the updated board helps with that
          // The base case for this recursive call is when there is no square with a single choice 
          SolveBoard(b);
        }
      }
    }
  }
}

// You do not need to change anything in the main() function
int main()
{
  int board[9][9]; // the 9x9 game board

  ReadBoard(board);

  cout << "Input Sudoku board:" << endl;
  PrintBoard(board);

  // solve the board using the naked single technique only
  SolveBoard(board);

  cout << endl;
  cout << "Final Sudoku board:" << endl;
  PrintBoard(board);

  return 0;
}
