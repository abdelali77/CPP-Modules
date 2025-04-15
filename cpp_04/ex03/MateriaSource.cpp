#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) { 
	for(int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other ) {
	for(int i = 0; i < 4; i++) {
		this->materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
	}
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ) {
	if (this != &other) {
		for(int i = 0; i < 4; i++) {
			if (this->materias[i]) {
				delete this->materias[i];
				this->materias[i] = NULL;
			}
		}
		for(int i = 0; i < 4; i++) {
			if (other.materias[i])
				this->materias[i] = other.materias[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
	}
}

void MateriaSource::learnMateria( AMateria* m ) {
	for(int i = 0; i < 4; i++) {
		if (!this->materias[i]) {
			this->materias[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria( std::string const & type ) {
	for (int i = 0; i < 4; i++) {
		if(this->materias[i] && this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	std::cout << "unknown type" << std::endl;
	return NULL;
}