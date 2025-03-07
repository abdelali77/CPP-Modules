#include "Point.hpp"

int main( void ) {
	Point a(2, 1);
	Point b(8, 3);
	Point c(4, 7);
	Point point(5, 4);

	if (bsp(a, b, c, point))
		std::cout << "point inside" << std::endl;
	else
		std::cout << "point outside" << std::endl;
	
	return 0;
}