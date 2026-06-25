.SILENT:

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = srcs/cub3d.c srcs/valid_map.c srcs/error.c srcs/inits.c srcs/cleaners.c
OBJ = $(SRC:.c=.o)

all: $(MLX) $(NAME) $(LIBFT)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -s -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(MAKE) -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C $(MLX_DIR) clean
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(NAME) 
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re fclean clean all