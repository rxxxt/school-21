#include "Array.hpp"

int main() {

	Array<int> arr(5);
	try {
		for (unsigned int i = 0; i < arr.size(); ++i)
			std::cout << arr[i] << std::endl;
		std::cout << arr[5] << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << "error message: ";
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

	Array<char *> s1(3);
	for (unsigned int i = 0; i < s1.size(); i++) {
		printf("s1[%d] = %s\n", i, s1[i]);
		s1[i] = (char*)"bla bla";
	}
	std::cout << std::endl;

	Array<char *> s2(s1);
	for (unsigned int i = 0; i < s2.size(); i++)
		printf("s2[%d] = %s\n", i, s2[i]);

	Array<char *> s3 = Array<char *>();
	s3 = s2;
	for (unsigned int i = 0; i < s3.size(); i++)
		printf("s3[%d] = %s\n", i, s3[i]);
	return 0;
}
