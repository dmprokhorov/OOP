#include "Rectangle.h"

Rectangle::Rectangle() : a(0.0, 0.0), b(0.0, 0.0), c(0.0, 0.0), d(0.0, 0.0) 
{
	std::cout << "Created default rectangle" << std::endl;
};

Rectangle::Rectangle(std::istream& is)
{
	std::cout << "Enter the values of rectangle's points" << std::endl;
	is >> a >> b >> c >> d;
	len1 = dist(a, b);
	len2 = dist(b, c);
	std::cout << "Created rectangle via istream" << std::endl;
}

void Rectangle::Print(std::ostream& os)
{
	os << "Rectangle: " << a << " " << b << " " << c << " " << d << std::endl;
}

size_t Rectangle::VertexesNumber()
{
	return 4;
}

double Rectangle::Square()
{
	return len1 * len2;
}

Rectangle::~Rectangle()
{
	std::cout << "Deleted rectangle" << std::endl;
}