#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main() {
	const Animal*	i = new Dog();
	const Animal*	j = new Cat();

	delete j;//should not create a leak
	delete i;

	system("leaks a.out");

	Animal*	arr[100];
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}
	arr[0]->makeSound();
	arr[1]->makeSound();
	std::cout << "STARTING ADDRESS POINTER COMPARISON" << std::endl;
	for (int i = 0; i < 99; i++) {
		for (int j = i + 1; j < 100; j++) {
			if (arr[i] == arr[j])
				std::cout << "POINTERS I=" << i << " AND J=" << j << " ARE POINTING TO THE SAME ADDRESS AND THUS ARE SHALLOW COPIES" << std::endl;
		}
	}
	std::cout << "FINISHED ADDRESS POINTER COMPARISON" << std::endl;
	for (int i = 0; i < 100; i++) {
		delete arr[i];
	}
	system("leaks a.out");
}