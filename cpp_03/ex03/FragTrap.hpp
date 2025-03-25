#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

// ************************************************************************** //
//                               FragTrap Class                               //
// ************************************************************************** //

class FragTrap : virtual public ClapTrap {
public:
	void highFivesGuys( void );

	FragTrap( void );
	FragTrap( std::string _name );
	FragTrap (const FragTrap& frag );
	FragTrap& operator=( const FragTrap& frag );
	~FragTrap();
};

#endif