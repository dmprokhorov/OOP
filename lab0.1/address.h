#ifndef ADDRESS_H
#define ADDRESS_H
#include <cmath>
#include <string>
#include <iostream>
#include <limits> 
class Address
{
private:
	std::string city, street;
	unsigned house, flat;
public:
	Address(std::string, std::string, unsigned, unsigned);
	Address(std::istream&);
	void operator= (const Address&);
	bool operator== (const Address&);
	bool belonding(std::string, std::string);
	bool neighbours(Address);
	void set_new_address(std::string, std::string, unsigned, unsigned);
	friend std::ostream& operator <<(std::ostream& os, const Address& address);
	friend std::istream& operator>> (std::istream&, Address&);
	~Address();
};

bool equals(std::string, std::string);

#endif
