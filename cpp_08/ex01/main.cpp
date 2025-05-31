#include "Span.hpp"

int main( void ) {
	try {
		Span sp = Span(10);
		std::vector<int> v;
		
		v.push_back(6);
		v.push_back(3);
		v.push_back(17);

		sp.addNumber(v);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}