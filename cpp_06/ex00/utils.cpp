#include "utils.hpp"

bool isChar( std::string& str, size_t& len ) {
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool isInt( std::string& str, size_t& len ) {
	if (len == 1 && str[0] >= '0' && str[0] <= '9')
		return true;
	if (len > 1 && (str[0] == '-' || str[0] == '+') && str[1] >= '0' && str[1] <= '9') {
		for (size_t i = 2; i < len; i++) {
			if (str[i] < '0' || str[i] > '9')
				return false;
		}
		return true;
	}
	for (size_t i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool isFloat( std::string& str, size_t& len, size_t& dot ) {
	if (str[len - 1] != 'f' || dot == 0 || dot >= len - 2)
		return false;
	int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	
	for (size_t i = start; i < dot; i++) {
		if (!isdigit(str[i]))
			return false;
	}
	for (size_t i = dot + 1; i < len - 1; ++i) {
		if (!isdigit(str[i]))
			return false;
	}

	return true;
}

bool isDouble( std::string& str, size_t& len, size_t& dot ) {
	if (dot == 0 || dot >= len - 1)
		return false;
	size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;

	if (dot <= start)
		return false;
	for (size_t i = start; i < dot; ++i) {
		if (!isdigit(str[i]))
			return false;
	}

	if (dot + 1 >= len)
		return false;
	for (size_t i = dot + 1; i < len; ++i) {
		if (!isdigit(str[i]))
			return false;
	}

	return true;
}

bool isSpecial( std::string& str ) {
	if (str == "-inff" || str == "+inff" || str == "nanf" ||
		str == "-inf" || str == "+inf" || str == "nan")
		return true;
	return false;
}

e_type find_type( std::string& str, size_t& len ) {
	size_t dot = str.find('.');
	size_t f = str.find('f');

	if (len == 0)
		return NONE;
	if (dot == std::string::npos) {
		if (isChar(str, len))
			return CHAR;
		if (isInt(str, len))
			return INT;
		if (isSpecial(str))
			return SPECIAL;
	}
	if (dot != std::string::npos && f != std::string::npos) {
		if (isFloat(str, len, dot))
			return FLOAT;
	}
	if (dot != std::string::npos && f == std::string::npos) {
		if (isDouble(str, len, dot))
			return DOUBLE;
	}
	return NONE;
}
