#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

# define RED			"\033[0;31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define BLUE			"\033[0;34m"
# define PURPLE			"\033[0;35m"
# define CYAN			"\033[0;36m"
# define GRAY			"\033[0;37m"
# define BOLD_RED		"\033[1;31m"
# define BOLD_GREEN		"\033[1;32m"
# define BOLD_YELLOW	"\033[1;33m"
# define BOLD_BLUE		"\033[1;34m"
# define BOLD_PURPLE	"\033[1;35m"
# define BOLD_CYAN		"\033[1;36m"
# define BOLD_GRAY		"\033[1;37m"
# define BOLD_WHITE		"\033[1m"
# define RESET			"\033[0m"

class Weapon {

private:
	std::string	_type;

public:
	Weapon(std::string type);
	void				setType(std::string type);
	const std::string &	getType();
};


#endif
