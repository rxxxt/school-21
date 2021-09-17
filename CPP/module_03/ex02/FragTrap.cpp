#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string const name) : ClapTrap(name,
													  100,
													  100,
													  100,
													  100,
													  1,
													  30,
													  20,
													  5) {
	std::cout << BYELLOW << "<" << name << ">" << RESET << GREEN << " brand new assault robot FR4G-TP came off the assembly line\n" << RESET;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {}

FragTrap::~FragTrap() {
	std::cout << BYELLOW << "<" << _name << ">" << RESET << BLUE << " has been sent for recycling\n";
}

FragTrap & FragTrap::operator=(const FragTrap &other) {
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

void FragTrap::vaulthunter_dot_exe(const std::string &target) {
	unsigned int	launch_cost(25);
	std::string randomAttack[5] = {
			"Funzerker",
			"Shhhhh... Trap",
			"Miniontrap",
			"Blightbot",
			"Mechromagician"
	};

	if (_hitPoints > 0) {
		std::cout << GREEN << "FR4G-TP " << BYELLOW << "<" << _name << ">" << RESET;
		if (_energyPoints >= launch_cost) {
			_energyPoints -= launch_cost;
			std::cout << GREEN << " attacks " << BYELLOW "<" << target << ">," << RESET
					  << GREEN << " using the " << randomAttack[rand() % 5] << " and deals <35> points of damage!";
		}
		else
			std::cout << GREEN << " tried to attack " << BYELLOW "<" << target << ">," << RESET << GREEN << " but he doesn't have enough energy!" << RESET;
		std::cout << std::endl;
	}
}
