// Increment an integer variable using pointers
// Created by Shaheer Ziya

#include <iostream>

// // Pass by reference version
// void addOne(int &p)
// {
//   ++p;
// }

void addOne(int *p)
{
  (*p)++;
}

int main()
{
  int x = 0;

  std::cout << x << std::endl;
  for (int i = 0; i < 10; i++)
  {
    addOne(&x);
    std::cout << x << std::endl;
  }

}