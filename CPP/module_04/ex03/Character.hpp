#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAXMATERIA 4


class Character : public ICharacter {

private:
	std::string	_name;
	AMateria	*_materia[MAXMATERIA];

public:
	explicit Character(std::string name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	~Character();

	std::string const &getName() const;
	void equip(AMateria* materia);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	unsigned int getXPOfMateria(int idx);


private:
	Character();

};


#endif
