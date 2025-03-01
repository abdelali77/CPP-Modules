#include "Zombie.hpp"

int	main() {
	Zombie	*zombie;

	zombie = newZombie("zoo");
	zombie->announce();
	randomChump("loo");
	delete zombie;
	return 0;
}
