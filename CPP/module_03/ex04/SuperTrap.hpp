#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"


class SuperTrap : public virtual FragTrap, public virtual NinjaTrap{

public:
	SuperTrap(std::string const name);
	SuperTrap(SuperTrap const &other);
	~SuperTrap();
	SuperTrap &operator=(SuperTrap const &other);

private:
	SuperTrap();

};


#endif
