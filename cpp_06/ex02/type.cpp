#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "type.hpp"

Base * generate( void ) {
	std::srand(time(0));
	int rnd = std::rand() % 3;

	Base* ret;
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
		std::cout << "[ptr] type: 'A'" << std::endl;
	else if (b)
		std::cout << "[ptr] type: 'B'" << std::endl;
	else if (c)
		std::cout << "[ptr] type: 'C'" << std::endl;
	else
		std::cout << "Failed to cast" << std::endl;
}

void identify( Base& p ) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "[ref] type: 'A'" << std::endl;
		return;
	} catch(const std::bad_cast& e) { }
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "[ref] type: 'B'" << std::endl;
		return;
	} catch(const std::bad_cast& e) { }
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "[ref] type: 'C'" << std::endl;
		return;
	} catch(const std::bad_cast& e) { }
	std::cerr << "Failed to cast" << std::endl;
}