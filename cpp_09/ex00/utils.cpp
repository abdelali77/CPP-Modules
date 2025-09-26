#include "BitcoinExchange.hpp"

bool isNumber( std::string& num ) {
	for (size_t i=0; i<num.size(); i++)
		if (!std::isdigit(num[i])) return false;
	return true;
}

bool dateIsValid( std::string& date ) {
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 7);
	std::string day = date.substr(8, 10);

	if (!(isNumber(year) || isNumber(month) || isNumber(day)))
		return false;
	if (!(year.length() != 4 || month.length() != 2 || day.length() != 2))
		return false;
	return true;
}
