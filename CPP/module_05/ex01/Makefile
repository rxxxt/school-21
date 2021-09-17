NAME		:=	ex01

CPP			:=	clang++

CFLAGS		:=	-Wall -Wextra -Werror

DEBUG		:=	#-g

SRCS		:=	Bureaucrat.cpp			\
				Form.cpp				\
				main.cpp				\

OBJ_DIR		:=	objects/

OBJS		:=	$(SRCS:.cpp=.o)

OBJS		:=	$(addprefix $(OBJ_DIR), $(OBJS))

all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(NAME):		$(OBJS)
	$(CPP) $(DEBUG) $^ -o $@

$(OBJ_DIR)%.o:	%.cpp Bureaucrat.hpp Form.hpp
	$(CPP) $(DEBUG) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:			clean
	rm -rf $(NAME)

re:					fclean all

.PHONY:				all clean fclean re