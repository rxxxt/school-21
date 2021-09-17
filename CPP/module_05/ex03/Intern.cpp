#include "Intern.hpp"

const char *Intern::UnknownForm::what() const throw() {
	return ("The requested form is unknown");
}

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	if (this != &other)
		*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this != &other)
		*this = other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::PresidentialPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::RobotomyRequest(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::ShrubberyCreation(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string	formNames[3] = {
			"presidential pardon",
			"robotomy request",
			"shrubbery creation"
	};
	AForm* (*pForm[3])(std::string target) = {
			PresidentialPardon,
			RobotomyRequest,
			ShrubberyCreation
	};
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i])
			return pForm[i](target);
	}
	throw UnknownForm();
}
