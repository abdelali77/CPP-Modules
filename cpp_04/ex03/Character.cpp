#include "Character.hpp"

Character::Character( std::string name ) : name(name) {
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
		this->unequipped[i] = NULL;
	}
}

Character::Character( void ) : name("unknown") {
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
		this->unequipped[i] = NULL;
	}
}

std::string const & Character::getName() const {
	return this->name;
}

Character::Character( const Character& other ) {
	for(int i = 0; i < 4; i++) {
		this->materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
		this->unequipped[i] = other.unequipped[i] ? other.unequipped[i]->clone() : NULL;
	}
}

Character& Character::operator=( const Character& other ) {
	if (this != &other) {
		for(int i = 0; i < 4; i++) {
			if (this->materias[i]) {
				delete this->materias[i];
				this->materias[i] = NULL;
			}
			if (this->unequipped[i]) {
				delete this->unequipped[i];
				this->unequipped[i] = NULL;
			}
		}
		for(int i = 0; i < 4; i++) {
			this->materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
		}
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
	if (idx < 0 || idx > 3 || !this->materias[idx])
		return;
	for (int i = 0; i < 4; i++) {
		if(!this->materias[i]) {
			this->unequipped[i] = this->materias[idx];
			this->materias[idx] = NULL;
			return;
		}
	}
	delete this->materias[idx];
	this->materias[idx] = NULL;
}

void Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx <= 3) {
		if (this->materias[idx])
			this->materias[idx]->use(target);
	}
}

Character::~Character() {
	for(int i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
		if (this->unequipped[i])
			delete this->unequipped[i];
	}
}