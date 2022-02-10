#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat " << this->type << " has been born into a nest!" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src) {
	std::cout << "WrongCat " << this->type << " has been born as a doppelganger!" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat " << this->type << " has lost one of its 2 lives!" << std::endl;
}

WrongCat &		WrongCat::operator=(WrongCat const & rhs) {
	this->type = rhs.type;
	std::cout << "WrongCat " << this->type << " has been assigned its next host!" << std::endl;
	return (*this);
}

void		WrongCat::makeSound(void) const {
	std::cout << this->getType() << ": HISSSSSSS!" << std::endl;
}

std::string	WrongCat::getType(void) const {
	return (this->type);
}
