#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie(void) {
	std::cout << "Zombie \"" << this->_name << "\" is getting destructed!" << std::endl;
}

void	Zombie::announce() {
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
