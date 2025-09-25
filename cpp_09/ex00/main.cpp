#include "BitcoinExchange.hpp"

int main( int ac, char **av ) {
	if (ac == 2) {
		try {
			BitcoinExchange::initData();
			BitcoinExchange::parseInput(av[1]);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	} else {
		std::cerr << "Usage: ./btc [file]" << std::endl;
	}
}
