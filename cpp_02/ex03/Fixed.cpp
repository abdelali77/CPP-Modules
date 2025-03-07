#include "Fixed.hpp"

void Fixed::setRawBits( int const raw ) {
	fixedValue = raw;
}

int	Fixed::getRawBits( void ) const {
	return fixedValue;
}

float Fixed::toFloat( void ) const {
	return (float)fixedValue / (1 << fractional);
}

int Fixed::toInt( void ) const {
	return fixedValue >> fractional;
}

Fixed::Fixed( const int n ) {
	fixedValue = n << fractional;
}

Fixed::Fixed( const float n ) {
	fixedValue = roundf(n * (1 << fractional));
}

Fixed::Fixed( void ) : fixedValue(0) { }

Fixed::Fixed( const Fixed& fixed) {
	*this = fixed;
}

Fixed& Fixed::operator=( const Fixed &fixed ) {
	if (this != &fixed)
		fixedValue = fixed.fixedValue;
	return *this;
}

bool Fixed::operator>( const Fixed &fixed ) const {
	return fixedValue > fixed.fixedValue;
}

bool Fixed::operator<( const Fixed &fixed ) const {
	return fixedValue < fixed.fixedValue;
}

bool Fixed::operator>=( const Fixed &fixed ) const {
	return fixedValue >= fixed.fixedValue;
}

bool Fixed::operator<=( const Fixed &fixed ) const {
	return fixedValue <= fixed.fixedValue;
}

bool Fixed::operator==( const Fixed &fixed ) const {
	return fixedValue == fixed.fixedValue;
}

bool Fixed::operator!=( const Fixed &fixed ) const {
	return fixedValue != fixed.fixedValue;
}

Fixed Fixed::operator+( const Fixed &fixed ) const{
	return this->toFloat() + fixed.toFloat();
}

Fixed Fixed::operator-( const Fixed &fixed )const {
	return this->toFloat() - fixed.toFloat();
}

Fixed Fixed::operator*( const Fixed &fixed ) const{
	return this->toFloat() * fixed.toFloat();
}

Fixed Fixed::operator/( const Fixed &fixed ) const{
	return this->toFloat() / fixed.toFloat();
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	this->fixedValue++;
	return tmp;
}

Fixed Fixed::operator++( void ) {
	this->fixedValue++;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	this->fixedValue--;
	return tmp;
	
}

Fixed Fixed::operator--( void ) { 
	this->fixedValue--;
	return *this;
}

Fixed& Fixed::min( Fixed& a, Fixed& b ) {
	return a < b ? a : b;
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
	return a < b ? a : b;
}

Fixed& Fixed::max( Fixed& a, Fixed& b ) {
	return a > b ? a : b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
	return a > b ? a : b;
}

std::ostream& operator<<( std::ostream& os, const Fixed &fixed ) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed( void ) { } 
