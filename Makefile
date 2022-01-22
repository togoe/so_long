NAME			=	so_long
MLX_DIR			=	./mlx/
SRC_DIR			=	./srcs/
INC_DIR			=	./includes/
SRCS			=	main.c			\
					pars_map.c
					
					
SRC_BASENAME	=	$(addprefix $(SRC_DIR), $(SRCS))		
OBJS			=	$(SRC_BASENAME:.c=.o)
CC				=	gcc
FLAGS			=	-I $(MLX_DIR) -I $(INC_DIR) -I ./libft/

.c.o		:
				$(CC) $(FLAGS) -Imlx -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(MLX_DIR)
			make -C ./libft/
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -L./libft/ -lft -lmlx -lz -lbsd -lXext -lX11
			@echo [$(NAME)] : Created !

clean		:
			rm -rf $(OBJS)
			make fclean -C ./libft/
			make clean -C $(MLX_DIR)
			@echo "[OBJS] Deleted"

fclean		:	clean
			rm -f $(NAME)
			@echo "[$(NAME)]: Deleted"

re			:	fclean all

