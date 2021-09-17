#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class NinjaTrap : public ClapTrap {

public:
	NinjaTrap(std::string const name);
	NinjaTrap(NinjaTrap const &other);
	~NinjaTrap();
	NinjaTrap &operator=(NinjaTrap const &other);
	void	ninjaShoebox(ClapTrap &target);
	void	ninjaShoebox(FragTrap &target);
	void	ninjaShoebox(ScavTrap &target);
	void	ninjaShoebox(NinjaTrap &target);

private:
	NinjaTrap();

};


#endif
