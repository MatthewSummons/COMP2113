// Order three integers

#include <iostream>
using namespace std;


void swap(int& x, int& y)
{
  int container;
  container = x;
  x = y;
  y = container;
}


void orderInts(int& a, int& b, int& c)
{
  cout << a << b << c << endl;
  int container;
  if (b > c)
  {
    swap(b, c);
    //cout << a << b << c << endl;
  }
  if (a > b)
  {
    swap(a, b);
    //cout << a << b << c << endl;
  }
  if (b > c)
  {
    swap(b, c);
    //cout << a << b << c << endl;
  }
}


int main()
{
  // Obtain three integers from the user  
  int a, b, c;
  cout << "Enter three integers: ";
  cin >> a >> b >> c;

  orderInts(a, b, c);

  cout << "After orderng the integers, we get:" << endl;
  cout << a << " " << b << " " << c << endl;

  return 0;
}