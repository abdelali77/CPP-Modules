#include "Serializer.hpp"

int main( void ) {
	Data data;
	data.name = "kl3z"; data.id = 7777777;

	Data* ptr = &data;

	uintptr_t serialized = Serializer::serialize(ptr);
	std::cout << "Serialized value (as integer): 0x" << std::hex << serialized << std::dec << '\n';

	Data* deserialized_ptr = Serializer::deserialize(serialized);
	std::cout << "Original pointer: " << ptr << '\n';
	std::cout << "Deserialized pointer: " << deserialized_ptr << '\n';

	if (ptr == deserialized_ptr)
		std::cout << "Success: Deserialized pointer matches original pointer!\n";
	else
		std::cout << "Failure: Deserialized pointer does not match original pointer.\n";
	
	return 0;
}
