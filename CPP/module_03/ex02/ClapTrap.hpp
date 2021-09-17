#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define BRED		"\033[1;31m"
# define BGREEN		"\033[1;32m"
# define BYELLOW	"\033[1;33m"
# define BBLUE		"\033[1;34m"
# define BPURPLE	"\033[1;35m"
# define BCYAN		"\033[1;36m"
# define BGRAY		"\033[1;37m"
# define BWHITE		"\033[1m"
# define RESET		"\033[0m"


class ClapTrap {

public:
	ClapTrap(std::string name,
			 unsigned int	hitPoints,
			 unsigned int	maxHitPoints,
			 unsigned int	energyPoints,
			 unsigned int	maxEnergyPoints,
			 unsigned int	level,
			 unsigned int	meleeAttackDamage,
			 unsigned int	rangedAttackDamage,
			 unsigned int	armorDamageReduction);
	ClapTrap(ClapTrap const & other);
	ClapTrap &operator=(ClapTrap const & other);
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

protected:
	ClapTrap();
	void			charger();
	void			levelUp();
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;

};


#endif
