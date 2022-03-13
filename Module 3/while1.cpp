#include <iostream>

int main()
{
    int answer = 4;
    while (answer != 4)
    {
        std::cout << "2 * 2 = ";
        std::cin >> answer;
    }

    std::cout << "Correct!" << std::endl;
    return 0;
}