#include <iostream>
#include "point.h"

using namespace std;

// get a point from user input
void InputPoint(Point & p) {
    double x, y;
    cin >> x >> y;
    p.SetCoord(x, y);
    return;
}


int main()
{
    Point a, b;

    cout << "Input 1st point (x,y): ";
    InputPoint(a);

    cout << "Input 2nd point (x,y): ";
    InputPoint(b);

    cout << "Distance between point: " << a.Distance(b) << endl;

    Point c;
    c.SetCoord(1, 1);
    a.Translate(c);
    cout << "Translating point a by an offset (1,1) = (" << a.GetX()
        << "," << a.GetY() << ")" << endl;

    return 0;
}
