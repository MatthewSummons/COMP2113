#include <iostream>

using namespace std;

// a function void addOne(int &p) which adds 1 to the integer referenced by p
void addOne(int &p)
{
  p++;
}


int main()
{
  int x;

  cin >> x;

  addOne(x);
  cout << x << endl;

  return 0;
}
