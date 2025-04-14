#include "Character.hpp"

Character::Character( std::string name ) : name(name) {
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

Character::Character( void ) : name("unknown") {
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

std::string const & Character::getName() const {
	return this->name;
}

Character::Character( const Character& other ) {
	*this = other;
}

Character& Character::operator=( const Character& other ) {
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < 4; i++)
			this->materias[i] = other.materias[i];
	}
	return *this;
}

void Character::equip( AMateria* m ) {
	for (int i = 0; i < 4; i++) {
		if (!this->materias[i]) {
			this->materias[i] = m;
			break;
		}
	}
}

void Character::unequip( int idx ) {
	AMateria *tmp;
	for (int i = 0; i < 4; i++) {
		if (i == idx) {
			tmp = this->materias[i];
			this->materias[i] = NULL;
		}
	}
}

void Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx <= 3) {
		if (this->materias[idx])
			this->materias[idx]->use(target);
	}
}

Character::~Character() { }