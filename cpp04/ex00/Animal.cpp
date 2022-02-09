#include "Animal.hpp"

Animal::Animal(void) : type("Dormaalocyon") {
	std::cout << "Animal " << this->type << " Has Been Evolved Into!" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal " << this->type << " Has Been Evolved Into!" << std::endl;
}

Animal::Animal(Animal const & src) : type(src.type) {
	std::cout << "Animal " << this->type << " Has Been Cloned!" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal " << this->type << " Has Gone Extinct!" << std::endl;
}

Animal &	Animal::operator=(Animal const & rhs) {
	this->type = rhs.type;
	std::cout << "Animal " << this->type << " Has Been Assigned Its Genus!" << std::endl;
	return (*this);
}

/* Specific */
void	Animal::makeSound(void) const {
	std::cout << this->getType() << ": SCREEEEECH!" << std::endl;
}

std::string		Animal::getType(void) const {
	return (this->type);
}
