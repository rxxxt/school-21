NAME			:=	push_swap

BONUS			:=	checker

LIBFT			:=	libft/libft.a

DIR_SRCS		:=	src/

DIR_OBJS		:=	objects/

SRCS			:=	push_swap.c						\
					main.c

SRCS_STACK		:=	operations_push.c				\
					operations_rotate.c				\
					processing.c					\
					operations_reverse_rotate.c		\
					operations_swap.c				\
					stack.c

SRCS_BONUS		:=	checker.c						\
					main.c

OBJS			:=	$(SRCS:.c=.o)
OBJS_STACK		:=	$(SRCS_STACK:.c=.o)
OBJS_BONUS		:=	$(SRCS_BONUS:.c=.o)

SRCS			:=	$(addprefix $(DIR_SRCS)$(NAME)/, $(SRCS))
SRCS_STACK		:=	$(addprefix $(DIR_SRCS)stack/, $(SRCS_STACK))
SRCS_BONUS		:=	$(addprefix $(DIR_SRCS)$(BONUS)/, $(SRCS_BONUS))

OBJS			:=	$(addprefix $(DIR_OBJS), $(OBJS))
OBJS_STACK		:=	$(addprefix $(DIR_OBJS), $(OBJS_STACK))
OBJS_BONUS 		:=	$(addprefix $(DIR_OBJS), $(OBJS_BONUS))

CC				:=	gcc

FLAGS			:=	#-Wall -Wextra -Werror

all:			$(DIR_OBJS) $(NAME)

$(DIR_OBJS):
	mkdir -p $@

$(DIR_OBJS)%.o:		$(DIR_SRCS)stack/%.c includes/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(DIR_OBJS)%.o:		$(DIR_SRCS)$(NAME)/%.c includes/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(NAME):			$(LIBFT) $(OBJS) $(OBJS_STACK)
	$(CC) $^ -o $@

bonus: $(LIBFT) $(OBJS_BONUS)
	$(CC) $^ -o $@

clean:
	rm -rf $(DIR_OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus