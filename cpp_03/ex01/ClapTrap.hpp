#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>
#include <string>

#define DEBUG 0

// ************************************************************************** //
//                               ClapTrap Class                               //
// ************************************************************************** //


class ClapTrap {
protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energy;
	unsigned int damage;
public:
	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap& claptrap );
	ClapTrap& operator=( const ClapTrap& claptrap );
	~ClapTrap();
};

#endif