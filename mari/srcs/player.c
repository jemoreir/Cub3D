#include "cub3d.h"

static void	set_north_south(t_player *player, char dir)
{
	player->dir_x = 0;
	player->plane_y = 0;
	if (dir == 'N')
	{
		player->dir_y = -1;
		player->plane_x = 0.66;
	}
	else
	{
		player->dir_y = 1;
		player->plane_x = -0.66;
	}
}

static void	set_east_west(t_player *player, char dir)
{
	player->dir_y = 0;
	player->plane_x = 0;
	if (dir == 'E')
	{
		player->dir_x = 1;
		player->plane_y = 0.66;
	}
	else
	{
		player->dir_x = -1;
		player->plane_y = -0.66;
	}
}

static void	set_player_direction(t_player *player, char dir)
{
	if (dir == 'N' || dir == 'S')
		set_north_south(player, dir);
	else
		set_east_west(player, dir);
}

void	init_player(t_cub *cub)
{
	cub->game.player.pos_x = cub->map.player_x + 0.5;
	cub->game.player.pos_y = cub->map.player_y + 0.5;
	set_player_direction(&cub->game.player, cub->map.player_dir);
}
