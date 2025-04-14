#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

// ************************************************************************** //
//                            MateriaSource Class                             //
// ************************************************************************** //

class MateriaSource : public IMateriaSource {
private:
	AMateria* materias[4];
public:
	MateriaSource( void );
	MateriaSource( const MateriaSource& other );
	MateriaSource& operator=( const MateriaSource& other );
	~MateriaSource();

	virtual void learnMateria( AMateria* );
	virtual AMateria* createMateria( std::string const & type );
};

#endif