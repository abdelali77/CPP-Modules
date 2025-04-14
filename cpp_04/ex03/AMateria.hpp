#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define DEBUG 0

class ICharacter;

// ************************************************************************** //
//                               AMateria Class                               //
// ************************************************************************** //

class AMateria {
protected:
	std::string type;
public:
	AMateria( std::string const & type );
	AMateria( void );
	AMateria( const AMateria& other );
	AMateria& operator=( const AMateria& other );
	~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use( ICharacter& target );
};

#endif