#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

// ************************************************************************** //
//                       PresidentialPardonForm Class                         //
// ************************************************************************** //

class PresidentialPardonForm : public AForm {
private:
	std::string target;
public:
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( void );
	PresidentialPardonForm( const PresidentialPardonForm& other );
	PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
	~PresidentialPardonForm();

	std::string getTarget( void ) const;
	void execute( Bureaucrat const & executor ) const;
};

#endif