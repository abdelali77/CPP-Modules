#include "ScavTrap.hpp"

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode!" << std::endl;
}

void ScavTrap::attack( const std::string& target ) {
	if (this->energy > 0 && this->hitPoints > 0) {
		this->energy--;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << this->name << " can't attack. No energy or hit points left!" << std::endl;
	}
}

ScavTrap::ScavTrap( void ) : ClapTrap("unnamed") {
	this->hitPoints = 100;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << this->name << " Parametrize constructor called!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& scav ) : ClapTrap(name) {
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
	std::cout << "ScavTrap " << this->name << " Destrcutor Called!" << std::endl;
}
