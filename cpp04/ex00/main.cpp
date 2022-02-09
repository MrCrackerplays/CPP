#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();// will outpute the WrongAnimal sound
	meta->makeSound();

	std::cout << std::endl << std::endl << "===Clone===" << std::endl << std::endl;
	Animal	a = Animal(*meta);
	Dog		d = Dog(*((Dog *)j));
	Cat		c = Cat(*((Cat *)i));

	std::cout << std::endl << std::endl << "===Destruct 'new'===" << std::endl << std::endl;
	delete meta;
	delete j;
	delete i;
	delete k;

	std::cout << std::endl << std::endl << "===Clone print===" << std::endl << std::endl;
	a.makeSound();
	d.makeSound();
	c.makeSound();

	std::cout << std::endl << std::endl << "===Default===" << std::endl << std::endl;
	Animal	x;
	Dog		y;
	Cat		z;
	x.makeSound();
	y.makeSound();
	z.makeSound();

	std::cout << std::endl << std::endl << "===Assign===" << std::endl << std::endl;
	a = x;
	d = y;
	c = z;
	a.makeSound();
	d.makeSound();
	c.makeSound();

	std::cout << std::endl << std::endl << "===Destructors===" << std::endl << std::endl;
	return 0;
}