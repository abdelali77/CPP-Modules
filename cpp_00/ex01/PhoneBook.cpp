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

void	_display(PhoneBook myPhoneBook, int index) {
	std::cout << "|";
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << check_width(myPhoneBook.get_contact(index % 8).get_field("first_name")) << "|";
	std::cout << std::setw(10) << check_width(myPhoneBook.get_contact(index % 8).get_field("last_name")) << "|";
	std::cout << std::setw(10) << check_width(myPhoneBook.get_contact(index % 8).get_field("nickname")) << "|";
	std::cout << std::endl;
	std::cout << " ___________________________________________ " << std::endl;
}

void	display_fields(PhoneBook myPhoneBook, int index) {
	std::cout << myPhoneBook.get_contact(index % 8).get_field("first_name") << std::endl;
	std::cout << myPhoneBook.get_contact(index % 8).get_field("last_name") << std::endl;
	std::cout << myPhoneBook.get_contact(index % 8).get_field("nickname") << std::endl;
	std::cout << myPhoneBook.get_contact(index % 8).get_field("phone") << std::endl;
	std::cout << myPhoneBook.get_contact(index % 8).get_field("secret") << std::endl;
}

void	display_columns(PhoneBook myPhoneBook) {
	for (int i = 0; i < 8; i++)
	{
		if (myPhoneBook.get_contact(i).get_field("first_name").empty())
			break;
		else
			_display(myPhoneBook, i);
	}
}

void	PhoneBook::set_contact(Contact contact, int index) {
	contacts[index % 8] = contact;
}

Contact	PhoneBook::get_contact(int index) {
	return contacts[index % 8];
}

int	check_fields(std::string fields[5]) {
	for (int i = 0 ; i < 5 ; i++) {
		if (fields[i].empty())
			return 1;
	}
	return 0;
}

void	fill_contact(Contact &contact, std::string fields[5]) {
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
}


void	ADD(int *index, PhoneBook &myPhoneBook) {
	Contact	contact;
	std::string fields[5];
	std::string	field;

	for (int i = 0 ; i < 5 ; i++) {
		if (i == 0)
			std::cout << "Enter first name: ";
		else if (i == 1)
			std::cout << "Enter last name: ";
		else if (i == 2)
			std::cout << "Enter nickname: ";
		else if (i == 3)
			std::cout << "Enter phone number: ";
		else if (i == 4)
			std::cout << "Enter darkest secret: ";
		if (std::getline(std::cin, field))
			fields[i] = field;
		else
			exit(1);
	}
	if (check_fields(fields))
		return;
	fill_contact(contact, fields);
	myPhoneBook.set_contact(contact, *index);
	(*index)++;
}

void	SEARCH(PhoneBook myPhoneBook) {
	std::string in;
	print_columns();
	display_columns(myPhoneBook);
	std::cout << "Enter index from 1 to 8: ";
	std::getline(std::cin, in);
	if (std::stoi(in) >= 1 && std::stoi(in) <= 8) {
		if (!myPhoneBook.get_contact(std::stoi(in) - 1).get_field("first_name").empty())
			display_fields(myPhoneBook ,std::stoi(in) - 1);
		else
			std::cout << "Empty Contact" << std::endl;
	}
	else
		std::cout << "Out of range index" << std::endl;
}

