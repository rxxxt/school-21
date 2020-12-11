# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tredfort <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 13:47:00 by tredfort          #+#    #+#              #
#    Updated: 2020/12/07 18:53:11 by tredfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c utils.c print.c standart_utils.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

INCLUDES = ./

all: $(NAME)

%o : %c printf.h
	gcc $(FLAGS) -I$(INCLUDES) $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:     all clean fclean re
