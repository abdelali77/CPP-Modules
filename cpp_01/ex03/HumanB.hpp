#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <iostream>
#include "Weapon.hpp"

// ************************************************************************** //
//                                HumanB Class                                //
// ************************************************************************** //

class HumanB {
private:
	std::string name;
	Weapon		*weapon;
public:
	void	attack( void );
	void	setWeapon( Weapon &weapon );
	HumanB( std::string name );
	~HumanB( void );
};

#endif