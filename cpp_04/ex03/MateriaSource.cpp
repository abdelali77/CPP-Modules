#include "MateriaSource.hpp"
#include "utils.hpp"

u_materia* MateriaSource::unequipped = NULL;

void MateriaSource::addBack( u_materia** list, u_materia* _new ) {
	if (!*list && !_new)
		return ;
	if (!*list) {
		*list = _new;
		return ;
	}
	u_materia* last;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = _new;
}

u_materia* MateriaSource::newNode( AMateria* materia ) {
	u_materia* newNode;

	if (!materia)
		return NULL;
	newNode = new u_materia;
	newNode->node = materia;
	newNode->next = NULL;
	return newNode;
}

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
	u_materia *tmp;
	while (this->unequipped)
	{
		tmp = this->unequipped;
		this->unequipped = this->unequipped->next;
		if (tmp->node) {
			delete tmp->node;
			tmp->node = NULL;
		}
		delete tmp;
		tmp = NULL;
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