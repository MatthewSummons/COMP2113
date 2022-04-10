#include <iostream>

using namespace std;

int main()
{
    int i;
    char c;

    cout << &i << ' ' << (void *)&c << endl;

    return 0;
}
