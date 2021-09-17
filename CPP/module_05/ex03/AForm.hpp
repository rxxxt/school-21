#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define MINGRADE 150
# define MAXGRADE 1

class Bureaucrat;


class AForm {

public:
	class GradeTooHighException : public std::exception {

	public:
		const char *what() const throw();

};

	class GradeTooLowException : public std::exception {

	public:
		const char *what() const throw();

};

	class ReSigningTheForm : public std::exception {

	public:
		const char *what() const throw();

};

	class FormIsNotSigned : public std::exception {

	public:
		const char *what() const throw();

};

private:
	const std::string	_name;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
	bool				_signed;

public:
	AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	~AForm();

	const std::string &getName() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &bureaucrat);
	virtual void action() const = 0;
	virtual void execute(const Bureaucrat &executor) const;

private:
	AForm();

};


std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
