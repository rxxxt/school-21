#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include "ISpaceMarine.hpp"


class TacticalMarine : public ISpaceMarine {

public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &other);
	TacticalMarine &operator=(TacticalMarine const &other);
	~TacticalMarine();

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

};


#endif
