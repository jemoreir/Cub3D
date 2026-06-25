#ifndef CUB3D_H
# define CUB3d_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef enum e_error_type
{
	T_MALLOC,
	T_OPEN,
	T_EXTENSION,
	T_ARG
}   t_error_type;

typedef struct s_cub
{
	char	**file_lines;
	char	**map;
	char	*north_t;
	char	*south_t;
	char	*west_t;
	char	*east_t;
	int		map_start;
	int		floor_rgb[3];
	int		sky_rgb[3];
	int		has_no;
	int		has_so;
	int		has_we;
	int		has_ea;
	int		has_floor;
	int		has_sky;
	int		player_x;
	int		player_y;
	char	player_dir;
	int		count_player;
}	t_cub;

int		count_lines(char *file);
int		check_extension(char *filename);
void	treat_error(t_error_type error);
int		is_map_line(char *line);
char	**file_to_array(char *filename);
void	free_cub(t_cub *cub);
void	init_cub(t_cub *cub);

#endif