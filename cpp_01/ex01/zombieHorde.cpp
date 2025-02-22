#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie	*zombies = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		zombies[i].set_name(name);
		i++;
	}
	return zombies;
}
