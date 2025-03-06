#include "Fixed.hpp"

void Fixed::setRawBits( int const raw ) {
	fixedValue = raw;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedValue;
}

float Fixed::toFloat( void ) const {
	return (float)fixedValue / (1 << fractional);
}

int Fixed::toInt( void ) const {
	return fixedValue >> fractional;
}

Fixed::Fixed( const int n ) {
	std::cout << "Int constructor called" << std::endl;
	fixedValue = n << fractional;
}

Fixed::Fixed( const float n ) {
	std::cout << "Float constructor called" << std::endl;
	fixedValue = roundf(n * (1 << fractional));
}

Fixed::Fixed( void ) : fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		fixedValue = fixed.fixedValue;
	return *this;
}

std::ostream& operator<<( std::ostream& os, const Fixed &fixed ) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}
