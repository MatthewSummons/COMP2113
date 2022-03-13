// Copy the elements from one array to another
#include <iostream>
using namespace std;

void copyArr(double src[], double dst[], int arrSize)
{
    for (int i{0}; i < arrSize; i++)
    {
        dst[i] = src[i];
    }
}

int main()
{
    // Determine size of array depeneding on user input
    int arrSize;
    cout << "Enter the size of the array: ";
    cin >> arrSize;

    // Init Source & Destination Arrays
    double srcArray[arrSize];
    double dstArray[arrSize];

    cout << "Enter the elements of the array [Type = double]: " << endl;
    for (int i{0}; i < arrSize; i++)
    {
        cin >> srcArray[i];
    }

    copyArr(srcArray, dstArray, arrSize);

    // // Print the elements of the copied array
    // for (int i{0}; i < arrSize; i++)
    // {
    //     cout << dstArray[i] << endl;
    // }

    return 0;
}