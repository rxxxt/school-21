#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"


class RobotomyRequestForm : public AForm {

private:
	std::string	_target;

public:
	explicit RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	virtual void action() const;
	void execute(const Bureaucrat &executor) const;

private:
	RobotomyRequestForm();

};


#endif
