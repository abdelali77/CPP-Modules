#include "BitcoinExchange.hpp"

int main( int ac, char **av ) {
	if (ac == 2) {
		BitcoinExchange::initData();
	} else {
		std::cerr << "Usage: ./btc [file]" << std::endl;
	}

	/* std::map<std::string, int>	_map;

	_map["01"] = 1;
	_map["02"] = 2;
	_map["03"] = 3;
	// _map["04"] = 4;
	_map["05"] = 5;

	std::map<std::string, int>::iterator it = _map.begin();
	while (it != _map.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
	if (_map.lower_bound("06") == _map.end())
		std::cout << "  +++++++++++++++ "<< std::endl;
	return 0; */
}
