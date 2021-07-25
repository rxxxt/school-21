NAME			:=	philo

BONUS			:=	philo_bonus

DIR_SRCS		:=	src/

DIR_BONUS		:=	philo_bonus/

DIR_OBJS		:=	objects/

SRCS			:=	\
					main.c					\
					ft_atoi.c				\

SRCS_BONUS		:=	\

INCLUDES		:=	includes/philo.h		\

OBJS			:=	$(SRCS:.c=.o)
OBJS_BONUS		:=	$(SRCS_BONUS:.c=.o)

SRCS			:=	$(addprefix $(DIR_SRCS), $(SRCS))
SRCS_BONUS		:=	$(addprefix $(DIR_SRCS), $(SRCS_BONUS))

OBJS			:=	$(addprefix $(DIR_OBJS), $(OBJS))
OBJS_BONUS 		:=	$(addprefix $(DIR_OBJS), $(OBJS_BONUS))

CC				:=	gcc

DEBUG			:=	#-g

FLAGS			:=	#-Wall -Wextra -Werror

all:				$(DIR_OBJS) $(NAME)

$(DIR_OBJS):
	mkdir -p $@

$(DIR_OBJS)%.o:		$(DIR_SRCS)%.c $(INCLUDES)
	@$(CC) $(DEBUG) $(FLAGS) -c $< -o $@

$(DIR_OBJS)%.o:		$(DIR_BONUS)%.c $(INCLUDES)
	$(CC) $(DEBUG) $(FLAGS) -c $< -o $@

$(NAME):			$(OBJS)
	$(CC) $^ -o $@

$(BONUS):			$(OBJS_BONUS)
	$(CC) $^ -o $@

bonus:				$(DIR_OBJS) $(BONUS)

clean:
	rm -rf $(DIR_OBJS)

fclean:				clean
	rm $(NAME)
	rm $(BONUS)

re:					fclean all

.PHONY:				all clean fclean re bonus