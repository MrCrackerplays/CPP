#include "DiamondTrap.hpp"

int	main( void ) {
	std::cout << std::endl << std::endl << "==========CREATION==========" << std::endl << std::endl;
	DiamondTrap	a = DiamondTrap("Kleppy");
	DiamondTrap	b = DiamondTrap(a);
	DiamondTrap	c = b;
	DiamondTrap	d = DiamondTrap("karel");
	c = d;
	std::cout << std::endl << std::endl << "==========TESTING==========" << std::endl << std::endl;
	a.attack("c");
	c.takeDamage(20);
	c.takeDamage(20);
	c.highFivesGuys();
	c.takeDamage(20);
	c.guardGate();
	c.takeDamage(20);
	c.beRepaired(10);
	c.ClapTrap::takeDamage(20);
	c.highFivesGuys();
	c.takeDamage(30);
	c.takeDamage(30);
	c.takeDamage(30);
	c.highFivesGuys();
	c.whoAmI();
	c.beRepaired(100);
	std::cout << std::endl << std::endl << "==========DESCTRUCTION==========" << std::endl << std::endl;
}