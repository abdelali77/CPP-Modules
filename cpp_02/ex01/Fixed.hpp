#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

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
	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed( const int n );
	Fixed( const float n );
	Fixed( void );
	Fixed( const Fixed& fixed);
	Fixed& operator=( const Fixed &fixed );
	~Fixed();
};

std::ostream& operator<<( std::ostream& os, const Fixed &fixed );

#endif