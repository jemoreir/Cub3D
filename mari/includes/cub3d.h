#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_texdraw
{
	t_texture	*tex;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			tex_x;
}	t_texdraw;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_player	player;
	t_ray		ray;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
}	t_game;

typedef enum e_error_type
{
	T_MALLOC,
	T_OPEN,
	T_EXTENSION,
	T_ARG,
	T_GNL,
	T_MAP,
	T_CONFIG
}	t_error_type;

typedef enum e_config_id
{
	T_INVALID,
	T_NO,
	T_SO,
	T_WE,
	T_EA,
	T_F,
	T_C
}	t_config_id;

typedef struct s_config
{
	int	comp;
	int	sep;
	int	has_d;
}	t_config;

typedef struct s_map
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
	int		ceil_rgb[3];
	int		has_no;
	int		has_so;
	int		has_we;
	int		has_ea;
	int		has_floor;
	int		has_ceil;
	int		count_player;
	t_game	game;
}	t_cub;

void	init_steps(t_cub *cub);
void	set_wall_limits(t_ray *ray);

int		init_game(t_cub *cub);
void	close_game(t_cub *cub);
int		key_hook(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);
int		close_hook(t_cub *cub);

int		init_image(t_cub *cub);
void	put_pixel(t_img *img, int x, int y, int color);
int		rgb_to_int(int r, int g, int b);
int		load_textures(t_cub *cub);
void	destroy_textures(t_cub *cub);

void	render_background(t_cub *cub);
void	cast_ray(t_cub *cub, int x);
void	render_raycast(t_cub *cub);
void	render_frame(t_cub *cub);

void	init_player(t_cub *cub);
void	update_movement(t_cub *cub);
int		game_loop(t_cub *cub);

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
int		is_out_of_map(int y, int x, t_map *map);
int		valid_closed_map(t_map *map);
int		set_no(t_cub *cub, char *line);
int		set_so(t_cub *cub, char *line);
int		set_we(t_cub *cub, char *line);
int		set_ea(t_cub *cub, char *line);
int		find_start_path(char *line);
void	init_config(t_config *config);
int		check_parameters(t_config *config, int *i);
int		set_element_color_floor(t_cub *cub, t_config *c,
			int *i, char *line);
int		set_element_color_ceil(t_cub *cub, t_config *c,
			int *i, char *line);
int		set_color(t_config_id id, t_cub *cub, char *line);
int		valid_configs(t_cub *cub);
int		parsing_cub(char *filename, t_cub *cub);

#endif