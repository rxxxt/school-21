#ifndef PREY_HPP
# define PREY_HPP

# include "Victim.hpp"


class Prey : public Victim {

public:
	Prey(std::string name);
	~Prey();
	Prey(Prey const &other);
	Prey &operator=(Prey const &other);
	void	getPolymorphed() const;

private:
	Prey();

};


#endif
