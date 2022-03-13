#include <iostream>
using namespace std;

bool isPalindrome(char arr[], int arrSize)
{
    // cout << arrSize << endl;
    int arrMid = (arrSize / 2) + 1;
    for (int i{0}; i < arrMid; i++)
    {
        // cout << arr[i] << "   " << arr[((arrSize - 1) - i)]  << endl;
        if (arr[i] != arr[((arrSize - 1) - i)])
            return false;
    }
    return true;
}

int main()
{
    // Test Arrays
    char arr1[5] = {'a', 'b', 'c', 'b', 'a'}; // Yes
    char arr2[5] = {'a', 'b', 'c', 'b', 'b'}; // No

    char arr3[4] = {'a', 'b', 'b', 'a'}; // Yes
    char arr4[4] = {'a', 'b', 'c', 'b'}; // No

    cout << isPalindrome(arr1, 5) << endl;
    cout << isPalindrome(arr2, 5) << endl;
    cout << isPalindrome(arr3, 4) << endl;
    cout << isPalindrome(arr4, 4) << endl;

    return 0;
}