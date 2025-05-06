#ifndef __SCALAECONVERTER_HPP__
#define __SCALAECONVERTER_HPP__

#include "utils.hpp"

// ************************************************************************** //
//                           ScalarConverter Class                            //
// ************************************************************************** //

class ScalarConverter {
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter& operator=( const ScalarConverter& other );
	~ScalarConverter();
public:
	static void convert( std::string str );
};

#endif