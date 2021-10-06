#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle();
	Rectangle(std::istream& is);
	virtual ~Rectangle();
	void Print(std::ostream& os);
	double Square();
	size_t VertexesNumber();

private:
	Point a, b, c, d;
	double len1, len2;
};

#endif
