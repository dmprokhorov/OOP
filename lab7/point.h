#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
class Point
{
public:
	Point();
	Point(std::istream& is);
	Point(double x, double y);
	double length(Point& p1, Point& p2);
	friend std::istream& operator>>(std::istream& is, Point& p);
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	bool operator== (Point point);
	bool operator!= (Point point);
	bool operator< (Point point);
	friend double dist(Point& p1, Point& p2);
	~Point();

private:
	double x_, y_;
};

#endif
