#include <iostream>
using namespace std;


int main()
{
    int x = 0;
    int * dangling_ptr;


    cout << *dangling_ptr << endl;      // this is unpredictable & dangerous!


    int * ptr = nullptr;           // initialize a ptr to 0

    // cout << *ptr << endl;       // this will crash the program!

    // to be safe, check if the pointer is null
    // or not before using it
    if (ptr != nullptr)
        cout << "1: " << *ptr << endl;


    ptr = &x;

    if (ptr != nullptr)
        cout << "2: " << *ptr << endl;

    return 0;
}
