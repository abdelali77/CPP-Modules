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
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(chr) << std::endl;
		std::cout << "float: " << static_cast<float>(chr) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
	}
}

void convertSpecial( std::string str ) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
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

void convertInt( std::string str ) {
	long num = std::atol(str.c_str());
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	}
	else if (!(num >= 32 && num <= 126)) {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	}
}

void convertFloat( std::string str ) {
	float num = std::atof(str.c_str());
	if (num >= 32.0 && num <= 126.0) {
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	} else if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
}

void convertDouble( std::string str ) {
	double num = std::atof(str.c_str());
	if (num >= 32.0 && num <= 126.0) {
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << num << std::endl;
	} else if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << num << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << num << std::endl;
	}
}

void converters( std::string str ) {
	int len = str.length();
	e_type type = find_type(str, len);

	if (type == CHAR)
		convertChar(str);
	else if (type == SPECIAL)
		convertSpecial(str);
	else if (type == INT)
		convertInt(str);
	else if (type == FLOAT)
		convertFloat(str);
	else if (type == DOUBLE)
		convertDouble(str);
	else if (type == NONE)
		std::cout << "Invalid input" << std::endl;
}