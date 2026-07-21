#include "cub3d.h"

void init_cub(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	init_map(&cub->map);
	cub->map_start = -1;
	cub->map_end = -1;
}

void init_map(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
	map->player_x = -1;
	map->player_y = -1;
}

void init_config(t_config *config)
{
	ft_bzero(config, sizeof(t_config));
}

int extract_map(t_cub *cub)
{
	int	i;
	int	map_it;

	map_it = 0;
	if (!cub || !cub->file_lines || cub->map_start == -1 || cub->map_end == -1)
		return (0);
	cub->map.height = cub->map_end - cub->map_start + 1;
	cub->map.grid = malloc(sizeof (char *) * (cub->map.height + 1));
	if (!cub->map.grid)
		return (treat_error(T_MALLOC), 0);
	i = cub->map_start;
	while (i <= cub->map_end)
	{
		cub->map.grid[map_it] = ft_strdup(cub->file_lines[i]);
		if (!cub->map.grid[map_it])
			return (treat_error(T_MALLOC), 0);
		map_it++;
		i++;
	}
	cub->map.grid[map_it] = NULL;
	return (1);
}

static void set_player_pos(int y, int x, t_cub *cub)
{
	cub->map.player_dir = cub->map.grid[y][x];
	cub->map.player_x = x;
	cub->map.player_y = y;
	cub->count_player++;
}

int find_player(t_cub *cub)
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
