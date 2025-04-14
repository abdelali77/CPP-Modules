#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"

// ************************************************************************** //
//                               Character Class                               //
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

	virtual std::string const & getName() const;
	virtual void equip( AMateria* m );
	virtual void unequip( int idx );
	virtual void use( int idx, ICharacter& target );
};

#endif