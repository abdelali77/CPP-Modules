#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

// ************************************************************************** //
//                                 Fixed Class                                //
// ************************************************************************** //

class Fixed {
private:
	int	fixedValue;
	static const int fractional = 8;
public:
	int	getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed( void );
	Fixed( const Fixed& fixed );
	void operator=( const Fixed &fixed );
	~Fixed();
};

#endif