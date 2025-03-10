#include "Fixed.hpp"

void Fixed::setRawBits( int const raw ) {
	this->fixedValue = raw;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedValue;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->fixedValue) / (1 << this->fractional);
}

int Fixed::toInt( void ) const {
	return this->fixedValue >> this->fractional;
}

Fixed::Fixed( const int nt ) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedValue = nt << this->fractional;
}

Fixed::Fixed( const float flt ) {
	std::cout << "Float constructor called" << std::endl;
	fixedValue = roundf(flt * (1 << fractional));
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
		this->fixedValue = fixed.fixedValue;
	return *this;
}

std::ostream& operator<<( std::ostream& os, const Fixed &fixed ) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}
