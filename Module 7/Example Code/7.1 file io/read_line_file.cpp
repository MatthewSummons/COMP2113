#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("data5.txt");
    if (fin.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    string line;

    while (getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();
    return 0;
}
