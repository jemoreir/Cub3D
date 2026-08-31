#include "cub3d.h"
#include <math.h>

static int	can_move(t_cub *cub, double x, double y)
{
	int	ix;
	int	iy;

	ix = (int)x;
	iy = (int)y;
	if (iy < 0 || iy >= cub->map.height)
		return (0);
	if (ix < 0 || ix >= (int)ft_strlen(cub->map.grid[iy]))
		return (0);
	if (cub->map.grid[iy][ix] == '1'
		|| cub->map.grid[iy][ix] == ' ')
		return (0);
	return (1);
}

static void	move_player(t_cub *cub, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = cub->game.player.pos_x + move_x;
	new_y = cub->game.player.pos_y + move_y;
	if (can_move(cub, new_x, cub->game.player.pos_y))
		cub->game.player.pos_x = new_x;
	if (can_move(cub, cub->game.player.pos_x, new_y))
		cub->game.player.pos_y = new_y;
}

static void	rotate_player(t_cub *cub, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->game.player.dir_x;
	cub->game.player.dir_x = cub->game.player.dir_x * cos(angle)
		- cub->game.player.dir_y * sin(angle);
	cub->game.player.dir_y = old_dir_x * sin(angle)
		+ cub->game.player.dir_y * cos(angle);
	old_plane_x = cub->game.player.plane_x;
	cub->game.player.plane_x = cub->game.player.plane_x * cos(angle)
		- cub->game.player.plane_y * sin(angle);
	cub->game.player.plane_y = old_plane_x * sin(angle)
		+ cub->game.player.plane_y * cos(angle);
}

void	update_movement(t_cub *cub)
{
	double	speed;
	double	rot_speed;

	speed = 0.05;
	rot_speed = 0.03;
	if (cub->game.key_w)
		move_player(cub,
			cub->game.player.dir_x * speed,
			cub->game.player.dir_y * speed);
	if (cub->game.key_s)
		move_player(cub,
			-cub->game.player.dir_x * speed,
			-cub->game.player.dir_y * speed);
	if (cub->game.key_a)
		move_player(cub,
			-cub->game.player.plane_x * speed,
			-cub->game.player.plane_y * speed);
	if (cub->game.key_d)
		move_player(cub,
			cub->game.player.plane_x * speed,
			cub->game.player.plane_y * speed);
	if (cub->game.key_left)
		rotate_player(cub, -rot_speed);
	if (cub->game.key_right)
		rotate_player(cub, rot_speed);
}

int	game_loop(t_cub *cub)
{
	update_movement(cub);
	render_frame(cub);
	return (0);
}
