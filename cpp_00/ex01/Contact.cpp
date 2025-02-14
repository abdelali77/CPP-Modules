#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
				 std::string phone_number, std::string darkest_secret) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::~Contact( void ) {
	std::cout << "Destructor Called" << std::endl;
}

/* int main() {
	Contact contact("ali", "mahdf", "klez", "324234", "dhsfilds");
	std::cout << contact.first_name << contact.last_name<< contact.nickname<< contact.phone_number << std::endl;
} */