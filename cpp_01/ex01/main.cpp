#include "Zombie.hpp"

int	main() {
	int	N = 10;
	Zombie	*zombies = zombieHorde(N, "kl3z");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
