#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::data;

BitcoinExchange::BitcoinExchange( void ) { this->data[""] = 0; }
BitcoinExchange::BitcoinExchange( const BitcoinExchange& oth ) { *this = oth; }
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& oth ) {
	if (this != &oth)
		this->data = oth.data;
	return *this;
}
BitcoinExchange::~BitcoinExchange() { }


void BitcoinExchange::initData( void ) {
	std::ifstream dataFile;
	std::string line;
	dataFile.open("./cpp_09/data.csv");
	if (dataFile.is_open()) {
		std::getline(dataFile, line);
		while (std::getline(dataFile, line)) {
			std::string date;
			float value;
			date = line.substr(0, 10);
			value = std::atof((line.substr(11, line.size() - 1)).c_str());
			data[date] = value;
		}
		dataFile.close();
	} else {
		throw std::runtime_error(std::string("Couldn'tOpenFile"));
	}
}

std::map<std::string, float> BitcoinExchange::getData( void ) {
	return data;
}

void processBtcTransaction( std::string& line, std::string& date ) {
	std::map<std::string, float> data = BitcoinExchange::getData();

	float value = std::atof(line.substr(13, line.length() - 1).c_str());
	if (value < 0)
		std::cerr << "Error: not a positive number." << std::endl;
	else if (value > 1000)
		std::cerr << "Error: too large a number." << std::endl;
	else {
		std::map<std::string, float>::iterator it = data.find(date);
		if (it != data.end())
			std::cout << date << " => " << value << " = " << static_cast<float>(value * it->second) << std::endl;
		else {
			it = data.lower_bound(date);
			if (it == data.begin())
				std::cerr << "Error : Not a valid date => " << date << std::endl;
			else {
				--it;
				std::cout << date << " => " << value << " = " << static_cast<float>(value * it->second) << std::endl;
			}
		}
	}
}

void BitcoinExchange::parseInput( char *av ) {
	std::ifstream file;
	std::string line;
	file.open(av);
	if (file.is_open()) {
		std::getline(file, line);
		while ( std::getline(file, line) ) {
			if (line.find(" | ") != std::string::npos) {
				std::string date = line.substr(0, line.find(" | "));
				if (dateIsValid(date))
					processBtcTransaction(line, date);
				else
					std::cerr << "Error: Not a valid date => " << date << std::endl;
			} else
				std::cerr << "Error: bad input => " << line << std::endl;
		}
		file.close();
	} else
		throw std::runtime_error(std::string("Couldn'tOpenFile"));
}
