#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed {

private:

	int					_value;
	static const int	_fractionalBits = 8;

public:

	Fixed();
	Fixed(Fixed const & other);
	~Fixed();
	Fixed &	operator=(Fixed const & other);
	int		getRawBits() const;
	void	setRawBits( int const raw );

};


#endif
