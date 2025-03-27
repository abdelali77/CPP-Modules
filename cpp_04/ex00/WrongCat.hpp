#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

// ************************************************************************** //
//                               WrongCat Class                               //
// ************************************************************************** //

class WrongCat : public WrongAnimal {
public:
	void makeSound( void ) const;

	WrongCat( void );
	WrongCat( const WrongCat& wrongcat );
	WrongCat& operator=( const WrongCat& wrongcat );
	~WrongCat();
};

#endif