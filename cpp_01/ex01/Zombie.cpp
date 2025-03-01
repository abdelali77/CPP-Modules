#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string name ) {
	this->name = name;
}

Zombie::Zombie( void ) {
	name = "kl3z";
}

Zombie::~Zombie( void ) {
	std::cout << name << std::endl;
}