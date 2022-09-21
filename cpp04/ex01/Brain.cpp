#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Created" << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Brain Cloning... ";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
	std::cout << "Brain Cloned!" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain Removed" << std::endl;
}

Brain &	Brain::operator=(Brain const & rhs) {
	std::cout << "Brain Assigning... ";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain Assigned!" << std::endl;
	return (*this);
}

std::string	Brain::getIdea(int i) const {
	return (this->ideas[i]);
}

void	Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}
