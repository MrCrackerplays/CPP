#include <iostream>
#include <string>
#include <PhoneBook.hpp>
#include <iomanip>

void	title(void)
{
	std::cout << "\x1b[38;5;200m______________                    ________            ______  " << std::endl;
	std::cout << "___  __ \\__  /___________________ ___  __ )______________  /__" << std::endl;
	std::cout << "__  /_/ /_  __ \\  __ \\_  __ \\  _ \\__  __  |  __ \\  __ \\_  //_/" << std::endl;
	std::cout << "_  ____/_  / / / /_/ /  / / /  __/_  /_/ // /_/ / /_/ /  ,<   " << std::endl;
	std::cout << "/_/     /_/ /_/\\____//_/ /_/\\___/ /_____/ \\____/\\____//_/|_|  \x1b[0m" << std::endl;
}

int	get_type(void)
{
	std::string	input;

	std::getline(std::cin, input);
	if (std::cin.eof() || input.compare("EXIT") == 0)
		return (0);
	if (input.compare("SEARCH") == 0)
		return (1);
	if (input.compare("ADD") == 0)
		return (2);
	return (3);
}

void	write_column(std::string value)
{
	std::cout << "|";
	if (value.length() > 10)
		std::cout << value.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << value;
}

int	execute_search(PhoneBook *book)
{
	std::string	id;

	title();
	std::cout << "    ID    |First Name| Last Name| Nickname " << std::endl;
	for (int i = 0; i < book->get_size(); i++)
	{
		std::cout << std::setw(10) << std::right << i;
		write_column(book->get_contact(i).get_first_name());
		write_column(book->get_contact(i).get_last_name());
		write_column(book->get_contact(i).get_nick_name());
		std::cout << std::endl;
	}
	std::cout << "                 ===end===                  " << std::endl;
	std::cout << "ID of the contact:";
	std::getline(std::cin, id);
	if (std::cin.eof())
		return (0);
	if (id.length() != 1 || id[0] < '0' || id[0] >= ('0' + book->get_size()))
		std::cout << "[Error]Can't find a matching id." << std::endl;
	else
	{
		std::cout << "First name: " << book->get_contact(id[0] - '0').get_first_name() << std::endl;
		std::cout << "Last name: " << book->get_contact(id[0] - '0').get_last_name() << std::endl;
		std::cout << "Nickname: " << book->get_contact(id[0] - '0').get_nick_name() << std::endl;
		std::cout << "Phone number: " << book->get_contact(id[0] - '0').get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << book->get_contact(id[0] - '0').get_darkest_secret() << std::endl;
	}
	return (1);
}

int	execute_add(PhoneBook *book)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "First name:";
	std::getline(std::cin, first_name);
	if (std::cin.eof())
		return (0);
	std::cout << "Last name:";
	std::getline(std::cin, last_name);
	if (std::cin.eof())
		return (0);
	std::cout << "Nick name:";
	std::getline(std::cin, nick_name);
	if (std::cin.eof())
		return (0);
	std::cout << "Phone number:";
	std::getline(std::cin, phone_number);
	if (std::cin.eof())
		return (0);
	std::cout << "Darkest secret:";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof())
		return (0);
	book->add(first_name, last_name, nick_name, phone_number, darkest_secret);
	std::cout << "Succesfully added \"" << first_name << "\"!" << std::endl;
	return (2);
}

int	main(void)
{
	PhoneBook	book;
	int			action_type = 3;

	title();
	std::cout << "== Waiting for input: ADD, SEARCH, EXIT ==" << std::endl;
	while (action_type)
	{
		if (action_type != 3)
			std::cout << "== Waiting for input: ADD, SEARCH, EXIT ==" << std::endl;
		action_type = get_type();
		if (action_type == 1)
		{
			action_type = execute_search(&book);
		}
		else if (action_type == 2)
		{
			action_type = execute_add(&book);
		}
	}
	std::cout << "  Thanks for using Hyper-Phonograph-Connection-Databook-9000 ©1987  " << std::endl;
	std::cout << "ERROR. SOMETHING WENT WRONG TRYING TO SAVE DATA. TRY AGAIN LATER." << std::endl;
}
