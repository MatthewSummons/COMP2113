#include <iostream>

using namespace std;

int fib(int num)
{
    if (num < 2)
        return num;
    else
        return fib(num-1) + fib(num-2);
}


int main()
{
    for (int i = 0; i < 20; ++i)
        cout << fib(i) << " ";
    cout << endl;

}



