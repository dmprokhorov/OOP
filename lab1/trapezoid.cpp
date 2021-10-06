#include "trapezoid.h"

Trapezoid::Trapezoid() : a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0)
{
	std::cout << "Created default trapezoid" << std::endl;
};

Trapezoid::Trapezoid(std::istream& is)
{
	std::cout << "Enter the values of trapeziod's points" << std::endl;
	is >> a >> b >> c >> d;
	lena = dist(a, b);
	lenb = dist(c, d);
	lenc = dist(b, c);
	lend = dist(a, d);
	if (lena > lenb)
	{
		std::swap(lena, lenb);
		std::swap(lenc, lend);
	}
	std::cout << "Created trapezoid via istream" << std::endl;
}

void Trapezoid::Print(std::ostream& os)
{
	os << "Trapezoid: " << a << " " << b << " " << c << " " << d << std::endl;
}

size_t Trapezoid::VertexesNumber()
{
	return 4;
}

double Trapezoid::Square()
{
	return ((lena + lenb) / 2.) * sqrt(pow(lenc, 2) - pow(((pow(lenb - lena, 2) + pow(lenc, 2) - pow(lend, 2)) / (2. * (lenb - lena))), 2));
}

Trapezoid::~Trapezoid()
{
	std::cout << "Deleted trapezoid" << std::endl;
}
