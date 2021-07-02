#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	std::srand(time(0));
	int randomNumber = rand() % 3;
	if (!randomNumber)
		return new A();
	else if (randomNumber == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	identify(&p);
}

int main() {
	Base* base = generate();
	identify(base);
	identify(*base);
	return 0;
}
