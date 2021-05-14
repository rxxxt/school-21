NAME =		checker

LIBFT =		../../libft/libft.a

DIR_OBJS =	objects

SRCS =		checker.c \
			main.c

OBJS =		$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

all: $(LIBFT)
 #$(DIR_OBJS) $(NAME)

$(DIR_OBJS):
	mkdir -p $@

$(DIR_OBJS)/%.o:%.c ../../includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ../../libft

$(NAME): $(OBJS)
	$(CC) $^ LIBFT -o $@

clean:
	rm -rf $(DIR_OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
