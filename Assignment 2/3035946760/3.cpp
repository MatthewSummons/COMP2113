// Morse Code Decoder
// Created by Shaheer Ziya on Apr 3, 2022

#include <iostream>
#include <string>

using namespace std;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is
//             You may add other functions wherever appropriate

// Function which converts a character in morse code to text
string morseChartoChar(string s)
// Non-ideal some data structure is probably better suited for this
{
  // The Alphabet
  if (s == "._")
    return "A";
  else if (s == "_...")
    return "B";
  else if (s == "_._.")
    return "C";
  else if (s == "_..")
    return "D";
  else if (s == ".")
    return "E";
  else if (s == ".._.")
    return "F";
  else if (s == "__.")
    return "G";
  else if (s == "....")
    return "H";
  else if (s == "..")
    return "I";
  else if (s == ".___")
    return "J";
  else if (s == "_._")
    return "K";
  else if (s == "._..")
    return "L";
  else if (s == "__")
    return "M";
  else if (s == "_.")
    return "N";
  else if (s == "___")
    return "O";
  else if (s == ".__.")
    return "P";
  else if (s == "__._")
    return "Q";
  else if (s == "._.")
    return "R";
  else if (s == "...")
    return "S";
  else if (s == "_")
    return "T";
  else if (s == ".._")
    return "U";
  else if (s == "..._")
    return "V";
  else if (s == ".__")
    return "W";
  else if (s == "_.._")
    return "X";
  else if (s == "_.__")
    return "Y";
  else if (s == "__..")
    return "Z";

  // Whitespace
  else if (s == " ")
    return " ";

  // Numerals
  else if (s == ".____")
    return "1";
  else if (s == "..___")
    return "2";
  else if (s == "...__")
    return "3";
  else if (s == "...._")
    return "4";
  else if (s == ".....")
    return "5";
  else if (s == "_....")
    return "6";
  else if (s == "__...")
    return "7";
  else if (s == "___..")
    return "8";
  else if (s == "____.")
    return "9";
  else if (s == "_____")
    return "0";

  // Empty string
  else if (s == "")
    return "";

  // Unkown Character
  else
  {
    return "?";
  }
}

// Decode the morse code 's' and return the text character
string morseCodeToText(string s)
{
  string text = "";

  // Add a marker to indicate end of the word
  s += "||";

  // 3 Cases
  // | is new char, || is new word, ./- is a morse char

  // Initialize a string to hold the morse characters
  string morseWord;
  // Iterate through the morse code string
  for (int i{0}; i < s.length(); i++)
  {
    // '|' indicates the possibility a new word or character
    if (s[i] == '|')
    {
      // "|" indicates a new character
      // Decode the morse character and add it to the text
      text += morseChartoChar(morseWord);
      // Clear the morse word for new morse character
      morseWord = "";

      // "||" indicates a new word
      if (s[i + 1] == '|')
      {
        // Add the text word to the text (with space)
        text += " ";
      }
    }

    else
    {
      // Add the morse character to the morse word
      morseWord += s[i];
    }
  }

  // Return the decoded text with no trailing whitespaces
  return text.substr(0, text.length()-1);
}

int main()
{
  string s;
  cin >> s;
  cout << morseCodeToText(s) << '\n';

  return 0;
}
