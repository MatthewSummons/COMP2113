#include <iostream>
using namespace std;

// cf.: https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// int          4 bytes
// double       8 bytes

// structure A
struct structA
{
   char        c;
   double      d;
   int         s;
};

// structure B
struct structB
{
   double      d;
   int         s;
   char        c;
};

int main()
{
   cout << "sizeof(structA) = " <<  sizeof(struct structA) << endl;
   cout << "sizeof(structB) = " <<  sizeof(struct structB) << endl;

   return 0;
}
