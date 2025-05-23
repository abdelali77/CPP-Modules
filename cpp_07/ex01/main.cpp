#include "iter.hpp"

void print(const std::string& element) {
	std::cout << element << std::endl;
}

void increment( double& element ) {
	element++;
}

int main( void ) {
	double arr[4] = {1.2, 2.4, 3.4, 4.4};
	::iter(arr, 4, increment);
	::iter(arr, 4, print);
	std::string stringArr[4] = {"sadam", "kadafi", "hasan2", "bachar"};	
	::iter(stringArr, 4, print);
}