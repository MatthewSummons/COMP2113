#include <iostream>

using namespace std;

const int MAXLEN = 50; // max length for input sequence of characters
const int MAXKEY = 10; // max length for key

char changeCase(char x)
{
  // //  Alternate implementation of the function
  // if (isupper(x))
  //   return tolower(x);
  // else
  //   return toupper(x);
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

  // Test-cases for boundary-conditions
  // cout << changeCase('@') << endl;
  // cout << changeCase('A') << endl;
  // cout << changeCase('Z') << endl;
  // cout << changeCase('[') << endl;
  // cout << changeCase('`') << endl;
  // cout << changeCase('a') << endl;
  // cout << changeCase('z') << endl;
  // cout << changeCase('{') << endl;
}

char encrypt(char input, int shift)
{
  // Encrypt a character by shifting it up in the alphabet
  return changeCase(input + (shift % 26));
}

char decrypt(char code, int shift)
{
  // Decrypt a character by shifting it down in the alphabet
  return changeCase(code - (shift % 26));
}

int main()
{
  //! Sttore user inputs

  // First Line inputs
  char s; // 'e' for encryption, 'd' for decryption
  cin >> s;
  // The sequence of characters to encrypt/decrypt
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
  // The key
  char key[MAXKEY];
  // First input (n) in the 2nd line is the num of char in the Key.
  int keyLen;
  cin >> keyLen;
  // Store the characters of key in an array
  for (int i{0}; i < keyLen; i++)
  {
    cin >> key[i];
  }

  //! 
  
  // Print Text array to screen
  for (int i{0}; i < numChr; i++)
  {
    cout << text[i] << " ";
  }
  cout << endl;

  // Print the contents of the key array
  // for (int i{0}; i < keyLen; i++)
  // {
  //   cout << key[i] << " ";
  // }
  // cout << endl;

  return 0;
}
