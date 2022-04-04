// Reverse a string in C++
// Modified by Shaheer Ziya

#include <iostream>
#include <string>

using namespace std;

/*
// iterative version
string reverse( string s )
{
  string r = "";

  for (int i = 0; i < s.length(); ++i)
    r = s[i] + r;

  return r;
}
*/

// recursive version
string reverse(string s)
{
  if (s.length() == 0)
    return "";
  else
  {
    int lastIndex = s.length() - 1;
    return s[lastIndex] + reverse(s.substr(0, lastIndex));
  }
}

int main()
{
  string s;
  cin >> s;

  cout << "String in reverse = " << reverse(s) << endl;

  return 0;
}