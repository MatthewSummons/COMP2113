#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double a = 1.2345678;
 	double b = 1234567.8;

 	cout << a << '\n' << b << "\n\n";

    cout << setprecision(2);
    cout << a << '\n' << b << "\n\n";

    // with fixed notation
    cout << fixed;
    cout << a << '\n' << b << "\n\n";

    cout << setprecision(8);
    cout << a << '\n' << b << '\n';

    return 0;
}
