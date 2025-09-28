#include "RPN.hpp"

std::stack<int> RPN::data;

RPN::RPN( void ) { }
RPN::RPN( const RPN& oth ) { (void)oth; }
RPN& RPN::operator=( const RPN& oth ) {
	(void)oth;
	return *this;
}
RPN::~RPN() { }

bool isOperator( std::string& op ) {
	return (op == "*" || op == "+" || op == "-" || op == "/");
}

int RPN::calculate( std::string& expr ) {
	std::stringstream stream(expr);
	std::string token;

	while(stream >> token) {
		if (token.length() == 1 && std::isdigit(token[0]))
			data.push(token[0] - '0');
		else if (isOperator(token)) {
			if (data.size() < 2)
				throw std::runtime_error("InsufficientOperands!");
			
			int b = data.top(); data.pop();
			int a = data.top(); data.pop();
			if (token == "+") data.push(a + b);
			else if (token == "-") data.push(a - b);
			else if (token == "*") data.push(a * b);
			else if (token == "/") {
				if (b == 0) throw std::runtime_error(std::string("DivisionByZero!"));
				data.push(a / b);
			}
		} else
			throw std::runtime_error(std::string("InvalidToken!"));
	}
	if (data.size() != 1)
		throw std::runtime_error(std::string("InvalidExpression!"));
	return data.top();
}
