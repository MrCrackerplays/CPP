#include <iostream>
#include <cmath>

void	cast_from_int(int value, char *c, double *d, float *f) {
	// std::cout << "casting from int" << std::endl;
	*c = static_cast<char>(value);
	*d = static_cast<double>(value);
	*f = static_cast<float>(value);
}

void	cast_from_char(char value, int *i, double *d, float *f) {
	// std::cout << "casting from char" << std::endl;
	*i = static_cast<int>(value);
	*d = static_cast<double>(value);
	*f = static_cast<float>(value);
}

void	cast_from_double(double value, char *c, int *i, float *f) {
	// std::cout << "casting from double" << std::endl;
	*c = static_cast<char>(value);
	*i = static_cast<int>(value);
	*f = static_cast<float>(value);
}

void	cast_from_float(float value, char *c, int *i, double *d) {
	// std::cout << "casting from float" << std::endl;
	*c = static_cast<char>(value);
	*i = static_cast<int>(value);
	*d = static_cast<double>(value);
}

int	main(int argc, char **argv) {
	if (argc != 2)
		return (1);

	{
		int i = 0;
		while (argv[1][i] && std::isspace(argv[1][i]))
			i++;
		argv[1] += i;
	}

	int integer;
	char character;
	double double_point;
	float floating_point;


	// ==========[Loading Data]==========
	char *num_end;
	integer = strtol(argv[1], &num_end, 10);
	bool fits_int = (*num_end == 0);
	bool fits_char = (argv[1][0] != '\0' && argv[1][1] == '\0');
	if (!fits_int && fits_char)
		character = argv[1][0];
	else
		character = (char) integer;

	double_point = strtod(argv[1], &num_end);
	floating_point = (float) double_point;
	bool fits_double = (*num_end == 0);
	bool fits_float = (*num_end == 'f' && num_end[1] == '\0');

	bool impossible_number = false;

	if (fits_int)
		cast_from_int(integer, &character, &double_point, &floating_point);
	else if (fits_char)
		cast_from_char(character, &integer, &double_point, &floating_point);
	else if (fits_double)
		cast_from_double(double_point, &character, &integer, &floating_point);
	else if (fits_float)
		cast_from_float(floating_point, &character, &integer, &double_point);
	else
		impossible_number = true;

	if (impossible_number) {
		double_point = std::numeric_limits<double>::quiet_NaN();
		floating_point = std::numeric_limits<float>::quiet_NaN();
	}
	if (std::isnan(double_point) || std::isnan(floating_point) || std::isinf(double_point) || std::isinf(floating_point))
		impossible_number = true;



	// ==========[Printing]==========

	std::cout << "char: ";
	if (impossible_number)
		std::cout << "impossible";
	else if (std::isprint(character))
		std::cout << "'" << character << "'";
	else
		std::cout << "Not displayable";
	std::cout << std::endl;
	std::cout << "int: ";
	if (impossible_number)
		std::cout << "impossible";
	else
		std::cout << integer;
	std::cout << std::endl;

	std::cout << "float: ";
	std::cout << floating_point;
	if (((float)integer) == floating_point)
		std::cout << ".0";
	std::cout << "f";
	std::cout << std::endl;

	std::cout << "double: ";
	std::cout << double_point;
	if (((float)integer) == (float)double_point)
		std::cout << ".0";
	std::cout << std::endl;
}
