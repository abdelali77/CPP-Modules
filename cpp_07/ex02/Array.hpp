#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <class T>
class Array {
private:
	T *arr;
	unsigned int _size;
public:
	Array( void );
	Array( unsigned int n );
	Array( const Array& other );
	Array& operator=( const Array& other );
	T& operator[]( unsigned int index );
	const T& operator[]( unsigned int index ) const;
	unsigned int size( void ) const;

	~Array();
};

#include "Array.tpp"

#endif