#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

// ************************************************************************** //
//                                Zombie Class                                //
// ************************************************************************** //

class Zombie {
private:
	std::string name;
public:
	void	announce( void );
	void	set_name( std::string _name );
	~Zombie( void );
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif