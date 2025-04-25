#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"

// ************************************************************************** //
//                                Intern Class                                //
// ************************************************************************** //

class Intern {
private:
	AForm* createRobotomy( std::string target );
	AForm* createPresidential( std::string target );
	AForm* createShrubbery( std::string target );
public:
	Intern( void );
	Intern( const Intern& other );
	Intern& operator=( const Intern& other );
	~Intern();

	AForm* makeForm( std::string name, std::string target );
};

#endif