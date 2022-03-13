// Swap the first and last element of an array
# include <iostream>
using namespace std;


void printArr(double arr[], int arrSize)
{
    for (int i{0}; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }
}

void swapFrontBack(double arr[], int arrSize)
{
    double container {arr[0]};
    arr[0] = arr[arrSize-1];
    arr[arrSize-1] = container;
}

int main()
{
    // Setup the Array with user inputted data
    // Ask for the size of an array
    int arrSize;
    cout << "How many elements does your array contain?" << endl;
    cout << "Elements in the array: ";
    cin >> arrSize;
    // Can work with any type of array; Let's work with doubles for now
    double testArray [arrSize];
    for (int i {0}; i < arrSize; i++)
    {
        cin >> testArray[i]; 
    }

    // Switch first & last element of the array
    swapFrontBack(testArray, arrSize);

    printArr(testArray, arrSize);
    
    return 0;
}