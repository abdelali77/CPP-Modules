#include "Animal.hpp"

std::string Animal::getType( void ) const {
	return this->type;
}

void Animal::makeSound( void ) const {
	std::cout << "Noise!" << std::endl;
}

Animal::Animal( void ) : type("Generic Animal") {
	if (DEBUG)
		std::cout << "Animal Default Constructor Called!" << std::endl;
}

Animal::Animal( const Animal& animal ) {
	if (DEBUG)
		std::cout << "Animal Copy Constructor Called!" << std::endl;
	*this = animal;
}

Animal& Animal::operator=( const Animal& animal ) {
	if (DEBUG)
		std::cout << "Animal Operator Assignment Called!" << std::endl;
	if (this != &animal) {
		this->type = animal.type;
	}
	return *this;
}

Animal::~Animal() {
	if (DEBUG)
		std::cout << "Animal Destructor Called!" << std::endl;
}