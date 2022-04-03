#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    char filename[80] = "data3.txt";
    ifstream fin;
    fin.open(filename);

    if (fin.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    string name;
    int age;
    double weight;

    fin >> age >> weight >> name;
    fin.close();

    cout << name << ", " << age << ", " << weight << endl;
    return 0;
}
