#include "address.h"

int main() 
{
	std::string city1 = "Moscow", street1 = "Arbat";
	unsigned house1 = 5, flat1 = 24;
	Address address1(city1, street1, house1, flat1);
	std::cout << address1.belonding("Moscow", "Neglinnaya") << "\n";
	std::cout << address1.belonding("Moscow", "Arbat") << "\n";
	std::cout << address1 << "\n";
	Address address156(std::cin);
	std::cout << address156 << "\n";
	std::string city2 = "Moscow", street2 = "Arbat";
	unsigned house2 = 4, flat2 = 19;
	Address address2(city2, street2, house2, flat2);
	std::cout << address1.neighbours(address2) << "\n";
	std::string city3 = "Moscow", street3 = "Olega Tsareva";
	unsigned house3 = 12, flat3 = 2;
	Address address3(city3, street3, house3, flat3);
	std::cout << address1.neighbours(address3);

	Address address4(std::cin);
	std::cout << address4.neighbours(Address(std::cin)) << "\n";
	
	/*std::string city1 = "Moscow", street1 = "Arbat";
	unsigned house1 = 5, flat1 = 24;
	std::string city1 = "Moscow", street1 = "Arbat";
	unsigned house1 = 5, flat1 = 24;
	std::cout << address1.neighbours*/
	system("pause");
	return 0;
}