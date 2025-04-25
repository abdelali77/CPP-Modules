#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include "Bureaucrat.hpp"

// ************************************************************************** //
//                                 AForm Class                                //
// ************************************************************************** //

class AForm {
private:
	const std::string name;
	bool _signed;
	const int sign_grade;
	const int execute_grade;
public:
	AForm( void );
	AForm( std::string name, int sign_grade, int execute_grade );
	AForm( const AForm& other );
	AForm& operator=( const AForm& other );
	virtual ~AForm();

	std::string getName( void ) const;
	int getSignGrade( void ) const;
	int getExcuteGrade( void ) const;
	bool getSigned( void ) const;

	void beSigned( Bureaucrat& bureaucrat );
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<( std::ostream& os, const AForm& form );

#endif