#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Feline " << this->type << " has been born into a litter!" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src) {
	std::cout << "Feline " << this->type << " has been born as a copycat!" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Feline " << this->type << " has lost one of its nine lives!" << std::endl;
}

Cat &		Cat::operator=(Cat const & rhs) {
	this->type = rhs.type;
	std::cout << "Feline " << this->type << " has been assigned its next life!" << std::endl;
	return (*this);
}

void		Cat::makeSound(void) const {
	std::cout << this->getType() << ": Mrrrp? Meow." << std::endl;
}

std::string	Cat::getType(void) const {
	return (this->type);
}
