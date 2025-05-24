#include "Array.hpp"

template <class T>
Array<T>::Array::Array( void ) : arr(NULL), _size(0) { }

template <class T>
Array<T>::Array::Array( unsigned int n ) : _size(n) { this->arr = new T[n]; }

template <class T>
Array<T>::Array( const Array& other ) {
	this->_size = other._size;
	this->arr = new T[other._size];
	for (size_t i = 0; i < this->_size; i++)
		this->arr[i] = other.arr[i];
}

template <class T>
Array<T>& Array<T>::operator=( const Array& other ) {
	if (*this != other) {
		this->_size = other._size;
		if (this->arr)
			delete[] this->arr;
		this->arr = new T[other._size];
		for (size_t i = 0; i < this->_size; i++)
			this->arr[i] = other.arr[i];
	}
	return *this;
}

template <class T>
T& Array<T>::operator[]( unsigned int index ) {
	if (index >= _size)
		throw std::out_of_range(std::string("Array: Out of Bounds"));
	else
		return this->arr[index];
}

template <class T>
const T& Array<T>::operator[]( unsigned int index ) const {
	if (index >= _size)
		throw std::out_of_range(std::string("Array: Out of Bounds"));
	else
		return this->arr[index];
}

template <class T>
unsigned int Array<T>::size( void ) const {
	return this->_size;
}

template <class T>
Array<T>::~Array() {
	if (this->arr)
		delete[] this->arr;
}