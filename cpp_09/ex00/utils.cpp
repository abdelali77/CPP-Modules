#include "BitcoinExchange.hpp"

bool	dateIsValid( std::string date ) {
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 7).c_str());
	int day = std::atoi(date.substr(8, 10).c_str());
	if (year > 2022 || month > 12 || day > 31)
		return false;
	return true;
}
