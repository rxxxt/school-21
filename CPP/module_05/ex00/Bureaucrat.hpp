#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# define MINGRADE 150
# define MAXGRADE 1


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
	Bureaucrat(std::string const &name, unsigned int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	const std::string &getName() const;
	unsigned int getGrade() const;
	void incrementTheGrade();
	void decrementTheGrade();

private:
	Bureaucrat();

};


std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
