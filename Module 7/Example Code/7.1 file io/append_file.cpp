#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("data2.txt", ios::app);

    if (fout.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    string name = "Simon";
    int age = 20;
    double weight = 135.3;

    fout << name << " " << age << " " << weight << endl;
    fout.close();

    return 0;
}
