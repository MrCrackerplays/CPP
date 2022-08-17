#include "Harl.hpp"

int main(void)
{
	Harl h = Harl();

	h.complain("DEBUG");
	h.complain("ERROR");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("banana");
}
