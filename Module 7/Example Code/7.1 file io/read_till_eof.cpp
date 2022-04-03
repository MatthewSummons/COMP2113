#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("data4.txt");
    if (fin.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    double x, sum = 0;
    while (fin >> x)
    {
        sum += x;
    }
    fin.close();
    cout << "Total = " << sum << endl;
    return 0;
}
