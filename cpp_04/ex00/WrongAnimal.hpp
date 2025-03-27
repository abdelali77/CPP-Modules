#ifndef __WRONGANIMAL_HPP
#define __WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"


// ************************************************************************** //
//                             WrongAnimal Class                              //
// ************************************************************************** //

class WrongAnimal {
protected:
	std::string type;
public:
	void makeSound( void ) const;
	std::string getType( void ) const;

	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& wronganimal );
	WrongAnimal& operator=(const WrongAnimal& wronganimal );
	~WrongAnimal();
};

#endif