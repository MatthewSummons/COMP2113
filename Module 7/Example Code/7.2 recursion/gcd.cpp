#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}


int main()
{
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "gcd = " << gcd(a, b) << endl;
}
