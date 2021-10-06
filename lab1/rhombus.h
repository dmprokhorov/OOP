#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"

class Rhombus : public Figure
{
public:
	Rhombus();
	Rhombus(std::istream& is);
	virtual ~Rhombus();
	void Print(std::ostream& os);
	double Square();
	size_t VertexesNumber();

private:
	Point a, b, c, d;
	double diag1, diag2;
};

#endif
