#ifndef ADDRESS_H
#define ADDRESS_H
#include <cmath>
#include <string>
#include <iostream>
#include <limits> 
#include <vector>
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
	bool belonding(std::vector<std::string>);
	bool neighbours(Address);
	void set_new_address(std::string, std::string, unsigned, unsigned);
	friend std::ostream& operator <<(std::ostream& os, const Address& address);
	friend std::istream& operator>> (std::istream&, Address&);
	~Address();
};

bool equals(std::string, std::string);
std::string rem(std::string);
Address operator "" _address(const char* str, size_t size);
std::vector<std::string> operator"" _city_and_street(const char* str, size_t size);
#endif
