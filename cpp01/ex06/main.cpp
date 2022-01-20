#include "Karen.hpp"

int	decide_level(int argc, char **argv)
{
	std::string	inputs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		return (4);
	int	i = 0;
	for (; i < 4; i++) {
		if (inputs[i].compare(argv[1]) == 0)
			break;
	}
	return (i);
}

int main(int argc, char **argv)
{
	Karen		k = Karen();

	int	level = decide_level(argc, argv);
	switch (level)
	{
		case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		k.complain("DEBUG");
		std::cout << std::endl;
		case 1:
		std::cout << "[ INFO ]" << std::endl;
		k.complain("INFO");
		std::cout << std::endl;
		case 2:
		std::cout << "[ WARNING ]" << std::endl;
		k.complain("WARNING");
		std::cout << std::endl;
		case 3:
		std::cout << "[ ERROR ]" << std::endl;
		k.complain("ERROR");
		std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
			break;
	}
}
