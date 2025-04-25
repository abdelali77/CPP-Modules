#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	try {
		Bureaucrat sadam("sadam", 1);
		Bureaucrat kadafi("kadafi", 140);
		Bureaucrat hasan2("hasan2", 50);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("roboto");
		PresidentialPardonForm pardon("presidential");


		std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
		kadafi.signForm(shrub);
		kadafi.executeForm(shrub);
		sadam.executeForm(shrub);

		std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
		hasan2.signForm(robo);
		kadafi.executeForm(robo);
		hasan2.executeForm(robo);

		std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
		sadam.signForm(pardon);
		hasan2.executeForm(pardon);
		sadam.executeForm(pardon);

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}