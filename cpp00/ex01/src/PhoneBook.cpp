#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{
	this->size = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	static int	next;

	if (this->size < 8)
		this->size++;
	this->contacts[next].first_name = first_name;
	this->contacts[next].last_name = last_name;
	this->contacts[next].nick_name = nick_name;
	this->contacts[next].phone_number = phone_number;
	this->contacts[next].darkest_secret = darkest_secret;
	next = (next + 1) % 8;
}
