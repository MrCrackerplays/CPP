#include "iter.hpp"

void charmagic(char c) {
	std::cout << "'" << (char)(c - 1) << "'" << std::endl;
}

void intmagic(int i) {
	int qt = i % 4;
	std::cout << i << " mod 4 = " << qt << std::endl;
}

void stringmagic(std::string s) {
	std::cout << "stringsize: " << s.size() << std::endl;
}

int main(void) {
	std::cout << "=======[charstuff]=======" << std::endl;
	char some[] = { 'b', 'c', 'q', 'r', 'z' };
	iter(some, (sizeof(some)/sizeof(*some)), charmagic);

	std::cout << "=======[intstuff]=======" << std::endl;
	int other[] = { 1, 2, 3, 4, 5, 10, 5713, 195 };
	iter(other, (sizeof(other)/sizeof(*other)), intmagic);

	std::cout << "=======[stringstuff]=======" << std::endl;
	std::string thing[] = { "lorem", "ipsum ", "Lorem ipsum dolor sit amet", "Aenean dignissim sollicitudin nisi, ac ornare" };
	iter(thing, (sizeof(thing)/sizeof(*thing)), stringmagic);

	std::cout << "=======[templatestuff]=======" << std::endl;
	iter(some, (sizeof(some)/sizeof(*some)), templatemagic);
	iter(other, (sizeof(other)/sizeof(*other)), templatemagic);
	iter(thing, (sizeof(thing)/sizeof(*thing)), templatemagic);
}
