#include "PhoneBook.hpp"

void	print_columns() {
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
	std::cout << " ___________________________________________ " << std::endl;
}

std::string	check_width(std::string string) {
	std::string	sub;

	sub = string;
	if (string.length() > 10) {
		sub = string.substr(0, 9);
		sub.replace(9, 1, 1, '.');
	}
	return sub;
}

void	_display(Contact contacts[8], int index) {
	std::cout << "|";
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << check_width(contacts[index % 8].get_field("first_name")) << "|";
	std::cout << std::setw(10) << check_width(contacts[index % 8].get_field("last_name")) << "|";
	std::cout << std::setw(10) << check_width(contacts[index % 8].get_field("nickname")) << "|";
	std::cout << std::endl;
	std::cout << " ___________________________________________ " << std::endl;
}

void	display_fields(Contact contacts[8], int index) {
	std::cout << contacts[index % 8].get_field("first_name") << std::endl;
	std::cout << contacts[index % 8].get_field("last_name") << std::endl;
	std::cout << contacts[index % 8].get_field("nickname") << std::endl;
	std::cout << contacts[index % 8].get_field("phone") << std::endl;
	std::cout << contacts[index % 8].get_field("secret") << std::endl;
}

void	display_columns(Contact contacts[8]) {
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].get_field("first_name").empty())
			break;
		else
			_display(contacts, i);
	}
}

int	check_fields(std::string fields[5]) {
	for (int i = 0 ; i < 5 ; i++) {
		if (fields[i].empty())
			return 1;
	}
	return 0;
}

void	PhoneBook::add( void ) {
	Contact	contact;
	std::string fields[5];
	std::string	field;
	static int index = 0;
	for (int i = 0 ; i < 5 ; i++) {
		if (i == 0)
			std::cout << "Enter [ first name ]: ";
		else if (i == 1)
			std::cout << "Enter [ last name ]: ";
		else if (i == 2)
			std::cout << "Enter [ nickname ]: ";
		else if (i == 3)
			std::cout << "Enter [ phone number ]: ";
		else if (i == 4)
			std::cout << "Enter [ darkest secret ]: ";
		if (std::getline(std::cin, field))
			fields[i] = field;
		else
			exit(1);
	}
	if (check_fields(fields))
		return ;
	for (int i = 0 ; i < 5 ; i++) {
		if (i == 0)
			contact.set_field("first_name", fields[i]);
		else if (i == 1)
			contact.set_field("last_name", fields[i]);
		else if (i == 2)
			contact.set_field("nickname", fields[i]);
		else if (i == 3)
			contact.set_field("phone", fields[i]);
		else if (i == 4)
			contact.set_field("secret", fields[i]);
	}
	contacts[index % 8] = contact;
	index++;
}

void	PhoneBook::search( void ) {
	std::string in;
	print_columns();
	display_columns(contacts);
	std::cout << "Enter index from 1 to 8: ";
	std::getline(std::cin, in);
	if (atoi(in.c_str()) >= 1 && atoi(in.c_str()) <= 8) {
		if (!contacts[std::atoi(in.c_str()) - 1].get_field("first_name").empty())
			display_fields(contacts ,std::atoi(in.c_str()) - 1);
		else
			std::cout << "Empty Contact" << std::endl;
	}
	else
		std::cout << "Out of range index" << std::endl;
}