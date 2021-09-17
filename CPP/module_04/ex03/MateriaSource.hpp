#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

# define MAXMATERIA 4


class MateriaSource : public IMateriaSource {

private:
	AMateria	*_materia[MAXMATERIA];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);
	~MateriaSource();

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const &type);

};


#endif
