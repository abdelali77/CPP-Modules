#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap su("SU-57");

	su.takeDamage(10);
	su.guardGate();
	su.attack("F-35");
	su.beRepaired(10);

	return 0;
}