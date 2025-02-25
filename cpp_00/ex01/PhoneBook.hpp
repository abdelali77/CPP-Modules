#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

// ************************************************************************** //
//                             PhoneBook Class                                //
// ************************************************************************** //

class PhoneBook {
private:
	Contact contacts[8];
public:
	void	add( void );
	void	search( void );
};

#endif