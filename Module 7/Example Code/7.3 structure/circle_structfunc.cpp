#include <iostream>
#include <cmath>
using namespace std;

// 2D circle
struct Circle {
	double x, y;   // center
	double r;      // radius

  double Area();

  void EnlargeCircle(double radius_to_add) {
      r += radius_to_add;
  };

  bool IsOverlap(Circle c);

};


// area of circle
double Circle::Area()
{
    const double PI = 3.14159265358979323846;
    return PI * r * r;
}


// check if circle c overlaps with this circle
bool Circle::IsOverlap(Circle c) {
    double dx = x - c.x;
    double dy = y - c.y;
	double centre_dist = sqrt(dx*dx + dy*dy);
    return (centre_dist <= (r + c.r));
}


int main() {

    Circle p = {1,1,2}, q = {2,2,1};

    //p.EnlargeCircle(5);
    //cout << "new radius of p: " << p.r << endl;

    cout << "area of q: " << q.Area() << endl;

    cout << "p and q overlap? " <<            (p.IsOverlap(q) ? "Yes" : "No") << endl;

    return 0;
}
