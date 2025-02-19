#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

// ************************************************************************** //
//                             PhoneBook Class                                //
// ************************************************************************** //

class PhoneBook {
private:
	Contact contacts[8];
public:
	void	set_contact( Contact contact, int index );
	Contact	get_contact( int index );
};

void	_add(int *index, PhoneBook &myPhoneBook);
void	_search(PhoneBook myPhoneBook);

#endif