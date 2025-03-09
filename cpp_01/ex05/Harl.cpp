#include "Harl.hpp"

int	getIndex( std::string level ) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			return i;
		i++;
	}
	return -1;
}

void	Harl::complain( std::string level ) {
	int	index = getIndex( level );
	void	(Harl::*ptr[4])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	switch (index) {
		case 0: (this->*ptr[0])();
			break;
		case 1: (this->*ptr[1])();
			break;
		case 2: (this->*ptr[2])();
			break;
		case 3: (this->*ptr[3])();
			break;
		default:
			std::cout << "Invalid Level" << std::endl;
			break;
	}
}

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for";
	std::cout << "years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl( void ) { }

Harl::~Harl() { }