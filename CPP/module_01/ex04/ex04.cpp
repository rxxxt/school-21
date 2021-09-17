#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *p_str = &str;
	std::string &ref_str = str;

	std::cout << "Using pointer : " << *p_str << std::endl;
	std::cout << "Using reference : " << ref_str << std::endl;
}