#include "cub3d.h"

void init_cub(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	cub->map_start = -1;
	cub->map_end = -1;
	cub->player_x = -1;
	cub->player_y = -1;
}

int extract_map(t_cub *cub)
{
	int	i;
	int	map_it;
	int	map_size;

	map_it = 0;
	if (!cub || !cub->file_lines || cub->map_start == -1 || cub->map_end == -1)
		return (0);
	map_size = cub->map_end - cub->map_start + 1;
	cub->map = malloc(sizeof (char *) * (map_size + 1));
	if (!cub->map)
		return (treat_error(T_MALLOC), 0);
	i = cub->map_start;
	while (i <= cub->map_end)
	{
		cub->map[map_it] = ft_strdup(cub->file_lines[i]);
		if (!cub->map[map_it])
			return (treat_error(T_MALLOC), 0);
		map_it++;
		i++;
	}
	cub->map[map_it] = NULL;
	return (1);
}
