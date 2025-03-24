#include "FragTrap.hpp"

int main( void ) {
	FragTrap su("SU-57");

	su.takeDamage(10);
	su.highFivesGuys();
	su.attack("F-35");
	su.beRepaired(10);

	return 0;
}