#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include "Animal.hpp"

// ************************************************************************** //
//                                 Brain Class                                //
// ************************************************************************** //

class Brain {
public:
	std::string ideas[100];

	Brain( void );
	Brain( const Brain& brain );
	Brain& operator=( const Brain& brain );
	~Brain();
};

#endif