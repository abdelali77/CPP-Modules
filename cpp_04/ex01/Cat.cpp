#include "Cat.hpp"

void Cat::makeSound( void ) const {
	std::cout << "Meow!" << std::endl;
}

Cat::Cat( void ) {
	if (DEBUG)
		std::cout << "Cat Default Constructor Called!" << std::endl;
	this->type = "Cat";
}

Cat::Cat( const Cat& cat ) : Animal() {
	if (DEBUG)
		std::cout << "Cat Copy Constructor Called!" << std::endl;
	*this = cat;
}

Cat& Cat::operator=( const Cat& cat ) {
	if (DEBUG)
		std::cout << "Cat Operator Assignment Called!" << std::endl;
	if (this != &cat)
		this->type = cat.type;
	return *this;
}

Cat::~Cat() {
	if (DEBUG)
		std::cout << "Cat Destructor Called!" << std::endl;
}