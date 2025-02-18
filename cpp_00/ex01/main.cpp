#include "PhoneBook.hpp"

int	main() {
	PhoneBook	myPhoneBook;
	std::string	command;
	int			index = 0;

	std::cout << "Enter command: ";
	while (std::getline(std::cin, command)) {
		if (command == "ADD") {
			ADD(&index, myPhoneBook);
		} else if (command == "SEARCH") {
			SEARCH(myPhoneBook);
		} else if (command == "EXIT")
			return 0;
		else
			std::cout << "please enter a valid command" << std::endl;
		std::cout << "Enter command: ";
	}
	return 0;
}