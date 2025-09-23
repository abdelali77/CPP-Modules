#include "RPN.hpp"

int main( int ac, char **av ) {
	if (ac == 2) {
		try {
			std::string expr(av[1]);
			int result = RPN::calculate(expr);

			std::cout << result << std::endl;
		} catch( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	} else {
		std::cerr << "Usage: ./RPN [expression]" << std::endl;
	}	
}
