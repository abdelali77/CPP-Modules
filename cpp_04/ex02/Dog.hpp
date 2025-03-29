#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

// ************************************************************************** //
//                                  Dog Class                                 //
// ************************************************************************** //

class Dog : public Animal {
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