#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <iostream>
#include "Weapon.hpp"

// ************************************************************************** //
//                                HumanA Class                                //
// ************************************************************************** //

class HumanA {
private:
	std::string name;
	Weapon		&weapon;
public:
	void	attack( void );
	HumanA( std::string name, Weapon &weapon );
};

#endif