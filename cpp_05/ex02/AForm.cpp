#include "AForm.hpp"

AForm::AForm( void ) : name("unknown"), _signed(false), sign_grade(150), execute_grade(150) { }

AForm::AForm( std::string name, int sign_grade, int execute_grade )
	  : name(name), _signed(false), sign_grade(sign_grade), execute_grade(execute_grade) {
	if (sign_grade < 1 || execute_grade < 1)
		throw std::runtime_error(std::string("AForm::GradeTooHighException"));
	else if (sign_grade > 150 || execute_grade > 150)
		throw std::runtime_error(std::string("AForm::GradeTooLowException"));
}

AForm::AForm( const AForm& other )
	  : name(other.getName()), sign_grade(10), execute_grade(10) {
	*this = other;
}

AForm& AForm::operator=( const AForm& other ) {
	if (this != &other) {
		this->_signed = getSigned();
	}
	return *this;
}

AForm::~AForm() { }

std::string AForm::getName( void ) const {
	return this->name;
}

int AForm::getSignGrade( void ) const {
	return this->sign_grade;
}

int AForm::getExcuteGrade( void ) const {
	return this->execute_grade;
}

bool AForm::getSigned( void ) const {
	return this->_signed;
}

void AForm::beSigned( Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= this->sign_grade)
		this->_signed = true;
	else if (bureaucrat.getGrade() > this->sign_grade)
		throw std::runtime_error(std::string("AForm::GradeTooLowException"));
}

std::ostream& operator<<( std::ostream& os, const AForm& form ) {
	os << "Form Name: " << form.getName() << "\n"
		<< "Signed: " << (form.getSigned() ? "Yes" : "No") << "\n"
		<< "Grade Required to Sign: " << form.getSignGrade() << "\n"
		<< "Grade Required to Execute: " << form.getExcuteGrade() << std::endl;
	return os;
}