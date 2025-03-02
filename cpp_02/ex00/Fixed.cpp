#include "Fixed.hpp"

const int Fixed::fractional = 8;

void Fixed::setRawBits( int const raw ) {
	fixedValue = raw;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedValue;
}

Fixed::Fixed( void ) {
	fixedValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	fixedValue = fixed.getRawBits();
}

void Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedValue = fixed.getRawBits();
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}
