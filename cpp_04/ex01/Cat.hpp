#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

// ************************************************************************** //
//                                 Cat Class                                  //
// ************************************************************************** //

class Cat : public Animal {
public:
	void makeSound( void ) const;

	Cat( void );
	Cat( const Cat& cat );
	Cat& operator=( const Cat& cat );
	~Cat();
};

#endif