#include <iostream>
using namespace std;

int main()
{
    // Handle user input to ensure number in the correct range is taken
    int inputNum;
    cout << "Enter a number to be conerted: ";
    cin >> inputNum;
    while ((inputNum < 0) or (inputNum > 99))
    {
        cout << "Please enter an integer in the valid range [1,99]:";
        cin >> inputNum;
    }

    if (inputNum >= 20)
    {
        switch (inputNum / 10)
        {
        case 2:
            cout << "twenty-";
            break;
        case 3:
            cout << "thirty-";
            break;
        case 4:
            cout << "forty-";
            break;
        case 5:
            cout << "fifty-";
            break;
        case 6:
            cout << "sixty-";
            break;
        case 7:
            cout << "seventy-";
            break;
        case 8:
            cout << "eighty-";
            break;
        case 9:
            cout << "ninety-";
            break;
        default:
            break;
        }
    }
    if ((inputNum < 10) || (inputNum >= 20))
    {
        switch (inputNum % 10)
        {
        case 1:
            cout << "one" << endl;
            break;
        case 2:
            cout << "two" << endl;
            break;
        case 3:
            cout << "three";
            break;
        case 4:
            cout << "four";
            break;
        case 5:
            cout << "five";
            break;
        case 6:
            cout << "six";
            break;
        case 7:
            cout << "seven";
            break;
        case 8:
            cout << "eight";
            break;
        case 9:
            cout << "nine";
            break;
        }
    }

    // If Input Num in [10,20)
    else
    {
        switch (inputNum % 10)
        {
        case 0:
            cout << "ten";
            break;
        case 1:
            cout << "eleven";
            break;
        case 2:
            cout << "twelve";
            break;
        case 3:
            cout << "thirteen";
            break;
        case 4:
            cout << "fourteen";
            break;
        case 5:
            cout << "fifteen";
            break;
        case 6:
            cout << "sixteen";
            break;
        case 7:
            cout << "seventeen";
            break;
        case 8:
            cout << "eighteen";
            break;
        case 9:
            cout << "nineteen";
            break;
        }
    }
    cout << endl;

    return 0;
}