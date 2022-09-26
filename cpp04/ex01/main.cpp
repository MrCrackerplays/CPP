#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void check_deep_or_shallow_cat(Cat *cat, Cat *kitty, bool opposite_idea = false) {
	if (cat->getBrain() == kitty->getBrain()) {
		std::cout << "Same brain, thus shallow copy" << std::endl;
	} else {
		std::cout << "Different brain, thus deep copy" << std::endl;
	}
	std::cout << ((cat->getBrain()->getIdea(0) == kitty->getBrain()->getIdea(0)) ? "Same" : "Different");
	if ((cat->getBrain()->getIdea(0) == kitty->getBrain()->getIdea(0)) != opposite_idea)
		std::cout << " first thought, correctly copied" << std::endl;
	else
		std::cout << " first thought, wrongly copied" << std::endl;
}

void check_deep_or_shallow_dog(Dog *dog, Dog *doggo, bool opposite_idea = false) {
	if (dog->getBrain() == doggo->getBrain()) {
		std::cout << "Same brain, thus shallow copy" << std::endl;
	} else {
		std::cout << "Different brain, thus deep copy" << std::endl;
	}
	std::cout << ((dog->getBrain()->getIdea(0) == doggo->getBrain()->getIdea(0)) ? "Same" : "Different");
	if ((dog->getBrain()->getIdea(0) == doggo->getBrain()->getIdea(0)) != opposite_idea)
		std::cout << " first thought, correctly copied" << std::endl;
	else
		std::cout << " first thought, wrongly copied" << std::endl;
}

int	main() {
	const Animal*	i = new Dog();
	const Animal*	j = new Cat();

	delete j;//should not create a leak
	delete i;

	system("leaks a.out");

	{
		const int amount = 100;
		Animal*	arr[amount];
		for (int i = 0; i < amount; i++) {
			if (i % 2 == 0)
				arr[i] = new Cat();
			else
				arr[i] = new Dog();
		}
		arr[0]->makeSound();
		arr[1]->makeSound();

		system("leaks a.out");
		for (int i = 0; i < amount; i++) {
			delete arr[i];
		}
	}

	system("leaks a.out");

	{
		Cat *c1 = new Cat();
		Cat *c2 = new Cat(*c1);
		Cat *c3 = new Cat();
		Cat *c4 = new Cat(*c3);
		Dog *d1 = new Dog();
		Dog *d2 = new Dog(*d1);
		Dog *d3 = new Dog();
		Dog *d4 = new Dog(*d3);
		c1->getBrain()->setIdea(0, "food");
		d1->getBrain()->setIdea(0, "toys");
		c2->getBrain()->setIdea(0, "sleep");
		d2->getBrain()->setIdea(0, "walks");
		*c3 = *c1;
		*c4 = *c2;
		*d3 = *d1;
		*d4 = *d2;

		std::cout << std::endl << "STARTING ADDRESS POINTER COMPARISON" << std::endl << std::endl;

		check_deep_or_shallow_cat(c1, c3);
		check_deep_or_shallow_cat(c2, c4);
		check_deep_or_shallow_dog(d1, d3);
		check_deep_or_shallow_dog(d2, d4);

		c2->getBrain()->setIdea(0, "hunting");
		check_deep_or_shallow_cat(c2, c4, true);//should no longer be the same thought, otherwise shallow copy
		d2->getBrain()->setIdea(0, "rolling");
		check_deep_or_shallow_dog(d2, d4, true);//should no longer be the same thought, otherwise shallow copy

		std::cout << std::endl << "FINISHED ADDRESS POINTER COMPARISON" << std::endl << std::endl;
		delete c1;
		delete c2;
		delete c3;
		delete c4;
		delete d1;
		delete d2;
		delete d3;
		delete d4;
	}

	system("leaks a.out");
}