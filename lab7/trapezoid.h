#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "figure.h"
#include <algorithm>
class Trapezoid : public Figure
{
public:
	Trapezoid();
	Trapezoid(std::istream& is);
	void Print(std::ostream& os);
	double Square();
	friend std::istream& operator >>(std::istream& is, Trapezoid& trapezoid);
	friend std::ostream& operator <<(std::ostream& os, const Trapezoid& trapezoid);
	Trapezoid& operator= (Trapezoid trapezoid);
	bool operator== (Trapezoid trapezoid);
	bool operator< (Trapezoid trapezoid);
	size_t VertexesNumber();
	virtual ~Trapezoid();

private:
	Point a, b, c, d;
	double lena, lenb, lenc, lend;
	double square;
};

#endif
