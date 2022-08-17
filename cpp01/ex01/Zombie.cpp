#include "Zombie.hpp"

Zombie::Zombie(void) : name("nameless") {
}

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::~Zombie(void) {
	std::cout << "Zombie \"" << this->name << "\" is getting destructed!" << std::endl;
}

void	Zombie::announce() {
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name) {
	this->name = name;
}
