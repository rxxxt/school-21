#include "AForm.hpp"

const char *AForm::GradeTooLowException::what() const throw() {
	return ("The grade is too low");
}

const char *AForm::GradeTooHighException::what( ) const throw() {
	return ("The grade is too high");
}

const char *AForm::ReSigningTheForm::what( ) const throw() {
	return ("The form has already been signed");
}

const char *AForm::FormIsNotSigned::what( ) const throw() {
	return ("The form has not been signed yet");
}

AForm::AForm() :
		_name("noname"),
		_gradeToSign(150),
		_gradeToExecute(150),
		_signed(false) {}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) :
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

AForm::AForm(const AForm &other) :
		_name(other._name),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute),
		_signed(other._signed) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() {
	std::cout << "form <" << _name << "> is destroyed"
		<< std::endl;
}

const std::string &AForm::getName() const {
	return _name;
}

unsigned int AForm::getGradeToSign() const {
	return _gradeToSign;
}

unsigned int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

bool AForm::isSigned() const {
	return _signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed)
		throw ReSigningTheForm();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_signed)
		throw FormIsNotSigned();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "form <" << form.getName() << ">"
	   << " with grade to signed "
	   << "<" << form.getGradeToSign() << ">"
	   << " and grade to execute "
	   << "<" << form.getGradeToExecute() << ">"
	   << std::endl;
	return os;
}
