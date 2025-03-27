#include "WrongAnimal.hpp"

std::string WrongAnimal::getType( void ) const {
	return this->type;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "Noise!" << std::endl;
}

WrongAnimal::WrongAnimal( void ) : type("Generic WrongAnimal") {
	if (DEBUG)
		std::cout << "WrongAnimal Default Constructor Called!" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& Wronganimal ) {
	if (DEBUG)
		std::cout << "WrongAnimal Copy Constructor Called!" << std::endl;
	*this = Wronganimal;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& Wronganimal ) {
	if (DEBUG)
		std::cout << "WrongAnimal Operator Assignment Called!" << std::endl;
	if (this != &Wronganimal) {
		this->type = Wronganimal.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	if (DEBUG)
		std::cout << "WrongAnimal Destructor Called!" << std::endl;
}