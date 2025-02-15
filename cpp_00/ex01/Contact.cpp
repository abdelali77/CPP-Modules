#include "Contact.hpp"

void	Contact::set_field(std::string type, std::string field) {
	if (type == "first_name")
		first_name = field;
	else if (type == "last_name")
		last_name = field;
	else if (type == "nickname")
		nickname = field;
	else if (type == "phone")
		phone_number = field;
	else if (type == "secret")
		darkest_secret = field;
}

std::string	Contact::get_field(std::string type) {
	if (type == "first_name")
		return first_name;
	else if (type == "last_name")
		return last_name;
	else if (type == "nickname")
		return nickname;
	else if (type == "phone")
		return phone_number;
	else if (type == "secret")
		return darkest_secret;
	return "Kl3z";
}
