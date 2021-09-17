#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"


class Squad : public ISquad {

private:
	int				_numberOfUnits;
	ISpaceMarine	**_pSpaceMarine;

public:
	Squad();
	Squad(Squad const &other);
	Squad &operator=(Squad const &other);
	~Squad();

	int getCount() const;
	ISpaceMarine* getUnit(int number) const;
	int push(ISpaceMarine* spaceMarine);


};


#endif
