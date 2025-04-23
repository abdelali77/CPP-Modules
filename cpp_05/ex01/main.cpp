#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
	try {
		Bureaucrat sadam("saddam", 10);
		Form form("ba3t", 1, 1);
		Form form1("vvv", 100, 2);
		sadam.signForm(form);
		sadam.signForm(form1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}