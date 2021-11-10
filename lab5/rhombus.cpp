#include "rhombus.h"

Rhombus::Rhombus() : a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0), square(0.0), diag1(0.0), diag2(0.0)
{

};

Rhombus::Rhombus(std::istream& is)
{
	is >> a >> b >> c >> d;
	diag1 = dist(a, c);
	diag2 = dist(b, d);
	square = (diag1 * diag2) / 2.;
}

Rhombus& Rhombus::operator= (Rhombus rhombus)
{
	a = rhombus.a;
	b = rhombus.b;
	c = rhombus.c;
	d = rhombus.d;
	diag1 = rhombus.diag1;
	diag2 = rhombus.diag2;
	square = rhombus.square;
	return rhombus;
};

bool Rhombus::operator== (Rhombus rhombus)
{
	if ((a == rhombus.a) && (b == rhombus.b) && (c == rhombus.c) && (d == rhombus.d))
	{
		return true;
	}
	return false;
};

void Rhombus::Print(std::ostream& os)
{
	os << "Rhombus: " << a << " " << b << " " << c << " " << d << std::endl;
}

std::istream& operator >>(std::istream& is, Rhombus& rhombus)
{
	is >> rhombus.a >> rhombus.b >> rhombus.c >> rhombus.d;
	return is;
};

std::ostream& operator <<(std::ostream& os, Rhombus rhombus)
{
	os << rhombus.a << " " << rhombus.b << " " << rhombus.c << " " << rhombus.d << "\n";
	return os;
};

size_t Rhombus::VertexesNumber()
{
	return 4;
}

double Rhombus::Square()
{
	return square;
}

Rhombus::~Rhombus()
{

}