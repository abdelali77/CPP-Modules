#include "ScalarConverter.hpp"

int main( int ac, char **av ) {
	if (ac == 2) {
		std::string str = av[1];
		ScalarConverter::convert(str);
	} else {
		std::cout << "Usage: ./convert [number to convert]" << std::endl;
	}

	return 0;
}