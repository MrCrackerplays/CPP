#include <iostream>
#include <fstream>
#include <string>

size_t	local_replace(std::string &text, std::string s1, std::string s2, size_t i) {
	size_t	found = text.find(s1, i);
	if (found == std::string::npos)
		return (found);
	text.erase(found, s1.length());
	text.insert(found, s2);
	return (found + s2.length());
}

void	local_replace_all(std::string &text, std::string s1, std::string s2)
{
	size_t i = 0;
	while (i != std::string::npos)
		i = local_replace(text, s1, s2, i);
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "invalid amount of arguments, wanted: 3 gotten: " << argc - 1 << std::endl;
		return (0);
	}
	std::string	filename = (std::string)argv[1];
	std::string	s1 = (std::string)argv[2];
	std::string	s2 = (std::string)argv[3];
	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cout << "arguments can't be empty" << std::endl;
		return (0);
	}
	std::ifstream originalfile;
	std::ofstream myfile;
	originalfile.open(filename);
	if (!originalfile.is_open()) {
		std::cout << "unable to open " << filename << std::endl;
		return (0);
	}
	myfile.open(filename + ".replace");
	if (!myfile.is_open()) {
		std::cout << "unable to open " << filename << ".replace" << std::endl;
		originalfile.close();
		return (0);
	}
	std::string	line;
	std::string	text;
	while (getline(originalfile, line)) {
		text += line;
		if (!originalfile.eof())
			text += "\n";
	}
	originalfile.close();
	local_replace_all(text, s1, s2);
	myfile << text;
	myfile.close();
}
