#include <iostream>
#include <cmath>
using namespace std;

// 2D circle
struct Circle {
	double x, y;   // center
	double r;      // radius
};


// area of circle
double CircleArea(Circle c) {
    const double PI = 3.14159265358979323846;
    return PI * c.r * c.r;
}


// enlarge circle size
void EnlargeCircle(Circle &c, double radius_to_add) {
	c.r += radius_to_add;
}


// check if two circles overlap
bool IsCircleOverlap(Circle c1, Circle c2) {
    double dx = c1.x - c2.x;
    double dy = c1.y - c2.y;
	  double centre_dist = sqrt(dx*dx + dy*dy);
    return (centre_dist <= (c1.r + c2.r));
}


int main() {
    Circle p = {1,1,2}, q = {2,2,1};

    EnlargeCircle(p, 5);
    cout << "new radius of p: " << p.r << endl;

    cout << "area of q: " << CircleArea(q) << endl;

    cout << "p and q overlap? " <<(IsCircleOverlap(p, q) ? "Yes" : "No") << endl;

    return 0;
}
