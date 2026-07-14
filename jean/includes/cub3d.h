#ifndef CUB3D_H
# define CUB3d_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef enum e_error_type
{
	T_MALLOC,
	T_OPEN,
	T_EXTENSION,
	T_ARG,
	T_GNL,
	T_MAP
}   t_error_type;

typedef struct t_map
{
	char	**grid;
	char	player_dir;
	int		height;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_cub
{
	t_map	map;
	char	**file_lines;
	char	*north_t;
	char	*south_t;
	char	*west_t;
	char	*east_t;
	int		map_start;
	int		map_end;
	int		floor_rgb[3];
	int		sky_rgb[3];
	int		has_no;
	int		has_so;
	int		has_we;
	int		has_ea;
	int		has_floor;
	int		has_sky;
	int		count_player;
}	t_cub;

int		count_lines(char *file);
int		check_extension(char *filename);
void	treat_error(t_error_type error);
int		is_map_line(char *line);
char	**file_to_array(char *filename);
void	free_cub(t_cub *cub);
void	init_cub(t_cub *cub);
int		construct_array_cub(int fd, int count, char **array);
int		line_has_char(char *line, char c);
int		find_start_map(t_cub *cub);
int		has_map_content(char *line);
int		valid_map_block(t_cub *cub);
int		is_border_wall_line(char *line);
int		extract_map(t_cub *cub);
int		is_config_line(char *line);
int		valid_border_map(t_cub *cub);
void	free_map(t_map *map);
void	init_map(t_map *map);
int		find_player(t_cub *cub);
t_map	*cpy_map(t_cub *cub);
int		is_out_of_map(int y, int x, t_cub *cub);

#endif