// Play rock paper scissors with the computer
#include <iostream>
#include <cstdlib> // For srand() & rand()
#include <ctime>   // For time(NULL)

using namespace std;

int main()
{
  // Set the seed for the run (Take runtime as seed)
  srand(time(NULL));
  
  // Determine the user's choice
  cout << "What do you choose? [1: Rock | 2: Paper | 3: Scissors | 4: Exit]: ";
  int userChoice;
  cin >> userChoice;
  
  while (userChoice != 4)
  {
    // Determine the computer's choice
    int computerChoice = (rand() % 3) + 1;

    // Output the user and computer's choices to the screen
    cout << "Computer: " << computerChoice << ", User: " << userChoice << endl;
    // Determine the victor
    bool userVictorious {false};
    bool gameTie {false};
    // User chose Rock
    if (userChoice == 1)
    {
      if (computerChoice == 1) gameTie = true;
      else if (computerChoice == 2) userVictorious = false;
      else userVictorious = true; 
    }
    // User chose Paper
    else if(userChoice == 2)
    {
      if (computerChoice == 1) userVictorious = true;
      else if(computerChoice == 2) gameTie = true;
      else userVictorious = false;
    }
    // User chose Scissors
    else
    {
      if (computerChoice == 1) userVictorious = false;
      else if(computerChoice == 2) userVictorious = true;
      else gameTie = true;
    }

    // Print out the round results
    if (gameTie)
    {
      cout << "It was a tie!";
    }
    else if (userVictorious)
    {
      cout << "You won!";
    }
    else
    {
      cout << "The computer won!";
    }
    
    cout << endl;
    
    // Determine the user's choice for the next round
    cout << "What do you choose? [1: Rock | 2: Paper | 3: Scissors | 4: Exit]: ";
    cin >> userChoice;
    cout << endl; 
    
  }

  cout << "Have fun! Good Bye ~" << endl;




  return 0;
}