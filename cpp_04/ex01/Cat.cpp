#include "Cat.hpp"

void Cat::makeSound( void ) const {
	std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain( void ) {
	return this->catBrain;
}

Cat::Cat( void ) {
	if (DEBUG)
		std::cout << "Cat Default Constructor Called!" << std::endl;
	this->type = "Cat";
	this->catBrain = new Brain();
}

Cat::Cat( const Cat& cat ) {
	if (DEBUG)
		std::cout << "Cat Copy Constructor Called!" << std::endl;
	this->type = cat.type;
	this->catBrain = new Brain(*cat.catBrain);
}

Cat& Cat::operator=( const Cat& cat ) {
	if (DEBUG)
		std::cout << "Cat Operator Assignment Called!" << std::endl;
	if (this != &cat) {
		this->type = cat.type;
		delete this->catBrain;
		this->catBrain = new Brain(*cat.catBrain);
	}
	return *this;
}

Cat::~Cat() {
	if (DEBUG)
		std::cout << "Cat Destructor Called!" << std::endl;
	delete this->catBrain;
}