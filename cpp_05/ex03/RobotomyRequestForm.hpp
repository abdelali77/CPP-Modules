#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"

// ************************************************************************** //
//                         RobotomyRequestForm Class                          //
// ************************************************************************** //

class RobotomyRequestForm : public AForm {
private:
	std::string target;
public:
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( void );
	RobotomyRequestForm( const RobotomyRequestForm& other );
	RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
	~RobotomyRequestForm();

	std::string getTarget( void ) const;
	void execute( Bureaucrat const & executor ) const;
};

#endif