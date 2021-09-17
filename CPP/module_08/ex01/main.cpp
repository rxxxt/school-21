#include "Span.hpp"

int main()
{
	std::srand(time(NULL));
	try {
		Span sp = Span(1000000);
		for (int i = 0; i < 1000000; ++i) {
			sp.addNumber(rand());
		}
//		sp.addNumbers(2000000);
//		sp.addNumber(5);
//		sp.addNumber(3);
//		sp.addNumber(17);
//		sp.addNumber(9);
//		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << "error message: " << ex.what()
			<< std::endl;
	}
	return 0;
}