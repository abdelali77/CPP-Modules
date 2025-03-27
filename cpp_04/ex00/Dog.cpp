#include "Dog.hpp"

void Dog::makeSound( void ) const {
	std::cout << "Woof!" << std::endl;
}

Dog::Dog( void ) {
	if (DEBUG)
		std::cout << "Dog Default Constructor Called!" << std::endl;
	this->type = "Dog";
}

Dog::Dog( const Dog& dog ) : Animal() {
	if (DEBUG)
		std::cout << "Dog Copy Constructor Called!" << std::endl;
	*this = dog;
}

Dog& Dog::operator=( const Dog& dog ) {
	if (DEBUG)
		std::cout << "Dog Operator Assignment Called!" << std::endl;
	if (this != &dog)
		this->type = dog.type;
	return *this; 
}

Dog::~Dog() {
	if (DEBUG)
		std::cout << "Dog Destructor Called!" << std::endl;
}