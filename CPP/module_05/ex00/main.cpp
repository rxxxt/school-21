#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat vova("vova", 1);
		vova.incrementTheGrade();
//		for (int i = 0; i < 15; ++i) {
//			vova.incrementTheGrade();
//			std::cout << vova;
//		}
//		Bureaucrat dimon("dimon", 140);
//		for (int i = 0; i < 15; ++i) {
//			dimon.decrementTheGrade();
//			std::cout << dimon;
//		}
	}
	catch (Bureaucrat::GradeTooLowException & ex) {
		std::cout << "error message: "
				  << ex.what()
				  << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & ex) {
		std::cout << "error message: "
				  << ex.what()
				  << std::endl;
	}
	return 0;
}
