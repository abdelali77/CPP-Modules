#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm(target, 25, 5), target(target) { }

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("unknown", 25, 5), target("unknown") { }

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) {
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { }

std::string PresidentialPardonForm::getTarget( void ) const {
	return this->target;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	if (this->getSigned() && executor.getGrade() <= this->getExcuteGrade()) {
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} else {
		throw std::runtime_error(std::string("PresidentialPardonForm::GradeTooLowException Or FormNotSigned"));
	}
}