#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <fstream>

// ************************************************************************** //
//                          ShrubberyCreationForm Class                       //
// ************************************************************************** //

class ShrubberyCreationForm : public AForm {
private:
	std::string target;
public:
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
	~ShrubberyCreationForm();

	std::string getTarget( void ) const;
	void execute( Bureaucrat const & executor ) const;
};

#endif