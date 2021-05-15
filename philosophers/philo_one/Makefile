NAME	:=	philo_one

SRCS	:=	main.c			\
			ft_atoi.c		\

OBJS	:=	$(SRCS:.c=.o)

CFLAGS	:=	#-Wall -Wextra -Werror

all: 	$(NAME)

%.o:	%.c philo_one.h
	gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	gcc $^ -o $@

clean:
	rm $(OBJS)

fclean:		clean
	rm $(NAME)

re:			fclean all

.PHONY:		all clean fclean re