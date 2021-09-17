NAME		:=	ex03

CPP			:=	clang++

CFLAGS		:=	-Wall -Wextra -Werror

DEBUG		:=	#-g

SRCS		:=	Bureaucrat.cpp				\
				AForm.cpp					\
				PresidentialPardonForm.cpp	\
				RobotomyRequestForm.cpp		\
				ShrubberyCreationForm.cpp	\
				Intern.cpp					\
				main.cpp					\

INCLUDES	:=	Bureaucrat.hpp				\
				AForm.hpp					\
				PresidentialPardonForm.hpp	\
				RobotomyRequestForm.hpp		\
				ShrubberyCreationForm.hpp	\
				Intern.hpp					\

OBJ_DIR		:=	objects/

OBJS		:=	$(SRCS:.cpp=.o)

OBJS		:=	$(addprefix $(OBJ_DIR), $(OBJS))

all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(NAME):		$(OBJS)
	$(CPP) $(DEBUG) $^ -o $@

$(OBJ_DIR)%.o:	%.cpp $(INCLUDES)
	$(CPP) $(DEBUG) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:			clean
	rm -rf $(NAME)

re:					fclean all

.PHONY:				all clean fclean re