#include "utils.hpp"

void convertChar( std::string str ) {
	char chr;
	if (str.length() == 1)
		chr = str[0];
	else
		chr = str[1];
	if (chr >= 32 && chr <= 126) {
		std::cout << "char: '" << chr << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(chr) << std::endl;
		std::cout << "float: " << static_cast<float>(chr) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
	} else {
		std::cout << "Non displayable"  << std::endl;
	}
}

void convertSpecial( std::string str ) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	if (str == "-inff" || str == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	if (str == "+inff" || str == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

// void convertInt( std::string str ) {

// }

void converters( std::string str ) {
	int len = str.length();
	e_type type = find_type(str, len);

	if (type == CHAR)
		convertChar(str);
	else if (type == SPECIAL)
		convertSpecial(str);
}