#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double hypotenuse(double side1, double side2)
{
  return sqrt( (side1 * side1) + (side2 * side2));
}

int main()
{
  double side1, side2;
  cin >> side1 >> side2;
  
  cout << hypotenuse(side1, side2) << endl;
}