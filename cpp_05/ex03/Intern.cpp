#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) { }

Intern::Intern( const Intern& other ) {
	(void)other;
}

Intern& Intern::operator=( const Intern& other ) {
	(void)other;
	return *this;
}

Intern::~Intern() { }

AForm* Intern::createShrubbery( std::string target ) {
	AForm* ret = new ShrubberyCreationForm(target);
	return ret;
}

AForm* Intern::createPresidential( std::string target ) {
	AForm* ret = new PresidentialPardonForm(target);
	return ret;
}

AForm* Intern::createRobotomy( std::string target ) {
	AForm* ret = new RobotomyRequestForm(target);
	return ret;
}

AForm* Intern::makeForm( std::string name, std::string target ) {
	AForm* (Intern::*arr[3]) ( std::string ) = {
		&Intern::createRobotomy,
		&Intern::createShrubbery,
		&Intern::createPresidential
	};
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (name == forms[i]) {
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (this->*arr[i])(target);
		}
	}
	throw std::runtime_error(std::string("Inter::UnknownForm"));
}