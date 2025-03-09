#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>
#include <string>

// ************************************************************************** //
//                                Weapon Class                                //
// ************************************************************************** //

class Weapon {
private:
	std::string type;
public:
	const std::string &getType();
	void		  	   setType( std::string type );

	Weapon( std::string type );
	~Weapon( void );
};

#endif