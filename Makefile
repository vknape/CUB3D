NAME		=		cub3D
SRC			=		clean.c\
					get_next_line_utils.c\
					get_next_line.c\
					init.c\
					main.c\
					map_boundaries.c\
					parsing.c\
					utils.c\
					verify_cub.c\
					parse_map.c\
					put_pixel.c\
					raycasting.c\
					raycast_x.c\
					raycast_y.c
OBJ			=		$(SRC:.c=.o)
CC			=		cc
FLAGS		=		-Wall -Wextra -Werror -g
# FLAGS		+=		-fsanitize=thread
# FLAGS		+=		-fsanitize=address
MLX42		=		MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
LIBFT 		=		./libft/libft.a
ARGS		=		

all:	libmlx	$(NAME)

libmlx:
	cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

$(LIBFT):
	make -C ./libft

$(NAME):	$(OBJ) $(LIBFT) 
				$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
				@rm -f $(OBJ)
				@make clean -C ./libft
				#@rm -rf ./MLX42/build

fclean:		clean
				@rm -f $(NAME)
				@make fclean -C ./libft

re:			fclean all
				make clean

run:		all
				@./$(NAME) $(ARGS)
#				@bash ./test.sh
#				@valgrind --leak-check=full ./$(NAME) $(ARGS)


.PHONY:		all clean fclean re libmlx