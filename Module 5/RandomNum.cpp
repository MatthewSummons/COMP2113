// RandomNum.cpp

#include <iostream>
#include <cstdlib> // For srand() & rand()
#include <ctime>   // For time()
using namespace std;

int main()
{
    srand(time(NULL));
    for (int i=0; i<=10; ++i)
        {cout << (rand() % 50) + 1 << endl;}
    return 0;
}