#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

enum e_type {
	CHAR ,
	INT ,
	FLOAT ,
	DOUBLE ,
	SPECIAL ,
	NONE
};

e_type find_type( std::string& str, size_t& len );
void convertChar( std::string& str );
void convertSpecial( std::string& str );
void convertInt( std::string& str );
void convertFloat( std::string& str );
void convertDouble( std::string& str );
