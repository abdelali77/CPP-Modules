#include "iter.hpp"

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main( void ) {
	double arr[4] = {1.2, 2.4, 3.4, 4.4};
	::iter(arr, 4, print<double>);
	std::string stringArr[3] = {"sadam", "kadafi", "hasan2"};	
	::iter(stringArr, 3, print<std::string>);
	int arr2[2] = {1337, 42};
	::iter(arr2, 2, print<int>);
}
