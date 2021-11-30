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

int	get_type(std::string input)
{
	if (input.compare("EXIT") == 0)
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

void	execute_search(PhoneBook *book)
{
	int	id;

	title();
	std::cout << "    ID    |First Name| Last Name| Nickname " << std::endl;
	for (int i = 0; i < book->size; i++)
	{
		std::cout << std::setw(10) << std::right << i;
		write_column(book->contacts[i].first_name);
		write_column(book->contacts[i].last_name);
		write_column(book->contacts[i].nick_name);
		std::cout << std::endl;
	}
	std::cout << "                 ===end===                  " << std::endl;
	std::cout << "ID of the contact:";
	std::cin >> id;
	if (std::cin.fail() || id < 0 || id >= book->size)
		std::cout << "[Error]Can't find a matching id." << std::endl;
	else
	{
		std::cout << "First name: " << book->contacts[id].first_name << std::endl;
		std::cout << "Last name: " << book->contacts[id].last_name << std::endl;
		std::cout << "Nickname: " << book->contacts[id].nick_name << std::endl;
		std::cout << "Phone number: " << book->contacts[id].phone_number << std::endl;
		std::cout << "Darkest secret: " << book->contacts[id].darkest_secret << std::endl;
	}
	std::cin.clear();
}

void	execute_add(PhoneBook *book)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "First name:";
	std::cin >> first_name;
	std::cout << "Last name:";
	std::cin >> last_name;
	std::cout << "Nick name:";
	std::cin >> nick_name;
	std::cout << "Phone number:";
	std::cin >> phone_number;
	std::cout << "Darkest secret:";
	std::cin >> darkest_secret;
	std::cin.clear();
	book->add(first_name, last_name, nick_name, phone_number, darkest_secret);
	std::cout << "Succesfully added \"" << first_name << "\"!" << std::endl;
}

int	main(void)
{
	PhoneBook	book;
	int			action_type = 3;
	std::string	input;

	title();
	std::cout << "== Waiting for input: ADD, SEARCH, EXIT ==" << std::endl;
	while (action_type)
	{
		if (action_type != 3)
			std::cout << "== Waiting for input: ADD, SEARCH, EXIT ==" << std::endl;
		std::cin >> input;
		std::cin.clear();
		action_type = get_type(input);
		if (action_type == 1)
		{
			execute_search(&book);
		}
		else if (action_type == 2)
		{
			execute_add(&book);
		}
	}
	std::cout << "  Thanks for using Hyper-Phonograph-Connection-Databook-9000 ©1987  " << std::endl;
	std::cout << "ERROR. SOMETHING WENT WRONG TRYING TO SAVE DATA. TRY AGAIN LATER." << std::endl;
}
