#include "HumanB.hpp"

void	HumanB::attack( void ) {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->weapon = &weapon;
}

HumanB::HumanB( std::string name ) : name(name) { }

HumanB::~HumanB() { }