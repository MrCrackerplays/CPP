#include "Zombie.hpp"

int	main(void) {
	Zombie	*horde;
	int		size;

	size = 11;
	horde = zombieHorde(size, "Zombino");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete[] horde;
	// system("leaks zombino");
}
