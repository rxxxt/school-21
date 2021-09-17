#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;


class AMateria {

protected:
	std::string		_type;
	unsigned int	_xp;

public:
	explicit AMateria(std::string const &type);
	AMateria(AMateria const &other);
	AMateria &operator=(AMateria const &other);
	virtual ~AMateria();

	const std::string &getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

private:
	AMateria();

};


#endif
