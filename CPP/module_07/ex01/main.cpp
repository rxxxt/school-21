#include <iostream>
#include "iter.hpp"

template<typename T>
void printOdd(T& x) {
	if (x % 2)
		std::cout << x << std::endl;
}

template<typename T>
void printASCIINum(T& s) {
	std::cout << (int)s << " ";
}

template<typename T>
void print(T& arr) {
	std::cout << arr << std::endl;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4, 5 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	char *str = (char*)"hello world!";
	std::string arr[3] = {
			"One",
			"Two",
			"Three"
	};
	iter(tab, 6, printOdd);
	iter(str, std::strlen(str), printASCIINum);
	std::cout << std::endl;
	iter(arr, 3, print);

	return 0;
}
