
#include <iostream>
using namespace std;

int main()
{
    int a[5];
  
    for (int i = 0; i < 5; ++i) {
        a[i] = 2*i;
    }

 
    int * p = a, * q = a + 5;

    while ( p != q ) {
        cout << *p << ' ';
        ++p;
    }
    cout << endl;

    return 0;
}
