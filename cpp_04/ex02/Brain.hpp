#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include "AAnimal.hpp"

// ************************************************************************** //
//                                 Brain Class                                //
// ************************************************************************** //

class Brain {
private:
	std::string ideas[100];
public:
	void setIdeas( std::string idea );
	std::string* getIdeas( void );

	Brain( void );
	Brain( const Brain& brain );
	Brain& operator=( const Brain& brain );
	~Brain();
};

#endif