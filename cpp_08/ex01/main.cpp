#include "Span.hpp"

int main( void ) {
	try {
		Span sp = Span(10);
		std::vector<int> v = { 1, 2, 3 };

		sp.addNumber(v);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}