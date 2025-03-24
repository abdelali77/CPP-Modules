#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

// ************************************************************************** //
//                               ScavTrap Class                               //
// ************************************************************************** //

class ScavTrap : public ClapTrap {
public:
	void guardGate( void );
	void attack( const std::string& target );
	
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& scav );
	ScavTrap& operator=( const ScavTrap& scav );
	~ScavTrap();
};

#endif