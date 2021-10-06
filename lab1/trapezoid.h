#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "Figure.h"
#include <algorithm>
class Trapezoid : public Figure
{
public:
	Trapezoid();
	Trapezoid(std::istream& is);
	virtual ~Trapezoid();
	void Print(std::ostream& os);
	double Square();
	size_t VertexesNumber();

private:
	Point a, b, c, d;
	double lena, lenb, lenc, lend;
};

#endif
