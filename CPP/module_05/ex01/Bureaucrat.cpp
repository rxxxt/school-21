#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is too low");
}

const char*	Bureaucrat::GradeTooHighException::what( ) const throw() {
	return ("The grade is too high");
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) :
		_name(name) {
	if (grade > MINGRADE)
		throw GradeTooLowException();
	if (grade < MAXGRADE)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "a bureaucrat was born"
			  << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
		_name(other._name),
		_grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_name = other._name;
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "the bureaucrat died"
			  << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementTheGrade() {
	if (_grade == MAXGRADE)
		throw GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::decrementTheGrade() {
	if (_grade == MINGRADE)
		throw GradeTooLowException();
	_grade += 1;
}

void Bureaucrat::signForm(Form &form) {
	try {
		if (form.isSigned())
			std::cout << "bureaucrat <" << _name << "> cannot sign form <" << form.getName()
					  << "> because <already signed>\n";
		else {
			form.beSigned(*this);
			std::cout << "bureaucrat <" << _name << "> signs form <" << form.getName() << ">\n";
		}
	}
	catch (Form::GradeTooLowException & ex) {
		std::cout << "bureaucrat <" << _name << "> cannot sign form <" << form.getName()
			<< "> because <" << ex.what() << ">" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << "<" << bureaucrat.getName() << ">"
		<< ", bureaucrat grade <"
		<< bureaucrat.getGrade() << ">"
		<< std::endl;
	return os;
}

