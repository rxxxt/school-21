#include "SuperTrap.hpp"

SuperTrap::SuperTrap() {}

SuperTrap::SuperTrap(std::string const name) : ClapTrap(name,
													  100,
													  100,
													  120,
													  120,
													  1,
													  30,
													  20,
													  5) {
	std::cout << BYELLOW << "<" << name << ">" << RESET << BLUE << " this is SuperTrap\n" << RESET;
}

SuperTrap::SuperTrap(const SuperTrap &other) : ClapTrap(other) {}

SuperTrap::~SuperTrap() {
	std::cout << BLUE << "SuperTrap " << BYELLOW << "<" << _name << ">" << RESET << BLUE << " has been sent for recycling\n";
}

SuperTrap & SuperTrap::operator=(const SuperTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_maxHitPoints = other._maxHitPoints;
		this->_energyPoints = other._energyPoints;
		this->_maxEnergyPoints = other._maxEnergyPoints;
		this->_level = other._level;
		this->_meleeAttackDamage = other._meleeAttackDamage;
		this->_rangedAttackDamage = other._rangedAttackDamage;
		this->_armorDamageReduction = other._armorDamageReduction;
	}
	return *this;
}
