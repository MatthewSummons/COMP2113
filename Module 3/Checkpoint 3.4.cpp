#include <iostream>

int main()
{
    int x=5, y=6, z=7;
    std::cout << (x+z) % y;
    std::cout << (x % y) % z;
    std::cout << (x * z) % y;
    std::cout << x % y % z;

    return 0;
}