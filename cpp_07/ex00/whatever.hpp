#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

#include <iostream>
#include <string>

template <typename SWAP>
void swap(SWAP& a, SWAP& b) {
	SWAP tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename MIN>
MIN min(MIN a, MIN b) {
	if (a < b) return a;
	else return b;
}

template <typename MAX>
MAX max(MAX a, MAX b) {
	if (a > b) return a;
	else return b;
}

#endif