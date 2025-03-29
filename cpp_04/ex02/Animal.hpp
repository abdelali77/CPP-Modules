#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP

#include <iostream>
#include <string>

#define DEBUG 0

// ************************************************************************** //
//                               Animal Class                             	  //
// ************************************************************************** //

class Animal {
protected:
	std::string type;
public:
	virtual void makeSound( void ) const = 0;
	std::string getType( void ) const;

	Animal( void );
	Animal( const Animal& animal );
	Animal& operator=(const Animal& animal );
	virtual ~Animal();
};


#endif