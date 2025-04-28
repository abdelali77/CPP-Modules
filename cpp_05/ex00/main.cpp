#include "Bureaucrat.hpp"

int main( void ) {
	try {
		Bureaucrat b("Saddam", 1);
		std::cout << b;
		Bureaucrat d("Kadafi", 150);
		std::cout << d;
		b.incrementGrade();
		d.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}