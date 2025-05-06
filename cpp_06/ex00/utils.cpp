#include "utils.hpp"

bool isChar( std::string& str, int& len ) {
	if (len == 1 && !isdigit(str[0]))
		return true;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool isInt( std::string& str, int& len ) {
	if (len == 1 && str[0] >= '0' && str[0] <= '9')
		return true;
	if (len > 1 && (str[0] == '-' || str[0] == '+') && str[1] >= '0' && str[1] <= '9') {
		for (int i = 2; i < len; i++) {
			if (str[i] < '0' || str[i] > '9')
				return false;
		}
		return true;
	}
	for (int i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool isFloat( std::string& str, int& len, size_t& dot ) {
	int flg = 0;
	if (str[0] == '-' || str[0] == '+')
		flg = 1;
	for (int i = dot - 1; i >= flg; i--) {
		if (!isdigit(str[i]))
			return false;
	}
	for (int i = dot + 1; i < len - 1; i++) {
		if (!isdigit(str[i]))
			return false;
	}
	if (!(str[len - 1] == 'f'))
		return false;
	return true;
}

bool isDouble( std::string& str, int& len, size_t& dot ) {
	int flg = 0;
	if (str[0] == '-' || str[0] == '+')
		flg = 1;
	for (int i = dot - 1; i >= flg; i--) {
		if (!isdigit(str[i]))
			return false;
	}
	for (int i = dot + 1; i < len; i++) {
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

e_type find_type( std::string& str, int& len ) {
	size_t dot = str.find('.');

	if (dot == std::string::npos) {
		if (isChar(str, len))
			return CHAR;
		if (isInt(str, len))
			return INT;
		if (isSpecial(str))
			return SPECIAL;
	}
	if (dot != std::string::npos) {
		if (isFloat(str, len, dot))
			return FLOAT;
		if (isDouble(str, len, dot))
			return DOUBLE;
	}
	return NONE;
}
