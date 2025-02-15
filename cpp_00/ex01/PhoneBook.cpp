#include "PhoneBook.hpp"

void	PhoneBook::set_contact(Contact contact, int index) {
	contacts[index] = contact;
}

Contact	PhoneBook::get_contact(int index) {
	return contacts[index];
}

int	check_fields(std::string fields[5]) {
	for (int i = 0 ; i < 5 ; i++) {
		if (fields[i].empty())
			return 1;
	}
	return 0;
}

void	fill_contact(Contact contact, std::string fields[5]) {
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

void	ADD(int *index, PhoneBook myPhoneBook) {
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
	index++;
}

void	SEARCH(int index) {
	(void)index;
	std::cout << "SERACH" << std::endl;	
}

int	main() {
	std::string	command;
	PhoneBook	myPhoneBook;
	int			index = 0;

	std::cout << "Enter command: ";
	std::getline(std::cin, command);
	while (command != "EXIT") {
		if (command == "ADD") {
			ADD(&index, myPhoneBook);
		} else if (command == "SEARCH") {
			std::cout << myPhoneBook.get_contact(0).get_field("nickname") << std::endl;
		}
		else
			std::cout << "please enter a valid command" << std::endl;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
	}
	return 0;
}