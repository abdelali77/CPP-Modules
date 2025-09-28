#include "BitcoinExchange.hpp"

bool isNumber( std::string& num ) {
	for (size_t i=0; i<num.size(); i++)
		if (!std::isdigit(num[i])) return false;
	return true;
}

bool dateIsValid( std::string& date ) {
	std::stringstream stream(date);
	std::string year, month, day;

	stream >> date;
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);

	if (!isNumber(month) || !isNumber(day) || !isNumber(year))
		return false;

	int mn = std::atoi(month.c_str()), dy = std::atoi(day.c_str());
	if ((mn > 12 || mn < 1) || (dy > 31 || dy < 1))
		return false;
	return true;
}
