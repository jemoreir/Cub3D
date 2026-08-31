.SILENT:

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = srcs/cub3d.c srcs/valid_map.c srcs/error.c srcs/inits.c \
	srcs/cleaners.c srcs/helpers.c srcs/map_helpers.c srcs/checks.c \
	srcs/flood_fill.c srcs/config_helpers.c srcs/texture_setters.c \
	srcs/color_helpers.c srcs/color_setters.c srcs/player_setter.c \
	srcs/init_game.c srcs/image.c srcs/render.c srcs/player.c \
	srcs/movement.c srcs/raycast.c srcs/raycast_draw.c \
	srcs/raycast_extras.c srcs/textures.c 

OBJ = $(SRC:.c=.o)

all: $(MLX) $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -s -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) \
		$(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C $(MLX_DIR) clean
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re