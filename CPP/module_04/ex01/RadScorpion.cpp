#include "RadScorpion.hpp"

RadScorpion::RadScorpion() :
		Enemy(80, "RadScorpion") {
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(RadScorpion const &other) :
		Enemy(other) {}

RadScorpion &RadScorpion::operator=(RadScorpion const &other) {
	if (this != &other) {
		this->_hp = other._hp;
		this->_type = other._type;
	}
	return *this;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *\n";
}
