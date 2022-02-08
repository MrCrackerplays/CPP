#include "ScavTrap.hpp"

int	main( void ) {
	// std::cout << "test1" << std::endl;
	ScavTrap	a = ScavTrap("Kleppy");
	ScavTrap	b = ScavTrap(a);
	ScavTrap	c = b;
	ScavTrap	d = ScavTrap("karel");
	c = d;
	a.attack("c");
	c.takeDamage(20);
	c.takeDamage(20);
	c.guardGate();
	c.takeDamage(20);
	c.takeDamage(20);
	c.beRepaired(10);
	c.ClapTrap::takeDamage(20);
	c.guardGate();
	c.takeDamage(20);
	c.takeDamage(20);
	c.takeDamage(20);
}