#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("presidential pardon",
			 25,
			 5),
			 _target("no target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		AForm("presidential pardon",
			 25,
			 5),
			 _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
		AForm(other),
		_target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	AForm::execute(executor);
	action();
}

void PresidentialPardonForm::action() const {
	std::cout << "<" << _target << "> has been pardoned by Zafod Beeblebrox.\n";
}
