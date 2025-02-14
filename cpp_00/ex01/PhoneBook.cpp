#include "PhoneBook.hpp"

PhoneBook::~PhoneBook( void ) {
	std::cout << "Desctructor called" << std::endl;
}

int	main() {
	std::string	command;

	std::cin >> command;
	while (command != "EXIT") {
		std::cout << "The Command is " << command << std::endl;
		std::cin >> command;
	}
	return 0;
}