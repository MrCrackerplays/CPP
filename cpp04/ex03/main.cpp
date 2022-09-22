#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void learn_magic(IMateriaSource *source, ICharacter *person, int amount) {
	for (int i = 0; i < amount; i++) {
		if (i % 2 == 0)
			person->equip(source->createMateria("ice"));
		else
			person->equip(source->createMateria("cure"));
	}
}

int main() {
	std::cout << "Testing started" << std::endl;
	// system("leaks a.out");

	IMateriaSource* src;
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	{
		ICharacter* me;
		AMateria* tmp;
		ICharacter* bob;
		me = new Character("me");
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = NULL;
		bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
	}

	{
		ICharacter* people[100];
		for (int i = 0; i < 94; i++) {
			people[i] = new Character("Clone");
			learn_magic(src, people[i], i % 6);
		}
		for (int i = 0; 94 + i < 100; i++)
			people[i + 94] = new Character(*((Character*)people[i]));
		//94..99 are copy constructor'd
		for (int i = 0; 84 + i < 90; i++)
			*(Character*)(people[i + 84]) = *(Character*)(people[i + 94]);
		//84..89 are copy assigned

		// for (int i = 0; i < 100; i++) {
		// 	people[i]->use(i % 4, *(people[i + 1]));
		// }

		// system("leaks a.out");
		for (int i = 0; i < 100; i++) {
			delete people[i];
		}
	}
	delete src;
	// system("leaks a.out");
	return 0;
}
