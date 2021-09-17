#include "Form.hpp"

const char *Form::GradeTooLowException::what() const throw() {
	return ("The grade is too low");
}

const char *Form::GradeTooHighException::what( ) const throw() {
	return ("The grade is too high");
}

Form::Form() :
		_name("noname"),
		_gradeToSign(150),
		_gradeToExecute(150),
		_signed(false) {}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) :
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute),
		_signed(false) {
	if (_gradeToSign > MINGRADE || _gradeToExecute > MINGRADE)
		throw GradeTooLowException();
	if (_gradeToSign < MAXGRADE || _gradeToExecute < MAXGRADE)
		throw GradeTooHighException();
	std::cout << "form <" << _name << "> created"
		<< std::endl;
}

Form::Form(const Form &other) :
		_name(other._name),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute),
		_signed(other._signed) {}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form() {
	std::cout << "form <" << _name << "> is destroyed"
		<< std::endl;
}

const std::string &Form::getName() const {
	return _name;
}

unsigned int Form::getGradeToSign() const {
	return _gradeToSign;
}

unsigned int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

bool Form::isSigned() const {
	return _signed;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "form <" << form.getName() << ">"
	   << " with grade to signed "
	   << "<" << form.getGradeToSign() << ">"
	   << " and grade to execute "
	   << "<" << form.getGradeToExecute() << ">"
	   << std::endl;
	return os;
}
