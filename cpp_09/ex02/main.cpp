#include "PmergeMe.hpp"

int main( int ac, char **av ) {
	if (ac == 1) {
		std::cerr << "Usage: ./PmergeMe [...]" << std::endl;
		return 1;
	} else {
		if (parseInput(ac, av)) {
			PmergeMe::init_data(ac, av);
		} else {
			std::cerr << "Error" << std::endl;
		}
	}
	return 0;
}