#include <Contact.hpp>

Contact::Contact(){}

Contact::~Contact(){}

void		Contact::set_first_name(std::string first_name) {
	this->first_name = first_name;
}

void		Contact::set_last_name(std::string last_name) {
	this->last_name = last_name;
}

void		Contact::set_nick_name(std::string nick_name) {
	this->nick_name = nick_name;
}

void		Contact::set_phone_number(std::string phone_number) {
	this->phone_number = phone_number;
}

void		Contact::set_darkest_secret(std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}

std::string	Contact::get_first_name(void) {
	return (this->first_name);
}

std::string	Contact::get_last_name(void) {
	return (this->last_name);
}

std::string	Contact::get_nick_name(void) {
	return (this->nick_name);
}

std::string	Contact::get_phone_number(void) {
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret(void) {
	return (this->darkest_secret);
}
