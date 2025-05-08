#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

enum e_type {
	CHAR ,
	INT ,
	FLOAT ,
	DOUBLE ,
	SPECIAL ,
	NONE
};

e_type find_type( std::string& str, size_t& len );
void converters( std::string& str );
