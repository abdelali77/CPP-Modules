#include "Serializer.hpp"

Serializer::Serializer( void ) { }

Serializer::Serializer( const Serializer& other ) { (void)other; }

Serializer& Serializer::operator=( const Serializer& other ) {
	(void)other;
	return *this;
}

Serializer::~Serializer() { }

uintptr_t Serializer::serialize( Data* ptr ) {
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data* Serializer::deserialize( uintptr_t raw ) {
	Data* ret = new Data;
	ret = reinterpret_cast<Data*>(raw);
	return ret;
}
