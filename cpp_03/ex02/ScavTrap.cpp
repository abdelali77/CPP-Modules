#include "ScavTrap.hpp"

void ScavTrap::guardGate( void ) {
	std::cout << this->name << " is now in Gate Keeper mode!" << std::endl;
}

void ScavTrap::attack( const std::string& target ) {
	if (this->energy > 0 && this->hitPoints > 0) {
		this->energy--;
		std::cout << this->name << " savagely scav-attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	} else {
		std::cout << this->name << " can't attack. No energy or hit points left!" << std::endl;
	}
}

ScavTrap::ScavTrap( void ) : ClapTrap("unnamed") {
	if (DEBUG)
		std::cout << "ScavTrap Default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	if (DEBUG)
		std::cout << "ScavTrap " << this->name << " Parametrize constructor called!" << std::endl;
	this->hitPoints = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& scav ) : ClapTrap(name) {
	if (DEBUG)
		std::cout << "ScavTrap " << this->name << " Copy Constructor Called!" << std::endl;
	*this = scav;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& scav ) {
	if (this != &scav) {
		this->name = scav.name;
		this->hitPoints = scav.hitPoints;
		this->energy = scav.energy;
		this->damage = scav.damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	if (DEBUG)
		std::cout << "ScavTrap " << this->name << " Destrcutor Called!" << std::endl;
}
