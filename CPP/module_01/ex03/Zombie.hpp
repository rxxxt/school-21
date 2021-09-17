#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Zombie {

private:
	std::string _name;
	std::string	_type;

public:
	Zombie();
	Zombie(std::string name, std::string type);
	void		announce();
	void		setName(std::string name);
	void		setType(std::string type);
};

#endif
