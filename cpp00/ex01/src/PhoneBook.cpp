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
	this->contacts[next].set_first_name(first_name);
	this->contacts[next].set_last_name(last_name);
	this->contacts[next].set_nick_name(nick_name);
	this->contacts[next].set_phone_number(phone_number);
	this->contacts[next].set_darkest_secret(darkest_secret);
	next = (next + 1) % 8;
}

int		PhoneBook::get_size(void) {
	return (this->size);
}

Contact&	PhoneBook::get_contact(int i) {
	return (this->contacts[i]);
}
