#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"
#include "utils.hpp"

// ************************************************************************** //
//                            MateriaSource Class                             //
// ************************************************************************** //

class MateriaSource : public IMateriaSource {
private:
	AMateria* materias[4];
public:
	static u_materia *unequipped;
	MateriaSource( void );
	MateriaSource( const MateriaSource& other );
	MateriaSource& operator=( const MateriaSource& other );
	~MateriaSource();

	static	void addBack( u_materia** list, u_materia* _new );
	static u_materia* newNode( AMateria *materia );
	void learnMateria( AMateria* );
	AMateria* createMateria( std::string const & type );
};

#endif