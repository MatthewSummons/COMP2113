#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
// iterative version
int largest_element( int a[], int size )
{
	int max = -1;		// given that the array stores only positive numbers

	for (int i = 0; i < size; ++i)
		if (a[i] > max)
			max = a[i];
	
	return max;
}
*/


// recursive versioln
int largest_element( int a[], int size )
{
	if (size < 1)
		return -1;
	else {
		int x = largest_element(a, size-1);
		return (x > a[size-1])? x : a[size-1]; 
	}
}


int main()
{
	const int SIZE = 10;
	int a[SIZE];

	// initialize random seed
	srand( time(NULL) );

	for (int i = 0; i < SIZE; ++i) 
		a[i] = rand()%100 + 1;

	cout << "array contents: ";
	for (int i = 0; i < SIZE; ++i)
		cout << a[i] << " ";
	cout << endl;

	cout << "the largest element = " << largest_element(a, SIZE) << endl;
	 
	return 0;

}