#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("kl3z"), grade(10) { }

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name), grade(grade) {
	if (grade < 1)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooHighException"));
	else if (grade > 150)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooLowException"));
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) {
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
	if (this->grade > 1)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooHighException"));
}

void Bureaucrat::decrementGrade( void ) {
	this->grade++;
	if (this->grade > 150)
		throw std::runtime_error(std::string("Bureaucrat::GradeTooLowException"));
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& other ) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return os;
}