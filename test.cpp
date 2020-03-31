#include <iostream>
#include <string> // std::to_string
#include <sstream> // std::stringstream

int main()
{
	// old method
	std::stringstream ss;
	ss << 1.23;
	std::string str = ss.str();
	std::cout << str << std::endl;
	// new method
	std::string pi = "pi is " + std::to_string(3.1415926);
	std::string perfect = std::to_string(1 + 2 + 4 + 7 + 14) + " is a perfect number";
	std::cout << pi << std::endl;
	std::cout << perfect << std::endl;

	return 0;
}
