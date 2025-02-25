#include "PhoneBook.hpp"

int	main() {
	PhoneBook	myPhoneBook;
	std::string	command;

	std::cout << "Enter command ADD or SEARCH or EXIT: ";
	while (std::getline(std::cin, command)) {
		if (command == "ADD") {
			myPhoneBook.add();
		} else if (command == "SEARCH") {
			myPhoneBook.search();
		} else if (command == "EXIT")
			return 0;
		else
			std::cout << "please enter a valid command" << std::endl;
		std::cout << "Enter command ADD or SEARCH or EXIT: ";
	}
	return 0;
}