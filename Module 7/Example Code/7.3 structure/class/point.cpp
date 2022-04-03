#include "point.h"  // this is needed because Point is defined in point.h
#include <cmath>

// distance between this point and point p
double Point::Distance(Point & p) {
	double dx = p.x - x;
	double dy = p.y - y;
	return sqrt( dx * dx + dy * dy);
}

// translate this point by an offset p
void Point::Translate(Point & p) {
	x += p.x;
	y += p.y;
}
