#include "WrongCat.hpp"

void WrongCat::makeSound( void ) const {
	std::cout << "Meow!" << std::endl;
}

WrongCat::WrongCat( void ) {
	if (DEBUG)
		std::cout << "WrongCat Default Constructor Called!" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& Wrongcat ) : WrongAnimal() {
	if (DEBUG)
		std::cout << "WrongCat Copy Constructor Called!" << std::endl;
	*this = Wrongcat;
}

WrongCat& WrongCat::operator=( const WrongCat& Wrongcat ) {
	if (DEBUG)
		std::cout << "WrongCat Operator Assignment Called!" << std::endl;
	if (this != &Wrongcat)
		this->type = Wrongcat.type;
	return *this;
}

WrongCat::~WrongCat() {
	if (DEBUG)
		std::cout << "WrongCat Destructor Called!" << std::endl;
}