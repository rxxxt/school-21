#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	std::cout << *easyfind(v, 7) << std::endl;
	try {
		std::cout << *easyfind(v, 100) << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << "error message: " << ex.what()
			<< std::endl;
	}
	return 0;
}