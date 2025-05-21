#include "iter.hpp"

int main( void ) {
	double arr[4] = {1.2, 2.4, 3.4, 4.4};
	::iter(arr, 4, print<double>);
}