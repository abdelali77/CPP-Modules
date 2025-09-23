#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <cctype>
#include <limits>
#include <ctime>

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
	~PmergeMe();
public:
	static void init_data( int ac, char **av );
	static void sort( void );
	static double getProcessTime( int v );
};

bool parseInput( int ac, char** av );
std::deque<int> fordJohnsonDeq( std::deque<int>& seq );
std::vector<int> fordJohnsonVec( std::vector<int>& seq );

#endif