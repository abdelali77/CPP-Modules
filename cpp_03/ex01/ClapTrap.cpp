#include "ClapTrap.hpp"

void ClapTrap::attack( const std::string& target ) {
	if (this->energy > 0 && this->hitPoints > 0) {
		this->energy--;
		std::cout << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	} else {
		std::cout << this->name << " can't attack. No energy or hit points left!" << std::endl;
	}
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->hitPoints < amount)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << this->name << " has been hit and loses " << amount << " health points! "
			  << "Remaining hit points: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->energy > 0 && this->hitPoints > 0) {
		this->energy--;
		this->hitPoints += amount;
		std::cout << this->name << " recovering " << amount << " hit points!" << std::endl;
	} else {
		std::cout << this->name << " can't repair. No energy or hit points left!" << std::endl;
	}
}

ClapTrap::ClapTrap( void ) : name("unnamed"), hitPoints(10), energy(10), damage(0) {
	if (DEBUG)
		std::cout << "ClapTrap Default Constructor called!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hitPoints(10), energy(10), damage(0) {
	if (DEBUG)
		std::cout << "ClapTrap " << this->name << " Parametrize construcotr called!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& claptrap ) {
	if (DEBUG)
		std::cout << "ClapTrap" << this->name << " Copy Constructor Called!" << std::endl;
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& claptrap ) {
	if (this != &claptrap) {
		this->name = claptrap.name;
		this->hitPoints = claptrap.hitPoints;
		this->energy = claptrap.energy;
		this->damage = claptrap.damage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	if (DEBUG)
		std::cout << "ClapTrap " << this->name << " Destructor called!" << std::endl;
}
