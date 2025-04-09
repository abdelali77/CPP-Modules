#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap su("su-57");

	su.takeDamage(10);
	su.guardGate();
	su.attack("f-35");
	su.beRepaired(10);

	return 0;
}