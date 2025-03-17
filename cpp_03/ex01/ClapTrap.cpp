#include "ClapTrap.hpp"

void ClapTrap::attack( const std::string& target ) {
	if (this->energy > 0 && this->hitPoints > 0) {
		this->energy--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " can't attack. No energy or hit points left!" << std::endl;
	}
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->hitPoints < amount)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " has been hit and loses " << amount << " health points! "
	<< "Remaining hit points: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->energy > 0 && this->hitPoints > 0) {
		this->energy--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " recovering " << amount << " hit points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " can't repair. No energy or hit points left!" << std::endl;
	}
}

ClapTrap::ClapTrap( void ) {
	this->name = "kl3z";
	this->hitPoints = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "Default Constructor called!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) {
	this->name = name;
	this->hitPoints = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << this->name << " Parametrize construcotr called!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& claptrap ) {
	std::cout << this->name << " Copy Constructor Called!" << std::endl;
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
	std::cout << this->name << " Desctructor called!" << std::endl;
}
