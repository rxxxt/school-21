# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tredfort <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 17:10:54 by tredfort          #+#    #+#              #
#    Updated: 2021/02/11 22:05:26 by tredfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX = libmlx.dylib

LIBFT = libft.a

SRCS = main.c \
    get_next_line.c \
    take_screenshot.c \
    movement.c \
    key_processing.c \
    utils.c \
    parse.c \
    set_parameters.c \
    ray_casting_part_1.c \
    ray_casting_part_2.c \
    init_cube3d.c \
    sprites.c

SRCS2 = $(addprefix src/, $(SRCS))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx
	mv mlx/libmlx.dylib .

$(NAME): includes/cub3d.h
	$(CC) $(SRCS2) -L. -lmlx libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C libft
	make clean -C mlx

fclean: clean
	rm -f $(NAME) libmlx.dylib
	make fclean -C libft

re: fclean all

bonus: re

.PHONY:     all clean fclean re bonus
