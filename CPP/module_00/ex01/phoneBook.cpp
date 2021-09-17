#include "phoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "Constructor called" << std::endl;
	numberOfContacts = 0;
	placeholder[0] = std::string(GREEN) + std::string(" First name:\t\t") + std::string(RESET);
	placeholder[1] = std::string(GREEN) + std::string(" Last name:\t\t") + std::string(RESET);
	placeholder[2] = std::string(GREEN) + std::string(" Nickname:\t\t") + std::string(RESET);
	placeholder[3] = std::string(GREEN) + std::string(" Login:\t\t\t") + std::string(RESET);
	placeholder[4] = std::string(GREEN) + std::string(" Postal address:\t") + std::string(RESET);
	placeholder[5] = std::string(GREEN) + std::string(" Email address:\t\t") + std::string(RESET);
	placeholder[6] = std::string(GREEN) + std::string(" Phone number:\t\t") + std::string(RESET);
	placeholder[7] = std::string(GREEN) + std::string(" Birthday date:\t\t") + std::string(RESET);
	placeholder[8] = std::string(GREEN) + std::string(" Favorite meal:\t\t") + std::string(RESET);
	placeholder[9] = std::string(GREEN) + std::string(" Underwear color:\t") + std::string(RESET);
	placeholder[10] = std::string(GREEN) + std::string(" Darkest secret:\t") + std::string(RESET);
	return ;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::string	PhoneBook::stringFormatting(std::string str) {
	if (str.length() > 9)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

void	PhoneBook::addContact( void ) {
	std::string	inputString;

	if (numberOfContacts < 8) {
		while (std::cin.good() && inputString.empty()) {
			std::cout << placeholder[0];
			std::getline(std::cin, inputString);
			if (inputString.empty() && std::cin.good())
				std::cout << std::string(20, ' ') << RED << "This field is required" << RESET << std::endl;
		}
		contacts[numberOfContacts].setFirstName(inputString);
		inputString = "";
		while (std::cin.good() && inputString.empty()) {
			std::cout << placeholder[1];
			std::getline(std::cin, inputString);
			if (inputString.empty() && std::cin.good())
				std::cout << std::string(20, ' ') << RED << "This field is required" << RESET << std::endl;
		}
		contacts[numberOfContacts].setLastName(inputString);
		inputString = "";
		while (std::cin.good() && inputString.empty()) {
			std::cout << placeholder[2];
			std::getline(std::cin, inputString);
			if (inputString.empty() && std::cin.good())
				std::cout << std::string(20, ' ') << RED << "This field is required" << RESET << std::endl;
		}
		contacts[numberOfContacts].setNickname(inputString);
		if (std::cin.good())
			std::cout << placeholder[3];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setLogin(inputString);
		if (std::cin.good())
			std::cout << placeholder[4];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setPostalAddress(inputString);
		if (std::cin.good())
			std::cout << placeholder[5];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setEmailAddress(inputString);
		if (std::cin.good())
			std::cout << placeholder[6];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setPhoneNumber(inputString);
		if (std::cin.good())
			std::cout << placeholder[7];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setBirthdayDate(inputString);
		if (std::cin.good())
			std::cout << placeholder[8];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setFavoriteMeal(inputString);
		if (std::cin.good())
			std::cout << placeholder[9];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setUnderwearColor(inputString);
		if (std::cin.good())
			std::cout << placeholder[10];
		std::getline(std::cin, inputString);
		contacts[numberOfContacts].setDarkestSecret(inputString);
		numberOfContacts += 1;
	}
	else {
		std::cout << std::setfill (' ') << std::setw (25);
		std::cout << RED << "The phone book is overflow" << RESET << std::endl;
	}
}

void	PhoneBook::showPhoneBook( void ) {
	std::stringstream output;

	output << YELLOW << "         ╔══════════╦══════════╦══════════╦══════════╗\n" << "         ║    " << GREEN
		   << "Number" << YELLOW << "║" << GREEN << "First name" << YELLOW << "║ " << GREEN << "Last name" << YELLOW
		   << "║  " << GREEN << "Nickname" << YELLOW << "║\n";
	output << YELLOW << "         ╠══════════╬══════════╬══════════╬══════════║\n";
	for (int i = 0; i < numberOfContacts; i += 1)
	{
		output << YELLOW << "         ║         " << GREEN << i + 1 << YELLOW << "║" << GREEN
			   << stringFormatting(contacts[i].getFirstName()) << YELLOW << "║" << GREEN
			   << stringFormatting(contacts[i].getLastName()) << YELLOW << "║" << GREEN
			   << stringFormatting(contacts[i].getNickname()) << YELLOW << "║\n";
	}
	output << YELLOW << "         ╚══════════╩══════════╩══════════╩══════════╝" << RESET << std::endl;
	std::cout << output.str();
}

void	PhoneBook::showContact(int number) {
	std::stringstream output;

	output << placeholder[0];
	output << contacts[number].getFirstName() << std::endl;
	output << placeholder[1];
	output << contacts[number].getLastName() << std::endl;
	output << placeholder[2];
	output << contacts[number].getNickname() << std::endl;
	output << placeholder[3];
	output << contacts[number].getLogin() << std::endl;
	output << placeholder[4];
	output << contacts[number].getPostalAddress() << std::endl;
	output << placeholder[5];
	output << contacts[number].getEmailAddress() << std::endl;
	output << placeholder[6];
	output << contacts[number].getPhoneNumber() << std::endl;
	output << placeholder[7];
	output << contacts[number].getBirthdayDate() << std::endl;
	output << placeholder[8];
	output << contacts[number].getFavoriteMeal() << std::endl;
	output << placeholder[9];
	output << contacts[number].getUnderwearColor() << std::endl;
	output << placeholder[10];
	output << contacts[number].getDarkestSecret() << std::endl;
	std::cout << output.str();
}

void	PhoneBook::search( void )
{
	int			number;
	std::string	inputString;

	if (!numberOfContacts)
		std::cout << std::string(20, ' ') << YELLOW << "The phone book is empty\n" << RESET;
	else
	{
		showPhoneBook();
		while (std::cin.good())
		{
			std::cout << std::string(7, ' ') << GREEN << " Please enter the number of the contact (1 to " << numberOfContacts <<") to view\n" << RESET;
			std::getline(std::cin, inputString);
			if (inputString.empty())
				break;
			try {
				number = std::stoi(inputString);
				if (number > 0 && number <= numberOfContacts) {
					showContact(number - 1);
					break ;
				}
				else
					std::cout << std::string(14, ' ') << RED << "There is no such contact. Try again\n\n" << RESET;
			}
			catch (...) {
				std::cout << std::string(18, ' ') << RED << "Incorrect input. Try again\n\n" << RESET;
			}
		}
	}
}
