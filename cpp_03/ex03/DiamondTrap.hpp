#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// ************************************************************************** //
//                             DiamondTrap Class                              //
// ************************************************************************** //

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string name;
public:
	void whoAmI( void );
	void attack( const std::string& target );

	DiamondTrap( void );
	DiamondTrap( std::string _name );
	DiamondTrap( const DiamondTrap& diamond );
	DiamondTrap& operator=( const DiamondTrap& diamond );
	~DiamondTrap();
};

#endif