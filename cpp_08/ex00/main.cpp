#include "easyfind.hpp"

int main( void ) {
	std::vector<int> intVector;

	intVector.push_back(1337);
	intVector.push_back(42);
	intVector.push_back(99);
	intVector.push_back(10);
	intVector.push_back(7);
	intVector.push_back(77);

	try {
		std::vector<int>::iterator i = easyfind(intVector, 77);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> intList;

	intList.push_back(0);
	intList.push_back(1337);
	intList.push_back(1);
	intList.push_back(42);

	try {
		std::list<int>::iterator i = easyfind(intList, 11);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::deque<int> intDeque;

	intDeque.push_back(55);
	intDeque.push_back(2);
	intDeque.push_back(1000);
	intDeque.push_back(9981111);
	intDeque.push_back(1);

	try {
		std::deque<int>::iterator i = easyfind(intDeque, 1000);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
