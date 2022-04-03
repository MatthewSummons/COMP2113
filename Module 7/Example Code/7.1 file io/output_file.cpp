#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

int main()
{
    ofstream outputfile;
    outputfile.open("data1.txt");

    if (outputfile.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    string name = "Simon";
    int age = 20;
    double weight = 150.5;

    outputfile << name << " " << age << " " << weight << endl;
    outputfile.close();

    return 0;
}
