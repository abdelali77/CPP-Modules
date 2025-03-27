#include "Brain.hpp"

Brain::Brain( void ) {
	if (DEBUG)
		std::cout << "Brain Default Constructor Called!" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "void";
}

Brain::Brain( const Brain& brain ) {
	if (DEBUG)
		std::cout << "Brain Copy Constructor Called!" << std::endl;
	*this = brain;
}

Brain& Brain::operator=( const Brain& brain ) {
	if (DEBUG)
		std::cout << "Brain Operator Assignment Called!" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	if (DEBUG)
		std::cout << "Brain Destructor Called!" << std::endl;
}