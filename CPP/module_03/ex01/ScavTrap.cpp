#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string const name) :
		_name(name),
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(50),
		_maxEnergyPoints(50),
		_level(1),
		_meleeAttackDamage(20),
		_rangedAttackDamage(15),
		_armorDamageReduction(3) {
	std::cout << BYELLOW << "<" << name << ">" << RESET << PURPLE << " brand new assault robot FR4G-TP came off the assembly line\n" << RESET;
}

ScavTrap::ScavTrap(ScavTrap const & other) :
		_name(other._name),
		_hitPoints(other._hitPoints),
		_maxHitPoints(other._maxHitPoints),
		_energyPoints(other._energyPoints),
		_maxEnergyPoints(other._maxEnergyPoints),
		_level(other._level),
		_meleeAttackDamage(other._meleeAttackDamage),
		_rangedAttackDamage(other._rangedAttackDamage),
		_armorDamageReduction(other._armorDamageReduction) {
	std::cout << GREEN << "Cloning " << BYELLOW << "<" << _name << ">" << RESET << GREEN << " was successful\n";
	if (_name.find("'s clone") > _name.length())
		_name += "'s clone";
}

ScavTrap::~ScavTrap() {
	std::cout << BYELLOW << "<" << _name << ">" << RESET << BLUE << " has been sent for recycling\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap const & other) {
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

void ScavTrap::rangedAttack(const std::string & target) {
	if (_hitPoints > 0) {
		std::cout << RED << "FR4G-TP " << BYELLOW << "<" << _name << ">" << RESET << RED " attacks "
				  << BYELLOW "<" << target << ">" << RESET << RED << " at range, causing <";
		if (_rangedAttackDamage < _hitPoints)
			std::cout << _rangedAttackDamage;
		else
			std::cout << _hitPoints;
		std::cout << "> points of damage!\n";
	}
}

void ScavTrap::meleeAttack(const std::string &target) {
	if (_hitPoints > 0) {
		std::cout << RED << "FR4G-TP " << BYELLOW << "<" << _name << ">" << RESET << RED " attacks "
				  << BYELLOW "<" << target << ">" << RESET << RED << " in melee, dealing <";
		if (_meleeAttackDamage < _hitPoints)
			std::cout << _meleeAttackDamage;
		else
			std::cout << _hitPoints;
		std::cout << "> points of damage!\n";
	}
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout << RED << "FR4G-TP " << BYELLOW << "<" << _name << ">" << RESET << RED << " takes <";
		if (amount <= _armorDamageReduction)
			std::cout << "0> points of damage!\n";
		else if (amount - _armorDamageReduction < _hitPoints) {
			_hitPoints -= (amount - _armorDamageReduction);
			std::cout << amount - _armorDamageReduction << "> points of damage!\n";
		}
		else {
			std::cout << _hitPoints << "> critical points of damage and dies!\n";
			_hitPoints = 0;
		}
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << RED << "FR4G-TP " << BYELLOW << "<" << _name << ">" << RESET;
	if (_hitPoints == 0)
		std::cout << RED << " is dead!\n";
	else if (_hitPoints < _maxHitPoints) {
		std::cout << RED << " has got <";
		if (_hitPoints + amount > _maxHitPoints) {
			std::cout << _maxHitPoints - _hitPoints;
			_hitPoints = _maxHitPoints;
		}
		else {
			std::cout << amount;
			_hitPoints += amount;
		}
		std::cout << "> health points!\n" << RESET;
	}
}

void ScavTrap::vaulthunter_dot_exe(const std::string &target) {
	unsigned int	launch_cost(25);
	std::string randomAttack[5] = {
			"Funzerker",
			"Shhhhh... Trap",
			"Miniontrap",
			"Blightbot",
			"Mechromagician"
	};

	if (_hitPoints > 0) {
		std::cout << RED << "FR4G-TP " << BYELLOW << "<" << _name << ">" << RESET;
		if (_energyPoints >= launch_cost) {
			_energyPoints -= launch_cost;
			std::cout << RED << " attacks " << BYELLOW "<" << target << ">," << RESET
					  << RED << " using the " << randomAttack[rand() % 5] << " and deals <35> points of damage!";
		}
		else
			std::cout << RED << " tried to attack " << BYELLOW "<" << target << ">," << RESET << RED << " but he doesn't have enough energy!" << RESET;
		std::cout << std::endl;
	}
}

void ScavTrap::charger() {
	if (_hitPoints > 0) {
		if (_energyPoints < _maxEnergyPoints)
			_energyPoints = _maxEnergyPoints;
	}
}

void ScavTrap::levelUp() {
	if (_hitPoints > 0) {
		_level += 1;
	}
}
