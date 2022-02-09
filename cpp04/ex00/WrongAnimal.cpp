#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Squirrel") {
	std::cout << "WrongAnimal " << this->type << " Has Been Created!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal " << this->type << " Has Been Created!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) : type(src.type) {
	std::cout << "WrongAnimal " << this->type << " Has Been Ripped Off!" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal " << this->type << " Might Have Gone Extinct!" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhs) {
	this->type = rhs.type;
	std::cout << "WrongAnimal " << this->type << " Has Been Assigned The Wrong Genus!" << std::endl;
	return (*this);
}

/* Specific */
void	WrongAnimal::makeSound(void) const {
	std::cout << this->getType() << ": Quack!" << std::endl;
}

std::string		WrongAnimal::getType(void) const {
	return (this->type);
}
