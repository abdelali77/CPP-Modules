#include "Ice.hpp"

Ice::Ice( void ) {
	this->type = "ice";
}

Ice::Ice( const Ice& other ) {
	*this = other;
}

Ice& Ice::operator=( const Ice& other ) {
	(void)other;
	return *this;
}

Ice::~Ice() { }

AMateria* Ice::clone() const {
	AMateria* iceClone = new Ice();
	return iceClone;
}