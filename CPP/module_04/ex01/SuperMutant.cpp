#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :
		Enemy(170, "Super Mutant"),
		_damageReduction(3) {
	std::cout << "Gaaah. Me want smash heads!\n";
}

SuperMutant::SuperMutant(SuperMutant const &other) :
		Enemy(other),
		_damageReduction(3) {}

SuperMutant &SuperMutant::operator=(SuperMutant const &other) {
	if (this != &other) {
		_hp = other._hp;
		_type = other._type;
		_damageReduction = other._damageReduction;
	}
	return *this;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh...\n";
}

void SuperMutant::takeDamage(int damage) {
	damage -= _damageReduction;
	if (damage >= _hp)
		_hp = 0;
	else if (damage > 0)
		_hp -= damage;
}
