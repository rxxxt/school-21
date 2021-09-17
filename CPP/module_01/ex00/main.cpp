#include "Pony.hpp"

void	ponyOnTheHeap(void) {
	Pony	*pony = new Pony;

	pony->hello();
	delete pony;
}

void	ponyOnTheStack(void) {
	Pony	pony;

	pony.hello();
}

int	main(void) {
	std::cout << GREEN;
	ponyOnTheHeap();
	std::cout << RED;
	ponyOnTheStack();
	std::cout << RED;
}