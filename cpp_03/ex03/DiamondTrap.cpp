#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI( void ) {
	std::cout << "I am DiamondTrap! My name is " << this->name 
              << ", and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}

void DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap( void ) : ScavTrap("unnamed"), FragTrap("unnamed") {
	if (DEBUG)
		std::cout << "DiamondTrap Default Constructor called!" << std::endl;
	this->name = "unnamed";
	this->hitPoints = 100;
	this->energy = 50;
	this->damage = 30;
}

DiamondTrap::DiamondTrap( std::string _name ) : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name) {
	if (DEBUG)
	std::cout << "DiamondTrap " << this->name << " Parametrize constructor called!" << std::endl;
	this->name = _name;
	this->hitPoints = 100;
	this->energy = 50;
	this->damage = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap& diamond ) : ClapTrap(diamond.name + "_clap_name") {
	if (DEBUG)
		std::cout << "DiamondTrap " << this->name << " Copy Constructor Called!" << std::endl;
	*this = diamond;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& diamond ) {
	if (this != &diamond) {
		this->name = diamond.name;
		this->hitPoints = diamond.hitPoints;
		this->energy = diamond.energy;
		this->damage = diamond.damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	if (DEBUG)
		std::cout << "DiamondTrap " << this->name << " Destrcutor Called!" << std::endl;
}