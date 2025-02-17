#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <iostream>
#include <string>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Contact {
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	void		set_field( std::string type, std::string field );
	std::string	get_field( std::string type );
};

#endif