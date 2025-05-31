#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>

typename T::iterator easyfind( T& container, int n ) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return it;
	else
		throw std::out_of_range(std::string("Number Not Found!"));
}

#endif