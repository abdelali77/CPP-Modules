#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>
#include <string>

template <typename ARR, typename FUNC>
void iter(ARR *arr, size_t len, FUNC func) {
	if (!arr || len == 0)
		return;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename U>
void print(const U& element) {
	std::cout << element << std::endl;
}

#endif