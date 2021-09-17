#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat vova("vova", 5);
		Bureaucrat dimon("dimon", 50);
		Form zero("zeroing out", 1, 1);
		std::cout << zero;
		dimon.signForm(zero);
		vova.signForm(zero);
		while (!zero.isSigned()) {
			vova.incrementTheGrade();
			vova.signForm(zero);
		}
	}
	catch (Form::GradeTooLowException & ex) {
		std::cout << "Form error message: "
				  << ex.what()
				  << std::endl;
	}
	catch (Form::GradeTooHighException & ex) {
		std::cout << "Form error message: "
				  << ex.what()
				  << std::endl;
	}
	return 0;
}
