#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>
#include <string>

template <typename ARR>
void iter(ARR *arr, size_t len, void(*f)(ARR&)) {
	if (!arr || len == 0)
		return;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename ARR>
void iter(const ARR *arr, size_t len, void(*f)(const ARR&)) {
	if (!arr || len == 0)
		return;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif