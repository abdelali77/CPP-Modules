#include "Harl.hpp"

int	main( int ac, char **av ) {
	if (ac == 2) {
		Harl harl;
		if (!std::strcmp(av[1], "DEBUG") || !std::strcmp(av[1], "INFO") 
			|| !std::strcmp(av[1], "WARNING") || !std::strcmp(av[1], "ERROR"))
			harl.complain(av[1]);
		else
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	} else {
		std::cout << "Usage [./harlFilter] [level]" << std::endl;
	}
}