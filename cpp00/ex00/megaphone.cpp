#include <iostream>

char	*ft_capitalize(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			std::cout << ft_capitalize(argv[i]);
	std::cout << std::endl;
	return (0);
}
