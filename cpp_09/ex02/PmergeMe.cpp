#include "PmergeMe.hpp"

std::vector<int> PmergeMe::vecSeq;
std::deque<int> PmergeMe::deqSeq;

PmergeMe::PmergeMe( void ) { }
PmergeMe::PmergeMe( const PmergeMe& oth ) { (void)oth; }
PmergeMe& PmergeMe::operator=( const PmergeMe& oth ) { (void)oth;return *this; }

bool isNumber( std::string& num ) {
	for (size_t i=0; i<num.size(); i++)
		if (!std::isdigit(num[i])) return false;
	return true;
}

bool parseInput( int ac, char **av ) {
	std::string numArg;
	long number;

	for (int i=1; i<ac; i++) {
		numArg = av[i];
		number = std::strtol(numArg.c_str(), NULL, 10);
		if (!numArg.size() || !isNumber(numArg) || number > std::numeric_limits<int>::max())
			return false;
	}
	return true;
}

void PmergeMe::init_data( int ac, char **av ) {
	for (int i=1; i<ac; i++) {
		int num = atoi(av[i]);
		vecSeq.push_back(num);
	}
	for (int i=1; i<ac; i++) {
		int num = atoi(av[i]);
		deqSeq.push_back(num);
	}
	std::cout << "Before: ";
	for(size_t i=0;i<vecSeq.size();i++)
		std::cout << vecSeq[i] << " ";
	std::cout << std::endl;
}
#include <unistd.h>
double PmergeMe::getProcessTime( int v ) {
	std::vector<int> vecSorted;
	std::deque<int> deqSorted;
	clock_t start = clock();
	if (!v) {
		std::cout << "After: ";
		vecSorted = fordJohnsonVec( vecSeq );
	} else
		deqSorted = fordJohnsonDeq( deqSeq );
	clock_t end = clock();

	for(size_t i=0;i<vecSorted.size();i++)
		std::cout << vecSorted[i] << " ";
	std::cout << std::endl;
	double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;

	return duration;
}

void PmergeMe::sort( void ) {
	double vec_seq = getProcessTime( 0 );
	(void)vec_seq;
	double deq_seq = getProcessTime( 1 );
	
	std::cout << "Time to process a range of " << vecSeq.size() <<
	" elements with std::[vector] : " << vec_seq << " ms" << std::endl;
	std::cout << "Time to process a range of " << deqSeq.size() <<
	" elements with std::[deque] : " << deq_seq << " ms" << std::endl;
}
