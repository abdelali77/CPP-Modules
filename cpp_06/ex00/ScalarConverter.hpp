#ifndef __SCALAECONVERTER_HPP__
#define __SCALAECONVERTER_HPP__

#include <iostream>
#include <string>

// ************************************************************************** //
//                           ScalarConverter Class                            //
// ************************************************************************** //

class ScalarConverter {
public:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter& operator=( const ScalarConverter& other );
	~ScalarConverter();

	static void convert( std::string str );
};

#endif