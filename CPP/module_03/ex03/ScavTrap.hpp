#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {

public:
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &other);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const &other);
	void			challengeNewcomer(std::string const & target);

private:
	ScavTrap();

};


#endif
