#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) { }

ScalarConverter::ScalarConverter( const ScalarConverter& other ) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other ) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert( std::string str ) {
	converters(str);
}
