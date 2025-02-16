#include "PhoneBook.hpp"

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
		std::cout << "Enter field: ";
		std::getline(std::cin, field);
		fields[i] = field;
	}
	if (check_fields(fields))
		return;
	fill_contact(contact, fields);
	myPhoneBook.set_contact(contact, *index);
	(*index)++;
}

void	SEARCH(PhoneBook myPhoneBook) {
	std::string in;
	display_columns(myPhoneBook);
	std::cout << "Enter index from 0 to 7: ";
	std::getline(std::cin, in);
	if (std::stoi(in) >= 0 && std::stoi(in) <= 7) {
		if (!myPhoneBook.get_contact(std::stoi(in)).get_field("first_name").empty())
			display_fields(myPhoneBook ,std::stoi(in));
		else
			std::cout << "Empty Contact" << std::endl;
	}
	else
		std::cout << "Out of range index" << std::endl;
}

int	main() {
	PhoneBook	myPhoneBook;
	std::string	command;
	std::string	in;
	int			index = 0;

	std::cout << "Enter command: ";
	std::getline(std::cin, command);
	while (command != "EXIT") {
		if (command == "ADD") {
			ADD(&index, myPhoneBook);
		} else if (command == "SEARCH") {
			SEARCH(myPhoneBook);
		}
		else
			std::cout << "please enter a valid command" << std::endl;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
	}
	return 0;
}
