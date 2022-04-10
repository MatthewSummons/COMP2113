#include <iostream>

using namespace std;

int main()
{
    int x = 10, y;
    int * ptr = &x;

    y = *ptr;
    *ptr = 20;
    cout << x << ' ' << y << endl;
    cout << *ptr << endl;

    ptr = &y;
    (*ptr)++;
    cout << x << ' ' << y << endl;
    cout << *ptr << endl;

    return 0;
}
