#include <iostream>

using namespace std;


int main()
{
    int a[10], i;

    for ( i = 0; i < 10; ++i )
        a[i] = 2 * i;

    int * p = a;

    for ( i = 0; i < 10; ++i )
        cout << p[i] << ' ';
    cout << endl;


    int * q = &a[0];
    for ( i = 0; i < 10; ++i )
        cout << q[i] << ' ';
    cout << endl;

    p = &a[2];
    cout << p[3] << endl;

    return 0;
}
