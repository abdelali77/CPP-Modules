#include "BitcoinExchange.hpp"

bool isNumber( std::string& num ) {
	for (size_t i=0; i<num.size(); i++)
		if (!std::isdigit(num[i])) return false;
	return true;
}

bool dateIsValid( std::string& date ) {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	// std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	if (!isNumber(month) || !isNumber(day))
		return false;
	
	int mn = std::atoi(month.c_str()), dy = std::atoi(day.c_str());
	if ((mn > 12 || mn == 0) || (dy > 31 || dy == 0))
		return false;
	return true;
}
