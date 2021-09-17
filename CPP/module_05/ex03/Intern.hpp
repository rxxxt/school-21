#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class RobotomyRequestForm;


class Intern {

public:
	class UnknownForm : public std::exception {

	public:
		const char *what() const throw();

};

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	static AForm *PresidentialPardon(std::string target);
	static AForm *RobotomyRequest(std::string target);
	static AForm *ShrubberyCreation(std::string target);
	AForm* makeForm(std::string formName, std::string target);

};


#endif
