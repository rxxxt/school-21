#include "phoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1) {
		if (!std::cin.eof())
			std::cout << std::endl << GREEN << " Please enter one of the following commands: " << YELLOW << "ADD, SEARCH, EXIT " << RESET << std::endl;
		if (!std::getline(std::cin, command)) {
			std::cout << std::endl << std::setfill (' ') << std::setw (28);
			std::cout << RED << "Something went wrong" << RESET << std::endl;
			break ;
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.search();
		else {
			std::cout << std::setfill (' ') << std::setw (24);
			std::cout << RED << "Command not found. Try again" << RESET << std::endl;
		}
	}
	std::cout << std::setfill (' ') << std::setw (36);
	std::cout << GREEN << "EXIT" << RESET << std::endl;
	return (0);
}