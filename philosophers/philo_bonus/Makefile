NAME			:=	philo_bonus

DIR_SRCS		:=	src/

DIR_OBJS		:=	objects/

SRCS			:=	\
					error_management.c		\
					ft_atoi.c				\
					initialization.c		\
					life_of_philosopher.c	\
					main.c					\
					observer.c				\
					time_managment.c		\

INCLUDES		:=	includes/philo_bonus.h	\

OBJS			:=	$(SRCS:.c=.o)

SRCS			:=	$(addprefix $(DIR_SRCS), $(SRCS))

OBJS			:=	$(addprefix $(DIR_OBJS), $(OBJS))

CC				:=	gcc

DEBUG			:=	#-g

FLAGS			:=	-Wall -Wextra -Werror

all:				$(DIR_OBJS) $(NAME)

$(DIR_OBJS):
	mkdir -p $@

$(DIR_OBJS)%.o:		$(DIR_SRCS)%.c $(INCLUDES)
	@$(CC) $(DEBUG) $(FLAGS) -c $< -o $@

$(NAME):			$(OBJS)
	$(CC) $^ -o $@

clean:
	rm -rf $(DIR_OBJS)

fclean:				clean
	rm $(NAME)

re:					fclean all

.PHONY:				all clean fclean re