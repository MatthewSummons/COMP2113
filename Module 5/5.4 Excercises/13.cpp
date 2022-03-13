#include "13.h"

bool isPerfectNumber(int num)
{
  int factorSum = 0;
  for (int multiple = 1; multiple < num; multiple++)
  {
    if (num % multiple == 0) 
      factorSum += multiple; 
  }
  if (factorSum == num)
    return true;
  else
    return false;
}