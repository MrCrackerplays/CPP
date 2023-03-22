#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	BitcoinExchange	exchange;
	std::ifstream file((argc > 1) ? argv[1] : NULL);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(file, line)) {
		size_t	i = line.find_first_of(' ');
		if (i == std::string::npos || line[i] != ' ' || line[i + 1] != '|' || line[i + 2] != ' ') {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string	date = line.substr(0, i);
		i += 3;
		size_t	progress = i;
		{ //multiplier check
			while (std::isdigit(line[i]))
				i++;
			if (line[i] == '.')
				i++;
			while (std::isdigit(line[i]))
				i++;
			if (i == progress || i != line.size()) {
				if (line[progress] == '-')
					std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
		}
		double multiplier = std::atof(line.substr(progress).c_str());
		if (multiplier > 1000.0f) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		try {
			double	price = exchange.getClosestPrice(BitcoinExchange::Date(date));
			std::cout << date << " => " << multiplier << " = " << multiplier * price << std::endl;
		} catch (const std::exception &e) {
			continue;
		}
	}
	file.close();
	return 0;
}
