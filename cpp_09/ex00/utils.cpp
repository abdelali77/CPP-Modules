#include "BitcoinExchange.hpp"

bool dateIsValid( std::string& date ) {
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 7).c_str());
	int day = std::atoi(date.substr(8, 10).c_str());
	if (year > 2022 || month > 12 || day > 31)
		return false;
	return true;
}

void checkErrors( std::ifstream& file, std::string& line ) {
	std::getline(file, line);
	while ( std::getline(file, line) ) {
		if (line.find('|') != std::string::npos) {
			std::string date = line.substr(0, 10);
			if (dateIsValid(date)) {
				float value = std::atof(line.substr(13, line.length() - 1).c_str());
				if (value < 0) {
					std::cerr << "Error: not a positive number." << std::endl;
				} if (value > 1000) {
					std::cerr << "Error: too large a number." << std::endl;
				} else {
					
				}
			} else {
				std::cerr << "Error: Not a valid date => " << date << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}
