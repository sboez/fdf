NAME 	= 	fdf

SRC 	= 	src/main.c \
			src/draw.c \
			src/key_move.c \
			src/projections.c \
			src/read_file.c \

FLAGS 	= 	-Wall -Werror -Wextra

OBJ 	= 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a -L/usr/X11/lib -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re