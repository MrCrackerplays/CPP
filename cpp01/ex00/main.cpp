#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z;

	//I don't understand what the subject wants the main to actually do but I hope that this is it
	z = newZombie("Susan");
	randomChump("Steve");
	z->announce();
	randomChump("Bob");
	delete z;
	std::cout << "eind" << std::endl;
}
