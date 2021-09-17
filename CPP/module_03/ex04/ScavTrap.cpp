#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name,
													  100,
													  100,
													  50,
													  50,
													  1,
													  20,
													  15,
													  3) {
	std::cout << BYELLOW << "<" << name << ">" << RESET << PURPLE << " ScavTrap robot is ready to work and defend!\n" << RESET;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {}

ScavTrap::~ScavTrap() {
	std::cout << BLUE << "ScavTrap " << BYELLOW << "<" << _name << ">" << RESET << BLUE << " has been sent for recycling\n";
}

ScavTrap & ScavTrap::operator=(const ScavTrap &other) {
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

void ScavTrap::challengeNewcomer(const std::string &target) {
	unsigned int	launch_cost(15);
	std::string randomSubject[5] = {
			"Battle Star",
			"Take It All",
			"Gunslinger",
			"Oh, the Humanity",
			"Pickle Picker"
	};
	std::string randomChallenge[5] = {
			"Dance with B4R-BOT in Moxxi's Up Over bar",
			"Defeat Deadlift without losing your shields",
			"Kill enemies with a Nova Shield burst",
			"Destroy all surveillance cameras",
			"Use all of the GREEN jump pads"
	};

	if (_hitPoints > 0) {
		std::cout << PURPLE << "ScavTrap " << BYELLOW << "<" << _name << ">" << RESET;
		if (_energyPoints >= launch_cost) {
			_energyPoints -= launch_cost;
			std::cout << PURPLE << " challenges " << BYELLOW "<" << target << ">, " << RESET << PURPLE << randomSubject[rand() % 5] << "!\n" << RESET;
			std::cout << CYAN << randomChallenge[rand() % 5] << "!" << RESET;
		}
		else
			std::cout << PURPLE << " tried to challenge " << BYELLOW "<" << target << ">," << RESET << PURPLE << " but he lacks imagination!" << RESET;
		std::cout << std::endl;
	}
}
