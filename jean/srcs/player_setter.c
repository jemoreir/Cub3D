#include "cub3d.h"

static void	set_player_pos(int y, int x, t_cub *cub)
{
	cub->map.player_dir = cub->map.grid[y][x];
	cub->map.player_x = x;
	cub->map.player_y = y;
	cub->count_player++;
}

int	find_player(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	if (!cub || !cub->map.grid || !cub->map.grid[0])
		return (0);
	while (cub->map.grid[y])
	{
		x = 0;
		while (cub->map.grid[y][x])
		{
			if (cub->map.grid[y][x] == 'N' || cub->map.grid[y][x] == 'S'
				|| cub->map.grid[y][x] == 'E' || cub->map.grid[y][x] == 'W')
				set_player_pos(y, x, cub);
			x++;
		}
		y++;
	}
	if (cub->count_player != 1)
		return (treat_error(T_MAP), 0);
	return (1);
}
