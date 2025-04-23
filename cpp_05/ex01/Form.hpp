#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"

// ************************************************************************** //
//                                 Form Class                                 //
// ************************************************************************** //

class Form {
private:
	const std::string name;
	bool _signed;
	const int sign_grade;
	const int execute_grade;
public:
	Form( void );
	Form( std::string name, int sign_grade, int execute_grade );
	Form( const Form& other );
	Form& operator=( const Form& other );
	~Form();

	std::string getName( void ) const;
	int getSignGrade( void ) const;
	int getExcuteGrade( void ) const;
	bool getSigned( void ) const;

	void beSigned( Bureaucrat& bureaucrat );
};

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif