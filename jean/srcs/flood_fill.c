#include "cub3d.h"

static int is_walkable(int c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int flood_fill(t_map *map, int y, int x)
{
	if (!map)
		return (0);
	if (is_out_of_map(y, x, map))
		return (0);
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'V')
		return (1);
	if (map->grid[y][x] == ' ')
		return (0);
	else if (is_walkable(map->grid[y][x]))
		map->grid[y][x] = 'V';
	if (!flood_fill(map, y + 1, x) || !flood_fill(map, y - 1, x))
		return (0);
	if (!flood_fill(map, y, x + 1) || !flood_fill(map, y, x - 1))
		return (0);
	return (1);
}

static void set_map_attributes(t_map *original, t_map *cpy)
{
	cpy->height = original->height;
	cpy->player_x = original->player_x;
	cpy->player_y = original->player_y;
	cpy->player_dir = original->player_dir;
}

t_map *cpy_map(t_map *map)
{
	int		i;
	t_map	*cpy_map;

	i = 0;
	if (!map || !map->grid || !map->grid[0])
	return (NULL);
	cpy_map = malloc(sizeof(t_map));
	if (!cpy_map)
		return (treat_error(T_MALLOC), NULL);
	set_map_attributes(map, cpy_map);
	cpy_map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!cpy_map->grid)
		return (free_map(cpy_map), treat_error(T_MALLOC), NULL);
	while (map->grid[i])
	{
		cpy_map->grid[i] = ft_strdup(map->grid[i]);
		if (!cpy_map->grid[i])
			return (free_map(cpy_map), treat_error(T_MALLOC), NULL);
		i++;
	}
	cpy_map->grid[i] = NULL;
	return (cpy_map);
}

int valid_closed_map(t_map *map)
{
	t_map *cpy;

	if (!map || !map->grid || !map->grid[0])
		return (0);
	cpy = cpy_map(map);
	if (!cpy)
		return (0);
	if (!flood_fill(cpy, cpy->player_y, cpy->player_x))
		return (free_map(cpy), treat_error(T_MAP), 0);
	free_map(cpy);
	return (1);	
}
