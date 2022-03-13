#include <iostream>

int main()
{
    int i, sum;

    for(i=20; i>=1; i--)
    {
        
        if (i % 2 != 0)
            sum += i;
    }
    std::cout << sum << std::endl;

    return 0;
}