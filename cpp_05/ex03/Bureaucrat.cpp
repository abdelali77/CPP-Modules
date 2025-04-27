#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : name("unknown"), grade(10) { }

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name), grade(grade) {
	if (grade < 1)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooHighException"));
	else if (grade > 150)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooLowException"));
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.name) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
		this->grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() { }

std::string Bureaucrat::getName( void ) const {
	return this->name;
}

int Bureaucrat::getGrade( void ) const {
	return this->grade;
}

void Bureaucrat::incrementGrade( void ) {
	this->grade--;
	if (this->grade < 1)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooHighException"));
}

void Bureaucrat::decrementGrade( void ) {
	this->grade++;
	if (this->grade > 150)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooLowException"));
}

void Bureaucrat::signForm( AForm& form ) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	} catch (std::runtime_error& e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const & form ) const {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	} catch (std::runtime_error& e) {
		std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& other ) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return os;
}