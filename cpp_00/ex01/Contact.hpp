#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	private:
		std::string	darkest_secret;
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
	
	Contact(std::string first_name, std::string last_name, std::string nickname,
			std::string phone_number, std::string darkest_secret);
	~Contact( void );
};

#endif