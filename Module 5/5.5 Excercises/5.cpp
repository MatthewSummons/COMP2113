#include <iostream>
using namespace std;

int Dice[7] = {0};

int main()
{
    double input{-1};
    while (input != 0)
    {
        cin >> input;

        if (input == 1)
        {
            Dice[1]++;
        }
        if (input == 2)
        {
            Dice[2]++;
        }
        if (input == 3)
        {
            Dice[3]++;
        }
        if (input == 4)
        {
            Dice[4]++;
        }
        if (input == 5)
        {
            Dice[5]++;
        }
        if (input == 6)
        {
            Dice[6]++;
        }
    }

    for (int i = 1; i < 7; i++)
    {
        cout << Dice[i] << endl;
    }

    return 0;
}