// lcm.cpp
#include <iostream>
#include "gcd.h"
#include "lcm.h"
using namespace std;

// for simplicity, we assume both inputs to be positive
int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}
