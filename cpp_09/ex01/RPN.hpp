#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>

// ************************************************************************** //
//                                  RPN Class                                 //
// ************************************************************************** //

class RPN {
private:
	static std::stack<int> data;

	RPN( void );
	RPN( const RPN& oth );
	RPN& operator=( const RPN& oth );
	~RPN();
public:
	static int calculate( std::string& expr );
};


#endif