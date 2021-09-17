#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define MINGRADE 150
# define MAXGRADE 1

class Bureaucrat;


class Form {

public:
class GradeTooHighException : public std::exception {

public:
	const char *what() const throw();

};

	class GradeTooLowException : public std::exception {

	public:
		const char *what() const throw();

};

private:
	const std::string	_name;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
	bool				_signed;

public:
	Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string &getName() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);

private:
	Form();

};


std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
