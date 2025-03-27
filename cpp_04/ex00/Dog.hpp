#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

// ************************************************************************** //
//                                  Dog Class                                 //
// ************************************************************************** //

class Dog : public Animal {
public:
	void makeSound( void ) const;

	Dog( void );
	Dog( const Dog& dog );
	Dog& operator=( const Dog& dog );
	~Dog();
};

#endif