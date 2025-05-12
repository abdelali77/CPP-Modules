#include "Serializer.hpp"

int main( void ) {
	Data data;
	data.name = "kl3z";
	data.id = 7777777;

	uintptr_t ret = Serializer::serialize(&data);
	Data* desr = Serializer::deserialize(ret);

	std::cout << ret << std::endl;
	std::cout << desr << std::endl;
}
