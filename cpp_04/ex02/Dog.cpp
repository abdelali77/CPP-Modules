#include "Dog.hpp"

void Dog::makeSound( void ) const {
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain( void ) {
	return this->dogBrain;
}

Dog::Dog( void ) {
	if (DEBUG)
		std::cout << "Dog Default Constructor Called!" << std::endl;
	this->type = "Dog";
	this->dogBrain = new Brain();
}

Dog::Dog( const Dog& dog ) : AAnimal() {
	if (DEBUG)
		std::cout << "Dog Copy Constructor Called!" << std::endl;
	this->type = dog.type;
	this->dogBrain = new Brain(*dog.dogBrain);	
}

Dog& Dog::operator=( const Dog& dog ) {
	if (DEBUG)
		std::cout << "Dog Operator Assignment Called!" << std::endl;
	if (this != &dog) {
		this->type = dog.type;
		delete this->dogBrain;
		this->dogBrain = new Brain(*dog.dogBrain);
	}
	return *this; 
}

Dog::~Dog() {
	if (DEBUG)
		std::cout << "Dog Destructor Called!" << std::endl;
	delete this->dogBrain;
}