#include "FragTrap.hpp"

void FragTrap::highFivesGuys( void ) {
	std::cout << name << " says: 'High five, guys! Who’s with me? positivity rocks!'" << std::endl;
}

FragTrap::FragTrap( void ) : ClapTrap("unnamed") {
	if (DEBUG)
		std::cout << "FragTrap Default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	if (DEBUG)
		std::cout << "FragTrap " << this->name << " Parametrize constructor called!" << std::endl;
	this->hitPoints = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap( const FragTrap& frag ) : ClapTrap(name) {
	if (DEBUG)
		std::cout << "FragTrap " << this->name << " Copy Constructor Called!" << std::endl;
	*this = frag;
}

FragTrap& FragTrap::operator=( const FragTrap& frag ) {
	if (this != &frag) {
		this->name = frag.name;
		this->hitPoints = frag.hitPoints;
		this->energy = frag.energy;
		this->damage = frag.damage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	if (DEBUG)
		std::cout << "FragTrap " << this->name << " Destrcutor Called!" << std::endl;
}