#include "Zombie.hpp"

int	main() {
	Zombie	*zombie;

	zombie = newZombie("zoo");
	randomChump("loo");
	delete zombie;

	return 0;
}
