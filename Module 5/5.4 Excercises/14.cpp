#include <iostream>
#include "13.h"

using namespace std;

int main()
{
    cout << "Please enter two numbers between which you would like to search perfect numbers for: ";
    int start, end;
    cin >> start >> end;

    for (int search = start; search <= end; search++)
    {
        if (isPerfectNumber(search))
            cout << search << " is a Perfect Number!" << endl;
    } 
    return 0;
}

