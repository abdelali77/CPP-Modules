#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap f_35("f-35");
	ClapTrap su_57("su-57");

	su_57.attack("f-35");
	f_35.takeDamage(40);
	f_35.attack("su-57");
	su_57.takeDamage(5);
	su_57.beRepaired(20);

	return 0;
}