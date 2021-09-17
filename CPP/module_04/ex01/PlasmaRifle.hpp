#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"


class PlasmaRifle : public AWeapon {

public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &other);
	PlasmaRifle &operator=(PlasmaRifle const &other);
	~PlasmaRifle();

	void	attack() const;

};


#endif
