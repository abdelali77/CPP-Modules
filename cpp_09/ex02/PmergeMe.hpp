#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <cctype>
#include <limits>

// ************************************************************************** //
//                               PmergeMe Class                               //
// ************************************************************************** //

class PmergeMe {
private:
	static std::vector<int> vecSeq;
	static std::deque<int> deqSeq;

	PmergeMe( void );
	PmergeMe( const PmergeMe& oth );
	PmergeMe& operator=( const PmergeMe& oth );
public:
	static void init_data( int ac, char **av );
	static std::vector<int> fordJohnson( std::vector<int>& seq );
	static void sort( void );
};

bool parseInput( int ac, char** av );

#endif