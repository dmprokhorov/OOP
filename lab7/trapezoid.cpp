#include "trapezoid.h"

Trapezoid::Trapezoid() : a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0), square(0.0), lena(0.0), lenb(0.0), lenc(0.0), lend(0.0)
{

};

Trapezoid::Trapezoid(std::istream& is)
{
	is >> a >> b >> c >> d;
	lena = dist(b, c);
	lenb = dist(a, d);
	lenc = dist(c, d);
	lend = dist(a, b);
	/*if (lena > lenb)
	{
		std::swap(lena, lenb);
		std::swap(lenc, lend);
	}*/
	square = ((lena + lenb) / 2.) * sqrt(pow(lenc, 2) - pow(((pow(lenb - lena, 2) + pow(lenc, 2) - pow(lend, 2)) / (2. * (lenb - lena))), 2));
}

Trapezoid& Trapezoid::operator= (Trapezoid trapezoid)
{
	a = trapezoid.a;
	b = trapezoid.b;
	c = trapezoid.c;
	d = trapezoid.d;
	lena = trapezoid.lena;
	lenb = trapezoid.lenb;
	lenc = trapezoid.lenc;
	lend = trapezoid.lend;
	square = trapezoid.square;
	return trapezoid;
};

bool Trapezoid::operator< (Trapezoid trapezoid)
{
	if (square != trapezoid.Square())
	{
		return square < trapezoid.Square();
	}
	if (a != trapezoid.a)
	{
		return a < trapezoid.a;
	}
	if (b != trapezoid.b)
	{
		return b < trapezoid.b;
	}
	if (c != trapezoid.c)
	{
		return c < trapezoid.c;
	}
	return d < trapezoid.d;
};

bool Trapezoid::operator== (Trapezoid trapezoid)
{
	if ((a == trapezoid.a) && (b == trapezoid.b) && (c == trapezoid.c) && (d == trapezoid.d))
	{
		return true;
	}
	return false;
};

void Trapezoid::Print(std::ostream& os)
{
	os << "Trapezoid: " << a << " " << b << " " << c << " " << d << std::endl;
}

std::istream& operator >>(std::istream& is, Trapezoid& trapezoid)
{
	is >> trapezoid.a >> trapezoid.b >> trapezoid.c >> trapezoid.d;
	return is;
};

std::ostream& operator <<(std::ostream& os, const Trapezoid& trapezoid)
{
	os << trapezoid.a << " " << trapezoid.b << " " << trapezoid.c << " " << trapezoid.d;
	return os;
};

size_t Trapezoid::VertexesNumber()
{
	return 4;
}

double Trapezoid::Square()
{
	return square;
}

Trapezoid::~Trapezoid()
{

}