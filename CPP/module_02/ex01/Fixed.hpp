#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed {

private:

	int					_value;
	static const int	_fractionalBits = 8;

public:

	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const & other);
	~Fixed();
	Fixed &	operator=(Fixed const & other);
	float	toFloat() const;
	int		toInt() const;
	int		getRawBits() const;
	void	setRawBits( int const raw );

};


std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);

#endif
