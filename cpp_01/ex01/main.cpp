#include "Zombie.hpp"

int	main() {
	Zombie	*zombies = zombieHorde(4, "foo");
	delete[] zombies;

	return 0;
}
