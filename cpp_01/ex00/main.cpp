#include "Zombie.hpp"

int	main() {
	Zombie	*zombie;

	zombie = newZombie("Foo");
	zombie->announce();
	randomChump("Foo");
	delete zombie;
	return 0;
}
