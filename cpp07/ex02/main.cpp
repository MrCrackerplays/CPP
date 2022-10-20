#include <iostream>
#include "Array.hpp"

int main(void)
{
	{
		std::cout << "=======[String Array]=======" << std::endl;
		Array<std::string> lines(5);
		lines[0] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
		lines[1] = "Quisque eget hendrerit mauris.";
		lines[2] = "Maecenas non gravida nibh, vel lobortis eros.";
		lines[3] = "Quisque ac vestibulum lorem, sit amet finibus est.";
		lines[4] = "Nullam quis magna malesuada, laoreet purus in, pellentesque dolor.";
		std::cout << "lines has size " << lines.size() << " with contents ===[" << std::endl;
		for (unsigned int i = 0; i < lines.size(); i++)
			std::cout << "\t[" << i << "]" << lines[i] << std::endl;
		std::cout << "]===" << std::endl;
	}
	{
		std::cout << "=======[Double Array]=======" << std::endl;
		Array<double> loss(4);
		loss[0] = 1;
		loss[1] = 2;
		loss[2] = 2;
		loss[3] = 1.5;
		for (unsigned int i = 0; i < loss.size(); i++) {
			if (i > 0 && i % 2 == 0)
				std::cout << "-+-" << std::endl;
			if (i % 2)
				std::cout << "|";
			std::cout << loss[i];
			if (i % 2)
				std::cout << std::endl;
		}
	}
	{
		std::cout << "=======[Empty Array]=======" << std::endl;
		Array<char> empt;
		std::cout << "empt has size " << empt.size() << std::endl;
		for (unsigned int i = 0; i < empt.size(); i++)
			std::cout << "\t[" << i << "]" << empt[i] << std::endl;
	}
	{
		std::cout << "=======[Exception Array]=======" << std::endl;
		Array<int> exc(1);
		try {
			exc[-1] = 10;
		} catch(const std::exception& e) {
			std::cerr << "tried to access an invalid position " << e.what() << std::endl;
		}
		exc[0] = 10;
		std::cout << "did not throw an exception at correct assignment" << std::endl;
		try {
			exc[1] = 10;
		} catch(const std::exception& e) {
			std::cerr << "tried to access an invalid position " << e.what() << std::endl;
		}
	}
	{
		std::cout << "=======[Copy Clone Array]=======" << std::endl;
		Array<int> dim(1);
		Array<int> dam(dim);
		Array<int> dom;
		dom = dam;
		dim[0] = 1;
		dam[0] = 2;
		dom[0] = 3;
		//should all have their respective numbers, not sharing any
		std::cout << dim[0] << "," << dam[0] << "," << dom[0] << std::endl;
	}
}
