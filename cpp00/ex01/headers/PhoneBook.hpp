#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <Contact.hpp>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		size;
public:
	PhoneBook(void);
	~PhoneBook(void);

	void		add(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);
	int			get_size(void);
	Contact&	get_contact(int i);
};

#endif
