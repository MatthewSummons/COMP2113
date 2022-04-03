#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int x = 12;
    string a = "Hello";
    double b = 34.567;

    cout << fixed << setprecision(2);
    cout << "12345678901234567890\n";

 	cout << setw(5) << x << setw(8) << a;
 	cout << setw(6) << b << endl;

 	cout << setfill('*');
 	cout << setw(5) << x << setw(8) << a;
 	cout << setw(6) << b << endl;

 	cout << setfill('-');
    cout << left;
 	cout << setw(5) << x << setw(8) << a;
 	cout << setw(6) << b << endl;

    cout << right;
 	cout << setw(5) << x << setw(8) << a;
 	cout << setw(6) << b << endl;

    return 0;
}
