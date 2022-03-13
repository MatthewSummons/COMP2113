#include <iostream>
using namespace std;

const int centreSize = 7;

int main()
{
    for (int line = 1; line < (centreSize + 1) / 2; line++)
    {
        for (int stars = 1; stars <= line; stars += 2)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}