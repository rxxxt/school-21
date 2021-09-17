#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <iomanip>
# include <sstream>
# include "contact.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define RESET	"\033[0m"

class PhoneBook
{
private:
	Contact		contacts[8];
	std::string	placeholder[11];
	int			numberOfContacts;
public:
	PhoneBook();
	~PhoneBook();
	void		addContact( void );
	void		search( void );
	void		showPhoneBook( void );
	void		showContact(int number);
	std::string	stringFormatting(std::string str);
};

#endif
