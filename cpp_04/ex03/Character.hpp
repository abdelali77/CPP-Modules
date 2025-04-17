#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

// ************************************************************************** //
//                               Character Class                              //
// ************************************************************************** //

class Character : public ICharacter {
private:
	AMateria* materias[4];
	std::string name;
public:
	Character( std::string name );
	Character( void );
	Character( const Character& other );
	Character& operator=( const Character& other );
	~Character();

	std::string const & getName() const;
	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );
};

#endif