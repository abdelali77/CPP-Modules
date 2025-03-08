#include "Zombie.hpp"

int	main() {
	int N = 100;
	Zombie	*zombies = zombieHorde(N, "foo");
	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}
	delete[] zombies;

	return 0;
}
