#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "AMateria.hpp"

typedef struct unequipedMaterias
{
	AMateria* node;
	unequipedMaterias *next;
}				u_materia;

#endif