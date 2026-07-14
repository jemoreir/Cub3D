#include "cub3d.h"

/* int	flood_fill(t_cub *cub)
{
} */
static void set_map_attributes(t_map *original, t_map *cpy)
{
	cpy->height = original->height;
	cpy->player_x = original->player_x;
	cpy->player_y = original->player_y;
	cpy->player_dir = original->player_dir;
}

t_map *cpy_map(t_cub *cub)
{
	int		i;
	int		size_map;
	t_map	*cpy_map;

	i = 0;
	if (!cub || !cub->map.grid || !cub->map.grid[0])
		return (NULL);
	cpy_map = malloc(sizeof(t_map));
	if (!cpy_map)
		return (treat_error(T_MALLOC), NULL);
	size_map = cub->map_end - cub->map_start + 1;
	cpy_map->grid = malloc(sizeof(char *) * (size_map + 1));
	if (!cpy_map->grid)
		return (free_map(cpy_map), treat_error(T_MALLOC), NULL);
	while (cub->map.grid[i])
	{
		cpy_map->grid[i] = ft_strdup(cub->map.grid[i]);
		if (!cpy_map->grid[i])
			return (free_map(cpy_map), treat_error(T_MALLOC), NULL);
		i++;
	}
	cpy_map->grid[i] = NULL;
	set_map_attributes(&cub->map, cpy_map);
	return (cpy_map);
}
