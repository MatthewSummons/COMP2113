// A 5-Card Hand [4.cpp]
// Program that generates a random hand of 5 poker hands from a deck of 52 poker cards
// & determines the type of hand it is
// Created by Shaheer Ziya on UTC+08 23:12

/*
General Layout of The Program

1. Create a normal poker deck using a 2D array storing all the cards as strings
2. Obtain a seed from the user (integer) to use in srand()
3. 


n. Display your hand & its type

*/

#include <iostream>
#include <cstdlib>  // For calling srand(), rand()
#include <ctime>    // For calling time()
#include <string>     // For storing name of the cards

#define SPADE "\xE2\x99\xA0"
#define HEART "\xE2\x99\xA5"
#define CLUB "\xE2\x99\xA3"
#define DIAMOND "\xE2\x99\xA6"
#define NUMCARDS 5

using namespace std;

void DealHand(int cards[])
{
  // Obatin the seed for srand() from user
  int seed;
  cin >> seed;
  // Set the seed for RNG
  srand(seed);

  int cardIndex;
  for (int i{0}; i < 5; i++)
  {
    cards[i] = rand() % 52;
  }
}

void PrintHand(int cards[])
{
  // cards[i] contains the index of the card to be printed
  for (int i{0}; i < NUMCARDS; i++)
  {
    // Convert Index to Card
    // Determine the rank of the card (13 Cards in a suit)
    string cardRank;
    if (cards[i] % 13 == 0) // First card in the suit
      cardRank = "A";
    else if (cards[i] % 13 < 10)                 // The numeric cards (2-10) in the suit
      cardRank = to_string((cards[i] % 13) + 1); // Card Value = Card Index (mod 13) + 1
    else if (cards[i] % 13 == 10)
      cardRank = "J"; // Jack
    else if (cards[i] % 13 == 11)
      cardRank = "Q"; // Queen
    else
      cardRank = "K"; // King
    // Determine the suit of the card
    string cardSuit;
    if (cards[i] < 13)
      cardSuit = SPADE;
    else if (cards[i] < 26)
      cardSuit = HEART;
    else if (cards[i] < 39)
      cardSuit = CLUB;
    else
      cardSuit = DIAMOND;
    
    // Print out the selected card
    cout << cardRank << cardSuit << " ";
  }
  cout << endl;
}

int main()
{
  int hand[NUMCARDS]; // declare an array of 5 integers to store a hand

  // Generate 5 random cards
  DealHand(hand);
  PrintHand(hand); 
  

  
  
  return 0;
}
