#include "Bureaucrat.hpp"

int main( void ) {
	try {
		Bureaucrat b("Saddam", 100);
		std::cout << b;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}