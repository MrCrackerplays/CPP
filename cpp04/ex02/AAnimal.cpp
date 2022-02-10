#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Dormaalocyon") {
	std::cout << "Animal " << this->type << " Has Been Evolved Into!" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "Animal " << this->type << " Has Been Evolved Into!" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) : type(src.type) {
	std::cout << "Animal " << this->type << " Has Been Cloned!" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal " << this->type << " Has Gone Extinct!" << std::endl;
}

AAnimal &	AAnimal::operator=(AAnimal const & rhs) {
	this->type = rhs.type;
	std::cout << "Animal " << this->type << " Has Been Assigned Its Genus!" << std::endl;
	return (*this);
}

/* Specific */
std::string		AAnimal::getType(void) const {
	return (this->type);
}
