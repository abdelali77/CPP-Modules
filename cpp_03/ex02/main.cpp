#include "FragTrap.hpp"

int main( void ) {
	FragTrap su("su-57");

	su.takeDamage(10);
	su.highFivesGuys();
	su.attack("f-35");
	su.beRepaired(10);

	return 0;
}