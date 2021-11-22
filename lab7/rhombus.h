#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"

class Rhombus : public Figure
{
public:
	Rhombus();
	Rhombus(std::istream& is);
	void Print(std::ostream& os);
	double Square();
	friend std::istream& operator >>(std::istream& is, Rhombus& rhombus);
	friend std::ostream& operator <<(std::ostream& os, const Rhombus& rhombus);
	Rhombus& operator= (Rhombus rhombus);
	bool operator== (Rhombus rhombus);
	bool operator< (Rhombus rhombus);
	size_t VertexesNumber();
	virtual ~Rhombus();


private:
	Point a, b, c, d;
	double diag1, diag2;
	double square;
};

#endif
