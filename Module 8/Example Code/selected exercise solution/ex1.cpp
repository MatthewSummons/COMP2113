#include <iostream>

using namespace std;

// a function to return the pointer to the maximum element of an array
int * maxElementPtr(int a[], int num)
{
    int max = a[0];
    int *ptr = &(a[0]);

    for (int i = 0; i < num; ++i) {
        if (a[i]>max) {
            ptr = &(a[i]);
            max = a[i];
        }
    }
    return ptr;
}



// a function to return the index to the maximum element of an array
int maxElement(int a[], int num)
{
    int max = a[0], idx=0;
    for (int i = 0; i < num; ++i) {
        if (a[i]>max) {
            idx = i;
            max = a[i];
        }
    }
    return idx;
}


int main()
{
    int m[] = {0, 4, 5, 2, 6, 9, 1};

    int idx = maxElement(m, 7);
    cout << "idx: " << idx << " element: " << m[idx] << endl;

    int * ptr = maxElementPtr(m, 7);
    cout << "max element: " << *ptr << endl;


    return 0;
}
