#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

class BitcoinExchange {
private:
	static std::map<std::string, float> data;
	static std::ifstream inputFile;

	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange& oth );
	BitcoinExchange& operator=( const BitcoinExchange& oth );
public:
	static void initData( void );
	static void parseInput( char *av );
};

bool dateIsValid( std::string& date );
void checkErrors( std::ifstream& file, std::string& line );

#endif