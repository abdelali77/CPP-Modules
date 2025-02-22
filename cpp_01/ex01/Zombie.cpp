#include "Zombie.hpp"

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string _name ) {
	name = _name;
}

Zombie::~Zombie( void ) {
	std::cout << name << std::endl;
}