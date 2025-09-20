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
		if (std::atoi(av[i]) < 0 || std::atoi(av[i]) > std::numeric_limits<int>::max())
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

std::vector<int> pairSeq( std::vector<int>& seq, std::vector<int>& a, std::vector<int>&b ) {
	a.clear();b.clear();

	for (size_t i=0; i < seq.size(); i+=2) {
		if (i + 1 < seq.size()) {
			int larger = std::max(seq[i], seq[i+1]);
			int smaller = std::min(seq[i], seq[i+1]);

			a.push_back(larger);
			b.push_back(smaller);
		} else {
			b.push_back(seq[i]);
		}
	}

	return a;
}

void fordJohnson( std::vector<int>& a ) {
	if (a.size() == 1) return;
	if (a.size() == 2) {
		if(a[0] > a[1]) std::swap(a[0], a[1]);
		return;
	}

	std::vector<int> sub_a, sub_b;
	pairSeq(a, sub_a, sub_b);
	fordJohnson(sub_a);

	a = sub_a;

	// std::vector<int>tmp = a;
	// a.clear();
	// a.insert(a.end(), sub_a.begin(), sub_a.end());
	// for (size_t i = 0; i < sub_a.size(); ++i)
	// 	a.push_back(sub_b[i]);
	
	// for (size_t i = 1; i < a.size(); ++i) {
    //     int key = a[i];
    //     size_t j = i;
    //     while (j > 0 && a[j - 1] > key) {
    //         a[j] = a[j - 1];
    //         --j;
    //     }
    //     a[j] = key;
    // }
}

void PmergeMe::sort( void ) {
	std::vector<int> a;
	std::vector<int> b;

	std::vector<int> sorted = pairSeq(vecSeq, a, b);
	fordJohnson(a);

	std::cout << "Larger (a, sorted): ";
    for (size_t i = 0; i < a.size(); ++i) std::cout << a[i] << " ";
    std::cout << "\nSmaller + Unpaired (b): ";
    for (size_t i = 0; i < b.size(); ++i) std::cout << b[i] << " ";
    std::cout << std::endl;
}