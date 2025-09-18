#include "PmergeMe.hpp"

std::vector<int> PmergeMe::vecSeq;
std::deque<int> PmergeMe::deqSeq;

PmergeMe::PmergeMe( void ) { }
PmergeMe::PmergeMe( const PmergeMe& oth ) { (void)oth; }
PmergeMe& PmergeMe::operator=( const PmergeMe& oth ) { (void)oth;return *this; }

bool parseInput( int ac, char **av ) {
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j] != '\0'; j++) {
			if (!isdigit(av[i][j]))
				return false;
		}
		if (std::atoi(av[i]) < 0 || std::atoi(av[i]) > INT_MAX)
			return false;
	}
	return true;
}

void PmergeMe::init_data( int ac, char **av ) {
	for (int i = 1; i < ac; i++) {
		int num = atoi(av[i]);
		vecSeq.push_back(num);
	}
	for (int i = 1; i < ac; i++) {
		int num = atoi(av[i]);
		deqSeq.push_back(num);
	}
}

void print( std::vector<int>& vec ) {
	std::cout << "Before:  ";
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size()
	<< " elements with std::vector : " << 0.0004 << " us" << std::endl;
}

std::vector<int> Jacobsthal( int n ) {
	std::vector<int> seq;

	int j0 = 0;
	int j1 = 1;
	
	while( true ) {
		int next = j1 + 2 * j0;
		if (next > n)
			break;
		seq.push_back(next);

		j0 = j1;
		j1 = next;
	}
	return seq;
}



void PmergeMe::sort( void ) {
	std::vector<int> a;
	std::vector<int> b;
	for (size_t i=0; i < vecSeq.size(); i+=2) {
		if (i + 1 < vecSeq.size()) {
			int larger = std::max(vecSeq[i], vecSeq[i+1]);
			int smaller = std::min(vecSeq[i], vecSeq[i+1]);

			a.push_back(larger);
			b.push_back(smaller);
		} else {
			b.push_back(vecSeq[i]);
		}
	}
	for(size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	for(size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	// std::vector<int> JacobsthalIndexes = Jacobsthal(b.size());
	// for(size_t i = 0; i < ret.size(); i++)
	// 	std::cout << ret[i] << " ";
	// std::cout << std::endl;
	// print(vecSeq);
}
