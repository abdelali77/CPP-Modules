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

void ScalarConverter::convert( std::string& str ) {
	size_t len = str.length();
	e_type type = find_type(str, len);

	switch (type)
	{
	case CHAR:
		convertChar(str);
		break;
	case SPECIAL:
		convertSpecial(str);
		break;
	case INT:
		convertInt(str);
		break;
	case FLOAT:
		convertFloat(str);
		break;
	case DOUBLE:
		convertDouble(str);
		break;
	default:
		std::cout << "Invalid input" << std::endl;
		break;
	}
}
