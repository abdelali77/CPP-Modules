#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

// ************************************************************************** //
//                                 Cure Class                                 //
// ************************************************************************** //

class Cure : public AMateria {
public:
	Cure( void );
	Cure( const Cure& other );
	Cure& operator=( const Cure& other );
	~Cure();

	virtual AMateria* clone() const;
};


#endif