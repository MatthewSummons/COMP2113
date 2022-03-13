// gcd.cpp
#include <iostream>
#include "gcd.h"
using namespace std;

// for simplicity, we assume both inputs to be positive
int gcd(int a, int b) {
  while(a != b) {
    if(a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return a;
}
