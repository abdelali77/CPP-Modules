#include "Cure.hpp"

Cure::Cure( void ) {
	this->type = "cure";
}

Cure::Cure( const Cure& other ) {
	*this = other;
}

Cure& Cure::operator=( const Cure& other ) {
	(void)other;
	return *this;
}

Cure::~Cure() { }

AMateria* Cure::clone() const {
	AMateria* newCure = new Cure();
	return newCure;
}