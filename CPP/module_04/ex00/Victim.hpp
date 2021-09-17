#ifndef VICTIM_HPP
# define VICTIM_HPP

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


class Victim {

public:
	Victim(std::string name);
	virtual ~Victim();
	Victim(Victim const &other);
	Victim &operator=(Victim const &other);
	std::string		getName() const;
	virtual void	getPolymorphed() const;

protected:
	Victim();
	std::string		_name;

};


std::ostream	&operator<<(std::ostream &o, Victim const &victim);

#endif
