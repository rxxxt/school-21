NAME =		libasm.a

SRC = 		ft_read.s \
			ft_write.s \
			ft_strcmp.s \
			ft_strlen.s \
			ft_strcpy.s \
			ft_strdup.s

SRC_BONUS =	ft_list_push_front_bonus.s \
			ft_list_size_bonus.s

FLAGS =		-f macho64

OBJ =		$(SRC:.s=.o)

OBJ_BONUS =	$(SRC_BONUS:.s=.o)

%.o: %.s libasm.h
	nasm $(FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

bonus: $(OBJ) $(OBJ_BONUS)
	ar rc $(NAME) $^

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus