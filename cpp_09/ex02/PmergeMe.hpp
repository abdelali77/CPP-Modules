#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <cctype>

#define INT_MAX 2147483647

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
	static void sort( void );
};

bool parseInput( int ac, char** av );

#endif