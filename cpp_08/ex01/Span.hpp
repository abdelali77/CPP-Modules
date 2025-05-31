#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <limits>

// ************************************************************************** //
//                                 Span Class                                 //
// ************************************************************************** //

class Span {
private:
	unsigned int N;
	std::vector<int> span;

public:
	Span( void );
	Span( unsigned int _N );
	Span( const Span& oth );
	Span& operator=( const Span& oth );

	~Span();

	void addNumber( unsigned int num );
	void addNumber( std::vector<int> sp );
	int shortestSpan( void );
	int longestSpan( void );
};

#endif