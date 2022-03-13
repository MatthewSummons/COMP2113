// Sieve of Eratosthenes --- Finding Primes
#include <iostream>
using namespace std;

int main()
{
    // Find the first 1000 primes
    int arrSize{1000};
    bool isPrime[arrSize];

    // Init all elements of the array to true (Assume all numbers are prime)
    for (int i{0}; i < arrSize; i++)
    {
        isPrime[i] = true;
    }

    // Run algorithm to determine primes iterating from 2 till (arrSize - ) which is 999 in this case
    for (int i{2}; i < arrSize; i++)
    {
        // If an element is prime, its multiples cannot be prime so set all multiples of the number to false by iterating from
        //  that element + 1 till the end of the array and checking for multiples with the % operator 
        if (isPrime[i])
        {
            for (int j{i + 1}; j < arrSize; j++)
            {
                // Set all multiples of the assumed prime to zero
                if (j % i == 0)
                {
                    isPrime[j] = false;
                }
            }
        }
    }

    // Output all the primes (till arrSize)
    for (int i{2}; i < arrSize; i++)
    {
        if (isPrime[i])
        {
            cout << i << endl;
        }
    }

    return 0;
}
