#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm {

private:
	std::string _target;

public:
	explicit PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &executor) const;
	virtual void action() const;

private:
	PresidentialPardonForm();

};


#endif
