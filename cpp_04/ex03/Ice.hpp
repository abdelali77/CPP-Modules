#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

// ************************************************************************** //
//                                  Ice Class                                 //
// ************************************************************************** //

class Ice : public AMateria {
public:
	Ice( void );
	Ice( const Ice& other );
	Ice& operator=( const Ice& other );
	~Ice();

	AMateria* clone() const;
};

#endif