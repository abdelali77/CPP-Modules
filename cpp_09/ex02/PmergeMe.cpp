#include "PmergeMe.hpp"

std::vector<int> PmergeMe::vec;
std::deque<int> PmergeMe::deq;

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
		vec.push_back(num);
	}
	for (int i = 1; i < ac; i++) {
		int num = atoi(av[i]);
		deq.push_back(num);
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

std::vector<int> mergeSort( std::vector<int>& a ) {
	if (a.size() == 1)
		return a;
	std::vector<int> halfOne;
	std::vector<int> halfTwo;
	std::vector<int> merged;

	for(size_t i = 0; i < a.size() / 2; i++)
		halfOne.push_back(a[i]);
	for(size_t i = (a.size() / 2); i < a.size(); i++)
		halfTwo.push_back(a[i]);

	halfOne = mergeSort(halfOne);
	halfTwo = mergeSort(halfTwo);

	merged.resize(halfOne.size() + halfTwo.size());
	std::merge(halfOne.begin(), halfOne.end(), halfTwo.begin(), halfTwo.end(), merged.begin());

	return merged;
}

void PmergeMe::sort( void ) {
	std::vector<int> a;
	std::vector<int> b;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (i + 1 < vec.size()) {
			int larger = std::max(vec[i], vec[i+1]);
			int smaller = std::min(vec[i], vec[i+1]);

			a.push_back(larger);
			b.push_back(smaller);
		} else {
			b.push_back(vec[i]);
		}
	}
	// for(size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;
	// for(size_t i = 0; i < b.size(); i++)
	// 	std::cout << b[i] << " ";
	// std::cout << std::endl;
	a = mergeSort(a);
	for(size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	// print(vec);
}