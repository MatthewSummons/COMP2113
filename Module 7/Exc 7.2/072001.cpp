// The Co-ordinate Geometery Struct
// Created by Shaheer Ziya on Apr 3, 2022

#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
  double x, y;
};


double distance(Point p, Point q)
{
  // The Cartesian Distance Formula
  return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}


void shrink_line(Point &p, Point &q)
{
  // PQ = OQ - OP
  Point lineVector = {q.x - p.x, q.y - p.y};
  // Srink line in half by moving the end-point 1/4d from their original position
  p.x = lineVector.x / 4.0;
  p.y = lineVector.y / 4.0;

  q.x = 3 * lineVector.x / 4.0;
  q.y = 3 * lineVector.y / 4.0;
}


Point midpoint(Point p1, Point p2)
{
  Point mid;
  mid.x = (p1.x + p2.x) / 2;
  mid.y = (p1.y + p2.y) / 2;
  return mid;
}

int main()
{
  Point A = {1,2};
  Point B = {3,2};

  Point mid = midpoint(A, B);

  cout << "The midpoint of the line segement AB is: ";
  cout << "(" << mid.x << ", " << mid.y << ")" << endl;



  shrink_line(A, B);
  cout << "The shrunken line segment AB is: " << endl;
  cout << "(" << A.x << ", " << A.y << ")" << endl;
  cout << "(" << B.x << ", " << B.y << ")" << endl;

  return 0;
}