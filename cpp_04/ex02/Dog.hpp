#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

// ************************************************************************** //
//                                  Dog Class                                 //
// ************************************************************************** //

class Dog : public AAnimal {
private:
	Brain* dogBrain;
public:
	void makeSound( void ) const;
	Brain* getBrain( void );

	Dog( void );
	Dog( const Dog& dog );
	Dog& operator=( const Dog& dog );
	~Dog();
};

#endif