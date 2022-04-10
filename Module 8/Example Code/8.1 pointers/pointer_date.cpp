#include <iostream>
#include <iomanip>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    Date today = { 26, 2, 2015 };

    cout << setfill('0');

    // access structure member using the dot operator
    cout << setw(2) << today.day << '/'
         << setw(2) << today.month << '/'
         << setw(4) << today.year << endl;

    Date * dPtr = &today;       // dPtr now points to today

    // access structure member using the dereference operator and dot operator
    cout << setw(2) << (*dPtr).day << '/'
         << setw(2) << (*dPtr).month << '/'
         << setw(4) << (*dPtr).year << endl;

    // access structure member using the member of pointer shorthand
    cout << setw(2) << dPtr->day << '/'
         << setw(2) << dPtr->month << '/'
         << setw(4) << dPtr->year << endl;


    return 0;
}
