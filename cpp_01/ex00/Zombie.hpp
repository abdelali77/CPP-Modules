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
	Zombie( std::string name );
	~Zombie( void );
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif