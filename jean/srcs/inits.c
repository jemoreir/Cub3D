#include "cub3d.h"

void init_cub(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	cub->map_start = -1;
	cub->map_end = -1;
	cub->player_x = -1;
	cub->player_y = -1;
}

void extract_map(t_cub *cub)
{
	int	i;
	int	map_size;

	map_size = cub->map_end - cub->map_start + 1;
	i = 0;
	if (!cub || !cub->file_lines || cub->map_start == -1)
		return (0);
	while (i < map_size)
	{
		cub->map[i] = ft_strdup(cub->file_lines[cub-])
	}
}
