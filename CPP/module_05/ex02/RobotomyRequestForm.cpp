#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("robotomy request",
			 72,
			 45),
		_target("no target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
		AForm("robotomy request",
			 72,
			 45),
			 _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
		AForm(other),
		_target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	AForm::execute(executor);
	action();
}

void RobotomyRequestForm::action() const {
	std::cout << "<" << _target << "> has been robotomized successfully 50% of the time.\n";
}
