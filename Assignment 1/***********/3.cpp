// Shift Cipher [3.cpp]
// Implement an ecnryption/decryption algorithm in C++
// Created by Shaheer Ziya

/*
General Layout of The Program

1. Obtain User Inputs
  - First line, first char is mode of program (encryption/decryption)
  - Other characters are the text to be coded/decoded
  - Second line, first character is the number of letters in the key
  - Other characters are the key characters

2. Perform Encryption/Decryption
  - Create an array which stores the shift values as translated from the key characters
  - Iterate over all text characters and encrypt/decrypt each character separately
    - The shift value for each character can be found simply by considering the index of
      the text array (modulus the length of the key array)
    - For decryption, we simply use the inverse of the shift value we would use for exncryption
  - To perform the encryption/decryption, we first find the relative position of the character in the
    alphabet (which is found by subtracting the start (A or a) from that character--it is different for
    upper & lowercase char). Then we shift it's base position by the provided shift value and consider
    the result (mod 26). This is the relative position of the resultant character which we conver back to
    the ASCII (incrementing the value by 65 or 97 depending on the case) and finally convert the ASCII to
    a character. Lastly we change the case of the resultant character
    In case the relPos + shift is negative (in some cases of decryption), we increment it by 26 so everything
    remains constant.

3. Print results
  - Finally we print out the results (stored in the text array) to the screen using a for loop, without any
    spaces in between them.
*/

#include <iostream>
using namespace std;

const int MAXLEN{50}; // max length for input sequence of characters
const int MAXKEY{10}; // max length for key


char changeCase(char x)
{
  // Use ASCII to change the case of letters
  // If char is lowercase, subtract 32 to make it upper, else add 32 to get lower
  // 'a' := 97; 'z' := 122
  if ((int(x) < 123) && (int(x) > 96))
    return x - 32;
  // 'A' := 65, 'Z' := 90
  else if ((int(x) > 64) && (int(x) < 91))
    return x + 32;
  // Do nothing if not an alphabet
  else
    return x;
}

// Encrypt or Decrypt a character  +/- shift value
char encrypt(char input, int shift)
{
  int relPos;   // To store the relative position of the character in the alphabet
  // A := 65, Z := 90
  if ((64 < int(input)) && (int(input) < 91)) // A-Z
  {
    relPos = int(input) - 65; // A = 0, Z = 25
    // Conditional for decryption to keep relative position (+)ive
    if ((relPos + shift) < 0)
      relPos += 26;
    // "(relPos + shift) % 26" gives the relPos of the encoded/decoded char
    //  The + 65  returns back the ASCII code for the char, while char(ASCII) gives the corresponding chr
    //  Finally, changeCase() changes the case of the chr
    return changeCase(char(((relPos + shift) % 26) + 65));
  }
  // a := 97, z := 122 
  else if (((96 < int(input)) && (int(input) < 123))) // a-z
  {
    relPos = int(input) - 97; // a = 0, z = 25
    // Conditional for decryption to keep relative position (+)ive
    if ((relPos + shift) < 0)
      relPos += 26;
    return changeCase(char((relPos + shift) % 26) + 97);
  }
  // If not an alphabet, do nothin
  else
    return input;
}


int main()
{
  //! Sttore user inputs

  // First Line inputs
  char s; // 'e' for encryption, 'd' for decryption
  cin >> s;
  // The array containing the sequence of characters to encrypt/decrypt
  char text[MAXLEN];
  // Variable to count the number of characters in the text and keep track of their index in the array
  int numChr{0};
  // Keep taking input until the ! is entered
  while (text[numChr - 1] != '!')
  {
    cin >> text[numChr];
    numChr++;
  }

  // Second Line inputs
  // First input (n) in the 2nd line is the num of char in the Key.
  int keyLen;
  cin >> keyLen;
  // The array contaning the key
  char key[MAXKEY];
  // Store the characters of key in an array
  for (int i{0}; i < keyLen; i++)
  {
    cin >> key[i];
  }

  //! Perform the Encryption or decryption
  
  //Obtain the shift values from the key array
  int shiftVal [MAXKEY];
  for (int i{0}; i < keyLen; i++)
  {
    // Characters in key will all be Uppercase, so subtracting 65 gives 
    //    the position of each char such that A is 0
    shiftVal[i] = int(key[i]) - 65; // ASCII(A) = 65
  }

  // Iterate over the characters that are to be coded/decoded & perform encryption/decryption as necessary
  for (int i{0}; i < numChr; i++)
  {
    // Encryption
    if (s == 'e')
      text[i] = encrypt(text[i], (shiftVal[i % keyLen]));
    // Decryption by shifting -k
    else
      text[i] = encrypt(text[i], -(shiftVal[i % keyLen]));
  }

  //! Print resultant characters (stored in the text array) to the screen
  for (int i{0}; i < numChr; i++)
  {
    cout << text[i];
  }
  cout << endl;


  return 0;
}