#include <iostream>
#include "Base.hpp"

Base * generate(void) {
	int numb = std::rand() % 3;
	std::cout << "numb:" << numb << "=";
	if (numb == 0) {
		std::cout << "A" << std::endl;
		return (new A());
	}
	if (numb == 1) {
		std::cout << "B" << std::endl;
		return (new B());
	}
	std::cout << "C" << std::endl;
	return (new C());
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "*p is of type A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "*p is of type B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "*p is of type C" << std::endl;
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "&p is of type A" << std::endl;
	} catch (std::exception e) {
	}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "&p is of type B" << std::endl;
	} catch (std::exception e) {
	}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "&p is of type C" << std::endl;
	} catch (std::exception e) {
	}
}

int main(void) {
	Base *base;

	std::srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << "=======[iteration " << i << "]=======" << std::endl;
		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	
}
