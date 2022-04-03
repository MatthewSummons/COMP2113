#include <iostream>
#include <string>

using namespace std;

bool is_palindrome( string s )
{
    if (s.length() < 2)
        return true;
    else
        return (s[0] == s[s.length()-1]) && is_palindrome(s.substr(1,s.length()-2));
}

int main()
{
    string str;
    cout << "enter a string: ";
    cin >> str;
    if (is_palindrome(str))
        cout << str << " is a palindrome\n";
    else
        cout << str << " is not a palindrome\n";

    return 0;
}
