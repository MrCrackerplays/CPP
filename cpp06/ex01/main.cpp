#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data* deserialize(uintptr_t raw) {
	Data *ret = reinterpret_cast<Data*>(raw);
	return (ret);
}

int main(void) {
	Data 		*d = new Data();
	uintptr_t	t = serialize(d);
	Data 		*b;
	std::cout << "address d[" << d << "] value[" << d->getValue() << "]" << std::endl;
	std::cout << "hex value t[" << std::hex << t << std::dec << "]" << std::endl;
	d->setValue(1);
	b = deserialize(t);
	std::cout << "address d[" << d << "] value[" << d->getValue() << "]" << std::endl;
	std::cout << "hex value t[" << std::hex << t << std::dec << "]" << std::endl;
	std::cout << "address b[" << b << "] value[" << b->getValue() << "]" << std::endl;
	b->setValue(5);
	std::cout << "address d[" << d << "] value[" << d->getValue() << "]" << std::endl;
	std::cout << "hex value t[" << std::hex << t << std::dec << "]" << std::endl;
	std::cout << "address b[" << b << "] value[" << b->getValue() << "]" << std::endl;
}
