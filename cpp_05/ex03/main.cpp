#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main( void ) {
	try {
		Intern intern;
		AForm* rrf;

		rrf = intern.makeForm("vvv", "Bender");
		delete rrf;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}