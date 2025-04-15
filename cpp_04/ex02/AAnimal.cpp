#include "AAnimal.hpp"

std::string AAnimal::getType( void ) const {
	return this->type;
}

void AAnimal::makeSound( void ) const {
	std::cout << "Noise!" << std::endl;
}

AAnimal::AAnimal( void ) : type("Generic Animal") {
	if (DEBUG)
		std::cout << "Animal Default Constructor Called!" << std::endl;
}

AAnimal::AAnimal( const AAnimal& animal ) {
	if (DEBUG)
		std::cout << "Animal Copy Constructor Called!" << std::endl;
	*this = animal;
}

AAnimal& AAnimal::operator=( const AAnimal& animal ) {
	if (DEBUG)
		std::cout << "Animal Operator Assignment Called!" << std::endl;
	if (this != &animal) {
		this->type = animal.type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	if (DEBUG)
		std::cout << "Animal Destructor Called!" << std::endl;
}