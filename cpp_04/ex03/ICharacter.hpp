#ifndef __ICHARACTER_HPP__
#define __ICHARACTER_HPP__

#include "AMateria.hpp"

class AMateria;

// ************************************************************************** //
//                              ICharacter Class                              //
// ************************************************************************** //

class ICharacter {
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif