#include <iostream>
using namespace std;

double input[10];

int main()
{
    double sum{0};
    for (int i = 0; i < 10; i++)
    {
        cin >> input[i];
        sum += input[i];
    }

    cout << sum << endl;

    return 0;
}