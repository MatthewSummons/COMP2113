// Luhn's Algorithm Implementation in C
// A Simple Checksum Method to Prevent Transcription Errors
// Created by Shaheer Ziya on Apr 3, 2022

#include <stdio.h> // For prinntf(), scanf()
#include <string.h> // For C-string handling functions
#include <stdlib.h> // For string to int/float conversions (atoi, atof)

// Maximum number of digits in the input sequence
#define MAX_DIGITS 30 


// Convert a numeral character to an integer
int charToint(char c)
{
  // Convert the character to an integer (using ASCII)
  if ((c >= '0') && (c <= '9'))
  // Character comparisons work in C
    return c - '0';
  else
    return c;
}


// Find the sum of odd the digits in a sequence (1, 3, 5, ...)
int partialOddSum(char revSeq[], int seqLen)
{
  int partialSum = 0;
  // Odd digits will be found at even indices because of the zero-index offset
  for (int i = 0; i < seqLen; i += 2)
  {
    // Convert the character to an integer
    int digit = charToint(revSeq[i]);
    // Add the digit to the partial sum
    partialSum += digit;
  }

  return partialSum;
}

// Find the sum of even the digits in a sequence (2, 4, 6, ...) (Luhn's Algorithm)
int partialEvenSum(char revSeq[], int seqLen)
// Multiply the even digits by 2 and add the digit-sum to the partial sum
// The digit sum for a number is defined as the sum of the digits of the number
// (e.g. the digit-sum of 1234 is 1 + 2 + 3 + 4 = 10)
{
  int partialSum = 0;
  // Even digits will be found at odd indices because of the zero-index offset
  for (int i = 1; i < seqLen; i += 2)
  {
    // Convert the character to an integer
    int digit = charToint(revSeq[i]);
    // Multiply the digit by 2
    digit *= 2;
    // Add the digit-sum to the partial sum
    // In this case the digit sum will only expect 2-digit numbers so no fancy function required
    partialSum += (digit / 10) + (digit % 10);
  }

  return partialSum;
}

int main()
{
  // Hold the characters in the input sequence of digits
  char sequence[MAX_DIGITS];
  // Obtain the input sequence of digits as a string & store it as a C-string
  scanf("%s", sequence);

  int seqLen = strlen(sequence); // Length of the input sequene
  char sequence_reverse[seqLen]; // Hold the reversed sequence of digits
  // Reverse the sequence of digits
  for (int i = seqLen; i >= 0; i--)
  {
    // 8 -> 0; 7 -> 1; ... ; 1 -> 7; 0 -> 8
    sequence_reverse[(seqLen-1) - i] = sequence[i];
  }

  // Find the partial sum of the odd digits (1, 3, 5, ...) in the reversed sequence
  
  int s1 = 0; // Partial sum of odd digits in the reversed sequence
  s1 = partialOddSum(sequence_reverse, seqLen);

  int s2 = 0; // Partial sum of even digits (2, 4, 6, ...) in the reversed sequence
  s2 = partialEvenSum(sequence_reverse, seqLen);

  // Dislpay the reversed sequence
  for (int i= 0; i < seqLen; i++)
  {
    printf("%c", sequence_reverse[i]);
  }
  printf("\n");
  // Display the partial sums
  printf("%d %d\n", s1, s2);
  // Display if the input string was a valid number
  if ((s1 + s2) % 10 == 0)
    printf("valid\n");
  else
    printf("invalid\n");


  return 0;
}
