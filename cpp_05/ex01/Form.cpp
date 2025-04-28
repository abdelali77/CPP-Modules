#include "Form.hpp"

Form::Form( void ) : name("unknown"), _signed(false), sign_grade(10), execute_grade(10) { }

Form::Form( std::string name, int sign_grade, int execute_grade )
	 : name(name), _signed(false), sign_grade(sign_grade), execute_grade(execute_grade) {
	if (sign_grade < 1 || execute_grade < 1)
		throw std::runtime_error(std::string("Form::GradeTooHighException"));
	else if (sign_grade > 150 || execute_grade > 150)
		throw std::runtime_error(std::string("Form::GradeTooLowException"));
}

Form::Form( const Form& other )
	: name(other.getName()), sign_grade(10), execute_grade(10) {
	*this = other;
}

Form& Form::operator=( const Form& other ) {
	if (this != &other) {
		this->_signed = getSigned();
	}
	return *this;
}

Form::~Form() { }

std::string Form::getName( void ) const {
	return this->name;
}

int Form::getSignGrade( void ) const {
	return this->sign_grade;
}

int Form::getExcuteGrade( void ) const {
	return this->execute_grade;
}

bool Form::getSigned( void ) const {
	return this->_signed;
}

void Form::beSigned( Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else if (bureaucrat.getGrade() > this->sign_grade)
		throw std::runtime_error(std::string("Form::GradeTooLowException"));
}

std::ostream& operator<<( std::ostream& os, const Form& form ) {
	os << "Form Name: " << form.getName() << "\n"
		<< "Signed: " << (form.getSigned() ? "Yes" : "No") << "\n"
		<< "Grade Required to Sign: " << form.getSignGrade() << "\n"
		<< "Grade Required to Execute: " << form.getExcuteGrade() << std::endl;
	return os;
}