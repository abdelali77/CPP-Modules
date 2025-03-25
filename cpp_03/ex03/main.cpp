#include "DiamondTrap.hpp"

int main() {
    DiamondTrap su("SU-57");

	su.attack("F-35");
	su.guardGate();
	su.takeDamage(20);
	su.beRepaired(20);
	su.whoAmI();

    return 0;
}