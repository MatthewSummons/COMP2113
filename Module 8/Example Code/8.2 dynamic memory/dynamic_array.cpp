
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    // create a dynamic array
    int * p = new int [n];

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cout << "Contents of the array: ";
    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }
    cout << endl;

    // free memory allocated to array
    delete [] p;

    return 0;
}
