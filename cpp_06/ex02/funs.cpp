#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "funs.hpp"

Base * generate( void ) {
	std::srand(time(0));
	int rnd = std::rand() % 3;

	Base * ret;
	switch (rnd)
	{
	case 0:
		ret = new A;
		break;
	case 1:
		ret = new B;
		break;
	case 2:
		ret = new C;
		break;
	default:
		ret = NULL;
		break;
	}
	return ret;
}

void identify( Base* p ) {
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "type of p: 'A'" << std::endl;
	else if (b)
		std::cout << "type of p: 'B'" << std::endl;
	else if (c)
		std::cout << "type of p: 'C'" << std::endl;
	else
		std::cout << "Failed to cast" << std::endl;
}

void identify( Base& p ) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "type of p: 'A'" << std::endl;
		return;
	} catch(const std::bad_cast& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "type of p: 'B'" << std::endl;
		return;
	} catch(const std::bad_cast& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "type of p: 'C'" << std::endl;
		return;
	} catch(const std::bad_cast& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cerr << "Failed to cast" << std::endl;
}