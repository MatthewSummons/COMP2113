// Reads in 8 characters from screen & outputs them in reverse order

#include <iostream>
using namespace std;

int main()
{
    int arraySize = 8;
    char letters[arraySize];
    // Store input characters in an array
    for (int i{0}; i < arraySize; i++)
    {
        cin >> letters[i];
    }

    // Output the content of the arrays in reverse order
    for (int i{arraySize - 1}; i >= 0; i--)
    {
        cout << letters[i] << endl;
    }

    return 0;
}