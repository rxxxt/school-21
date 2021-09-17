#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>


class ShrubberyCreationForm : public AForm {

private:
	std::string _target;

public:
	explicit ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat &executor) const;
	virtual void action() const;

private:
	ShrubberyCreationForm();

};


#endif
