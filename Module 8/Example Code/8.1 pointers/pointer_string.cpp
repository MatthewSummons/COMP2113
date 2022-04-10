#include <iostream>
#include <string>
using namespace std;


int main()
{
    // accessing member functions of a class
    string s = "good day!";
    string * sPtr = &s;     // sPtr points to s

    cout << "length of string: " << s.length() << endl;
    cout << "1st word: " << (*sPtr).substr(0, 4) << endl;
    cout << "2nd word: " << sPtr->substr(5, 3) << endl;

    cout << "sixth letter: " << (*sPtr)[5] << endl;

    return 0;
}
