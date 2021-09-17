#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"


class SuperMutant : public Enemy {

private:
	int	_damageReduction;

public:
	SuperMutant();
	SuperMutant(SuperMutant const &other);
	SuperMutant	&operator=(SuperMutant const &other);
	~SuperMutant();

	void takeDamage(int damage);

};


#endif
