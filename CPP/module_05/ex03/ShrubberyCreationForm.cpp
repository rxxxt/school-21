#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
		AForm("shrubbery creation",
			 145,
			 137),
			 _target("no target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
		AForm("shrubbery creation",
			 145,
			 137),
			 _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
		AForm(other),
		_target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	AForm::execute(executor);
	action();
}

void ShrubberyCreationForm::action() const {
	std::string	filename = _target + "_shrubbery";
	std::ofstream fout(filename);
	std::string tree =	"                  %%%,%%%%%%%\n"
						"                   ,'%% \\\\-*%%%%%%%\n"
						"             ;%%%%%*%   _%%%%\"\n"
						"              ,%%%       \\(_.*%%%%.\n"
						"              % *%%, ,%%%%*(    '\n"
						"            %^     ,*%%% )\\|,%%*%,_\n"
						"                 *%    \\/ #).-\"*%%*\n"
						"                     _.) ,/ *%,\n"
						"             _________/)#(_____________";
	if (fout.good())
		fout << tree << std::endl;
	else
		std::cout << "Failed to create file " << filename << std::endl;
	fout.close();
}
