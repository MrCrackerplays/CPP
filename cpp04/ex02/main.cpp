#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	const AAnimal*	i = new Dog();
	const AAnimal*	j = new Cat();
	// const AAnimal*	k = new AAnimal();
	// delete k;
	delete j;
	delete i;
}