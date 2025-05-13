#include "funs.hpp"

void lks() {system("leaks real");}

int main( void ) {
	atexit(lks);
	Base* base = generate();

	identify(base);
}