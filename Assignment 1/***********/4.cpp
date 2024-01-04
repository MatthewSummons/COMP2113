// A 5-Card Hand [4.cpp]
// Program that generates a random hand of 5 poker hands from a deck of 52 poker cards
// & determines the type of hand it is
// Created by Shaheer Ziya

/*
General Layout of The Program

1. Obtain a seed from the user (integer) to use in srand() & generate 5 randomn ints
2. Create Cards from those integers (which have been stored in the hand array)
3. Check the type of hand the user has, going down the list staring from the highest type (four of a kind) 
    down to one pair.
*/

#include <iostream>
#include <cstdlib>      // For calling srand(), rand()
#include <ctime>        // For calling time()
#include <string>       // For storing name of the cards
// UTF-8 encoding for the suits' symbols
#define SPADE "\xE2\x99\xA0"
#define HEART "\xE2\x99\xA5"
#define CLUB "\xE2\x99\xA3"
#define DIAMOND "\xE2\x99\xA6"
// Number of cards in the hand
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

bool IsFourOfAKind(int cards[]);      // return if the hand is a four of a kind
bool IsFullHouse(int cards[]);        // return if the hand is a full house
bool IsFlush(int cards[]);            // return if the hand is a flush
bool IsThreeOfAKind(int cards[]);     // return if the hand is a three of a kind
bool IsTwoPair(int cards[]);          // return if the hand is a two pair
bool IsOnePair(int cards[]);          // return if the hand is a one pair

int main()
{
  int hand[NUMCARDS]; // declare an array of 5 integers to store a hand

  // Generate 5 random cards
  DealHand(hand);
  PrintHand(hand);

  if (IsFourOfAKind(hand))
    cout << "four of a kind";
  else if (IsFullHouse(hand))
    cout << "full house";
  else if (IsFlush(hand))
    cout << "flush";
  else if (IsThreeOfAKind(hand))
    cout << "three of a kind";
  else if (IsTwoPair(hand))
    cout << "two pair";
  else if (IsOnePair(hand))
    cout << "one pair";
  else
    cout << "others";
  
  cout << endl;

  return 0;
}

bool IsFourOfAKind(int cards[])   // return if the hand is a four of a kind
{
  // 4 cards of same rank, 1 card of different rank
  
  // Initialize an array with 13 elements, where it's (index + 1) represents the rank of a card
  int ranks[13] = {0};            // Stores the frequency of the cards' ranks
  // Iterate over the hand and store the ranks of each card in the ranks array
  for (int card{0}; card < NUMCARDS; card++)
  {
    // (cards[card] % 13) returns the rank of the card
    ranks[(cards[card] % 13)]++; 
  }
  // Iterate over the ranks array & see if there are ranks of frequency 4
  for (int i{0}; i < 13; i++)
  {
    if (ranks[i] == 4)
      return true;
  }
  // If no rank with frequncy 4 in ranks, then hand is not Four of a Kind 
  return false;
}
bool IsFullHouse(int cards[])     // return if the hand is a full house
{
  // 3 cards of same rank & 2 cards of another same rank
  
  // Initialize an array with 13 elements, where it's (index + 1) represents the rank of a card
  int ranks[13] = {0}; // Stores the frequency of the cards' ranks
  // Iterate over the hand and store the ranks of each card in the ranks array
  for (int card{0}; card < NUMCARDS; card++)
  {
    // (cards[card] % 13) returns the rank of the card
    ranks[(cards[card] % 13)]++;
  }
  // Initialize boolean flags which check if rank of at least 1 element in the array is 2 or 3
  bool rankIs2 {false}, rankIs3 {false};
  // Iterate over the frequency of ranks in the hand
  for (int i{0}; i < 13; i++)
  {
    // Check if any of the elements has frequnecy 2 or 3 & modify its flag correspondingly
    if (ranks[i] == 2)
      rankIs2 = true;
    if (ranks[i] == 3)
      rankIs3 = true;
  }

  if (rankIs2 && rankIs3)
    return true;
  else
    return false;
}
bool IsFlush(int cards[])         // return if the hand is a flush
{
  // 5 cards of the same suit

  // Store the frequency of each Suit in the hand
  int suitFreq[4] = {0};     // Init all values to zero
  // Iterate over the hand to collect true freq of suits in hand
  for (int i{0}; i < NUMCARDS; i++)
  {
    if (cards[i] < 13)
      suitFreq[0]++;          // Spades
    else if (cards[i] < 26)
      suitFreq[1]++;          // Hearts
    else if (cards[i] < 39)
      suitFreq[2]++;          // Clubs 
    else
      suitFreq[3]++;          // Diamonds
    }
  // Check if any of the suits has frequency 5
  for (int i{0}; i < 4; i++)
  {
    if (suitFreq[i] == 5)
      return true;
  }

  return false;
}
bool IsThreeOfAKind(int cards[])  // return if the hand is a three of a kind
{
  // 3 cards of same rank & 2 cards of two other rank

  // Initialize an array with 13 elements, where it's (index + 1) represents the rank of a card
  int ranks[13] = {0}; // Stores the frequency of the cards' ranks
  // Iterate over the hand and store the ranks of each card in the ranks array
  for (int card{0}; card < NUMCARDS; card++)
  {
    // (cards[card] % 13) returns the rank of the card
    ranks[(cards[card] % 13)]++;
  }
  // Iterate over the ranks array & see if there are ranks of frequency 3
  for (int i{0}; i < 13; i++)
  {
    // Guard to ensure hand isn't full house
    if (ranks[i] == 2)
      return false;
    // Check if three of a kind
    if (ranks[i] == 3)
      return true;
  }
  // If no rank with frequncy 3 in ranks, then hand is not Four of a Kind
  return false;
}
bool IsTwoPair(int cards[])       // return if the hand is a two pair
{
  // 2 cards of one rank, 2 cards of another rank & 1 card of a different rank

  // Initialize an array with 13 elements, where it's (index + 1) represents the rank of a card
  int ranks[13] = {0}; // Stores the frequency of the cards' ranks
  // Iterate over the hand and store the ranks of each card in the ranks array
  for (int card{0}; card < NUMCARDS; card++)
  {
    // (cards[card] % 13) returns the rank of the card
    ranks[(cards[card] % 13)]++;
  }

  // Count the number of pairs in the hand
  int pairs {0};
  for (int i{0}; i < 13; i++)
  {
    if (ranks[i] == 2)
      pairs++;
  }
  // Check if two pair
  if (pairs == 2)
    return true;
  else
    return false;
}
bool IsOnePair(int cards[])       // return if the hand is a one pair
{
  // 2 cards of one rank & 3 cards each of different ranks

  // Initialize an array with 13 elements, where it's (index + 1) represents the rank of a card
  int ranks[13] = {0}; // Stores the frequency of the cards' ranks
  // Iterate over the hand and store the ranks of each card in the ranks array
  for (int card{0}; card < NUMCARDS; card++)
  {
    // (cards[card] % 13) returns the rank of the card
    ranks[(cards[card] % 13)]++;
  }

  // Count the number of pairs in the hand
  int pairs{0};
  for (int i{0}; i < 13; i++)
  {
    if (ranks[i] == 2)
      pairs++;
  }
  // Check if one pair
  if (pairs == 1)
    return true;
  else
    return false;
}