#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap("Default",
														60,
														60,
														120,
														120,
														1,
														60,
														5,
														0) {
	std::cout << BYELLOW << "<" << _name << ">" << RESET << RED << " NinjaTrap is ready!\n" << RESET;
}

NinjaTrap::NinjaTrap(const std::string name) : ClapTrap(name,
														60,
														60,
														120,
														120,
														1,
														60,
														5,
														0) {
	std::cout << BYELLOW << "<" << name << ">" << RESET << RED << " NinjaTrap is ready!\n" << RESET;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other) : ClapTrap(other) {}

NinjaTrap::~NinjaTrap() {
	std::cout << BLUE << "NinjaTrap " << BYELLOW << "<" << _name << ">" << RESET << BLUE << " has been sent for recycling\n";
}

NinjaTrap & NinjaTrap::operator=(const NinjaTrap &other) {
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

void NinjaTrap::ninjaShoebox(ClapTrap &target) {
	if (_hitPoints > 0) {
		std::cout << YELLOW << "NinjaTrap " << BRED << "<" << _name << ">" << RESET << YELLOW " asks ClapTrap "
		<< BRED "<" << target.getName() << ">." << RESET << YELLOW << " How are your heirs doing?\n";
	}
}

void NinjaTrap::ninjaShoebox(FragTrap &target) {
	if (_hitPoints > 0) {
		std::cout << YELLOW << "NinjaTrap " << BRED << "<" << _name << ">" << RESET << YELLOW " says FragTrap "
		<< BRED "<" << target.getName() << ">." << RESET << YELLOW << " I know your parents!\n";
	}
}

void NinjaTrap::ninjaShoebox(ScavTrap &target) {
	if (_hitPoints > 0) {
		std::cout << YELLOW << "NinjaTrap " << BRED << "<" << _name << ">" << RESET << YELLOW " asks ScavTrap "
		<< BRED "<" << target.getName() << ">." << RESET << YELLOW << " Are you not infected with COVID?\n";
	}
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target) {
	if (_hitPoints > 0) {
		std::cout << YELLOW << "NinjaTrap " << BRED << "<" << _name << ">" << RESET << YELLOW " asks NinjaTrap "
		<< BRED "<" << target.getName() << ">." << RESET << YELLOW << " What is your profession?\n";
	}
}
