#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a = 1.2345678;
 	double b = 0.00012345678;
    double c = 1234567.8;
    double d = 0.000012345678;

    cout << a << endl << b << endl << c << endl << d << endl;

    cout << endl;

    double e = 12.0;
    cout << e << endl;
    cout << showpoint << e << endl;

    return 0;
}
