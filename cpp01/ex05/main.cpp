#include "Karen.hpp"

int main(void)
{
	Karen k = Karen();

	k.complain("DEBUG");
	k.complain("ERROR");
	k.complain("INFO");
	k.complain("WARNING");
}
