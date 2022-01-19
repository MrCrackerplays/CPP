#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen k = Karen();

	k.complain("DEBUG");
	k.complain("ERROR");
	k.complain("INFO");
	k.complain("WARNING");
}
