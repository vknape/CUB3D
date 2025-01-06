NAME		=		cub3D
SRC			=		main.c
OBJ			=		$(SRC:.c=.o)
CC			=		cc
FLAGS		=		-Wall -Wextra -Werror -g
# FLAGS		+=		-fsanitize=thread
# FLAGS		+=		-fsanitize=address
MLX42		=		MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
ARGS		=		

all:	libmlx	$(NAME)

libmlx:
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

$(NAME):	$(OBJ)
				$(CC) $(FLAGS) $(MLX42) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
				@rm -f $(OBJ)

fclean:		clean
				@rm -f $(NAME)

re:			fclean all

run:		all
				@./$(NAME) $(ARGS)
#				@bash ./test.sh
#				@valgrind --leak-check=full ./$(NAME) $(ARGS)


.PHONY:		all clean fclean re