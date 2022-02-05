#include "ClapTrap.hpp"

int	main( void ) {
	// std::cout << "test1" << std::endl;
	ClapTrap	a = ClapTrap("Kleppy");
	ClapTrap	b = ClapTrap(a);
	ClapTrap	c = b;
	ClapTrap	d = ClapTrap("karel");
	c = d;

	std::cout <<"=====testing with b=====" << std::endl;
	b.attack("karel");
	//after 9 repairs b's energy will be all used up (since the attack on karel also took 1 energy) so it can't repair itself anymore but can still take damage
	for (int i = 0; i < 15; i++) {
		b.takeDamage(1);
		b.beRepaired(1);
	}
	std::cout << "exit loop" << std::endl;
	//b will now have 5 hit points
	b.takeDamage(5);
	std::cout << "nothing will be printed about b" << std::endl;
	//b will now have 0 hit points and won't take any more (won't underflow)
	b.takeDamage(1);
	b.beRepaired(1);
	b.takeDamage(1);
	b.attack("himself");
	std::cout << "=====all object will now be destroyed=====" << std::endl;
}