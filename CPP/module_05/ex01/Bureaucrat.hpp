#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

# define MINGRADE 150
# define MAXGRADE 1

class Form;


class Bureaucrat {

public:
	class GradeTooLowException : public std::exception {

public:
	const char *what() const throw();

};

class GradeTooHighException : public std::exception {

public:
	const char *what() const throw();

};

private:
	std::string		_name;
	unsigned int	_grade;

public:
	Bureaucrat(const std::string &name, unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	unsigned int getGrade() const;
	void incrementTheGrade();
	void decrementTheGrade();
	void signForm(Form &form);

private:
	Bureaucrat();

};


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
