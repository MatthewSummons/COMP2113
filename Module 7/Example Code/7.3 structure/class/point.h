#ifndef _POINT_H_
#define _POINT_H_

// a class for 2D point
class Point {
public:
	double GetX() { return x; }
	double GetY() { return y; }
  void SetCoord(double s, double t) {
		x = s;
		y = t;
	}

	double Distance(Point & p);
	void   Translate(Point & p);

private:
	double x;
	double y;

};



#endif
