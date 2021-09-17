#include "Human.hpp"

std::string	Human::identify() {
	return (_brain.identify());
}

Brain	&	Human::getBrain() {
	return (_brain);
}
