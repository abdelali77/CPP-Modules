#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP

#include <iostream>
#include <string>

#define DEBUG 0

// ************************************************************************** //
//                              AAnimal Class                             	  //
// ************************************************************************** //

class AAnimal {
protected:
	std::string type;
public:
	virtual void makeSound( void ) const = 0;
	std::string getType( void ) const;

	AAnimal( void );
	AAnimal( const AAnimal& animal );
	AAnimal& operator=(const AAnimal& animal );
	virtual ~AAnimal();
};


#endif