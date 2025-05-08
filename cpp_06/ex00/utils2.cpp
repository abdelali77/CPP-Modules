#include "utils.hpp"

void convertChar( std::string str ) {
	char chr = str[1];
	std::cout << "char: ";
	if (isprint(chr))
		std::cout << "'" << chr << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(chr) << std::endl;
	std::cout << "float: " << static_cast<float>(chr) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
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
	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else {
		if (isprint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
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

void converters( std::string& str ) {
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