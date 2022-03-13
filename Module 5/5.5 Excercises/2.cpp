# include <iostream>

const int Odds[10] = {1,3,5,7,9,11,13,15,17,19};

int main()
{
    int product = 1;
    for (int i = 0; i < 10; i++)
    {
        product *= Odds[i];
    }
    
    std::cout << product << std::endl;

    return 0;
}