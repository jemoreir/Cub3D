#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	init_map(&cub->map);
	cub->map_start = -1;
	cub->map_end = -1;
}

void	init_map(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
	map->player_x = -1;
	map->player_y = -1;
}

void	init_config(t_config *config)
{
	ft_bzero(config, sizeof(t_config));
}
