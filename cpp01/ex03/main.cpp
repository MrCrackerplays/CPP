#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	// system("leaks unnecessary_violence");
	/*
		In which case is it appropriate to store the Weapon as a pointer?
		HumanB (also HumanA if you save the address of a passed reference, but that's a bit silly
		since you're already using a reference at that point so you might as well just save it as a
		reference)

		And as a reference?
		only HumanA

		Why?
		because for pointers you're able to not have data stored (NULL) whereas a reference can only
		exist when there's a variable it can reference to.
		that means that for HumanB where you don't get a weapon by default you need a pointer and for
		HumanA you need a reference since you directly pass the Weapon variable as a parameter rather
		than a pointer to its address `HumanA bob("Bob", club);`
		(if you tried saving the address of a non-reference variable you'd just get the address of a
		local variable(the paramater) which would be lost after leaving that scope)
	*/
}
