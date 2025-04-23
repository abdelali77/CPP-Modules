#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>

class Form;

// ************************************************************************** //
//                              Bureaucrat Class                              //
// ************************************************************************** //

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	std::string getName( void ) const;
	int getGrade( void ) const;
	void incrementGrade( void );
	void decrementGrade( void );
	void signForm( Form& form );

	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat();
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& other );

#endif