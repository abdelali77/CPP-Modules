#include "Span.hpp"

Span::Span( void ) : N(0) { }

Span::Span( unsigned int _N ) : N(_N) { }

Span::Span( const Span& oth ) : N(oth.N), span(oth.span) { }

Span& Span::operator=( const Span& oth ) {
	if (this != &oth) {
		this->N = oth.N;
		this->span = oth.span;
	}
	return *this;
}

Span::~Span() { }

void Span::addNumber( unsigned int num ) {
	if (span.size() <= N) {
		span.push_back(num);
	} else
		throw std::out_of_range(std::string("Not enough space!"));
}

int Span::shortestSpan( void ) {
	int minSpan = std::numeric_limits<int>::max();
	if (span.size() < 2)
		throw std::invalid_argument(std::string("Not enough Numbers"));
	else {
		std::sort(span.begin(), span.end());
		for (int i = 1; static_cast<long unsigned int>(i) < span.size(); ++i) {
			int diff = span[i] - span[i - 1];
			if (diff < minSpan)
				minSpan = diff;
		}
	}
	return minSpan;
}

void Span::addNumber( std::vector<int> sp ) {
	if (sp.size() > N)
		throw std::out_of_range(std::string("Not enough space!"));
	else
		span.insert(span.end(), sp.begin(), sp.end());
}

int Span::longestSpan( void ) {
	if (span.size() < 2)
		throw std::invalid_argument(std::string("Not enough Numbers"));
	else {
		std::sort(span.begin(), span.end());
		return (span[span.size() - 1] - span[0]);
	}
}