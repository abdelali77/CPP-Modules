#include "AMateria.hpp"

AMateria::AMateria( void ) : type("unknown") {
	if (DEBUG)
		std::cout << "AMateria of type '" << type << "' has been created with default constructor." << std::endl;
}

AMateria::AMateria( std::string const & type ) : type(type) {
	if (DEBUG)
		std::cout << "AMateria of type '" << type << "' has been created with parameterized constructor." << std::endl;
}

AMateria::AMateria( const AMateria& other ) {
	if (DEBUG)
		std::cout << "AMateria of type '" << type << " ' has been copied with copy constructor." << std::endl;
	*this = other;
}

AMateria& AMateria::operator=( const AMateria& other ) {
	(void)other;
	return *this;
}

AMateria::~AMateria() {
	if (DEBUG)
		std::cout << "AMateria of type '" << type << "' has been destroyed." << std::endl;
}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use( ICharacter& target ) {
	if (this->type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cout << "* shoots an " << this->type << " " << target.getName() << std::endl;
}
