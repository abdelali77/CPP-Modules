#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

class BitcoinExchange {
private:
	static std::map<std::string, float> data;

	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange& oth );
	BitcoinExchange& operator=( const BitcoinExchange& oth );
	~BitcoinExchange();
public:
	static void initData( void );
	static void parseInput( char *av );
	static std::map<std::string, float> getData( void );
};

bool dateIsValid( std::string& date );

#endif