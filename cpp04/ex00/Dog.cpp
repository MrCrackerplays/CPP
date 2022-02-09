#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "K-9 UNIT " << this->type << " HAS COME ONLINE!" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src) {
	std::cout << "K-9 UNIT " << this->type << " MARK II HAS BEEN ACTIVATED!" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "K-9 UNIT " << this->type << " HAS LOST ITS MAIN REACTOR, GOING OFFLINE!" << std::endl;
}

Dog &		Dog::operator=(Dog const & rhs) {
	this->type = rhs.type;
	std::cout << "K-9 UNIT " << this->type << " HAS BEEN ASSIGNED ITS NEW BODY!" << std::endl;
	return (*this);
}

void		Dog::makeSound(void) const {
	std::cout << this->getType() << ": Woof" << std::endl;
}

std::string	Dog::getType(void) const {
	return (this->type);
}
