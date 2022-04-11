// Problem 1 (8.1)
// Transcribed by Shaheer Ziya

#include <iostream>

int main()
{
  int i1, i2;
  int *p1 = &i1, *p2 = &i2;
  *p1 = 10;
  *p2 = 20;
  
  std::cout << *p1 << " " << *p2 << std::endl;
  *p1 = *p2;
  // p1 = p2;

  std::cout << *p1 << " " << *p2 << std::endl;
  *p1 = 30;

  std::cout << *p1 << " " << *p2 << std::endl;

}