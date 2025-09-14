#include "PmergeMe.hpp"

std::vector<int> PmergeMe::vec;
std::deque<int> PmergeMe::deq;

PmergeMe::PmergeMe( void ) { }
PmergeMe::PmergeMe( const PmergeMe& oth ) { (void)oth; }
PmergeMe& PmergeMe::operator=( const PmergeMe& oth) { (void)oth;return *this; }

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
	for (int i = 0; i < ac - 1; i++) {
		std::cout << vec[i] << std::endl;
	}
}