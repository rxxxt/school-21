#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"


class Peon : public Victim {

public:
	Peon(std::string name);
	~Peon();
	Peon(Peon const &other);
	Peon &operator=(Peon const &other);
	void	getPolymorphed() const;

private:
	Peon();

};


#endif
