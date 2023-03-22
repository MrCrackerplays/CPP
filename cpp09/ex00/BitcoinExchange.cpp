#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(void) : _history() {
	std::ifstream file(DATA_FILE);
	if (!file.is_open()) {
		std::cerr << "Error: " << DATA_FILE << " not found" << std::endl;
		std::exit(1);
	}
	std::string line;
	while (std::getline(file, line)) {
		size_t	sep = line.find(',');
		if (sep == std::string::npos || sep == 0 || sep == line.size() - 1)
			continue;
		std::string date = line.substr(0, sep);
		std::string price = line.substr(sep + 1);
		try {
			this->_history.push_back(std::make_pair(BitcoinExchange::Date(date), std::atof(price.c_str())));
		} catch (const std::exception &e) {
			continue;
		}
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange(void) {
}

double	BitcoinExchange::getClosestPrice(BitcoinExchange::Date const & date) {
	std::deque<std::pair<BitcoinExchange::Date, double> >::reverse_iterator	rit;
	for (rit = this->_history.rbegin(); rit != this->_history.rend(); rit++) {
		if (rit->first <= date)
			return rit->second;
	}
	std::cerr << "date is before first entry, subject doesn't specify behavior so I'm returning the first entry" << std::endl;
	return this->_history.front().second;
}

BitcoinExchange::Date::Date(std::string date)
{
	size_t	i = 0;
	size_t	progress = i;
	while (std::isdigit(date[i]))
		i++;
	if (i == progress || date[i] != '-')
		throw std::exception();
	this->year = std::atoi(date.substr(progress, i - progress).c_str());
	progress = ++i;
	while (std::isdigit(date[i]))
		i++;
	if (i == progress || date[i] != '-')
		throw std::exception();
	this->month = std::atoi(date.substr(progress, i - progress).c_str());
	progress = ++i;
	while (std::isdigit(date[i]))
		i++;
	if (i == progress || i != date.size())
		throw std::exception();
	this->day = std::atoi(date.substr(progress, i - progress).c_str());
}

BitcoinExchange::Date::~Date(void){}

bool BitcoinExchange::Date::operator>(Date const & rhs) const
{
	return (this->year > rhs.year
		|| (this->year == rhs.year && (this->month > rhs.month
		|| (this->month == rhs.month && this->day > rhs.day))));
}

bool BitcoinExchange::Date::operator<(Date const & rhs) const
{
	return (this->year < rhs.year
		|| (this->year == rhs.year && (this->month < rhs.month
		|| (this->month == rhs.month && this->day < rhs.day))));
}

bool BitcoinExchange::Date::operator==(Date const & rhs) const
{
	return (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day);
}

bool BitcoinExchange::Date::operator>=(Date const & rhs) const
{
	return (*this == rhs || *this > rhs);
}

bool BitcoinExchange::Date::operator<=(Date const & rhs) const
{
	return (*this == rhs || *this < rhs);
}