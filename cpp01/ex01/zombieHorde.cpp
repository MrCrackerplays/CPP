#include "Zombie.hpp"
#include <sstream>
 
Zombie	*zombieHorde(int N, std::string name) {
	Zombie				*horde;
	std::ostringstream	oss;//streams are freaky ngl, but are allowed as they're not part of STL

	horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		oss << name << i;
		horde[i].set_name(oss.str());
		oss.str("");
	}
	return (horde);
}

