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
	if (A* a = dynamic_cast<A*>(p))
		std::cout << *a;
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << *b;
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << *c;
}

void identify(Base& p) {
	try {
		std::cout << dynamic_cast<A&>(p);
	} catch (...) {}
	try {
		std::cout << dynamic_cast<B&>(p);
	} catch (...) {}
	try {
		std::cout << dynamic_cast<C&>(p);
	} catch (...) {}
}

int main() {
	Base* base = generate();
	std::cout << "Class definition by pointer - ";
	identify(base);
	std::cout << "Class definition by reference - ";
	identify(*base);
	delete base;
	return 0;
}
