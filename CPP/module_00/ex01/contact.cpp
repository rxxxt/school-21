#include "contact.hpp"

std::string	Contact::getFirstName( void ) {
	return (this->firstName);
}

std::string	Contact::getLastName( void ) {
	return (this->lastName);
}

std::string	Contact::getNickname( void ) {
	return (this->nickname);
}

std::string	Contact::getLogin( void ) {
	return (this->login);
}

std::string	Contact::getPostalAddress( void ) {
	return (this->postalAddress);
}

std::string	Contact::getEmailAddress( void ) {
	return (this->emailAddress);
}

std::string	Contact::getPhoneNumber( void ) {
	return (this->phoneNumber);
}

std::string	Contact::getBirthdayDate( void ) {
	return (this->birthdayDate);
}

std::string	Contact::getFavoriteMeal( void ) {
	return (this->favoriteMeal);
}

std::string	Contact::getUnderwearColor( void ) {
	return (this->underwearColor);
}

std::string	Contact::getDarkestSecret( void ) {
	return (this->darkestSecret);
}

void	Contact::setFirstName(std::string inputString) {
	this->firstName = inputString;
}

void	Contact::setLastName(std::string inputString) {
	this->lastName = inputString;
}

void	Contact::setNickname(std::string inputString) {
	this->nickname = inputString;
}

void	Contact::setLogin(std::string inputString) {
	this->login = inputString;
}

void	Contact::setPostalAddress(std::string inputString) {
	this->postalAddress = inputString;
}

void	Contact::setEmailAddress(std::string inputString) {
	this->emailAddress = inputString;
}

void	Contact::setPhoneNumber(std::string inputString) {
	this->phoneNumber = inputString;
}

void	Contact::setBirthdayDate(std::string inputString) {
	this->birthdayDate = inputString;
}

void	Contact::setFavoriteMeal(std::string inputString) {
	this->favoriteMeal = inputString;
}

void	Contact::setUnderwearColor(std::string inputString) {
	this->underwearColor = inputString;
}

void	Contact::setDarkestSecret(std::string inputString) {
	this->darkestSecret = inputString;
}
