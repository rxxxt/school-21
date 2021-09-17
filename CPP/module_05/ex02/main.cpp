#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat zafod("Zafod", 1);
	Bureaucrat ford("Ford", 20);
	PresidentialPardonForm form("Navalny");
	ShrubberyCreationForm bush("bush");
	RobotomyRequestForm robo("something there");
	std::cout << zafod << ford << form << bush << robo;
	zafod.executeForm(form);
	ford.signForm(form);
	zafod.executeForm(form);
	return 0;
}
