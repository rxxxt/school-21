#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"


class PowerFist : public AWeapon {

public:
	PowerFist();
	PowerFist(PowerFist const &other);
	PowerFist &operator=(PowerFist const &other);
	~PowerFist();

	void attack() const;

};


#endif