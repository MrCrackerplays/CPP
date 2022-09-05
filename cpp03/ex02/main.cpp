#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {
	FragTrap	a = FragTrap("Kleppy");
	FragTrap	b = FragTrap(a);
	FragTrap	c = b;
	FragTrap	d = FragTrap("karel");
	c = d;
	a.attack("c");
	c.takeDamage(20);
	c.takeDamage(20);
	c.highFivesGuys();
	c.takeDamage(20);
	c.takeDamage(20);
	c.beRepaired(10);
	c.ClapTrap::takeDamage(20);
	c.highFivesGuys();
	c.takeDamage(30);
	c.takeDamage(30);
	c.takeDamage(30);
	c.highFivesGuys();
}