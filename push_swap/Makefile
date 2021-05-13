# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tredfort <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 22:45:16 by tredfort          #+#    #+#              #
#    Updated: 2021/04/19 22:45:18 by tredfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER =	checker

PUSH_SWAP =	push_swap

LIBFT =		libft/libft.a

DIR_SRCS =	src

DIR_OBJS =	objects

SRCS1 =		checker.c

SRCS2 =		main.c

OBJS1 =		$(addprefix $(DIR_OBJS)/, $(SRCS1:.c=.o))

OBJS2 =		$(addprefix $(DIR_OBJS)/, $(SRCS2:.c=.o))

CC = gcc

FLAGS = #-Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(DIR_OBJS)/%.o:$(DIR_SRCS)/%.c includes/push_swap.h
	mkdir -p objects
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

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
