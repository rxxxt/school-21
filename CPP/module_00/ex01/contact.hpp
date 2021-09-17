#ifndef CONTACT_H
# define CONTACT_H
# include <istream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	login;
	std::string	postalAddress;
	std::string	emailAddress;
	std::string	phoneNumber;
	std::string	birthdayDate;
	std::string	favoriteMeal;
	std::string	underwearColor;
	std::string	darkestSecret;
public:
	void		setFirstName(std::string inputString);
	void		setLastName(std::string inputString);
	void		setNickname(std::string inputString);
	void		setLogin(std::string inputString);
	void		setPostalAddress(std::string inputString);
	void		setEmailAddress(std::string inputString);
	void		setPhoneNumber(std::string inputString);
	void		setBirthdayDate(std::string inputString);
	void		setFavoriteMeal(std::string inputString);
	void		setUnderwearColor(std::string inputString);
	void		setDarkestSecret(std::string inputString);
	std::string	getFirstName( void );
	std::string	getLastName( void );
	std::string	getNickname( void );
	std::string	getLogin( void );
	std::string	getPostalAddress( void );
	std::string	getEmailAddress( void );
	std::string	getPhoneNumber( void );
	std::string	getBirthdayDate( void );
	std::string	getFavoriteMeal( void );
	std::string	getUnderwearColor( void );
	std::string	getDarkestSecret( void );
};

#endif
