#include "address.h"

bool equals(std::string s1, std::string s2)
{
	if (s1.length() == s2.length())
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (tolower(s1[i]) != tolower(s2[i]))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

Address::Address(std::string city, std::string street, unsigned house, unsigned flat): city(city), street(street), house(house), flat(flat)
{

}

Address::Address(std::istream& is)
{
	std::string aux, h, f;
	//is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(is, aux);
	if (aux == "")
	{
		getline(is, city);
	}
	else
	{
		city = aux;
	}
	//getline(is, city);
	getline(is, street);
	getline(is, h);
	getline(is, f);
	this->house = unsigned(stoi(h));
	this->flat = unsigned(stoi(f));
}

void Address::operator= (const Address& address)
{
	city = address.city;
	street = address.street;
	house = address.house;
	flat = address.flat;
}

bool Address::operator== (const Address& address)
{
	std::string adcity = address.city, adstreet = address.street;
	if (equals(city, address.city) && (equals(street, address.street)) && (house == address.house) && (flat == address.flat))
	{
		return true;
	}
	return false;
}

bool Address::belonding(std::string city, std::string street)
{
	if (equals(this->city, city) && (equals(this->street, street)))
	{
		return true;
	}
	return false;
}

bool Address::neighbours(Address address)
{
	if (equals(city, address.city) && (equals(street, address.street)))
	{
		return true;
	}
	return false;
}

void Address::set_new_address(std::string city, std::string street, unsigned house, unsigned flat)
{
	this->city = city;
	this->street = street;
	this->house = house;
	this->flat = flat;
}

std::istream& operator>> (std::istream& is, Address& address)
{
	std::string aux, h, f;
	//is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(is, aux);
	if (aux == "\n")
	{
		getline(is, address.city);
	}
	else
	{
		address.city = aux;
	}
	//getline(is, address.city);
	getline(is, address.street);
	getline(is, h);
	getline(is, f);
	address.house = unsigned(stoi(h));
	address.flat = unsigned(stoi(f));
	return is;
}

std::ostream& operator << (std::ostream& os, const Address& address)
{
	os << "City: " << address.city << "\n";
	os << "Street: " << address.street << "\n";
	os << "House: " << address.house << "\n";
	os << "Flat: " << address.flat;
	return os;
}

Address::~Address()
{

}