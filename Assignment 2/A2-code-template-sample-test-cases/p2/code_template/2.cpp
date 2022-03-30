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
void ReadBoard( int b[][9] )
{

}

// display the game board stored in the 2D array b
void PrintBoard( int b[][9] )
{

}


// solve a game board stored in b using the Naked Single technique only
// the (partial) solution is stored in the input array b
void SolveBoard( int b[][9] )
{


}

// You do not need to change anything in the main() function
int main()
{
  int board[9][9];    // the 9x9 game board

  ReadBoard( board );

  cout << "Input Sudoku board:" << endl;
  PrintBoard( board );

  // solve the board using the naked single technique only
  SolveBoard( board );

  cout << endl;
  cout << "Final Sudoku board:" << endl;
  PrintBoard( board );

  return 0;
}
