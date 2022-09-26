#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	const AAnimal*	i = new Dog();
	const AAnimal*	j = new Cat();
	// const AAnimal*	k = new AAnimal();
	// delete k;
	std::cout << std::endl << "---------SOUNDS---------" << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << "---------SOUNDS---------" << std::endl << std::endl;
	delete j;
	delete i;
}