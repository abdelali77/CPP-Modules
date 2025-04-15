#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

// ************************************************************************** //
//                                 Cat Class                                  //
// ************************************************************************** //

class Cat : public AAnimal {
private:
	Brain* catBrain;
public:
	void makeSound( void ) const;
	Brain* getBrain( void );

	Cat( void );
	Cat( const Cat& cat );
	Cat& operator=( const Cat& cat );
	~Cat();
};

#endif