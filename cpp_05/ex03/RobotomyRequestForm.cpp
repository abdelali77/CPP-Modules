#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(target, 72, 45), target(target) { }

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("default", 72, 45), target("default") { }

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(target, 72, 45) {
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { }

std::string RobotomyRequestForm::getTarget( void ) const {
	return this->target;
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	if (this->getSigned() && executor.getGrade() <= this->getExcuteGrade()) {
		std::cout << "“BZZZ! DRRR!”" << std::endl;
		std::srand(std::time(0));
		int randomNum = std::rand() % 100 + 1;
		if (randomNum % 2 == 0) {
			std::cout << this->target << " has been robotomized successfully." << std::endl;
		} else {
			std::cout << this->target << " failed to robotomized." << std::endl;
		}
	} else {
		throw std::runtime_error(std::string("RobotomyRequestForm::GradeTooLowException Or FormNotSigned"));
	}
}