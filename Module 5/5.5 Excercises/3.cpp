#include <iostream>

const char Letters[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

int main()
{
    for (int i = 9; i >= 0; i--)
    {
        std::cout << Letters[i] << std::endl;
    }
    return 0;
}