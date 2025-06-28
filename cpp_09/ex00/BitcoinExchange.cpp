#include "BitcoinExchange.hpp"

std::ifstream BitcoinExchange::inputFile;

BitcoinExchange::BitcoinExchange( void ) {
	this->data[""] = 0;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& oth ) {
	*this = oth;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& oth ) {
	if (this != &oth) {
		this->data = oth.data;
	}

	return *this;
}

void BitcoinExchange::initData( void ) {
	std::ifstream csvFile;
	std::string line;
	csvFile.open("./cpp_09/data.csv");
	if (csvFile.is_open()) {
		std::getline(csvFile, line);
		while (std::getline(csvFile, line)) {
			std::string date;
			double value;
			date = line.substr(0, 10);
			value = std::atol((line.substr(11, line.size() - 1)).c_str());
			data[date] = value;
		}
	} else {
		std::runtime_error(std::string("Couldn'tOpenFile"));
	}
}

void BitcoinExchange::parseInput( char *av ) {
	std::ifstream file;
	std::string line;
	file.open(av);
	if (file.is_open()) {
		std::getline(file, line);
		while ( std::getline(file, line) ) {
			if (line.find('|') != std::string::npos) {
				std::string date = line.substr(0, 10);
				
			}
		}
	}
	
}