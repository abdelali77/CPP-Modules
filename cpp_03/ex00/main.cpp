#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap clap1("f-35");
	ClapTrap clap2("su-57");

	clap2.attack("f-35");
	clap1.takeDamage(40);
	clap1.attack("su-57");
	clap2.takeDamage(5);
	clap2.beRepaired(20);

	return 0;
}