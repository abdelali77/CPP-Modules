#include "DiamondTrap.hpp"

int main() {
    DiamondTrap su("su-57");

	su.attack("f-35");
	su.guardGate();
	su.takeDamage(20);
	su.beRepaired(20);
	su.whoAmI();

    return 0;
}