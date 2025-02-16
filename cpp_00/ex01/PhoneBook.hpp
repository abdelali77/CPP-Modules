#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact contacts[8];
	public:
		void	set_contact(Contact contact, int index);
		Contact	get_contact(int index);
};

#endif