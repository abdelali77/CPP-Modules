#include "Bureaucrat.hpp"

int main( void ) {
	try {
		Bureaucrat b("Saddam", 150);
		std::cout << b;
		b.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}