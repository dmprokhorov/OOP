#include "Rhombus.h"

Rhombus::Rhombus() : a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0)
{
	std::cout << "Created default rhombus" << std::endl;
};

Rhombus::Rhombus(std::istream& is)
{
	std::cout << "Enter the values of rhombus' points" << std::endl;
	is >> a >> b >> c >> d;
	diag1 = dist(a, c);
	diag2 = dist(b, d);
	std::cout << "Created rhombus via istream" << std::endl;
}

void Rhombus::Print(std::ostream& os)
{
	os << "Rhombus: " << a << " " << b << " " << c << " " << d << std::endl;
}

size_t Rhombus::VertexesNumber()
{
	return 4;
}

double Rhombus::Square()
{
	return (diag1 * diag2) / 2.;
}

Rhombus::~Rhombus()
{
	std::cout << "Deleted rhombus" << std::endl;
}