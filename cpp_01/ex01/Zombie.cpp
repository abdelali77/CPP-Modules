#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

Zombie::Zombie( void ) {
	name = "kl3z";
}

Zombie::~Zombie( void ) {
	std::cout << name << std::endl;
}