#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main( void ) {
	try {
		Intern intern;
		AForm* rrf;
		Bureaucrat sadam("sadam", 17);

		rrf = intern.makeForm("presidential pardon", "vv-ve32");
		sadam.signForm(*rrf);
		delete rrf;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}