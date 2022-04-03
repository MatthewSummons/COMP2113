#include <iostream>

using namespace std;


int binary_search_R(int A[], int lb, int ub, int value)
{
	if (lb > ub)
		return -1;
	else
	{
		int i = (lb + ub) / 2;
		if (A[i] == value)
			return i;
		else if (A[i] > value)
			return binary_search_R(A, lb, i - 1, value);
		else
			return binary_search_R(A, i + 1, ub, value);
	}
}

int binary_search(int A[], int size, int value)
{
 	int lb = 0, ub = size - 1;

	while (lb <= ub)
	{
		int i = (lb + ub) / 2;
 		if (A[i] == value)
	 		return i;
		else if (A[i] > value)
			ub = i - 1;
		else
			lb = i + 1;
	}
	return -1;
}


int main()
{
    int a[] = { 1, 3, 5, 6, 8, 9, 11, 13, 14, 18 };
    int size = 10;

    cout << "a[] = ";
    for (int i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << endl << endl;

    int x;
    cout << "Input a number: ";
    cin >> x;

    int pos = binary_search(a, size, x);
    if (pos != -1)
        cout << "Found at position: " << pos << endl;
    else
        cout << "Not found" << endl;

    cout << "\nRetry using recursive version:\n";
    pos = binary_search_R(a, 0, size-1, x);
    if (pos != -1)
        cout << "Found at position: " << pos << endl;
    else
        cout << "Not found" << endl;

}
