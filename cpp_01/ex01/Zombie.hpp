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
	void	set_name( std::string name );
	Zombie( void );
	~Zombie( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif