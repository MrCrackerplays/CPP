#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), brain(new Brain()) {
	std::cout << "K-9 UNIT " << this->type << " HAS COME ONLINE!" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src), brain(new Brain(*(src.brain))) {
	std::cout << "K-9 UNIT " << this->type << " MARK II HAS BEEN ACTIVATED!" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "K-9 UNIT " << this->type << " HAS LOST ITS MAIN REACTOR, GOING OFFLINE!" << std::endl;
	delete this->brain;
}

Dog &		Dog::operator=(Dog const & rhs) {
	delete this->brain;
	this->brain = new Brain(*(rhs.brain));
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
