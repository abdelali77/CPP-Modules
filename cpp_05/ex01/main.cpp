#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
	try {
		Bureaucrat sadam("saddam", 10);
		Form form("4-43dfgw", 1, 1);
		Form form1("vvv-11", 100, 2);
		sadam.signForm(form);
		sadam.signForm(form1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}