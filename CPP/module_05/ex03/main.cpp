#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Intern someRandomIntern;
		AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		AForm* fail = someRandomIntern.makeForm("shrubbery creation ", "Bender");
		std::cout << *ppf << *rrf << *scf << *fail;
	}
	catch (Intern::UnknownForm &ex) {
		std::cout << "error message: "
			<< ex.what()
			<< std::endl;
	}
	return 0;
}
