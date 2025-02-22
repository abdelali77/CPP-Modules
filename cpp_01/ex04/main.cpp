#include "replacer.hpp"

int	main( int ac, char **av ) {
	if (ac == 4) {
		std::string	s1 = av[2];
		std::string s2 = av[3];
		replaceString(s1, s2, av);
	} else {
		std::cout << "Usage [filename] [s1] [s2]" << std::endl;
	}

	return 0;
}
