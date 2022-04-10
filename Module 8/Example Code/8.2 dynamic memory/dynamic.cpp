
#include <iostream>
using namespace std;
int main()
{
    int *p1, *p2;
    p1 = new int;
    *p1 = 42;
    p2 = p1;

    cout << "*p1 = " << *p1 << ", ";
    cout << "*p2 = " << *p2 << endl;

    *p2 = 53;
    cout << "*p1 = " << *p1 << ", ";
    cout << "*p2 = " << *p2 << endl;

    p1 = new int;
    *p1 = 88;
    cout << "*p1 = " << *p1 << ", ";
    cout << "*p2 = " << *p2 << endl;

    delete p1;
    delete p2;

    return 0;
}
