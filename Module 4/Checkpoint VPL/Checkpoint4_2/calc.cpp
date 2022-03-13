// calc.cpp
#include <iostream>
#include "gcd.h"
#include "lcm.h"
using namespace std;

int main() {
  int a, b, c, d;
  cout << "Please input two positive numbers: ";
  cin >> a >> b;
  c = gcd(a, b);
  d = lcm(a, b);
  cout << "GCD is " << c << endl;
  cout << "LCM is " << d << endl;
}
