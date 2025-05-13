#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <iostream>
#include "data.hpp"

class Serializer {
private:
	Serializer( void );
	Serializer( const Serializer& other );
	Serializer& operator=( const Serializer& other );
	~Serializer();
public:
	static uintptr_t serialize( Data* ptr );
	static Data* deserialize( uintptr_t raw );
};

#endif